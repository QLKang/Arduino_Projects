// C++ code
/*
# Button Toggle Debounce Project

This project implements a button-controlled LED with toggle functionality and hardware/software debounce using an Arduino. The LED changes its state (ON/OFF) each time the button is pressed, not just while holding it down.

---

## Key Features

- **Button Toggle Logic**: Pressing the button switches the LED state.
- **Hardware Debounce**: Using Arduino's `INPUT_PULLUP` and careful state tracking.
- **Software Debounce**: Ensures that button bouncing does not trigger multiple toggles.
- **Serial Monitor Debugging**: Prints button readings (HIGH/LOW) for debugging.

---

## Hardware Setup

- Button connected to **D3** and **GND** (4-pin button placed across the breadboard gap)
- LED connected to **D13 (or LED_BUILTIN)** and **GND**
- Optional 220Ω resistor in series with the LED if using an external LED

---

## Code Explanation

The final working version uses two state variables:

1. `lastReading` → captures the instantaneous button state.
2. `lastStableState` → captures the debounce-confirmed stable state.

LED state is toggled **only when the button is pressed and the stable state changes**, ensuring reliable operation in both real hardware and Tinkercad simulation.

### Final Working Code

*/
const int buttonPin = 3;
const int ledPin = LED_BUILTIN;  // Use board LED or external LED

bool ledState = false;
int lastStableState = HIGH;     // Last stable state after debounce
int lastReading = HIGH;         // Last instantaneous reading
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);
  Serial.println(reading);

  // If the reading has changed, reset the debounce timer
  if (reading != lastReading) lastDebounceTime = millis();

  // Check if the state has been stable longer than the debounce delay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != lastStableState) {
      lastStableState = reading;

      // Toggle LED only on button press (LOW)
      if (reading == LOW) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
    }
  }

  lastReading = reading;
}

