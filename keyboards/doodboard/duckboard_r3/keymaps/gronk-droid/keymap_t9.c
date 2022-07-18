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

typedef enum {
	TD_NONE,
	TD_UNKNOWN,
	TD_SINGLE_TAP,
	TD_DOUBLE_TAP,
	TD_TRIPLE_TAP,
	TD_QUAD_TAP
} td_state_t;

typedef struct {
	bool is_pressed_action;
	td_state_t state;
} td_tap_t;

enum {
	A_B_C,
	D_E_F,
	G_H_I,
	J_K_L,
	M_N_O,
	P_Q_R_S,
	T_U_V,
	W_X_Y_Z
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

void a_finished(qk_tap_dance_state_t *state, void *user_data);
void a_reset(qk_tap_dance_state_t *state, void *user_data);
void d_finished(qk_tap_dance_state_t *state, void *user_data);
void d_reset(qk_tap_dance_state_t *state, void *user_data);
void g_finished(qk_tap_dance_state_t *state, void *user_data);
void g_reset(qk_tap_dance_state_t *state, void *user_data);
void j_finished(qk_tap_dance_state_t *state, void *user_data);
void j_reset(qk_tap_dance_state_t *state, void *user_data);
void m_finished(qk_tap_dance_state_t *state, void *user_data);
void m_reset(qk_tap_dance_state_t *state, void *user_data);
void p_finished(qk_tap_dance_state_t *state, void *user_data);
void p_reset(qk_tap_dance_state_t *state, void *user_data);
void t_finished(qk_tap_dance_state_t *state, void *user_data);
void t_reset(qk_tap_dance_state_t *state, void *user_data);
void w_finished(qk_tap_dance_state_t *state, void *user_data);
void w_reset(qk_tap_dance_state_t *state, void *user_data);


/*
██   ██ ███████ ██    ██ ███    ███  █████  ██████
██  ██  ██       ██  ██  ████  ████ ██   ██ ██   ██
█████   █████     ████   ██ ████ ██ ███████ ██████
██  ██  ██         ██    ██  ██  ██ ██   ██ ██
██   ██ ███████    ██    ██      ██ ██   ██ ██
*/

td_state_t cur_dance(qk_tap_dance_state_t *state) {
	switch (state->count) {
		case 1: if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
		case 2: if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
		case 3: if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
		case 4: if (state->interrupted || !state->pressed) return TD_QUAD_TAP;
		default: return TD_UNKNOWN;
	}
}

static td_tap_t atap_state = {
	.is_pressed_action = true,
	.state = TD_NONE
};

void a_finished(qk_tap_dance_state_t *state, void *user_data) {
	atap_state.state = cur_dance(state);
	switch (atap_state.state) {
		case TD_SINGLE_TAP: register_code(KC_A); break;
		case TD_DOUBLE_TAP: register_code(KC_B); break;
		case TD_TRIPLE_TAP: register_code(KC_C); break;
		case TD_QUAD_TAP: register_code(KC_COMMA); break;
		case TD_NONE: break;
		case TD_UNKNOWN: break;
	}
}

void a_reset(qk_tap_dance_state_t *state, void *user_data) {
	switch (atap_state.state) {
		case TD_SINGLE_TAP: unregister_code(KC_A); break;
		case TD_DOUBLE_TAP: unregister_code(KC_B); break;
		case TD_TRIPLE_TAP: unregister_code(KC_C); break;
		case TD_QUAD_TAP: unregister_code(KC_COMMA); break;
	}
	atap_state.state = TD_NONE;
}

qk_tap_dance_state_t tap_dance_actions[] = {
	[A_B_C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, a_finished, a_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT_default(
		         KC_R,   KC_F, 		TG(1),         KC_SPACE,
		         KC_E,   KC_D, 		KC_M,          KC_X,
		         KC_W,   KC_S, 		KC_RIGHT,      KC_Z,
		KC_MUTE, KC_Q,   TD(A_B_C),		KC_LEFT,       KC_LEFT_ALT,
		KC_ESC,  KC_GRV, KC_TAB, 	KC_LEFT_SHIFT, KC_LEFT_CTRL),

	LAYOUT_default(
		         KC_TRNS, KC_TRNS,             TG(1),    RGB_MOD,
		         LCTL(LALT(KC_RIGHT)), KC_MEDIA_NEXT_TRACK, RGB_M_B,  RGB_RMOD,
		         KC_TRNS, KC_MEDIA_PLAY_PAUSE, RGB_M_SN, RGB_HUD,
		KC_TRNS, LCTL(LALT(KC_LEFT)), KC_MEDIA_PREV_TRACK, RGB_M_SW, RGB_HUI,
		KC_TRNS, RGB_TOG, RGB_VAI,             RGB_VAD,  KC_TRNS),
};

// void keyboard_post_init_user(void) {
//   //Customise these values to debug
//   debug_enable=true;
//   debug_matrix=true;
//   //debug_keyboard=true;
//   //debug_mouse=true;
// }
