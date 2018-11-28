/* Neopixel (WS2812) Fade to Potentiometer Example
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  Connect the 10k Potentiometer to the Arduino, you need 3 wires:
 *  - Connect the left leg to GND
 *  - Connect the right leg to 5V
 *  - Connect the middle pin to an unused Analog pin, I used A0
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
 *  This sketch demonstrates how the potentiometer value can be used to change something, such as the LED
 *  brightness. The WS2812 LEDs have a brightness range of 0 to 255 for each colour - 255 is very bright!
 *  Here we introduce the map() function to change the potentiometer value to a suitable range for the 
 *  LEDs - notice the use of the maxbrightness variable below.
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

const int delaytime = 10; // Parameter used to set the pace of the sketch

const byte potpin = A0;
const byte maxbrightness = 150;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  
}

void loop() {
  int potval; // create a variable to store the potentiometer reading
  byte ledval; // a variable to set the led brightness (this is only for articulation here!)

  potval = analogRead(potpin); // write the analog reading into the variable
  
  // map potval to a more suitable range
    // map() arguments work like this: map(variable, in low, in high, out low, out high)
  ledval = map(potval, 0, 1023, 0, maxbrightness);

  for(int i = 0; i < 8; i++) {
    pixels.setPixelColor(i, pixels.Color(ledval,ledval,ledval)); // preset all LEDs
  }
  pixels.show(); // update all LEDs

  delay(delaytime);
}
