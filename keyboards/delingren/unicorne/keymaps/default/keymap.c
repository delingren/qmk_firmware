/* Copyright 2021 Yang Hu
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
#include "layers.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define NUM TG(_NUM)

#define LT_ENT LT(LOWER, KC_ENT)
#define LT_SPC LT(RAISE, KC_SPC)
#define MT_CAPS MT(MOD_LSFT, KC_CAPS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_split_3x6_4(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  QK_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  MT_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_LCTL, KC_LALT, KC_LGUI, LT_ENT,   LT_SPC,  KC_RGUI, KC_RALT, KC_RCTL
),

[_LOWER] = LAYOUT_split_3x6_4(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_PLUS,
  KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,   KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, _______,
                    _______, _______, _______, _______,   _______, NUM,     _______, _______
),

[_RAISE] = LAYOUT_split_3x6_4(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, _______,
                    _______, _______, _______, _______,   _______, _______, _______, _______
),

[_NUM] = LAYOUT_split_3x6_4(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PSLS, _______,
  NUM,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX, _______,
                    _______, _______, _______, _______,   KC_P0,   XXXXXXX, KC_PDOT, XXXXXXX
),

[_ADJUST] = LAYOUT_split_3x6_4(
  RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RESET,   RGB_TOG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RGB_VAD, RGB_SAD, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE
),
};
// clang-format on
layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

// Left encoder scrolls the mousewheel. Right encoder adjusts underglow hue.
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#else
            tap_code(KC_PGDN);
#endif
        } else {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#else
            tap_code(KC_PGUP);
#endif
        }
    } else {  // index = 1: right encoder
        if (clockwise) {
#ifdef RGB_MATRIX_ENABLE
            rgb_matrix_step();
#else
            rgblight_increase_hue_noeeprom();
#endif
        } else {
#ifdef RGB_MATRIX_ENABLE
            rgb_matrix_step_reverse();
#else
            rgblight_decrease_hue_noeeprom();
#endif
        }
    }
    return false;
}

// Set underglow color to blue.
void keyboard_post_init_user(void) { rgblight_sethsv_noeeprom(RGBLIGHT_DEFAULT_COLOR); }
