#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define LC_TOGG TOGGLE_LAYER_COLOR

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum tap_dance_codes {
  DANCE_MSP_AGR,
};

// Meta-Space on tap, AltGr on hold
#define MSP_AGR TD(DANCE_MSP_AGR)
#define M_PGUP LGUI(KC_PGUP)
#define M_PGDN LGUI(KC_PGDN)

enum planck_layers {
  _BASE,
  _COLDH,
  _EXPERIM,
  _LOWER,
  _RAISE,
  _ADJUST,
  _TFH,
  _VSRG,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TFH TG(_TFH)
#define VSRG TG(_VSRG)
#define COLDH TG(_COLDH)
#define EXPERIM TG(_EXPERIM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_ESC,  MSP_AGR, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  XXXXXXX, RAISE,   KC_LGUI, KC_LBRC, KC_RBRC, KC_ENT
  ),

  [_COLDH] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_ESC,  MSP_AGR, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  XXXXXXX, RAISE,   KC_LGUI, KC_LBRC, KC_RBRC, KC_ENT
  ),

  [_EXPERIM] = LAYOUT_planck_grid(
    _______, _______,      _______,      _______,      _______,      _______, _______, _______,      _______,      _______,      _______,         _______,
    XXXXXXX, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), _______, _______, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), _______,
    XXXXXXX, _______,      _______,      _______,      _______,      _______, _______, _______,      _______,      _______,      _______,         XXXXXXX,
    _______, _______,      XXXXXXX,      CAPSWRD,      _______,      _______, XXXXXXX, _______,      XXXXXXX,      _______,      _______,         _______
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_VOLU, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR, XXXXXXX,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_VOLD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BTN3, KC_INS,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_ACL0, _______, KC_WH_D, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,
    _______, _______, _______, _______, _______, KC_DEL,  XXXXXXX, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_CIRC, KC_LABK, KC_RABK, KC_DLR,  KC_EXLM, KC_HASH, KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_AT,   KC_LPRN, KC_RPRN, KC_AMPR, KC_PERC, KC_MINS, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_BSLS,
    _______, KC_TILD, KC_LCBR, KC_RCBR, KC_UNDS, KC_PIPE, KC_PLUS, KC_1,    KC_2,    KC_3,    KC_EQL,  _______,
    _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, EXPERIM, _______, TFH,     _______, _______, _______, _______, KC_PAUS, QK_RBT,
    _______, _______, AU_ON,   AU_OFF,  AU_TOG,  _______, LC_TOGG, RGB_TOG, RGB_VAI, RGB_VAD, _______, QK_BOOT,
    _______, _______, _______, COLDH,   VSRG,    _______, NK_TOGG, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______,
    _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______
  ),

  [_TFH] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______
  ),

  [_VSRG] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______
  ),

};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_LOWER] = { {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {252,255,232}, {252,255,232}, {252,255,232}, {252,255,232}, {0,0,0}, {252,255,232}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {188,255,255}, {252,255,232}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {152,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255} },

    [_TFH] = { {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {41,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (get_highest_layer(layer_state)) {
    case _LOWER:
      set_layer_color(_LOWER);
      break;
    case _TFH:
      set_layer_color(_TFH);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint8_t layer_state_set_user(uint8_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
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


void on_dance_msp_agr(qk_tap_dance_state_t *state, void *user_data);
void dance_msp_agr_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_msp_agr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_msp_agr(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_SPACE));
        tap_code16(LGUI(KC_SPACE));
        tap_code16(LGUI(KC_SPACE));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_SPACE));
    }
}

void dance_msp_agr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_SPACE)); break;
        case SINGLE_HOLD: register_code16(KC_RALT); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_SPACE)); register_code16(LGUI(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_SPACE)); register_code16(LGUI(KC_SPACE));
    }
}

void dance_msp_agr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
        case SINGLE_HOLD: unregister_code16(KC_RALT); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_SPACE)); break;
    }
    dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_MSP_AGR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_msp_agr, dance_msp_agr_finished, dance_msp_agr_reset),
};

bool caps_word_press_software_qwerty(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            send_keyboard_report();
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool caps_word_press_software_coldh(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        // Skip KC_P, which is a semicolon, and add KC_SCLN, which is a P.
        case KC_A ... KC_O:
        case KC_Q ... KC_Z:
        case KC_SCLN:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            send_keyboard_report();
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool caps_word_press_user(uint16_t keycode) {
    if (IS_LAYER_ON(_COLDH)) {
        // Hardware Col-DH uses software qwerty.
        return caps_word_press_software_qwerty(keycode);
    } else {
        // Otherwise, assume software Col-DH.
        // return caps_word_press_software_coldh(keycode);

        // Software Col-DH is over.
        return caps_word_press_software_qwerty(keycode);
    }
}
