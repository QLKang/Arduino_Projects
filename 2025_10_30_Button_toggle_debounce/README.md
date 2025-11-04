# Button Toggle with Debounce (Pull-Down Version)

**Date**: 2025-10-30  
**Function**: Press the button once to toggle the LED, with software debounce  
**Platform**: Tinkercad (Web Version)  
**Usage**: Download the `.ino` file and upload it to an Arduino board

---

## Features

- **Button Toggle Logic**: LED switches ON/OFF each time the button is pressed  
- **Software Debounce**: Prevents multiple toggles caused by button bouncing  
- **Works with Pull-Down Resistor**: Uses external pull-down resistor to keep input stable  

---

## Hardware Setup

- Button connected to digital pin **D3** and **GND**  
- LED connected to digital pin **D13** (or board LED) and **GND**  
- External 10kΩ resistor between D3 and GND (pull-down)

---

## Code Overview

- `ledState` tracks the current LED state (ON/OFF)  
- `lastButtonState` stores the previous button reading for debounce  
- LED toggles only when the button is pressed and the state is stable  

```cpp