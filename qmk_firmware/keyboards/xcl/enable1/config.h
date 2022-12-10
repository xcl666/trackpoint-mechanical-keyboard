#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE32
#define PRODUCT_ID      0x7315
#define DEVICE_VER      0x0002
#define MANUFACTURER    Leo Deng
#define PRODUCT         enaBLE
#define DESCRIPTION     Bluetooth LE 4.2

/* Command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* Matrix */
#define MATRIX_ROWS 2
#define MATRIX_COLS 3
#define MATRIX_ROW_PINS { D3, D2 }
#define MATRIX_COL_PINS { F5, F6, F7 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

/* BLE */
#define AdafruitBleResetPin D4
#define AdafruitBleCSPin B4
#define AdafruitBleIRQPin E6
// #define BATTERY_LEVEL_PIN B6


/* PS/2 Mouse */
#ifdef PS2_USE_USART
#define PS2_CLOCK_PORT  PORTD
#define PS2_CLOCK_PIN   PIND
#define PS2_CLOCK_DDR   DDRD
#define PS2_CLOCK_BIT   5
#define PS2_DATA_PORT   PORTD
#define PS2_DATA_PIN    PIND
#define PS2_DATA_DDR    DDRD
#define PS2_DATA_BIT    2

/* synchronous, odd parity, 1-bit stop, 8-bit data, sample at falling edge */
/* set DDR of CLOCK as input to be slave */
#define PS2_USART_INIT() do {   \
  PS2_CLOCK_DDR &= ~(1<<PS2_CLOCK_BIT);   \
  PS2_DATA_DDR &= ~(1<<PS2_DATA_BIT);     \
  UCSR1C = ((1 << UMSEL10) |  \
            (3 << UPM10)   |  \
            (0 << USBS1)   |  \
            (3 << UCSZ10)  |  \
            (0 << UCPOL1));   \
  UCSR1A = 0;                 \
  UBRR1H = 0;                 \
  UBRR1L = 0;                 \
} while (0)
#define PS2_USART_RX_INT_ON() do {  \
  UCSR1B = ((1 << RXCIE1) |       \
            (1 << RXEN1));        \
} while (0)
#define PS2_USART_RX_POLL_ON() do { \
  UCSR1B = (1 << RXEN1);          \
} while (0)
#define PS2_USART_OFF() do {    \
  UCSR1C = 0;                 \
  UCSR1B &= ~((1 << RXEN1) |  \
              (1 << TXEN1));  \
} while (0)
#define PS2_USART_RX_READY      (UCSR1A & (1<<RXC1))
#define PS2_USART_RX_DATA       UDR1
#define PS2_USART_ERROR         (UCSR1A & ((1<<FE1) | (1<<DOR1) | (1<<UPE1)))
#define PS2_USART_RX_VECT       USART1_RX_vect

#define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_MIDDLE)
#define PS2_MOUSE_SCROLL_BTN_SEND 300
#define PS2_MOUSE_ROTATE 180
// #define PS2_MOUSE_X_MULTIPLIER 1
// #define PS2_MOUSE_Y_MULTIPLIER 1
#define PS2_MOUSE_V_MULTIPLIER 0.1
#endif

/* RGB Matrix */
#ifdef RGB_MATRIX_ENABLE
// #define DRIVER_ADDR_1 0b1110100
// #define DRIVER_COUNT 1
#define RGB_DI_PIN F4
#define DRIVER_LED_TOTAL 3
#define RGBLIGHT_ANIMATIONS
#define RGB_MATRIX_KEYPRESSES
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10

// #define RGBLED_NUM 3
// #define RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_HUE_STEP 8
// #define RGBLIGHT_SAT_STEP 8
// #define RGBLIGHT_VAL_STEP 8
// #define RGBLIGHT_LIMIT_VAL 155

// #define RGB_MATRIX_KEYPRESSES
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
// #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
// #define RGB_MATRIX_STARTUP_HUE 0
// #define RGB_MATRIX_STARTUP_SAT 255
// #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
// #define RGB_MATRIX_STARTUP_SPD 127
// #define RGB_MATRIX_DISABLE_KEYCODES
// #define RGB_DISABLE_TIMEOUT 0
// #define RGB_DISABLE_AFTER_TIMEOUT 0
// #define RGB_DISABLE_WHEN_USB_SUSPENDED true
// #define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5
// #define RGB_MATRIX_LED_FLUSH_LIMIT 16
#endif

#endif
