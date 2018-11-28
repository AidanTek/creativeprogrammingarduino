/* Neopixel (WS2812) Basic Example
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
 *  This sketch functions much like blink. Here we also use the random() function for some fun.
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
 
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.

}

void loop() {
  // Turn on all LEDs as a random colour, then turn them all off
  
  // First let's make some new variables and store a random number in them 
    // (this updates every loop)
  int red = random(80);
  int green = random(80);
  int blue = random(80);
  
  for(int i = 0 ; i < numleds; i++) {
    pixels.setPixelColor(i, pixels.Color(red, green, blue)); // This command presets one LED at a time
  }
  pixels.show(); // This sends the updated pixel color to all preset LEDs

  delay(1000);

  for(int i = 0 ; i < numleds; i++) {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show();

  delay(1000);

}
