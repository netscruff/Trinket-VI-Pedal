#include <TrinketKeyboard.h>

#define PIN_BUTTON 0

// Variables will change:
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup()
{
  // button pins as inputs
  pinMode(PIN_BUTTON, INPUT);

  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(PIN_BUTTON, HIGH);

  // remember, the buttons are active-low, they read LOW when they are not pressed

  // start USB stuff
  TrinketKeyboard.begin();
}

void loop()
{
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors
  TrinketKeyboard.poll();
  // read the pushbutton input pin:
  buttonState = digitalRead(PIN_BUTTON);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      TrinketKeyboard.pressKey(0, KEYCODE_ESC);
      // this releases the key (otherwise it is held down!)
      TrinketKeyboard.pressKey(0, 0);
    } else {
      // if the current state is LOW then the button went from on to off:
      TrinketKeyboard.print("i");
    }
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
}
