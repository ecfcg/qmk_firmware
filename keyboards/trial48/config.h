/*
Copyright 2020 nabe

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER nabe
#define PRODUCT trial48
#define DESCRIPTION A custom keyboard

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS \
    { D4, C6, D7, E6 }
#define MATRIX_COL_PINS \
    { F6, F7, B1, B3, B2, B6 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/*
 * Tap danse
 */
#define TAPPING_TERM 200

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D2
#define MASTER_LEFT

/*
 * RGB LED configure
 */
#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
  #define RGBLED_NUM_LEFT  25
  #define RGBLED_NUM_RIGHT 25
  #define RGBLED_NUM       (RGBLED_NUM_LEFT + RGBLED_NUM_RIGHT)
  #define RGBLED_SPLIT     {RGBLED_NUM_LEFT, RGBLED_NUM_RIGHT}
  #define RGBLIGHT_LAYERS

  #define LED_LAYOUT(\
    L00, L01,                                                   R04, R05, \
    L10, L11, L02, L03, L04, L05,           R00, R01, R02, R03, R14, R15, \
    L20, L21, L12, L13, L14, L15,           R10, R11, R12, R13, R24, R25, \
    L30, L31, L22, L23, L24, L25, L99, R99, R20, R21, R22, R23, R34, R35, \
                   L32, L33, L34, L35, R30, R31, R32, R33\
  ) \
  { \
    L99, \
    L05, L04, L03, L02, L01, L00, \
    L15, L14, L13, L12, L11, L10, \
    L25, L24, L23, L22, L21, L20, \
    L35, L34, L33, L32, L31, L30, \
    R99, \
    R00, R01, R02, R03, R04, R05, \
    R10, R11, R12, R13, R14, R15, \
    R20, R21, R22, R23, R24, R25, \
    R30, R31, R32, R33, R34, R35  \
  }

  #define RGBLIGHT_LED_MAP LED_LAYOUT( \
     1,  5,                                         42, 46, \
     2,  6,  9, 12, 16, 20,         27, 31, 35, 39, 43, 47, \
     3,  7, 10, 13, 17, 26,         28, 32, 36, 40, 44, 48, \
     4,  8, 11, 14, 18, 22,  0, 25, 29, 33, 37, 41, 45, 49, \
                15, 19, 23, 24, 26, 30, 34, 38  \
  )

  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
  #define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
//   #define RGBLIGHT_EFFECT_BREATHING
//   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
//   #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
//   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING
/*== customize breathing effect ==*/
  /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
  #define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
  /*==== use exp() and sin() ====*/
  #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
  #define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION


