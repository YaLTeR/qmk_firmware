
 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
	{35+15, 5, hsv},\
	  {35+22, 3, hsv},\
	  {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
		{20, 2, hsv}, \
		{30, 2, hsv}, \
	  {35+ 10, 2, hsv}, \
	  {35+ 20, 2, hsv}, \
	  {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	  {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	  {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
		{1, 6, hsv}, \
    {35+1, 6, hsv}, \
		{7, 4, hsv}, \
	  {35+ 7, 4, hsv}, \
		{25, 2, hsv}, \
	  {35+ 25, 2, hsv}


enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
};

enum tap_dance_codes {
  TD_MSP_AGR,
};

#define MSP_AGR TD(TD_MSP_AGR)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  MSP_AGR,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_RBRC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,    KC_MUTE,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_PSCR, KC_LALT, KC_LOWER,  KC_SPC,  KC_ESC,    KC_ENT,  KC_SPC,   KC_RAISE,KC_LGUI,  KC_LBRC
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

[_LOWER] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
   _______, _______,_______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
   KC_GRV,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_VOLU,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_DEL,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
   _______, KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_VOLD,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_INS,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
   _______, KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_ACL0,QK_BOOT,   _______,_______, KC_WH_D, KC_WH_U, _______, _______, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 NK_TOGG, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

[_RAISE] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
   _______, _______,_______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
   KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
   _______, KC_EXLM,KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
   _______, KC_TILD,KC_LCBR, KC_RCBR, KC_UNDS, KC_PIPE, _______, QK_BOOT, KC_PLUS, KC_MINS, KC_LABK, KC_RABK, KC_EQL,  _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

[_ADJUST] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
   _______, _______,_______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
   _______, _______,_______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
   _______, _______,_______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
   _______, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_RED)

);

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
	layer_num_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Sors\nRuns"), false);

    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)


    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("ylay"), false);
            break;

        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
		} else if (index == 1) {
			switch (get_highest_layer(layer_state)) {
				case _QWERTY:
					if (clockwise) {
						tap_code(KC_PGDN);
					} else {
						tap_code(KC_PGUP);
					}
				break;
			case _RAISE:
			case _LOWER:
					if (clockwise) {
						tap_code(KC_DOWN);
					} else {
						tap_code(KC_UP);
					}
				break;
			default:
					if (clockwise) {
						tap_code(KC_WH_D);
					} else {
						tap_code(KC_WH_U);
					}
				break;
		}
    }
    return true;
}

#endif

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_SPACE));
        tap_code16(LGUI(KC_SPACE));
        tap_code16(LGUI(KC_SPACE));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_SPACE));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_SPACE)); break;
        case SINGLE_HOLD: register_code16(KC_RALT); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_SPACE)); register_code16(LGUI(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_SPACE)); register_code16(LGUI(KC_SPACE));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
        case SINGLE_HOLD: unregister_code16(KC_RALT); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_MSP_AGR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};
