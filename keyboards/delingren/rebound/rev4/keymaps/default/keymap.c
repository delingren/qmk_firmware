#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _NUM,
    _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define TG_NUM TG(_NUM)
#define MO_NUM MO(_NUM)

#define LT_ENT LT(LOWER, KC_ENT)
#define LT_SPC LT(RAISE, KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_all(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    QK_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_ESC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
    KC_LCTL, LOWER,   KC_LALT, KC_LGUI, XXXXXXX, LT_ENT, KC_MUTE, LT_SPC,  XXXXXXX, KC_RGUI, KC_RALT, RAISE,   KC_RCTL
),

[_LOWER] = LAYOUT_all(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, KC_PLUS,
    KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, _______,
    MO_NUM,  _______, _______, _______, XXXXXXX, _______, _______, _______, XXXXXXX, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_all(
    KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, XXXXXXX, _______,
    _______, _______, _______, _______, XXXXXXX, _______, _______, _______, XXXXXXX, _______, _______, _______, _______
),

[_NUM] = LAYOUT_all(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PSLS, KC_BSPC,
    TG_NUM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG_NUM,  KC_P1,   KC_P2,   KC_P3,   KC_PENT, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, XXXXXXX, _______, _______, KC_P0,   XXXXXXX, KC_PDOT, _______, _______, _______
),

[_ADJUST] = LAYOUT_all(
    RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,  XXXXXXX, RGB_TOG,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code16(S(KC_VOLD));
    } else {
        tap_code16(KC_VOLU);
    }
    return true;
}

static bool caps_lock_on = false;

bool oled_task_user(void) {
    static const char PROGMEM hr[] = {
        0x81, 0x81, 0x81, 0x81, 0x00,
    };

    static const char PROGMEM logo[] = {
        0x80, 0x84, 0x85, 0x80, 0x80, 0x86, 0x87, 0x80, 0x00,
    };

    static const char PROGMEM empty[] = {
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    };

    static const char PROGMEM layer0[] = {
        0x90, 0x91, 0x80, 0x80, 0x92, 0x93, 0x80, 0x80, 0x00,
    };

    static const char PROGMEM layer1[] = {
        0x80, 0x80, 0x94, 0x95, 0x80, 0x80, 0x96, 0x97, 0x00,
    };

    static const char PROGMEM layer01[] = {
        0x90, 0x91, 0x94, 0x95, 0x92, 0x93, 0x96, 0x97, 0x00,
    };

    static const char PROGMEM layer2[] = {
        0x98, 0x99, 0x80, 0x80, 0x9a, 0x9b, 0x80, 0x80, 0x00,
    };

    static const char PROGMEM layer3[] = {
        0x80, 0x80, 0x9c, 0x9d, 0x80, 0x80, 0x9e, 0x9f, 0x00,
    };

    static const char PROGMEM layer23[] = {
        0x98, 0x99, 0x9c, 0x9d, 0x9a, 0x9b, 0x9e, 0x9f, 0x00,
    };

    static const char PROGMEM mod0[] = {
        0xa0, 0xa1, 0x80, 0x80, 0xa2, 0xa3, 0x80, 0x80, 0x00,
    };

    static const char PROGMEM mod1[] = {
        0x80, 0x80, 0xa4, 0xa5, 0x80, 0x80, 0xa6, 0xa7, 0x00,
    };

    static const char PROGMEM mod01[] = {
        0xa0, 0xa1, 0xa4, 0xa5, 0xa2, 0xa3, 0xa6, 0xa7, 0x00,
    };

    static const char PROGMEM mod2[] = {
        0xa8, 0xa9, 0x80, 0x80, 0xaa, 0xab, 0x80, 0x80, 0x00,
    };

    static const char PROGMEM mod3[] = {
        0x80, 0x80, 0xac, 0xad, 0x80, 0x80, 0xae, 0xaf, 0x00,
    };

    static const char PROGMEM mod23[] = {
        0xa8, 0xa9, 0xac, 0xad, 0xaa, 0xab, 0xae, 0xaf, 0x00,
    };

    static const char PROGMEM capslock[] = {
        0x80, 0x88, 0x89, 0x80, 0x80, 0x8a, 0x8b, 0x80, 0x00,
    };

    oled_write_P(logo, false);
    oled_write_P(hr, false);

    bool layer0_on = IS_LAYER_ON(0);
    bool layer1_on = IS_LAYER_ON(1);
    bool layer2_on = IS_LAYER_ON(2);
    bool layer3_on = IS_LAYER_ON(3);

    // we are not doing one shot mods here
    static uint8_t mods;
    mods         = get_mods();
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

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(RGBLIGHT_DEFAULT_COLOR);
}
