/* Copyright 2020 doodboard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "duckboard_r3.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT_default(
		         KC_R,   KC_F, 		KC_V,          	KC_SPACE,
		         KC_E,   KC_D, 		KC_M,          	KC_B,
		         KC_W,   KC_S, 		KC_X,      		KC_T,
		TG(1), 	 KC_Q,   KC_A,		KC_Z,       	KC_LEFT_ALT,
		KC_ESC,  KC_TAB, KC_CAPS, 	KC_LEFT_SHIFT, 	KC_LEFT_CTRL),

	LAYOUT_default(
		         KC_TRNS, KC_TRNS,             KC_TRNS,    RGB_MOD,
		         LCTL(LALT(KC_RIGHT)), KC_MEDIA_NEXT_TRACK, RGB_M_B,  RGB_RMOD,
		         KC_TRNS, KC_MEDIA_PLAY_PAUSE, RGB_M_SN, RGB_HUD,
		TG(1), LCTL(LALT(KC_LEFT)), KC_MEDIA_PREV_TRACK, RGB_M_SW, RGB_HUI,
		LALT(KC_G), RGB_TOG, RGB_VAI,             RGB_VAD,  KC_PSCR),
};

// void keyboard_post_init_user(void) {
//   //Customise these values to debug
//   debug_enable=true;
//   debug_matrix=true;
//   //debug_keyboard=true;
//   //debug_mouse=true;
// }
