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

// clang-format off
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
	QK_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
	KC_LCTL, KC_LGUI,          KC_LALT,          LT_ENT,     LT_SPC,           KC_APP,                    KC_RALT, ADJUST ),

[_LOWER] = LAYOUT(
	KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,
	KC_CAPS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
	KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,    _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______,
	_______, _______,          _______,          _______,    _______,          _______,                   _______, _______),

 [_RAISE] = LAYOUT(
	_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______,
	KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
	KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_DEL,  KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______,
	_______, _______,          _______,          _______,	   _______,          _______,                   _______, _______),

[_ADJUST] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, _______, _______, _______, _______,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,
  _______, _______,          _______,          _______,    _______,          _______,                   _______, _______)
};
// clang-format on

void matrix_init_user(void) {
    // set CapsLock LED to output and low
    gpio_set_pin_output(B1);
    gpio_write_pin_low(B1);
    // set NumLock LED to output and low
    gpio_set_pin_output(B2);
    gpio_write_pin_low(B2);
    // set ScrollLock LED to output and low
    gpio_set_pin_output(B3);
    gpio_write_pin_low(B3);
}

bool led_update_user(led_t led_state) {
    if (IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)) {
        gpio_write_pin_high(B2);
    } else {
        gpio_write_pin_low(B2);
    }

    if (IS_LAYER_ON(_ADJUST)) {
        gpio_write_pin_high(B3);
    } else {
        gpio_write_pin_low(B3);
    }

    if (led_state.caps_lock) {
        gpio_write_pin_high(B1);
    } else {
        gpio_write_pin_low(B1);
    }
    return false;
}
