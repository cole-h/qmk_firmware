#pragma once

/* Required BOOT key hold time (in ms) for restarting to bootloader */
#undef BOOTKEY_HOLD_MS
#define BOOTKEY_HOLD_MS 500

/* vin settings */
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

/* Force boot in NKRO mode */
#define FORCE_NKRO
