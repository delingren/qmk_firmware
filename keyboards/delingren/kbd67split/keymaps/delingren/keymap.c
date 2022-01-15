/* Copyright 2018 'mechmerlin'
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

#define FL_CAPS LT(_ADJUST,KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp | ~` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |Gui |        Space          |Gui|Fn2| Fn1|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_65_ansi_split_space(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  \
    FL_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
    KC_LCTL, KC_LALT, KC_LGUI,          LT_ENT,  ADJUST,  LT_SPC,                    KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[_LOWER] = LAYOUT_65_ansi_split_space(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, _______, \
    KC_GRV,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, _______, \
    KC_TILD, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______,          _______, _______, \
    _______, _______, _______,          _______, _______, _______,                   _______, _______, _______, _______, _______, _______),

[_RAISE] = LAYOUT_65_ansi_split_space(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______,          _______, _______, \
    _______, _______, _______,          _______, _______, _______,                   _______, _______, _______, _______, _______, _______),

[_ADJUST] = LAYOUT_65_ansi_split_space(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______, \
    _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,          KC_PGUP, _______, \
    _______, _______, _______,          _______, _______, _______,                   _______, _______, _______, KC_HOME, KC_PGDN, KC_END),
};
