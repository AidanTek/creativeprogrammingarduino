/* Neopixel (WS2812) Fade Example
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
 *  Here is another example using a for() loop within a for() loop - but now we use the outer for() loop
 *  to iterate between numbers 0 and 100. This number is used to set the brightness for a fade. The inner
 *  for() loop is repeated for each iteration of the outer loop to update all LEDs at the same time.
 *  Note that pixels.show and delay are only used once per outer iteration.
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
 
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.

}

void loop() {
  // Fade all LEDs in, then fade all LEDs out.

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
