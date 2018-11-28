/* Neopixel (WS2812) Random Colour Fade Example
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
 *  This sketch is an extra - Here a new function is introduce, random(). random() will generate a random
 *  number and store it in a variable. It is used in this sketch to generate values for RGB colours. There
 *  is a different take on the fade sketch here, the outer loop variable i is used to multiply the random
 *  numbers generated: 
 *  - n (or one of the RGB variables) is first divided by 100
 *  - if i == 0 then n * i results in 0
 *  - if i == 50 then n * i results in 50% of n (or n/2)
 *  - if i == 100 then n * i results in 100% of n (or simply n!)
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

const byte neopin = 2; // this is the pin Din or DATAIN is connected to for the WS2812 LEDs
const byte numleds = 8; // How many individual LEDs have you got?

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numleds, neopin, NEO_GRB + NEO_KHZ800);

const int delaytime = 10; // Parameter used to set the pace of the sketch
 
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.

}

void loop() {
  // Fade a random colour:

  // First, for each iteration of void loop() generate some random rgb values:
  float r = (random(150)/100.0); // a float variable stores a decimal point number
  float g = (random(150)/100.0);
  float b = (random(150)/100.0);

  // Use the outer loop to scale the colours with multiplication:
  for(int i = 0; i < 100; i++) {
    for(int x = 0; x < 8; x++) { 
      pixels.setPixelColor(x, pixels.Color(r*i,g*i,b*i)); 
    }
    pixels.show();
    delay(delaytime);
  }
  
  for(int i = 100; i > 0; i--) {
    for(int x = 0; x < 8; x++) { 
      pixels.setPixelColor(x, pixels.Color(r*i,g*i,b*i)); 
    }
    pixels.show(); 
    delay(delaytime);
  }
    
}
