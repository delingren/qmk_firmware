# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

BOOTMAGIC_ENABLE = lite     # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
MOUSEKEY_ENABLE = no        # Mouse keys
NKRO_ENABLE = no            # USB Nkey Rollover
COMMAND_ENABLE = no         # Commands for debug and configuration
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work

RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = no

MIDI_ENABLE = no            # MIDI support
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
ENCODER_ENABLE = yes

LAYOUTS = ortho_4x12
LAYOUTS_HAS_RGB = no

# Disable unsupported hardware
RGBLIGHT_SUPPORTED = yes
AUDIO_SUPPORTED = no
BACKLIGHT_SUPPORTED = no

OLED_DRIVER_ENABLE = yes

LTO_ENABLE = yes
