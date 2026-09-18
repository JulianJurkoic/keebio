#pragma once

// Mirrors the ZMK &mt settings from the Charybdis config:
//   tapping-term-ms = 200, flavor = "tap-preferred",
//   quick-tap-ms = 100, require-prior-idle-ms = 150
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 100

// "tap-preferred" == QMK default resolution, so PERMISSIVE_HOLD and
// HOLD_ON_OTHER_KEY_PRESS are deliberately left off.

// require-prior-idle-ms -> Flow Tap (QMK 0.27+). Harmless on older QMK.
#define FLOW_TAP_TERM 150
