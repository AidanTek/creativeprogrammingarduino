/* Neopixel (WS2812) Loop Example
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
 *  This sketch demonstrates further use of the for() loop. Use for() to create more intricate patterns
 *  with the WS2812 Neopixel LEDs. Try changing the colour, add more to the sequence and try changing the
 *  speed with the "delaytime" parameter
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

const int delaytime = 100; // Parameter used to set the pace of the sketch (delay in milliseconds)
 
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.

}

void loop() {
  // Turn on one LED at a time in a sequence, then turn them off one at a time
  
  for(int i = 0; i < numleds; i++) {
    pixels.setPixelColor(i, pixels.Color(100,100,100)); // This command presets one LED at a time
    pixels.show(); // This sends the updated pixel color to all preset LEDs
    delay(delaytime);
  }
  for(int i = numleds; i > 0; i--) {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(delaytime);
  }
}
