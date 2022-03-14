/*Copyright 2019 Lyso1

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

#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE

#define VENDOR_ID       0x7856
#define PRODUCT_ID      0x6163
#define DEVICE_VER      0x0002
#define MANUFACTURER    Lyso1
#define PRODUCT         lck75

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 16

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
/*                        0    1    2    3    4    5    6    7    8    9   10  11  12  13  14  15*/
#define MATRIX_ROW_PINS { C2, C3, C7, C4, C6, C5 }
#define MATRIX_COL_PINS { A0, B0, A1, B1, A2, B2, A3, B3, A4, B4, A5, A6, A7, D7, D6, D5 }
#define DIODE_DIRECTION COL2ROW /* COL2ROW, ROW2COL*/

#define ENCODERS_PAD_B { D1 }
#define ENCODERS_PAD_A { D0 }

#define ENCODER_RESOLUTION 2 //default/suggested

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0        //🐉
#define BOOTMAGIC_LITE_COLUMN 0

// disables the rgb lighting, (which you can notice the lck75 does not have)
#define RGBLIGHT_SLEEP

#define OLED_TIMEOUT 0

/*  unicode input modes list. starts at first one, and then can be moved with
    the UC_MOD key in the keymap.c                                          */
#define UNICODE_SELECTED_MODES UC_WINC, UC_MAC, UC_LNX

/*  forces the unicode input mode to start at the beginning each time instead of
    remembering what it was last time it started                            */
#define UNICODE_CYCLE_PERSIST false


//  stuff to auto shift keys on hold
/*  `AUTO_SHIFT_ENABLE = yes` in rules.mk
    #define AUTO_SHIFT_MODIFIERS
    #define AUTO_SHIFT_TIMEOUT 170
    #define NO_AUTO_SHIFT_SPECIAL
    #define NO_AUTO_SHIFT_NUMERIC           */

#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif

// stuff for dual duty keys, read here:
// https://docs.qmk.fm/#/tap_hold?id=tap-or-hold-decision-modes

// #define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD
// #define TAPPING_TERM 200

#define NO_ACTION_ONESHOT

#define NO_MUSIC_MODE       // remove music mode for the matrix positions
