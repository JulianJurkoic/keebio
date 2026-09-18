// Keebio Iris Rev. 5 port of the ZMK Charybdis (4x6) keymap.
//
// The Charybdis and the Iris share an identical 4x6 main matrix, so rows 0-3
// are a literal transcription. Only the thumb clusters differ: the Charybdis
// has 5 left / 3 right thumbs, the Iris has 3 thumbs + 1 inner key per side.
// See README.md for the thumb mapping and the ZMK features that were dropped.
//
// This board has no trackball and no encoders, so the Charybdis' mouse buttons
// and scroll encoders are omitted entirely. XXXXXXX marks a thumb slot that is
// free as a result.

#include QMK_KEYBOARD_H

enum layers {
    _BASE,   // layer_0: Colemak-ish
    _FN,     // layer_1: F-keys, numpad, arrows
    _QWERTY, // layer_2
    _GAME,   // layer_3: FPS
};

// Home-row mods from the ZMK &mt bindings.
#define A_ALT   LALT_T(KC_A)
#define T_SFT   LSFT_T(KC_T)
#define N_SFT   RSFT_T(KC_N)

// ZMK &kp C_VOICE_COMMAND
#define VOICE   KC_ASSISTANT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* layer_0 */
    [_BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_ESC,  A_ALT,   KC_R,    KC_S,    T_SFT,   KC_G,                        KC_M,    N_SFT,   KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX,   KC_LALT, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
                                   KC_LGUI, VOICE,   MO(_FN),                     KC_SPC,  KC_ENT,  XXXXXXX
    ),

    /* layer_1 */
    [_FN] = LAYOUT(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL,
        XXXXXXX, TO(2),   KC_7,    KC_8,    KC_9,    TO(3),                       QK_BOOT, KC_EQL,  KC_BSLS, KC_LBRC, KC_RBRC, KC_BSPC,
        XXXXXXX, KC_0,    KC_4,    KC_5,    KC_6,    XXXXXXX,                     XXXXXXX, KC_DOWN, KC_UP,   KC_LEFT, KC_RGHT, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX,   KC_LALT, XXXXXXX, XXXXXXX, KC_DOT,  KC_RBRC, XXXXXXX, KC_DEL,
                                   KC_LGUI, VOICE,   TO(0),                       KC_SPC,  KC_ENT,  XXXXXXX
    ),

    /* layer_2 */
    [_QWERTY] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    T_SFT,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  A_ALT,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,   KC_LALT, N_SFT,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
                                   KC_LGUI, VOICE,   TO(1),                       KC_SPC,  KC_ENT,  XXXXXXX
    ),

    /* layer_3 - FPS gaming */
    [_GAME] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_Q,    KC_F,    KC_W,    KC_P,    KC_B,                        _______, _______, _______, _______, _______, _______,
        KC_ESC,  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_G,                        _______, _______, _______, _______, _______, _______,
        KC_LALT, KC_LCTL, KC_X,    KC_C,    KC_V,    KC_Z,    XXXXXXX,   _______, _______, _______, _______, _______, _______, _______,
                                   KC_R,    KC_SPC,  KC_E,                        _______, KC_ENT,  TO(0)
    ),
};
