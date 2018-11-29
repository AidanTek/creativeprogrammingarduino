/* Neopixel (WS2812) Basic Use
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less then try to adapt your code
 *  This sketch functions much like blink. Experiment by changing the colour settings in loop() and try
 *  adding more steps to the sequence.
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

const byte neopin = 2; // this is the pin Din or DATAIN is connected
const byte numleds = 8; // How many individual LEDs have you got?

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numleds, neopin, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  // The following command picks one Neopixel in the chain and sets it to a RGB colour
  pixels.setPixelColor(0, pixels.Color(100,0,0)); 
  pixels.show(); // This command updates the pixel so you see the result
  delay(1000);
  pixels.setPixelColor(1, pixels.Color(0,100,0)); 
  pixels.show();
  delay(1000);
  pixels.setPixelColor(2, pixels.Color(0,0,100)); 
  pixels.show();
  delay(1000);
  pixels.setPixelColor(3, pixels.Color(100,100,100));
  pixels.show();
  delay(1000); 
  pixels.setPixelColor(4, pixels.Color(100,0,0)); 
  pixels.show();
  delay(1000);
  pixels.setPixelColor(5, pixels.Color(0,100,0)); 
  pixels.show();
  delay(1000);
  pixels.setPixelColor(6, pixels.Color(0,0,100)); 
  pixels.show();
  delay(1000);
  pixels.setPixelColor(7, pixels.Color(100,100,100)); 
  pixels.show();
  delay(1000);

  // Now let's turn all the lights off and start again:
  pixels.setPixelColor(0, pixels.Color(0,0,0)); 
  pixels.setPixelColor(1, pixels.Color(0,0,0)); 
  pixels.setPixelColor(2, pixels.Color(0,0,0)); 
  pixels.setPixelColor(3, pixels.Color(0,0,0)); 
  pixels.setPixelColor(4, pixels.Color(0,0,0)); 
  pixels.setPixelColor(5, pixels.Color(0,0,0)); 
  pixels.setPixelColor(6, pixels.Color(0,0,0)); 
  pixels.setPixelColor(7, pixels.Color(0,0,0)); 
  pixels.show();
  delay(1000);
}
