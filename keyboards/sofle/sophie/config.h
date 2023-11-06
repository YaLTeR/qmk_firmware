#pragma once

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#ifdef RGBLIGHT_ENABLE
    #define RGBLED_NUM 16
    #define RGBLED_SPLIT { 8, 8 }
#endif
