BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
MOUSEKEY_ENABLE = no        # Mouse keys
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
COMMAND_ENABLE = no         # Commands for debug and configuration
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
ENCODER_ENABLE = no         # Enable rotary encoder support
AUDIO_ENABLE = no           # Audio output

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

WS2812_DRIVER = pwm
AUDIO_DRIVER = pwm_hardware

RGB_MATRIX_DRIVER = WS2812
# Underglow and rgb matrix features shouldn't be on at the same time.
# Choose one. Otherwise both driver will try to change color and you'll see
# colors flickering.
RGBLIGHT_ENABLE = yes # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = no

DEFAULT_FOLDER = delingren/unicorn/f411
