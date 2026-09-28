#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_mono(KC_MUTE),
};

// bool encoder_update_user(uint8_t index, bool clockwise) {
// 	// tap_code_delay(clockwise ? KC_VOLD : KC_VOLU, 10);
//     tap_code_delay(clockwise ? KC_U : KC_D, 100);
//     return true;
// }
