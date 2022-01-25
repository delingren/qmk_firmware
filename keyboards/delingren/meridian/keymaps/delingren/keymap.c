/*
Copyright 2020 Holten Campbell

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define LAYOUT_split_rshift( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013,       \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112,       K113, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,             K213, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K312, K313, \
	K400, K401,             K402, K404,       K407, K409,                   K411, K412, K413  \
) \
{ \
	{ K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013 }, \
	{ K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113 }, \
	{ K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K_NO, K213 }, \
	{ K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313 }, \
	{ K400, K401, K402, K_NO, K404, K_NO, K_NO, K407, K_NO, K409, K_NO, K411, K412, K413 }  \
}

enum layer_names {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define LT_ENT LT(LOWER, KC_ENT)
#define LT_SPC LT(RAISE, KC_SPC)
#define SFT_ENT RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_split_rshift(
		KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_DEL,
		KC_LCTL, KC_LALT,          KC_LGUI,          LT_ENT,  LT_SPC,           KC_RGUI, KC_APP,  KC_RALT,          KC_RCTL
  ),
  [_LOWER] = LAYOUT_split_rshift(
  	_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
  	KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______,
  	KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_PLUS,          _______,
  	KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, KC_PSCR, _______,
  	_______, _______, _______,          _______,          _______,          _______,                   _______, _______, _______
  ),
	[_RAISE] = LAYOUT_split_rshift(
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  	KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______,
  	_______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,          _______,
  	_______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, _______, _______,
  	_______, _______, _______,          _______,          _______,          _______,                   _______, _______, _______
  ),
	[_ADJUST] = LAYOUT_split_rshift(
    	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    	_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
    	_______, _______, _______,          _______,          _______,          _______,                   _______, _______, _______
    )
};

void keyboard_post_init_user(void) {
	rgblight_setrgb_at(0, 0, 0, 0); // [..., 0] = top LED
  rgblight_setrgb_at(0, 0, 0, 1); // [..., 1] = middle LED
  rgblight_setrgb_at(0, 0, 0, 2); // [..., 2] = bottom LED
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    rgblight_setrgb_at(0, 255, 0, 0);
  } else {
    rgblight_setrgb_at(0, 0, 0, 0);
  }

  if (IS_LAYER_ON(_LOWER)) {
  	rgblight_setrgb_at(255, 0, 0, 1);
  } else {
  	rgblight_setrgb_at(0, 0, 0, 1);
  }

  if (IS_LAYER_ON(_RAISE)) {
  	rgblight_setrgb_at(0, 0, 255, 2);
  } else {
    rgblight_setrgb_at(0, 0, 0, 2);	
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
