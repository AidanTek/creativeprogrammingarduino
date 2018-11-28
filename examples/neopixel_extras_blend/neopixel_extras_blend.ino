/* Neopixel (WS2812) Colour Blend Example
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
 *  This sketch is an extra - a modification on neopixel_fade. It's up to you to figure out how it works!
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

const byte neopin = 19; // this is the pin Din or DATAIN is connected to for the WS2812 LEDs
const byte numleds = 1; // How many individual LEDs have you got?

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numleds, neopin, NEO_GRB + NEO_KHZ800);

const int delaytime = 2; // Parameter used to set the pace of the sketch
 
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.

}

void loop() {
  // Blend between two colours:

  for(int i = 0; i < 100; i++) {
    for(int x = 0; x < 8; x++) { 
      pixels.setPixelColor(x, pixels.Color(i,0,100-i)); 
    }
    pixels.show();
    delay(delaytime);
  }
  
  for(int i = 100; i > 0; i--) {
    for(int x = 0; x < 8; x++) { 
      pixels.setPixelColor(x, pixels.Color(i,0,100-i)); 
    }
    pixels.show(); 
    delay(delaytime);
  }
    
}
