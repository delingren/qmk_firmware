#include QMK_KEYBOARD_H

#define LAYOUT_65SPLIT( \
  LA3, LA4, LA5, LA6, LA7, LA8, LA9,      RA1, RA2, RA3, RA4, RA5, RA6,      RA8, RA9, \
  LB3, LB4, LB5, LB6, LB7, LB8,           RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9, \
  LC3, LC4, LC5, LC6, LC7, LC8,           RC1, RC2, RC3, RC4, RC5, RC6,      RC8, RC9, \
  LD3,      LD5, LD6, LD7, LD8, LD9,      RD1, RD2, RD3, RD4, RD5,      RD7,      RD9, \
  LE3, LE4, LE5, LE6,      LE8,                RE2, RE3, RE4, RE5,      RE7, RE8, RE9 \
  ) \
  { \
    { KC_NO, KC_NO, LA3, LA4, LA5, LA6, LA7, LA8, LA9 }, \
    { KC_NO, KC_NO, LB3, LB4, LB5, LB6, LB7, LB8, KC_NO }, \
    { KC_NO, KC_NO, LC3, LC4, LC5, LC6, LC7, LC8, KC_NO }, \
    { KC_NO, KC_NO, LD3, KC_NO, LD5, LD6, LD7, LD8, LD9 }, \
    { KC_NO, KC_NO, LE3, LE4, LE5, LE6, KC_NO, LE8, KC_NO }, \
    { RA1, RA2, RA3, RA4, RA5, RA6, KC_NO, RA8, RA9 }, \
    { RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, RB9 }, \
    { RC1, RC2, RC3, RC4, RC5, RC6, KC_NO, RC8, RC9 }, \
    { RD1, RD2, RD3, RD4, RD5, KC_NO, RD7, KC_NO, RD9 }, \
    { KC_NO, RE2, RE3, RE4, RE5, KC_NO, RE7, RE8, RE9 } \
  }

enum keyboard_layers {
    _BL, // base layer
    _FL, // function layer
    _LL, // backlights and underglow
};

#define FL_CAPS LT(_FL,KC_CAPS)    // Use caps lock as layer tap: held for function layer, tap for normal caps lock

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_65SPLIT(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MUTE, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, \
    FL_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_DEL,  \
    KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  MO(_FL),          KC_SPC,           MO(_FL), MO(_LL), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  [_FL] = LAYOUT_65SPLIT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______, \
    _______, _______, _______, _______, RESET,   _______, _______, RESET,   _______, _______, _______, KC_HOME, KC_END,  _______, KC_HOME, \
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_PGDN, _______, KC_END,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______,          _______,          _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),

  [_LL] = LAYOUT_65SPLIT(
    RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______,          _______, _______, \
    _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______, _______, _______
  ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}
