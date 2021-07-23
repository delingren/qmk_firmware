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
#include "oled.h"

// The oled is vertical. Need to rotate 270 degrees.
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

char keylog_str[24] = {};

const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
}

void oled_render_keylog(void) { oled_write(keylog_str, false); }

void oled_write_empty_line(int n) {
    for (int i = 0; i < n; i ++) {
        oled_write_ln(" ", false);
    }
}

// Some characters position:
// alt: 84 85 86/a..../c...
// shift:87 88 89/a.../c...
// ctrl: b6 b6/d.../
// capslock: 9c-9f/b.../d...
// numlock: 98-9b/b.../d...
// navigation logo: 92-95/b2.../d2...
// symbol logo: 8a-8d/aa..../ca....
// qmk logos; 8e-91/ae..../ce....
void oled_render_layer(void) {
    /* static const char PROGMEM cmd_logo[] = { */
    /*   0x80, 0x81, 0x82, 0x83, 10, */
    /*   0xa0, 0xa1, 0xa2, 0xa3, 10, */
    /*   0xc0, 0xc1, 0xc2, 0xc3, 10, */
    /*   0}; */
    // clang-format off
    static const char PROGMEM adjust_logo[] = {
      0x92, 0x93, 0x94, 0x95, 10,
      0xb2, 0xb3, 0xb4, 0xb5, 10,
      0xd2, 0xd3, 0xd4, 0xd5, 10, 0};
    static const char PROGMEM numlock_logo[] = {
      0x98, 0x99, 0x9a, 0x9b, 10,
      0xb8, 0xb9, 0xba, 0xbb, 10,
      0xd8, 0xd9, 0xda, 0xdb, 10, 0};
    static const char PROGMEM symbol_logo[] = {
      0x8a, 0x8b, 0x8c, 0x8d, 10,
      0xaa, 0xab, 0xac, 0xad, 10,
      0xca, 0xcb, 0xcc, 0xcd, 10, 0};
    static const char PROGMEM qmk_logo[] = {
      0x8e, 0x8f, 0x90, 0x91, 10,
      0xae, 0xaf, 0xb0, 0xb1, 10,
      0xce, 0xcf, 0xd0, 0xd1, 10, 0};
    // clang-format on
    if (IS_LAYER_ON(_ADJUST)) {
        oled_write_P(adjust_logo, false);
    } else if (IS_LAYER_ON(_LOWER)) {
        oled_write_P(symbol_logo, false);
    } else if (IS_LAYER_ON(_RAISE)) {
        oled_write_P(numlock_logo, false);
    } else if (IS_LAYER_ON(_BASE)) {
        oled_write_P(qmk_logo, false);
    } else {
        oled_write_empty_line(3);
    }
}
// Oneshot mods status
uint8_t osmods;

void oled_render_mods(void) {
    static const char PROGMEM cmd[] = {
        0x80, 0x81, 0x82, 0x83, 0x20,
        0xa0, 0xa1, 0xa2, 0xa3, 0x20,
        0xc0, 0xc1, 0xc2, 0xc3, 0x20,
        0};
    static const char PROGMEM ctrl[] = {
        0xb6, 0xb7, 10,
        0xd6, 0xd7, 10,
        0x20, 0x20, 10,
        0};
    static const char PROGMEM shift_ctrl[] = {
        0x87, 0x88, 0x89, 0xb6, 0xb7,
        0xa7, 0xa8, 0xa9, 0xd6, 0xd7,
        0xc7, 0xc8, 0xc9, 0x20, 0x20,
        0};
    static const char PROGMEM shift[] = {
        0x87, 0x88, 0x89, 10,
        0xa7, 0xa8, 0xa9, 10,
        0xc7, 0xc8, 0xc9, 10,
        0};
    static const char PROGMEM alt[] = {
        0x84, 0x85, 0x86, 10,
        0xa4, 0xa5, 0xa6, 10,
        0xc4, 0xc5, 0xc6, 10,
        0};

    static uint8_t mods;
    mods = get_mods() | osmods;

    if (mods & MOD_MASK_SHIFT) {
        if (mods & MOD_MASK_CTRL) {
            oled_write_P(shift_ctrl, false);
        } else {
            oled_write_P(shift, false);
        }
    } else {
        if (mods & MOD_MASK_CTRL)
        {
            oled_write_P(ctrl, false);
        } else {
            oled_write_empty_line(3);
        }
    }

    if (mods & MOD_MASK_ALT) {
        oled_write_P(alt, false);
    } else {
        oled_write_empty_line(3);
    }

    if (mods & MOD_MASK_GUI) {
        oled_write_P(cmd, false);
    } else {
        oled_write_empty_line(3);
    }

    return;
}

void oneshot_mods_changed_user(uint8_t mods) { osmods = mods; }

void oled_task_user(void) {
    /* oled_render_keylog(); */
    oled_render_layer();
    oled_render_mods();
}

// Call this from "led_update_user" and use `led_state.caps_lock` to check
// the status of capslock.
void oled_render_capslock(bool caps_on) {
    static const char PROGMEM capslock_logo[] = {0x9c, 0x9d, 0x9e, 0x9f, 10, 0xbc, 0xbd, 0xbe, 0xbf, 10, 0xdc, 0xdd, 0xde, 0xdf, 10, 0};
    if (caps_on) {
        oled_write_P(capslock_logo, false);
    } else {
        oled_write_empty_line(3);
    }
}
