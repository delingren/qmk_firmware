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
#ifdef OLED_ENABLE
#    include QMK_KEYBOARD_H
#    include "layers.h"

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

    bool layer0_on = IS_LAYER_ON(_BASE);
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

    // Tell oled_task_kb to stop proceeding
    return false;
}

bool led_update_user(led_t led_state) {
    caps_lock_on = led_state.caps_lock;
    return true;
}

#endif