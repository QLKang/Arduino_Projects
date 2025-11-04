Button Toggle Debounce with internal pull-up resistor.
Press the button to toggle the LED state.

Timing Diagram (Conceptual)

Button readings (reading) vs LED state:

Button reading (reading): ──────HIGH─────LOW─────HIGH────
Old code LED state      : ─────────-──────●─────────
Final code LED state    : ──────●─────────●─────────


HIGH = button not pressed

LOW = button pressed

Old code: LED did not toggle reliably due to immediate state update

Final code: LED toggles correctly using debounce-confirmed stable state

Software Debounce Visualization
Time → 
reading:      ─────HIGH────LOW────LOW────HIGH────
lastReading:  ─────HIGH────HIGH────LOW────LOW────
lastStable:   ─────HIGH────────────LOW─────────
LED state:    ─────OFF────────────ON──────────


lastReading tracks instantaneous input

lastStable tracks debounce-confirmed stable state

LED toggles only when lastStable changes on a button press