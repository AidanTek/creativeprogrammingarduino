# 04. Neopixels: Setting Up and Basic Use

WS2812 are awesome little digital chips that have 3 LEDs built in to a tiny package. They can be chained together in large numbers and controlled very simply from a microcontroller like an Arduino. A great thing about these little lights is there is very little difference in terms of software between controlling 5 leds to controlling 5000! Adafruit provide WS2812 in a number of prepared packages such as flexible strips, circular PCBs and matrixes - they call their product line Neopixels and provide the Neopixel library that we will be using.

[Click Here to see a great Neopixel Demo](http://www.youtube.com/watch?v=2FXs1arWMrE) by YouTuber Megalomaniacat

### Connecting the Neopixels

WS2812/Neopixel LEDs need just 3 pins to work, which provide power and data. Examine the Neopixel board, you should see markings for connection to +5V, GND (ground) and Data In and Data Out. Data In will come from the Arduino, Data Out can link more Neopixels together in a chain. 

The Arduino can provide power to devices from some of its pins - but it is only designed for driving small projects, 8 Neopixels is not a problem but if you want to work with a larger number then you will need a different power source. Look at the pins on the Arduino, there is a section of pins that includes 5V and GND connections. On the opposite side of the board the Digital pins are found. Digital pins can act as input and output connections for data and controls to the Arduino. 

* Connect Neopixel pad labelled **+V** or **5V** to **5V** on the Arduino
* Connect Neopixel pad **-V** or **GND** to **GND** on the Arduino
* Connect Neopixel pad **Data In** to **Digital Pin 2** on the Arduino

I recommend that you use the breadboard and connect the Arduino power connections to the outer rows - this will make your 5V and GND rails easily accessible to any devices that require it. **Be careful that you do not connect 5V to GND at any point, this is a recipe for disaster!**

![neo connection](https://electricnoodlebox.files.wordpress.com/2018/08/neopixels_arduino_bb.png  "neo uno connection")

If you are using a strip or string of LEDs, you will most likely need to use a DC adaptor to provide enough power for the strip. Strips and strings in my experience use a generic 3-pin connector that you can join with breadboard jumper cables. Data is in the middle, and the input will be the female end connector. Sometimes you will have a red lead for V+ and a blue lead for V-, sometimes all the leads are black but V- will have a dotted line for indication. 

That's it, now we are ready to code!

### Basic Use:

Let's run a basic test, either open the Arduino IDE, open a new sketch and copy in the following code (or open the neopixel_basicexample sketch):

```cpp
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
```

Upload the code to the Arduino to see the results. If everything is working as expected then great! Now is a great time to experiment with the colour combination possibilities of the WS2812 LEDs. As mentioned, each WS2812 is a digital package that contains 3 LEDs, a red, green and blue LED specifically. We can control the brightness of each colour. There are just two core commands to pay attention to in the neopixel library;

```cpp
pixels.setPixelColor(n, pixels.Color(R, G, B));
```
This command presets a single WS2812 with a new colour setting (or off) where n is the Neopixel in the chain (counting up from 0) and R,G,B are the brightness levels of the 3 colours. Brightness goes from 0 (off) to 255 (brightest). This command alone only presets the LEDs, it doesn't actually make a change that we can see. In order to do that we need to follow with:

```cpp
pixels.show();
```

Try changing the colours in the example sketch now to see what the WS2812 is capable of. Be mindful that a brightness of 255 can be very bright!

Spend some time making a sequence of LEDs with the commands you now know. 

### Other notes:

Let's look at the other things included in this sketch before we move on.

```cpp
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
```

These lines tell the Arduino IDE to import the Adafruit library and a power management library that is required by the former - just copy and paste these lines into any Neopixel sketch that you create.

```cpp
  const byte neopin = 2; 
  const byte numleds = 8; 
```

These lines are creating two variables that let you define which pin your Neopixels are on and how many Neopixels are in your chain in total - the numleds variable can be very useful in creating algorithms to affect all of your pixels at once.

```cpp
  Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numleds, neopin, NEO_GRB + NEO_KHZ800);
```

This is an important line that sets up the Neopixel library - WS2811 Neopixels are often RGB ordered so change the line to say NEO_RGB. Notice that the two variables we created are used here as well.

```cpp
  pixels.begin();
```

This command is in void setup() and will initialise the Arduino hardware according to the library setup.