# Redox Lite

> A modified firmware for [the Redox keyboard](https://github.com/mattdibi/redox-keyboard).

[Setting up your QMK environment](https://docs.qmk.fm/#/newbs_getting_started), compile the firmware, flash it with CLI or [QMK Toolbox](https://github.com/qmk/qmk_toolbox) (to both halves).

```sh
# Compile the firmware
qmk compile -kb dg/redox -km default

# Compile and flash (press the reset button after you see the tip)
qmk flash -kb dg/redox -km default
```

## Implemented features

- [x] RGB Lighting
- [x] LED Indicators
- [x] Split Keyboard
