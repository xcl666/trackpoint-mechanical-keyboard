# MCU name
MCU = atmega32u4

# Processor frequency.
F_CPU = 16000000

# Input clock frequency.
F_USB = $(F_CPU)

# LUFA specific
ARCH = AVR8

# Bootloader selection
#   Atmel DFU    atmel-dfu
#   Pro Micro    caterina
#   QMK DFU      qmk-dfu
BOOTLOADER = atmel-dfu

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

# Boot Section Size in *bytes*
OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Build Options
BOOTMAGIC_ENABLE ?= lite # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE ?= no   # Mouse keys(+4700)
EXTRAKEY_ENABLE ?= yes   # Audio control and System control(+450)
CONSOLE_ENABLE ?= no     # Console for debug(+400)
COMMAND_ENABLE ?= no     # Commands for debug and configuration
SLEEP_LED_ENABLE ?= no   # Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
NKRO_ENABLE ?= yes       # USB Nkey Rollover. See <https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work> if doesn't work.
BACKLIGHT_ENABLE ?= no   # Enable keyboard backlight functionality
RGBLIGHT_ENABLE ?= no
PS2_MOUSE_ENABLE = no    # +1278
PS2_USE_USART = no
AUDIO_ENABLE ?= no       # +7048
OLED_DRIVER_ENABLE ?= yes # +3838
VIA_ENABLE ?= yes         # +4326
# DIP_SWITCH_ENABLE ?= yes
# BLUETOOTH_ENABLE = no
# BLUETOOTH = AdafruitBLE
