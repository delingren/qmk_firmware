#include QMK_KEYBOARD_H

#ifdef BACKLIGHT_LEVELS
#    undef BACKLIGHT_LEVELS
#endif
#define BACKLIGHT_LEVELS 3

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 300

#define BACKLIGHT_BREATHING

// clang-format off

enum keyboard_layers {
    _BL, // base layer
    _FL, // function layer
    _LL, // backlights and underglow
};

#define FL_CAPS LT(_FL,KC_CAPS)    // Use caps lock as layer tap: held for function layer, tap for normal caps lock

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
     * │Esc│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│Slk│Pse│
     * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│End│PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │              
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐    
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │    
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Menu│Ctrl│ │ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘
     */

    [_BL] = LAYOUT_tkl_ansi( \
        KC_ESC,         KC_F1,  KC_F2,  KC_F3,  KC_F4,      KC_F5,  KC_F6,  KC_F7,  KC_F8,      KC_F9,  KC_F10, KC_F11,  KC_F12,  KC_VOLD,KC_VOLU,KC_MUTE, \
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,          KC_INS, KC_HOME,KC_PGUP, \
        KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,      KC_DEL, KC_END, KC_PGDN, \
        FL_CAPS,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_ENT,                                      \
        KC_LSFT,          KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,                        KC_UP,           \
        KC_LCTL,  KC_LALT,  KC_LGUI,                      KC_SPC,                       KC_RGUI,  MO(_FL),  MO(_LL),  KC_RCTL,    KC_LEFT,KC_DOWN,KC_RGHT  \
    ),
    [_FL] = LAYOUT_tkl_ansi( \
        KC_SLEP,        _______,_______,_______,_______,    _______,_______,_______,_______,    _______,_______,_______,_______,  KC_MRWD,KC_MFFD,KC_MPLY, \
        _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL,           KC_BTN2,_______,KC_WH_D, \
        _______,    _______,_______,_______,_______,_______,_______,_______,_______, _______,_______,KC_HOME,KC_END, _______,      KC_BTN1,_______,KC_WH_U, \
        _______,      _______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_PGUP,KC_PGDN,_______,                                     \
        _______,          _______,_______,_______,_______,_______,_______,_______,KC_VOLD,KC_VOLU,KC_MUTE,_______,                        KC_MS_U,         \
        _______,  _______,  _______,                      _______,                      _______,  _______,  _______,  _______,    KC_MS_L,KC_MS_D,KC_MS_R  \
    ),
    [_LL] = LAYOUT_tkl_ansi( \
        _______,        _______,_______,_______,_______,    _______,_______,_______,_______,    _______,_______,_______,_______,  _______,_______,_______, \
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,          _______,_______,_______, \
        _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      _______,_______,_______, \
        _______,      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                                     \
        _______,          _______,_______,_______,_______,_______,_______,_______,BL_DOWN,BL_UP,  BL_TOGG,BL_BRTG,                        _______,         \
        _______,  _______,  _______,                      _______,                      _______,  _______,  _______,  _______,    _______,_______,_______  \
    ),
};
