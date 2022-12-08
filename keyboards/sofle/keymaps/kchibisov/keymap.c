#include QMK_KEYBOARD_H

enum sofle_layers {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | INS  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Mute  |    | ADJST |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | MO(1) | /Space  /       \Enter \  |MO(2) | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_BASE] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_INS,  \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC, \
  KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,   TO(_ADJUST), KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                 KC_LGUI,KC_LALT,KC_LCTRL, MO(_LOWER), KC_SPC,       KC_ENT,  MO(_RAISE), KC_RCTRL,KC_RALT, KC_RGUI            \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | TRNS | TRNS | COPY | TRNS | Right|   \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| TRNS | Left |   +  |   )  |   =  |   ]  |
 * |------+------+------+------+------+------|  TRNS |    | TRNS  |------+------+------+------+------+------|
 * | TRNS |      |      |      |      |      |-------|    |-------| BRIU | BRID | TRNS | PASTE| SYRQ | TRNS |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS | TRNS | / TRNS  /       \ DEL  \  |TRNS  | TRNS | TRNS | TRNS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F12,  \
  KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_TRNS, KC_TRNS, KC_COPY, KC_TRNS,  KC_RGHT, KC_BSLS, \
  KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_TRNS, KC_LEFT, KC_PLUS, KC_RPRN,  KC_EQL,  KC_RBRC, \
  KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,       KC_TRNS, KC_BRIU, KC_BRID, KC_TRNS, KC_PASTE, KC_SYRQ, KC_TRNS, \
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,        KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS                     \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | MPRV | MPLY | MPRV | HOME |  END |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   -  |   (  |  _   | PGUP | PGDN |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  TRNS |    | TRNS  |------+------+------+------+------+------|
 * | TRNS |      |      | DONN |  UP  | CUT  |-------|    |-------|      |      |      |      |      | TRNS |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS | TRNS | / BSPC  /       \ TRNS \  | TRNS | TRNS | TRNS | TRNS |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_F11,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, \
  KC_NO,   KC_MPRV,  KC_MPLY, KC_MNXT, KC_HOME, KC_END,                        KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, \
  KC_NO,   KC_MINUS, KC_LPRN, KC_UNDS, KC_PGUP, KC_PGDN,                       KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, \
  KC_TRNS, KC_NO,    KC_NO,   KC_DOWN, KC_UP,   KC_CUT, KC_TRNS,      KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, \
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_BSPC,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS              \
),
/* ADJUST
 * ,-------------------------------------------------.                          ,-----------------------------------------.
 * |      |RGB_M_P|RGB_M_B|RGB_M_R|RGB_M_SW|RGB_M_SN|                          |RGB_M_K|RGB_M_X|RGB_M_G|      |      |      |
 * |------+-------+-------+-------+--------+--------|                          |-------+-------+-------+------+------+------|
 * |      |       |       |       |        |        |                          |       |       |       |      |      |      |
 * |------+-------+-------+-------+--------+--------|                          |------+--------+-------+------+------+------|
 * |      |       |       |       |        |        |-------.          ,-------|       |       |       |      |      |      |
 * |------+-------+-------+-------+--------+--------|  TRNS |          | BASE  |------+--------+-------+------+------+------|
 * | TRNS |       |       |       |        |        |-------|          |-------|       |       |       |      |      | TRNS |
 * `-----------------------------------------/       /                  \      \-----------------------------------------'
 *            | TRNS | TRNS | TRNS | TRNS | / TRNS  /                    \ TRNS \  | TRNS | TRNS | TRNS | TRNS |
 *            |      |      |      |      |/       /                      \      \ |      |      |      |      |
 *            `----------------------------------'                        '------''---------------------------'
 */
[_ADJUST] = LAYOUT( \
  KC_NO,   RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN,                     RGB_M_K, RGB_M_X, RGB_M_G, KC_NO, KC_NO, KC_NO, \
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, \
  KC_NO,   RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,  KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, \
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_TRNS,   TO(_BASE), KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, \
                    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS              \
),
};

#ifdef OLED_ENABLE


static void render_nix_logo(void) {
    static const char PROGMEM raw_logo[] = {
// 'nixos', 32x32px
 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x9c, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x80, 0x84, 0x9c, 
0xbc, 0xfc, 0xfc, 0xf0, 0xf0, 0xf8, 0xfc, 0x7c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xc0, 0xc0, 0xc0, 0xc6, 0xc7, 0xc7, 0xc7, 0xe7, 0xff, 0xff, 0x7f, 0x1f, 0x0f, 0x07, 0x07, 0x07, 
0x07, 0x07, 0x07, 0x0f, 0x1f, 0x7f, 0xff, 0xf8, 0xf0, 0xfc, 0xff, 0xff, 0xce, 0xc0, 0xc0, 0xc0, 
0x03, 0x03, 0x03, 0x7b, 0xff, 0xff, 0x3f, 0x0f, 0x1f, 0xff, 0xfe, 0xf8, 0xf0, 0xe0, 0xe0, 0xe0, 
0xe0, 0xe0, 0xe0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xe7, 0xe3, 0xe3, 0xe3, 0x63, 0x03, 0x03, 0x03, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x3e, 0x3f, 0x1f, 0x0f, 0x0f, 0x3f, 0x3f, 0x3d, 
0x39, 0x21, 0x01, 0x03, 0x0f, 0x1f, 0x3f, 0x3f, 0x39, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00  
    };

    oled_set_cursor(0, 6);
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
    oled_set_cursor(0, 11);
    oled_write_ln_P(PSTR("NixOS"), false);
}


static void render_status(void) {
    static const char PROGMEM raw_logo[] = {
// 'alacritty-simple', 32x40px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 
0xe0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xfc, 0xff, 0xff, 0x7f, 0x1f, 
0x1f, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xfc, 0xff, 0xff, 0x7f, 0x0f, 0x83, 0xe0, 0xfc, 
0xfc, 0xe0, 0x83, 0x0f, 0x7f, 0xff, 0xff, 0xfc, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfe, 0xff, 0xff, 0x3f, 0x07, 0x01, 0x00, 0x00, 0x07, 0x3f, 0xff, 
0xff, 0x3f, 0x07, 0x00, 0x00, 0x01, 0x0f, 0x3f, 0xff, 0xff, 0xfe, 0xf0, 0xc0, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(raw_logo, sizeof(raw_logo));

    oled_set_cursor(0, 14);
    oled_write_ln_P(PSTR("WPM"), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);

}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    #if defined(KEYBOARD_sofle_sophie)
    return OLED_ROTATION_180;
    #endif
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_nix_logo();
    }

    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void keyboard_post_init_user(void) {
    rgblight_sethsv_range(7, 255, 255, 0, RGBLED_NUM/2);
    rgblight_sethsv_range(HSV_BLUE, RGBLED_NUM/2, RGBLED_NUM);
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
