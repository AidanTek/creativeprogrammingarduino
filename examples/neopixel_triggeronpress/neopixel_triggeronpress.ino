/* Neopixel (WS2812) Fade on Trigger Example
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  Connect the push button to the Arduino, you need 2 wires:
 *  - Connect one side of the button to GND
 *  - Connect the other side of the button to an unused digital pin, I used pin 4
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
 *  This sketch combines the push button example with the neopixel fade example. When the push button is 
 *  pressed, the fade will happen once. This is achieved using the if() function. if() is simple and 
 *  fundamental, you input an argument in the brackets, the if() checks if it is true and if it is then
 *  it will carry out the associated line(s) of code. Use parenthesis {} to specify a section of code for
 *  the if().
 *  
 *  Respect is due to Adafruit for their work on the Neopixel library.
 *  
 *  Example by Aidan Taylor. 2018. Cardiff Metropolitan University
 *  Released under a GPLv3 license
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

const byte neopin = 2; // this is the pin Din or DATAIN is connected to for the WS2812 LEDs
const byte numleds = 8; // How many individual LEDs have you got?

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numleds, neopin, NEO_GRB + NEO_KHZ800);

const byte buttonpin = 4; // The pin used to read from the button

const int delaytime = 10; // Parameter used to set the pace of the sketch

void setup() {
  pinMode(buttonpin, INPUT_PULLUP); // Tell Arduino that pin 4 is an input

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  boolean buttonval; // variable used to store the button value

  buttonval = digitalRead(buttonpin); // write the state of pin 4 to variable

  if(buttonval == 0) { // Remember that 0 is a registered press not 1!
    for(int i = 0; i < 100; i++) { // This is the outer loop
      for(int x = 0; x < 8; x++) { // This is the inner loop
        pixels.setPixelColor(x, pixels.Color(i,i,i)); // Preset each LED with current fade brightness
      }
      pixels.show(); // This sends the updated pixel color to all preset LEDs
      delay(delaytime);
    }
  
    for(int i = 100; i > 0; i--) {
      for(int x = 0; x < 8; x++) { 
        pixels.setPixelColor(x, pixels.Color(i,i,i)); 
      }
      pixels.show();
      delay(delaytime);
    }
  }
}
