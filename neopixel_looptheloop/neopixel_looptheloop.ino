/* Neopixel (WS2812) Loop Example
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
 *  This sketch demonstrates further use of for(). You can make a loop happen within a loop, for each 
 *  iteration of the outer loop, the inner loop will complete all of its iterations. See this in action in
 *  the sketch, the placement of delays, pixel presets and pixel.show() commands need to be considered in
 *  order for the sequence to work correctly.
 *  
 *  Respect is due to Adafruit for their work on the Neopixel library.
 *  
 *  Example by Aidan Taylor. 2018. Cardiff Metropolitan University
 *  Released under a GPLv3 license following the Neopixel library by Adafruit
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

const byte neopin = 2;
const byte numleds = 8;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numleds, neopin, NEO_GRB + NEO_KHZ800);

const int delaytime = 100; // Parameter used to set the pace of the sketch
 
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.

}

void loop() {
  // The outer for() loop first presets all LEDs to OFF with an inner for() loop (n is the loop variable)
    // then the "next" led  to ON (i is the loop variable)
      // pixels.show() and delay are only used once per iteration of the outer loop
  
  for(int i = 0; i < numleds; i++) { // This is the outer loop
    for(int n = 0; n < 8; n++) { // This is an inner loop
      pixels.setPixelColor(n, pixels.Color(0,0,0)); // This command presets one LED at a time
    }
    pixels.setPixelColor(i, pixels.Color(100,100,100)); // Now turn the next LED on
    pixels.show(); // This sends the updated pixel color to all preset LEDs
    delay(delaytime);
  }
}
