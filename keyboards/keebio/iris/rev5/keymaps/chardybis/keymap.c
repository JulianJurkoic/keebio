// Keebio Iris Rev. 5 port of the ZMK Charybdis (4x6) keymap.
//
// The Charybdis and the Iris share an identical 4x6 main matrix, so rows 0-3
// are a near-literal transcription. The thumb clusters are laid out for the
// Iris and no longer mirror the Charybdis. See README.md.
//
// This board has no trackball and no encoders, so the Charybdis' mouse buttons
// and scroll encoders are omitted entirely.

#include QMK_KEYBOARD_H

enum layers {
    _BASE,   // layer_0: Colemak-ish
    _FN,     // layer_1: F-keys, numpad, arrows
    _QWERTY, // layer_2
    _GAME,   // layer_3: FPS
};

// Home-row mods. Shift lives on the index-1 key of each home row -- A on the
// left, and the mirrored key on the right (O in Colemak, ; in QWERTY).
// Alt is no longer a home-row mod; it moved to the inner thumb keys.
#define A_SFT   LSFT_T(KC_A)
#define O_SFT   RSFT_T(KC_O)
#define SCLN_SFT RSFT_T(KC_SCLN)

// Dictation. QMK has no keycode for Apple's F5 mic key -- that is a vendor-
// specific HID usage only Apple keyboards emit -- and KC_ASSISTANT (consumer
// usage 0x1CB) is a different feature that macOS ignores. So we send a key
// macOS can bind instead: set System Settings -> Keyboard -> Dictation ->
// Shortcut -> Customize to F13. MacBooks have no physical F13, so nothing
// else collides with it.
#define VOICE   KC_F13

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* layer_0 */
    [_BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_ESC,  A_SFT,   KC_R,    KC_S,    KC_T,    KC_G,                        KC_M,    KC_N,    KC_E,    KC_I,    O_SFT,   KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_LALT,   KC_LALT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
                                   VOICE,   KC_LGUI, MO(_FN),                     KC_ENT,  KC_SPC,  XXXXXXX
    ),

    /* layer_1 */
    [_FN] = LAYOUT(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL,
        XXXXXXX, TO(2),   KC_7,    KC_8,    KC_9,    TO(3),                       QK_BOOT, KC_EQL,  KC_BSLS, KC_LBRC, KC_RBRC, KC_BSPC,
        XXXXXXX, KC_0,    KC_4,    KC_5,    KC_6,    XXXXXXX,                     XXXXXXX, KC_DOWN, KC_UP,   KC_LEFT, KC_RGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, KC_LALT,   KC_LALT, XXXXXXX, XXXXXXX, KC_DOT,  KC_RBRC, XXXXXXX, KC_DEL,
                                   VOICE,   KC_LGUI, TO(0),                       KC_ENT,  KC_SPC,  XXXXXXX
    ),

    /* layer_2 */
    [_QWERTY] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  A_SFT,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    SCLN_SFT,KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,   KC_LALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
                                   VOICE,   KC_LGUI, TO(1),                       KC_ENT,  KC_SPC,  XXXXXXX
    ),

    /* layer_3 - FPS gaming */
    [_GAME] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_Q,    KC_F,    KC_W,    KC_P,    KC_B,                        _______, _______, _______, _______, _______, _______,
        KC_ESC,  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_G,                        _______, _______, _______, _______, _______, _______,
        KC_LALT, KC_LCTL, KC_X,    KC_C,    KC_V,    KC_Z,    KC_LALT,   _______, _______, _______, _______, _______, _______, _______,
                                   KC_R,    KC_SPC,  KC_E,                        KC_ENT,  _______, TO(0)
    ),
};
