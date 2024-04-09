/*******************************************************************************
 * Keyboard libraries:
 * https://github.com/Xinyuan-LilyGO/T-Deck/tree/master/examples/Keyboard_T_Deck_Master
 * 
 * Based on 'keyboard.h' by moononournation <https://github.com/moononournation/T-Deck/tree/main>
 ******************************************************************************/

#include "TDECK_PINS.h"
#include <Wire.h>

void keyboard_init() {
  // Check keyboard
  Wire.requestFrom(TDECK_KEYBOARD_ADDR, 1);
  if (Wire.read() == -1) {
    Serial.println("LILYGO keyboard offline.");
  }
}

/*char keyboard_get_key() {
    // Read key value from esp32c3
    Wire.requestFrom(TDECK_KEYBOARD_ADDR, 1);
    if (Wire.available() > 0) {
        return Wire.read();
    } else {
      return 0;
    }
}*/

char getKeyboardInput()
{
    char incoming = 0;
    Wire.requestFrom(TDECK_KEYBOARD_ADDR, 1);
    while (Wire.available() > 0)
    {
        incoming = Wire.read();
        if (incoming != (char)0x00)
        {
            return incoming;
        }
    }
    
}
