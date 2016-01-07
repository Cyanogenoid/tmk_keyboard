/* Copyright 2012 Jun Wako <wakojun@gmail.com>
 *
 * This is heavily based on hid_liber/board.{c|h}.
 * https://github.com/BathroomEpiphanies/AVR-Keyboard
 *
 * Copyright (c) 2012 Fredrik Atmer, Bathroom Epiphanies Inc
 * http://bathroomepiphanies.com
 *
 * As for liscensing consult with the original files or its author.
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


#ifndef DEBOUNCE
#   define DEBOUNCE 0
#endif

// bit array of key state(1:on, 0:off)
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debounce[MATRIX_ROWS * MATRIX_COLS];


#define _DDRA (uint8_t *const)&DDRA
#define _DDRB (uint8_t *const)&DDRB
#define _DDRC (uint8_t *const)&DDRC
#define _DDRD (uint8_t *const)&DDRD
#define _DDRE (uint8_t *const)&DDRE
#define _DDRF (uint8_t *const)&DDRF

#define _PINA (uint8_t *const)&PINA
#define _PINB (uint8_t *const)&PINB
#define _PINC (uint8_t *const)&PINC
#define _PIND (uint8_t *const)&PIND
#define _PINE (uint8_t *const)&PINE
#define _PINF (uint8_t *const)&PINF

#define _PORTA (uint8_t *const)&PORTA
#define _PORTB (uint8_t *const)&PORTB
#define _PORTC (uint8_t *const)&PORTC
#define _PORTD (uint8_t *const)&PORTD
#define _PORTE (uint8_t *const)&PORTE
#define _PORTF (uint8_t *const)&PORTF

#define _BIT0 0x01
#define _BIT1 0x02
#define _BIT2 0x04
#define _BIT3 0x08
#define _BIT4 0x10
#define _BIT5 0x20
#define _BIT6 0x40
#define _BIT7 0x80

/* Specifies the ports and pin numbers for the rows */
static
uint8_t *const row_ddr[MATRIX_ROWS] = {
                                           _DDRB,                  _DDRB,
                                                           _DDRC,  _DDRC,
           _DDRD,  _DDRD,  _DDRD,  _DDRD,  _DDRD,  _DDRD,  _DDRD,  _DDRD,
           _DDRF,  _DDRF,                  _DDRF,  _DDRF,  _DDRF,  _DDRF};

static
uint8_t *const row_port[MATRIX_ROWS] = {
                                          _PORTB,                 _PORTB,
                                                          _PORTC, _PORTC,
          _PORTD, _PORTD, _PORTD, _PORTD, _PORTD, _PORTD, _PORTD, _PORTD,
          _PORTF, _PORTF,                 _PORTF, _PORTF, _PORTF, _PORTF};

static
uint8_t *const row_pin[MATRIX_ROWS] = {
                                           _PINB,                  _PINB,
                                                           _PINC,  _PINC,
           _PIND,  _PIND,  _PIND,  _PIND,  _PIND,  _PIND,  _PIND,  _PIND,
           _PINF,  _PINF,                  _PINF,  _PINF,  _PINF,  _PINF};

static
const uint8_t row_bit[MATRIX_ROWS] = {
                                           _BIT4,                  _BIT7,
                                                           _BIT6,  _BIT7,
           _BIT0,  _BIT1,  _BIT2,  _BIT3,  _BIT4,  _BIT5,  _BIT6,  _BIT7,
           _BIT0,  _BIT1,                  _BIT4,  _BIT5,  _BIT6,  _BIT7};

static
const uint8_t mask = 0x0E;

/* Specifies the ports and pin numbers for the columns */
static
const uint8_t   col_bit[MATRIX_COLS] = {  0x00,   0x02,   0x04,   0x06,   0x08,   0x0A,   0x0C,   0x0E};

static
inline void pull_column(int col) {
  PORTB = col_bit[col] | (PORTB & ~mask);
}

static
inline void release_column(int col) {
}

/* PORTB is set as input with pull-up resistors
   PORTC,D,E,F are set to high output */
static
void setup_io_pins(void) {
  uint8_t row;
  DDRB  |=  0x0E;
  PORTB &= ~0x0E;
  for(row = 0; row < MATRIX_ROWS; row++) {
    *row_ddr[row]  &= ~row_bit[row];
    *row_port[row] &= ~row_bit[row];
  }
}

static
void setup_leds(void) {
  DDRB  |=  0x60;
  PORTB |=  0x60;
}


inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // To use PORTF disable JTAG with writing JTD bit twice within four cycles.
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);

    // initialize row and col
    setup_io_pins();
    setup_leds();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        for (uint8_t j=0; j < MATRIX_COLS; j++) {
            matrix_debounce[j * MATRIX_ROWS + i] = 0;
        }
    }
}

uint8_t matrix_scan(void)
{
    // debounce code adapted from Soarer on geekhack
    // https://geekhack.org/index.php?topic=42385.msg1085707#msg1085707

    // scan delay
    _delay_ms(1);

    // how many scans to match pattern with
    uint8_t debounce_mask = 0xFF >> (7 - DEBOUNCE);

    // fast debounce pattern
    uint8_t debounce_down = 0x01;
    uint8_t debounce_up = debounce_down ^ debounce_mask;

    // slow debounce pattern
    // when the key is pressed/released for less than the debounce time,
    // this makes sure that the key is released/pressed afterwards
    uint8_t debounce_down_safe = debounce_mask >> 1;
    uint8_t debounce_up_safe = debounce_down_safe ^ debounce_mask;

    // array of bytes that hold the bit buffers
    uint8_t* debounce_buffer = matrix_debounce;

    for (uint8_t col = 0; col < MATRIX_COLS; col++) {  // 0-7
        pull_column(col);   // output hi on the line
        _delay_us(5);       // without this wait it won't read stable value.
        uint8_t col_offset = col * MATRIX_ROWS;
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {  // 0-17
            bool curr_bit = *row_pin[row] & row_bit[row];  // read current value
            uint8_t offset = col_offset + row;  // calculate offset that corresponds to the key

            // update buffer with new value
            uint8_t buffer = (debounce_buffer[offset] << 1) | curr_bit;
            debounce_buffer[offset] = buffer;

            // buffer must have changed recently
            if (buffer != 0x00 && buffer != 0xFF) {
                // only consider part of buffer within the mask
                buffer &= debounce_mask;

                // match debounce patterns
                if (buffer == debounce_down || buffer == debounce_down_safe) {
                    matrix[row] |=  ((matrix_row_t)1<<col);
                } else if (buffer == debounce_up || buffer == debounce_up_safe) {
                    matrix[row] &= ~((matrix_row_t)1<<col);
                }
            }
        }
        release_column(col);
    }

    return 1;
}

bool matrix_is_modified(void)
{
    // NOTE: no longer used
    return true;
}

inline
bool matrix_has_ghost(void)
{
    return false;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 01234567\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        for (uint8_t j = 0; j < MATRIX_COLS; j++) {
            if (matrix_is_on(i, j))
                count++;
        }
    }
    return count;
}
