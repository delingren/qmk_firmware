#include QMK_KEYBOARD_H

#include "delingren.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┘
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │              
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤ ┌───┐    
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │ │ ↑ │    
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬──┌─┴─┼───┼───┐
     * │Ctrl│GUI │Alt │                        │ Fn │ GUI│Ctrl│  │ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┘  └───┴───┴───┘
     */

  [_BL] = _BL_mf68_ansi,
  [_FL] = _FL_mf68_ansi,
  [_LL] = _LL_mf68_ansi,
};

void keyboard_pre_init_user() {
    setPinOutput(B0);
    writePinHigh(B0);
    setPinOutput(D5);
    writePinHigh(D5);
}

bool led_update_user(led_t usb_led) {
    writePin(B0, !usb_led.caps_lock);
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    writePin(D5, IS_LAYER_ON_STATE(state, _FL) ? 0 : 1);
    return state;
}
