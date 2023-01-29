#pragma once

//#define USE_MATRIX_I2C


/* Select hand configuration */

#define MASTER_LEFT
//#define MASTER_RIGHT
//#define EE_HANDS
//#define USE_SERIAL_PD2
//#define USE_MATRIX_I2C

#define LAYER_STATE_8BIT

#undef ENCODER_RESOLUTION 
#define ENCODER_RESOLUTION 4

#define TAPPING_FORCE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 100
#define PERMISSIVE_HOLD
#define NO_ACTION_ONESHOT
#define USB_POLLING_INTERVAL_MS 1

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

#define OLED_TIMEOUT 60000
#define OLED_BRIGHTNESS 255
#define OLED_UPDATE_INTERVAL 1000

#if defined(KEYBOARD_sofle_rev1)
#define WPM_LAUNCH_CONTROL
#define WPM_SAMPLE_SECONDS 5
#define WPM_SAMPLE_PERIODS 25
#endif


#if defined(KEYBOARD_sofle_sophie)
#    define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
#undef RGBLED_NUM
#if defined(KEYBOARD_sofle_rev1)
#    define RGBLED_NUM 72
#elif defined(KEYBOARD_sofle_sophie)
#    define RGBLED_NUM 16
#endif
#undef RGBLED_SPLIT
#define RGBLED_SPLIT { RGBLED_NUM/2, RGBLED_NUM/2 }
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 255
#define RGBLIGHT_HUE_STEP 2
#define RGBLIGHT_SAT_STEP 5
#define RGBLIGHT_VAL_STEP 5

#define RGBLIGHT_EFFECT_STATIC_LIGHT
#endif
