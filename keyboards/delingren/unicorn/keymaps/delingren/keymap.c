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

enum layer_names {
    _BL,
    _LOWER,
    _RAISE,
    _NUM,
    _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define NUM TG(_NUM)

#define LT_ENT LT(LOWER, KC_ENT)
#define LT_SPC LT(RAISE, KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BL] = LAYOUT(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_LCTL, KC_LALT, KC_LGUI, LT_ENT,   LT_SPC,  KC_RGUI, KC_RALT, KC_RCTL
),

[_LOWER] = LAYOUT(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_CAPS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_PLUS,
  KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,   KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, _______,
                    _______, _______, _______, _______,   _______, NUM,     _______, _______
),

[_RAISE] = LAYOUT(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, _______,
                    _______, _______, _______, _______,   _______, _______, _______, _______
),

[_NUM] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PSLS, _______,
  NUM,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX, _______,
                    _______, _______, _______, _______,   KC_P0,   XXXXXXX, KC_PDOT, XXXXXXX
),

[_ADJUST] = LAYOUT(
  RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RESET,   RGB_TOG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RGB_VAD, RGB_SAD, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE
),
};

void keyboard_post_init_user(void) { 
  rgblight_sethsv(HSV_BLUE); 
  rgblight_mode(RGBLIGHT_MODE_BREATHING);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { 
  return OLED_ROTATION_270; 
}

static bool caps_lock_on = false;

bool oled_task_user(void) {
    static const char PROGMEM hr[] = {
        0x81, 0x81, 0x81, 0x81, 
        0x00,
    };

    static const char PROGMEM logo[] = {
        0x80, 0x84, 0x85, 0x80,
        0x80, 0x86, 0x87, 0x80,
        0x00,
    };

    static const char PROGMEM empty [] = {
        0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80,
        0x00,
    };

    static const char PROGMEM layer0[] = {
        0x90, 0x91, 0x80, 0x80,
        0x92, 0x93, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM layer1[] = {
        0x80, 0x80, 0x94, 0x95, 
        0x80, 0x80, 0x96, 0x97, 
        0x00,
    }; 

    static const char PROGMEM layer01[] = {
        0x90, 0x91, 0x94, 0x95, 
        0x92, 0x93, 0x96, 0x97, 
        0x00,
    }; 

    static const char PROGMEM layer2[] = {
        0x98, 0x99, 0x80, 0x80,
        0x9a, 0x9b, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM layer3[] = {
        0x80, 0x80, 0x9c, 0x9d, 
        0x80, 0x80, 0x9e, 0x9f, 
        0x00,
    }; 

    static const char PROGMEM layer23[] = {
        0x98, 0x99, 0x9c, 0x9d, 
        0x9a, 0x9b, 0x9e, 0x9f, 
        0x00,
    }; 

    static const char PROGMEM mod0[] = {
        0xa0, 0xa1, 0x80, 0x80,
        0xa2, 0xa3, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM mod1[] = {
        0x80, 0x80, 0xa4, 0xa5, 
        0x80, 0x80, 0xa6, 0xa7, 
        0x00,
    }; 

    static const char PROGMEM mod01[] = {
        0xa0, 0xa1, 0xa4, 0xa5, 
        0xa2, 0xa3, 0xa6, 0xa7, 
        0x00,
    }; 

    static const char PROGMEM mod2[] = {
        0xa8, 0xa9, 0x80, 0x80,
        0xaa, 0xab, 0x80, 0x80,
        0x00,
    }; 

    static const char PROGMEM mod3[] = {
        0x80, 0x80, 0xac, 0xad, 
        0x80, 0x80, 0xae, 0xaf, 
        0x00,
    }; 

    static const char PROGMEM mod23[] = {
        0xa8, 0xa9, 0xac, 0xad, 
        0xaa, 0xab, 0xae, 0xaf, 
        0x00,
    }; 

    static const char PROGMEM capslock[] = {
        0x80, 0x88, 0x89, 0x80,
        0x80, 0x8a, 0x8b, 0x80,
        0x00,
    };

    oled_write_P(logo, false);
    oled_write_P(hr, false);

    bool layer0_on = IS_LAYER_ON(_BL);
    bool layer1_on = IS_LAYER_ON(_LOWER);
    bool layer2_on = IS_LAYER_ON(_RAISE);
    bool layer3_on = IS_LAYER_ON(_NUM);

    // we are not doing one shot mods here
    static uint8_t mods;
    mods = get_mods();
    bool mod0_on = mods & MOD_MASK_CTRL;
    bool mod1_on = mods & MOD_MASK_SHIFT;
    bool mod2_on = mods & MOD_MASK_ALT;
    bool mod3_on = mods & MOD_MASK_GUI;

    if (layer0_on) {
        oled_write_P(layer1_on ? layer01 : layer0, false);
    } else {
        oled_write_P(layer1_on ? layer1 : empty, false);
    }

    if (layer2_on) {
        oled_write_P(layer3_on ? layer23 : layer2, false);
    } else {
        oled_write_P(layer3_on ? layer3 : empty, false);
    }

    oled_write_P(hr, false);

    if (mod0_on) {
        oled_write_P(mod1_on ? mod01 : mod0, false);
    } else {
        oled_write_P(mod1_on ? mod1 : empty, false);
    }

    if (mod2_on) {
        oled_write_P(mod3_on ? mod23 : mod2, false);
    } else {
        oled_write_P(mod3_on ? mod3 : empty, false);
    }

    oled_write_P(hr, false);
    oled_write_P(caps_lock_on ? capslock : empty, false);

    return true;
}

bool led_update_user(led_t led_state) {
    caps_lock_on = led_state.caps_lock;
    return true;
}
