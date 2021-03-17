#include QMK_KEYBOARD_H

enum keyboard_layers {
    _BL,
    _FL,
    _ML,
    _CL
};

enum custom_keycodes {
    S_BSKTC = SAFE_RANGE,
    S_ODEJY,
    S_RCKBY,
    S_DOEDR,
    S_SCALE,
    S_ONEUP,
    S_COIN,
    S_SONIC,
    S_ZELDA
};

#ifdef AUDIO_ENABLE
  float song_basketcase[][2] = SONG(BASKET_CASE);
  float song_ode_to_joy[][2]  = SONG(ODE_TO_JOY);
  float song_rock_a_bye_baby[][2]  = SONG(ROCK_A_BYE_BABY);
  float song_doe_a_deer[][2]  = SONG(DOE_A_DEER);
  float song_scale[][2]  = SONG(MUSIC_SCALE_SOUND);
  float song_coin[][2]  = SONG(COIN_SOUND);
  float song_one_up[][2]  = SONG(ONE_UP_SOUND);
  float song_sonic_ring[][2]  = SONG(SONIC_RING);
  float song_zelda_puzzle[][2]  = SONG(ZELDA_PUZZLE);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  `|BSp|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn0|
     * |-----------------------------------------------------------'
     * |Ctrl |Gui|Alt  |         Space         |Alt  |Gui|Fn |Ctrl |
     * `-----------------------------------------------------------'
     */
    [_BL] = LAYOUT_all(
      KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_NO,  KC_BSPC,\
      KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     \
      LT(_ML,KC_CAPS),     KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_NO,  KC_ENT,  \
      KC_LSFT,  KC_NO,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_RSFT,   KC_BSLS, \
      KC_LCTL,  KC_LALT,  KC_LGUI,                        KC_SPC,                      KC_RGUI,  KC_RALT,  MO(_FL),   KC_RCTL),
    [_FL] = LAYOUT_all(
      KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,KC_DEL,\
      _______,   _______,_______,_______,_______,_______,_______,_______,KC_UP,  _______,_______,KC_HOME,KC_END,_______,     \
      _______,     _______,MO(_CL),_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,  _______, \
      _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______,   _______, \
      _______,_______,_______,                        _______,                     _______,  _______,  MO(_FL),   _______),
    [_ML] = LAYOUT_all(
      KC_ESC, KC_BRID,KC_BRIU,KC_NO, KC_NO, BL_DEC,BL_INC,KC_MRWD,KC_MPLY,KC_MFFD,KC_MUTE,KC_VOLD,KC_VOLU, _______,KC_DEL,\
      _______,   _______,_______,_______,_______,_______,_______,_______,KC_UP,  _______,_______,KC_HOME,KC_END,_______,     \
      _______,     _______,MO(_CL),_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGUP,KC_PGDN,_______,  _______, \
      _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______,   _______, \
      _______,_______,_______,                        _______,                     _______,  _______,  MO(_FL),   _______),
    [_CL] = LAYOUT_all(
      BL_STEP,S_BSKTC,S_ODEJY,S_RCKBY,S_DOEDR,S_SCALE,S_ONEUP,S_COIN, S_SONIC,S_ZELDA,_______,_______,_______,_______,_______,\
      _______,   _______,_______,_______,RESET,  _______,_______,_______,_______,_______,_______,_______,_______,_______,     \
      _______,     _______,MO(_CL),_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______, \
      _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______, \
      _______,  _______,  _______,                        _______,                     _______,  _______,  MO(_FL),   _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case S_BSKTC:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_basketcase);
            }
            return false;
        case S_ODEJY:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_ode_to_joy);
            }
            return false;
        case S_RCKBY:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_rock_a_bye_baby);
            }
            return false;
        case S_DOEDR:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_doe_a_deer);
            }
            return false;
        case S_SCALE:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_scale);
            }
            return false;
        case S_ONEUP:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_one_up);
            }
            return false;
        case S_COIN:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_coin);
            }
            return false;
        case S_SONIC:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_sonic_ring);
            }
            return false;
        case S_ZELDA:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_zelda_puzzle);
            }
            return false;
    }
    return true;
}
