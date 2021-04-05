#include QMK_KEYBOARD_H

enum keyboard_layers {
    _BL,
    _FL,
    _ML,
};

#define FL_CAPS LT(_FL,KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_68_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_GRV,  KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,  KC_PGDN,
    FL_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,          KC_UP,
    KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MO(_ML), MO(_FL),          KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_FL] = LAYOUT_68_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           _______, KC_HOME,
    _______, _______, _______, _______, RESET,   _______, _______, _______, KC_UP,   _______, _______, KC_HOME, KC_END,  _______,          _______, KC_END,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_PGDN,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU,                   _______,          KC_PGUP,
    _______, _______, _______,                            _______,                            _______, _______, _______,          KC_HOME, KC_PGDN, KC_END
  ),
  [_ML] = LAYOUT_68_ansi(
    KC_ESC,  KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, BL_DEC,  BL_INC,  KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,           BL_TOGG, KC_HOME,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, KC_HOME, KC_END,  _______,          BL_STEP, KC_END,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_PGDN,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,          KC_PGUP,
    _______, _______, _______,                            _______,                            _______, _______, _______,          KC_HOME, KC_PGDN, KC_END
  )
};

void keyboard_pre_init_user() {
    setPinOutput(B0);
    writePinHigh(B0);
    setPinOutput(D5);
    writePinHigh(D5);
}

bool led_update_user(led_t usb_led) {
    writePin(B0, !usb_led.caps_lock);
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    writePin(D5, IS_LAYER_ON_STATE(state, _FL) ? 0 : 1);
    return state;
}
