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
| `&mt` timings | `TAPPING_TERM 200`, `QUICK_TAP_TERM 100`, `FLOW_TAP_TERM 150` (`config.h`) |

ZMK's `tap-preferred` flavor is QMK's default hold resolution, so
`PERMISSIVE_HOLD` / `HOLD_ON_OTHER_KEY_PRESS` are intentionally *not* set.

## Thumb clusters

Laid out for the Iris rather than mirroring the Charybdis (5 left / 3 right
thumbs there, 3 thumbs + 1 inner key per half here):

```
left   (L->R):  VOICE   GUI   MO(FN)      + inner/upper-right key: LALT
right  (L->R):  ENT     SPC   <free>      + inner/upper-left  key: LALT
```

Both inner keys are Alt. The layer key is the third left thumb: `MO(FN)` on
base, `TO(0)` on FN, `TO(1)` on QWERTY. On the gaming layer the left thumbs are
`R` / `SPC` / `E` and the free right slot holds `TO(0)` as the escape hatch.

## Home-row mods

Shift sits on the index-1 key of each home row: `A` on the left, and the
mirrored right-hand key -- `O` in Colemak, `;` in QWERTY (same physical switch).
Alt is no longer a home-row mod; it moved to the two inner thumb keys.

## Dictation (the VOICE thumb key)

The ZMK config used `&kp C_VOICE_COMMAND`. There is no QMK equivalent that
macOS acts on: Apple's F5 mic key is a vendor-specific HID usage only Apple
keyboards emit, and QMK's `KC_ASSISTANT` (consumer usage `0x1CB`) is a
different feature macOS ignores.

So `VOICE` sends **F13** instead. To hook it up:

    System Settings -> Keyboard -> Dictation -> Shortcut -> Customize... -> F13

MacBooks have no physical F13, so nothing else collides with it. To use a
different key, change the `VOICE` define at the top of `keymap.c`.

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
