# Arduino_TPL0501

A simple PlatformIO TPL0501 Library
Tested on Wemos S2 Pico ESP32

See the `example` folder for a full example project.

# Wiring

This example is wired as follows:

| ESP32 Pin | TPL0501 Pin |
| --------- | ----------- |
| GND       | GND         |
| 3V3       | VCC         |
| GPIO 1    | SCLK        |
| GPIO 2    | DIN         |
| GPIO 3    | CS          |

I then connected my meter to `L` and `W` (not `H`, which will give a resistance of `100K - resistance`).
