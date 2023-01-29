#pragma once

#include "config_common.h"

// USB Device descriptor parameter
#define VENDOR_ID    0x0079
#define PRODUCT_ID   0x0058
#define DEVICE_VER   0x0001
#define MANUFACTURER HolySwitch
#define PRODUCT      Sophie

// Keyboard Matrix (Rows are doubled)
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW

// Encoder support
#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 4

// Define Communication
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN D3
    #define RGBLED_NUM 16
    #define RGBLED_SPLIT { 8, 8 }
#endif
