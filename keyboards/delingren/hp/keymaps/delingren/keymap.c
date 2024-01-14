#include QMK_KEYBOARD_H

enum keyboard_layers {
  _BL,
  _LOWER,
};

#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_ansi(
                 KC_RSFT,                   KC_LSFT,
                                   KC_RCTL,          KC_LCTL,
        KC_F7,   KC_W,    KC_2,    KC_S,    KC_X,    KC_F6,   KC_F5,   KC_F8,
        KC_ESC,  KC_Q,    KC_1,    KC_A,    KC_Z,    KC_TAB,  KC_TILD, KC_CAPS,
        KC_F4,   KC_E,    KC_3,    KC_D,    KC_C,    KC_F3,   KC_F2,   KC_F1,
        KC_G,    KC_R,    KC_4,    KC_F,    KC_V,    KC_T,    KC_5,    KC_B, 
        KC_H,    KC_U,    KC_7,    KC_J,    KC_M,    KC_Y,    KC_6,    KC_N,
                 KC_I,    KC_8,    KC_K,    KC_COMM, KC_RBRC,
        KC_LGUI,
                          KC_LALT,                                     KC_RALT,
        KC_BSPC, KC_UP,   KC_DOWN, KC_ENT,  KC_SPC,           KC_BSLS, KC_PSCR,
        KC_F11,  KC_0,    KC_9,    KC_L,    KC_DOT,  KC_F10,  KC_F9,   KC_F12,
        KC_QUOT, KC_P,    KC_0,    KC_SCLN, KC_SLSH, KC_LBRC, KC_MINS, KC_EQL,
        KC_INS,  KC_LEFT, KC_RGHT, KC_PGDN, KC_END,  KC_HOME, KC_PGUP, KC_DEL,
                                                              LOWER
    ),
};
