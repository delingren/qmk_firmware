#include QMK_KEYBOARD_H

enum layer_names {
  _BL,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define LT_ENT LT(LOWER, KC_ENT)
#define LT_SPC LT(RAISE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BL] = LAYOUT(
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,
	KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
	KC_LCTL, KC_LALT,          KC_LGUI,          LT_ENT,     LT_SPC,           KC_APP,                    KC_RALT, ADJUST ),

[_LOWER] = LAYOUT(
	_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,
	KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
	KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,    KC_BSPC, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______,
	_______, _______,          _______,          _______,    _______,          _______,                   _______, _______),

 [_RAISE] = LAYOUT(
	_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______,
	KC_CAPS, _______, _______, _______, _______, _______,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
	_______, _______, _______, _______, _______, _______,    KC_DEL,  KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______,
	_______, _______,          _______,          _______,	   _______,          _______,                   _______, _______),

[_ADJUST] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,
  _______, _______,          _______,          _______,    _______,          _______,                   _______, _______)
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) { 
    rgblight_sethsv(HSV_BLUE); 
}
#endif

void matrix_init_user(void) {
  setPinOutput(B1);
  writePinLow(B1);
  setPinOutput(B2);
  writePinLow(B2);
  setPinOutput(B3);
  writePinLow(B3);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }

  if (IS_LAYER_ON(_ADJUST)) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }
    
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(B1);
  } else {
    writePinLow(B1);
  }
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }
