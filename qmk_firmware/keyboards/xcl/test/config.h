#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* Device */
#define VENDOR_ID       0xDE29
#define PRODUCT_ID      0x7310
#define DEVICE_VER      0x0005
#define MANUFACTURER    Leo Deng
#define PRODUCT         Think
#define DESCRIPTION     ThinkPad TrackPoint on a 40% staggered layout, plus OLED display and buzzer.

/* DFU */
#define QMK_ESC_INPUT E6  // usually ROW
#define QMK_ESC_OUTPUT B4 // usually COL
#define QMK_LED B0
#define QMK_SPEAKER C6

/* Command */
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

/* Matrix */
#define MATRIX_ROWS 1
#define MATRIX_COLS 2
#define MATRIX_ROW_PINS { E6 }
#define MATRIX_COL_PINS {B4, B5 }
#define DIODE_DIRECTION COL2ROW // COL2ROW or ROW2COL

#define DEBOUNCE 5
#define TAP_CODE_DELAY 10
#define PREVENT_STUCK_MODIFIERS

/* LED Indicators */
// #define LED_CAPS_LOCK_PIN B0
// #define LED_PIN_ON_STATE 0

/* BLE */
// #define AdafruitBleResetPin D1
// #define AdafruitBleIRQPin D0
// #define AdafruitBleCSPin C6
// #define BATTERY_LEVEL_PIN B6

/* Audio */
#ifdef AUDIO_ENABLE
#define AUDIO_PIN C6
// #define AUDIO_PIN_ALT B6
// #define AUDIO_ENABLE_TONE_MULTIPLEXING
// #define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
// #define AUDIO_CLICKY
// #define AUDIO_VOICES
// #define AUDIO_VOICE_DEFAULT something // vibrating | something | drums | butts_fader | octave_crunch | duty_osc | duty_octave_down | delayed_vibrato
// #define THINK_STARTUP Q__NOTE(_C4), Q__NOTE(_E4), Q__NOTE(_D4), Q__NOTE(_G4),
// #define THINK_GOODBYE Q__NOTE(_C5), Q__NOTE(_G4), Q__NOTE(_E4), Q__NOTE(_C4),
// #define STARTUP_SONG SONG(THINK_STARTUP)
// #define GOODBYE_SONG SONG(THINK_GOODBYE)
#define NO_MUSIC_MODE
#endif

/* OLED */
#ifdef OLED_DRIVER_ENABLE
#define OLED_BRIGHTNESS 5
#define OLED_TIMEOUT 3000
#endif

/* DIP Switch */
#ifdef DIP_SWITCH_ENABLE
#define DIP_SWITCH_PINS { B2, B3 }
#endif

/* VIA */
// #ifdef VIA_ENABLE
// #define DYNAMIC_KEYMAP_LAYER_COUNT 3
// #endif

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

#endif
