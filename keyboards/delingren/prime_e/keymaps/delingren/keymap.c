/* Copyright 2018 Holten Campbell
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
  _BASE,
  _LOWER,
  _RAISE,
  _NUM,
  _ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define TG_NUM TG(_NUM)
#define MO_NUM MO(_NUM)

#define LT_ENT LT(LOWER, KC_ENT)
#define LT_SPC LT(RAISE, KC_SPC)
#define SFT_ENT RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,
	KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_ESC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
	KC_LCTL, KC_LALT,          KC_LGUI,          LT_ENT,     LT_SPC,           KC_RGUI, KC_RALT,          KC_RCTL
),

[_LOWER] = LAYOUT(
	_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,
	KC_GRV,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_PLUS,
	KC_TILD, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,    _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, _______,
	MO_NUM,  _______,          _______,          _______,    _______,          _______, _______,          _______
),

 [_RAISE] = LAYOUT(
	KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  _______,
	KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
	KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, _______,
	_______, _______,          _______,          _______,	 _______,          _______, _______,          _______
),
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
  if (IS_LAYER_ON(1)) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }

  if (IS_LAYER_ON(2)) {
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

