#include "led.h"
#include "action_layer.h"


static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0: Core 0
 * QWERTY
 *
 * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|FN3|FN1|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------.
 * |~  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp | |Ins|Hom|PgU|
 * |-----------------------------------------------------------| |-----------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \| |Del|End|PgD|
 * |-----------------------------------------------------------| `-----------'
 * |FN5   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
 * |-----------------------------------------------------------|     ,---.
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |     |Up |
 * |-----------------------------------------------------------| ,-----------.
 * |Ctl|Gui|Alt|          Space                |Alt|Gui|FN4|Ctl| |Lef|Dow|Rig|
 * `-----------------------------------------------------------' `-----------'
 */

    KEYMAP(\
        ESC,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,       PSCR,  FN3,  FN1, \
        GRV,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, BSPC,  INS, HOME, PGUP, \
        TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSLS,  DEL,  END, PGDN, \
        FN5,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,        ENT,                   \
       LSFT, NUBS,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,       RSFT,         UP,       \
       LCTL, LGUI, LALT,              SPC,                         RALT, RGUI,  FN4, RCTL, LEFT, DOWN, RGHT),


/*
 * Layer 1: Core 1
 * I wanna keybinding
 *
 * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |   |   |   |   |   |   | |   |   |   |   | |   |   |   |   | |   |FN0|FN2|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------.
 * |   |   |   |   |   |   |   |   |   |   |   |   |   |       | |   |   |   |
 * |-----------------------------------------------------------| |-----------|
 * |     |   |   |   |   |   |   |   |   |   |   |   |   |     | |   |   |   |
 * |-----------------------------------------------------------| `-----------'
 * |      |  R|   |   |   |   |   |   |   |   |   |   |        |
 * |-----------------------------------------------------------|     ,---.
 * |        |SFT|  Z|   |   |   |   |   |   |   |   |Up        |     |SFT|
 * |-----------------------------------------------------------| ,-----------.
 * |   |   |   |                               |   |   |   |   | |   |KP0|   |
 * `-----------------------------------------------------------' `-----------'
 */

    KEYMAP(\
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,  FN0,  FN2, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS,    R, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,                   \
        TRNS, TRNS, LSFT,    Z, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,         UP,       LSFT,       \
        TRNS, TRNS, TRNS,                   TRNS,                   TRNS, TRNS, TRNS, TRNS, TRNS,   P0, TRNS),


/*
 * Layer 2: Core 2
 * osu! keybinding
 *
 * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |   |   |   |   |   |   | |   |   |   |   | |   |   |   |   | |   |FN1|FN3|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------.
 * |   |   |   |   |   |   |   |   |   |   |   |   |   |       | |   |   |   |
 * |-----------------------------------------------------------| |-----------|
 * |     |   |   |   |   |   |   |   |   |   |   |   |   |     | |   |   |   |
 * |-----------------------------------------------------------| `-----------'
 * |      |   |   |   |   |   |   |   |   |   |   |   |        |
 * |-----------------------------------------------------------|     ,---.
 * |        |   |   |   |   |   |   |   |   |   |   |          |     |   |
 * |-----------------------------------------------------------| ,-----------.
 * |   |Alt|Alt|                               |   |   |   |   | |   |   |   |
 * `-----------------------------------------------------------' `-----------'
 */

    KEYMAP(\
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,  FN1,  FN3, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,                   \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS,       \
        TRNS, LALT, RALT,                   TRNS,                   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),


/*
 * Layer 3: Core 3
 *
 * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |   |   |   |   |   |   | |   |   |   |   | |   |   |   |   | |   |FN2|FN0|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------.
 * |   |   |   |   |   |   |   |   |   |   |   |   |   |       | |   |   |   |
 * |-----------------------------------------------------------| |-----------|
 * |     |   |   |   |   |   |   |   |   |   |   |   |   |     | |   |   |   |
 * |-----------------------------------------------------------| `-----------'
 * |      |   |   |   |   |   |   |   |   |   |   |   |        |
 * |-----------------------------------------------------------|     ,---.
 * |        |   |   |   |   |   |   |   |   |   |   |          |     |   |
 * |-----------------------------------------------------------| ,-----------.
 * |   |   |   |                               |   |   |   |   | |   |   |   |
 * `-----------------------------------------------------------' `-----------'
 */

    KEYMAP(\
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,  FN2,  FN0, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,                   \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       TRNS,       \
        TRNS, TRNS, TRNS,                   TRNS,                   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),


/*
 * Layer 4: Overlay 0
 *          Media Keys
 *
 * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |   |   |   |   |   |   | |   |   |   |   | |   |   |   |   | |NmL|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------.
 * |   |KP1|KP2|KP3|KP4|KP5|KP6|KP7|KP8|KP9|KP0|   |   |       | |   |Med|Vl+|
 * |-----------------------------------------------------------| |-----------|
 * |     |   |   |   |   |   |   |   |   |   |   |   |   |     | |   |Mut|Vl-|
 * |-----------------------------------------------------------| `-----------'
 * |      |   |   |   |   |   |   |   |   |   |   |   |        |
 * |-----------------------------------------------------------|     ,---.
 * |        |   |   |   |   |   |   |   |   |   |   |          |     |Ply|
 * |-----------------------------------------------------------| ,-----------.
 * |   |   |   |                               |   |   |   |   | |Prv|Stp|Nxt|
 * `-----------------------------------------------------------' `-----------'
 */

    KEYMAP(\
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       NLCK, SLCK,  BRK, \
        TRNS,   P1,   P2,   P3,   P4,   P5,   P6,   P7,   P8,   P9,   P0, TRNS, TRNS, TRNS, TRNS, MSEL, VOLU, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, MUTE, VOLD, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,                   \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,       MPLY,       \
        TRNS, TRNS, TRNS,                   TRNS,                   TRNS, TRNS, TRNS, TRNS, MPRV, MSTP, MNXT),


/*
 * Layer 5: Overlay 1
 * Vim cursor movement and mouse movement
 *
 * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |   |   |   |   |   |   | |   |   |   |   | |   |   |   |   | |   |   |   |
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------.
 * |   |   |   |   |   |   |   |   |   |   |   |   |   |       | |   |   |   |
 * |----------------------------------------------------------| |-----------|
 * |     |Ma0|Ma1|Ma2|   |   |   |Hom|PgU|   |   |   |   |     | |   |   |   |
 * |-----------------------------------------------------------| `-----------'
 * |      |Mb2|Mb1|Mb3|Mb4|Mb5|Lef|Dow| Up|Rig|   |   |        |
 * |-----------------------------------------------------------|     ,---.
 * |        |MwL|MwD|MwU|MwR|   |   |End|PgD|   |   |          |     |McU|
 * |-----------------------------------------------------------| ,-----------.
 * |   |   |Mb1|                               |   |   |   |   | |McL|McD|McR|
 * `-----------------------------------------------------------' `-----------'
 * Mc: Mouse Cursor / Mw: Mouse Wheel / Ma: Mouse Acceleration
 */

    KEYMAP(\
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, ACL0, ACL1, ACL2, TRNS, TRNS, TRNS, HOME, PGUP, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, BTN2, BTN1, BTN3, BTN4, BTN5, LEFT, DOWN,   UP, RGHT, TRNS, TRNS,       TRNS,                   \
        TRNS, TRNS, WH_L, WH_D, WH_U, WH_R, TRNS, TRNS,  END, PGDN, TRNS, TRNS,       TRNS,       MS_U,       \
        TRNS, TRNS, BTN1,                   TRNS,                   TRNS, TRNS, TRNS, TRNS, MS_L, MS_D, MS_R),

};


enum function_id {
    LED_OPERATION,
};

static const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION_OPT(LED_OPERATION, 0),
    [1] = ACTION_FUNCTION_OPT(LED_OPERATION, 1),
    [2] = ACTION_FUNCTION_OPT(LED_OPERATION, 2),
    [3] = ACTION_FUNCTION_OPT(LED_OPERATION, 3),
    [4] = ACTION_LAYER_MOMENTARY(4),
    [5] = ACTION_LAYER_TAP_KEY(5, KC_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case LED_OPERATION:
            if (record->event.pressed) {
                // set the layer
                layer_move(opt);
                // set the leds
                const uint8_t led_l = ((opt >> 1) & 1) << USB_LED_CAPS_LOCK;
                const uint8_t led_r = ((opt >> 0) & 1) << USB_LED_SCROLL_LOCK;
                led_set(led_l | led_r);
            }
            break;
    }
}
