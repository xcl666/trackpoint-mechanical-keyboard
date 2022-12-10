# enaBLE

Bluetooth 4.2 powered by MDBT40 and Adafruit firmware.

```shel
pyocd erase --mass
pyocd flash -t nrf51 ./blespifriend_s110_xxac_0_8_1_190410_blespifriend_signature.hex
pyocd flash -t nrf51 ./s110_nrf51_8.0.0_softdevice.hex
pyocd flash -t nrf51 ./bootloader_0002.hex
pyocd flash -t nrf51 ./blespifriend_s110_xxac_0_8_1_190410_blespifriend.hex
```

## Implemented features

- [x] Bluetooth
