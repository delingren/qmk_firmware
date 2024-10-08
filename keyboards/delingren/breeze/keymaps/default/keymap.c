/* Copyright 2021 eithanshavit
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
    _MAIN,
    _LOWER,
    _RAISE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SFT_ENT RSFT_T(KC_ENT)
#define LT_ENT LT(LOWER, KC_ENT)
#define LT_SPC LT(RAISE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAIN] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┐
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_MINS, KC_EQL, KC_GRV,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_LBRC, KC_RBRC, KC_BSLS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_UP,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SFT_ENT, KC_LEFT, KC_DOWN, KC_RIGHT,
        // └────────┴────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘└────────┴────────┴────────┘
        KC_LCTL, KC_LALT, KC_LGUI, LT_ENT, LT_SPC, LOWER, RAISE, KC_MUTE
        //                            └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
        ),

    [_LOWER] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┐
        KC_GRV, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, KC_HOME, KC_PGUP,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
        _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, KC_DEL, KC_END, KC_PGDN,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
        KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_MINS, KC_EQL, KC_PGUP,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
        KC_GRV, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_END, KC_PGUP, KC_PGDN, _______, _______, KC_HOME, KC_PGDN, KC_END,
        // └────────┴────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘└────────┴────────┴────────┘
        _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS
        //                            └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
        ),

    [_RAISE] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┐
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
        _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_UNDS, KC_PLUS, KC_PGUP,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_END, KC_PGUP, KC_PGDN, _______, _______, KC_HOME, KC_PGDN, KC_END,
        // └────────┴────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┴────────┴────────┴────────┘└────────┴────────┴────────┘
        _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE
        //                            └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
        )};

void keyboard_pre_init_user() {
    setPinOutput(B0);
    writePinHigh(B0);
    setPinOutput(D5);
    writePinHigh(D5);
}

bool led_update_user(led_t usb_led) {
    writePin(B0, !usb_led.caps_lock);
    writePin(D5, !usb_led.caps_lock);

    return false;
}
