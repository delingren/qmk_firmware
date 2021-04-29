enum keyboard_layers {
    _BL, // base layer
    _FL, // function layer
    _LL, // backlights and underglow
};

#define FL_CAPS LT(_FL,KC_CAPS)    // Use caps lock as layer tap: held for function layer, tap for normal caps lock

// TKL layout
#define _BL_tkl_ansi \
LAYOUT_tkl_ansi( \
    KC_ESC,         KC_F1,  KC_F2,  KC_F3,  KC_F4,      KC_F5,  KC_F6,  KC_F7,  KC_F8,      KC_F9,  KC_F10, KC_F11,  KC_F12,  KC_VOLD,KC_VOLU,KC_MUTE, \
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,          KC_INS, KC_HOME,KC_PGUP, \
    KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,      KC_DEL, KC_END, KC_PGDN, \
    FL_CAPS,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_ENT,                                      \
    KC_LSFT,          KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,                        KC_UP,           \
    KC_LCTL,  KC_LALT,  KC_LGUI,                      KC_SPC,                       KC_RGUI,  MO(_FL),  MO(_LL),  KC_RCTL,    KC_LEFT,KC_DOWN,KC_RGHT  \
)

#define _FL_tkl_ansi \
LAYOUT_tkl_ansi( \
    KC_SLEP,        _______,_______,_______,_______,    _______,_______,_______,_______,    _______,_______,_______,_______,  KC_MRWD,KC_MFFD,KC_MPLY, \
    _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL,           KC_BTN2,_______,KC_WH_D, \
    _______,    _______,_______,_______,RESET,  _______,_______,_______,_______, _______,_______,KC_HOME,KC_END, _______,      KC_BTN1,_______,KC_WH_U, \
    _______,      _______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_PGUP,KC_PGDN,_______,                                     \
    _______,          _______,_______,_______,_______,_______,_______,_______,KC_VOLD,KC_VOLU,KC_MUTE,_______,                        KC_MS_U,         \
    _______,  _______,  _______,                      _______,                      _______,  _______,  _______,  _______,    KC_MS_L,KC_MS_D,KC_MS_R  \
)

#define _LL_tkl_ansi \
LAYOUT_tkl_ansi( \
    _______,        _______,_______,_______,_______,    _______,_______,_______,_______,    _______,_______,_______,_______,  _______,_______,_______, \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,          _______,_______,_______, \
    _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      _______,_______,_______, \
    _______,      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                                     \
    _______,          _______,_______,_______,_______,_______,_______,_______,BL_DEC, BL_INC, BL_TOGG,BL_BRTG,                        _______,         \
    _______,  _______,  _______,                      _______,                      _______,  _______,  _______,  _______,    _______,_______,_______  \
)

// Magicforce 68/Miya Pro 68 layout
#define _BL_mf68_ansi \
LAYOUT_68_ansi( \
    KC_GESC,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,          KC_GRV, KC_PGUP, \
    KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,      KC_DEL, KC_PGDN, \
    FL_CAPS,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_ENT,                              \
    KC_LSFT,          KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,                KC_UP,           \
    KC_LCTL,  KC_LALT,  KC_LGUI,                      KC_SPC,                       KC_RGUI,  MO(_FL),  MO(_LL),      KC_LEFT,KC_DOWN,KC_RGHT  \
)

#define _FL_mf68_ansi \
LAYOUT_68_ansi( \
    KC_SLEP,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL,           KC_BTN2,KC_WH_D, \
    _______,    _______,_______,_______,RESET,  _______,_______,_______,KC_UP,  _______,_______,KC_HOME,KC_END, _______,      KC_BTN1,KC_WH_U, \
    _______,      _______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGUP,KC_PGDN,_______,                             \
    _______,          _______,_______,_______,_______,_______,_______,_______,KC_VOLD,KC_VOLU,KC_MUTE,_______,                KC_MS_U,         \
    _______,  _______,  _______,                      _______,                      _______,  _______,  _______,      KC_MS_L,KC_MS_D,KC_MS_R  \
)

#define _LL_mf68_ansi \
LAYOUT_68_ansi( \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,          _______,_______, \
    _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,      _______,_______, \
    _______,      _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                             \
    _______,          _______,_______,_______,_______,_______,_______,_______,BL_DEC, BL_INC, BL_TOGG,BL_BRTG,                _______,         \
    _______,  _______,  _______,                      _______,                      _______,  _______,  _______,      _______,_______,_______  \
)
