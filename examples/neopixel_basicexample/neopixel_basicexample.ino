/* Neopixel (WS2812) Basic Example
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
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

const byte neopin = 2; // this is the pin Din or DATAIN is connected to for the WS2812 LEDs
const byte numleds = 8; // How many individual LEDs have you got?

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numleds, neopin, NEO_GRB + NEO_KHZ800);
 
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
}

int red1 = random(100);
int green1 = random(100);
int blue1 = random(100);

void loop() {
  // Turn on all LEDs then turn them all off

int red2 = random(100);
float redR = red1-red2;
int green2 = random(100);
float greenR = green1-green2;
int blue2 = random(100);
float blueR = blue1-blue2;

  for(int i = 0; i < 100; i++) {
    for(int x = 0; x < numleds; x++) {
      pixels.setPixelColor(x, pixels.Color((red1-((redR/100)*i)),(green1-((greenR/100)*i)),(blue1-((blueR/100)*i)))); // This command presets one LED at a time
    }
    pixels.show(); // This sends the updated pixel color to all preset LEDs
    delay(5);
  }

  red1 = random(100);
  redR = red2-red1;
  green1 = random(100);
  greenR = green2-green1;
  blue1 = random(100);
  blueR = blue2-blue1;
  
  for(int i = 0; i < 100; i++) {
    for(int x = 0; x < numleds; x++) {
      pixels.setPixelColor(x, pixels.Color((red2-((redR/100)*i)),(green2-((greenR/100)*i)),(blue2-((blueR/100)*i)))); // This command presets one LED at a time
    }
    pixels.show(); // This sends the updated pixel color to all preset LEDs
    delay(5);
  }

 
}
