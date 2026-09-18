# keebio — QMK userspace

QMK [External Userspace](https://docs.qmk.fm/newbs_external_userspace) holding a
port of my ZMK [Charybdis 4x6 keymap](../chardybis) to a **Keebio Iris Rev. 5**.

Keymap: `keyboards/keebio/iris/rev5/keymaps/chardybis/`

## Build & flash

```sh
brew install qmk/qmk/qmk        # one time (pulls the AVR toolchain)
qmk setup                       # one time
qmk config user.overlay_dir="$(realpath .)"

qmk compile -kb keebio/iris/rev5 -km chardybis
qmk flash   -kb keebio/iris/rev5 -km chardybis      # reset each half, flash both
```

The Iris Rev. 5 uses the `qmk-dfu` bootloader: short the reset pads / press the
reset button on a half, then let `qmk flash` pick it up. Repeat for the other half.

## What carried over 1:1

The Charybdis 4x6 and the Iris both have a 4x6 main matrix per half, so rows 0-3
of all four layers are a literal transcription:

| ZMK | QMK |
| --- | --- |
| `&kp X` | `KC_X` |
| `&mt LALT A` / `&mt LSHFT T` / `&mt RSHFT N` | `LALT_T(KC_A)` / `LSFT_T(KC_T)` / `RSFT_T(KC_N)` |
| `&mo 1` / `&to N` | `MO(_FN)` / `TO(N)` |
| `&none` / `&trans` | `XXXXXXX` / `_______` |
| `&kp C_VOICE_COMMAND` | `KC_ASSISTANT` |
| `&mt` timings | `TAPPING_TERM 200`, `QUICK_TAP_TERM 100`, `FLOW_TAP_TERM 150` (`config.h`) |

ZMK's `tap-preferred` flavor is QMK's default hold resolution, so
`PERMISSIVE_HOLD` / `HOLD_ON_OTHER_KEY_PRESS` are intentionally *not* set.

## Thumb clusters — needs tweaking

This is the part that could not be transcribed. The Charybdis has **5 left / 3
right** thumb keys; the Iris has **3 thumbs + 1 inner key** per half (4 + 4).

Dropping the Charybdis' two left-thumb mouse buttons brought the left hand down
to three keys, which happens to fit the Iris' three thumbs exactly:

```
left:   LGUI   ASSISTANT   MO(FN)     + inner key (next to B): free
right:  SPC    ENT         free       + inner key (next to K): LALT
```

The two `XXXXXXX` slots are deliberately empty rather than invented — they are
yours to assign. The occupied positions are a guess at the Iris' differently
shaped thumb arc; retune `keymap.c` once you have typed on it.

## Dropped, no Iris/QMK equivalent

- **Mouse** — this Iris has no trackball, so `&mkp MB1/MB2/MB3` are gone rather
  than mapped to `KC_BTN*`. `MOUSEKEY_ENABLE` is off and there is no `rules.mk`.
- **Encoders** — not installed on this board, so the ZMK `scroll_vertical_encoder`
  / `scroll_horizontal_encoder` sensor bindings are dropped and `ENCODER_MAP` is
  off. (The Rev. 5 supports one encoder per half if you ever add them.)
- **Trackball tuning** — `&mmv` / `&msc` acceleration, `zip_xy_scaler`, and the
  input listeners go with the trackball.
- **Bluetooth** — `&bt BT_SEL 0..3` on the layer-1 outer column became `XXXXXXX`;
  the Iris Rev. 5 is wired. `&bt BT_CLR` became `QK_BOOT`, which is genuinely
  useful there for flashing.
- The commented-out `Mouse` / `layer_4` / `layer_5` blocks in the ZMK config were
  not ported.
