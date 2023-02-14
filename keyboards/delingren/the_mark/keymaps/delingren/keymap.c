/* Copyright 2022 Boardsource
 *           2022 QMK / James Young (@noroadsleft)
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

enum keyboard_layers {
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
    [_BL] = LAYOUT_ansi_split_space(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_ESC,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_END,  \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,            \
        KC_LCTL, KC_LGUI, KC_LALT,          LT_ENT,  ADJUST,  LT_SPC,                    KC_APP,  KC_RALT, KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT  ),

    [_LOWER] = LAYOUT_ansi_split_space(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_VOLD, \
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, KC_PGUP, \
        KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, KC_PGDN, \
        KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______,          KC_PGUP,          \
        _______, _______, _______,          _______, _______, _______,                   _______, _______, _______, KC_HOME, KC_PGDN, KC_END   ),

    [_RAISE] = LAYOUT_ansi_split_space(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_VOLU, \
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, KC_PGUP, \
        KC_CAPS, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, KC_PGDN, \
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______,          KC_PGUP,          \
        _______, _______, _______,          _______, _______, _______,                   _______, _______, _______, KC_HOME, KC_PGDN, KC_END   ),

    [_ADJUST] = LAYOUT_ansi_split_space(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_MUTE, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, \
        KC_CAPS, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, RGB_MOD, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,          KC_PGUP,          \
        _______, _______, _______,          KC_ENT,  _______, KC_SPC,                    _______, _______, _______, KC_HOME, KC_PGDN, KC_END   ),
};
