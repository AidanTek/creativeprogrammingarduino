# 06. Neopixels: Using Loops

### Getting to grips with loops:

Loops are very important and powerful in software programming, besides the functional benefit they offer, if you understand how to use them then you can save having to write out repetitive lines of code. We already did this in the previous section when we activated the Neopixels, you may have noticed that commands were contained in a function called for():

```cpp
for(int i = 0 ; i < numleds; i++) {
    pixels.setPixelColor(i, pixels.Color(100,100,100)); // This command presets one LED at a time
  }
```
The for() loop is designed to repeat something by a set number of times, without the loop, the equivalent solution to the above would look like this (numleds == 8 in the previous example):
```cpp
pixels.setPixelColor(0, pixels.Color(100,100,100)); // This command presets one LED at a time
pixels.setPixelColor(1, pixels.Color(100,100,100)); // This command presets one LED at a time
pixels.setPixelColor(2, pixels.Color(100,100,100)); // This command presets one LED at a time
pixels.setPixelColor(3, pixels.Color(100,100,100)); // This command presets one LED at a time
pixels.setPixelColor(4, pixels.Color(100,100,100)); // This command presets one LED at a time
pixels.setPixelColor(5, pixels.Color(100,100,100)); // This command presets one LED at a time
pixels.setPixelColor(6, pixels.Color(100,100,100)); // This command presets one LED at a time
pixels.setPixelColor(7, pixels.Color(100,100,100)); // This command presets one LED at a time
```

Much less efficient right? But what just happened??

I often say remember for() as asking the program to "do this *for()* this many times", but the argument really says "repeat this code until *this argument* becomes *true*.

The above example usage of for() is quite typical, there are three arguments included, a number to start with a.k.a. the *initialiser*, a *condition* and then an *increment* to the initialiser. The for() will loop until the test is successful (true). Take another look at for() from the example above:

* **int i = 0;** create a new "int" called i and start at 0 **the initialiser**
* **i < numpixels;** is i less than *numpixels* variable? true/false **the test or condition**
* **i++** shorthand way to write add 1 to i (the code is run first) **the increment** - after this takes place the condition is tested again.

![Arduino For](https://startingelectronics.org/software/arduino/learn-to-program-course/07-for-loop/for-loop-parts.png) 
*Image from startingelectronics.org*

A couple of things to remember, but well worth learning as for() is extremely useful for all kinds of things!

[More detail can be found in the Arduino Reference](https://www.arduino.cc/reference/en/language/structure/control-structure/for/)

### Using Loops to Control Neopixels:

Let's take a look at some of the other Neopixel sketches provided in this repository. Open a new window in Arduino and copy the following code in (or open the neopixel_basicloopexample sketch):

```cpp
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
```
Upload the code and have a look at the results - now we are getting into more interesting stuff! Let's quickly unpack some of these commands:

```cpp
for(int i = 0; i < numleds; i++) 
```
This for() function is built like so: make a new variable "i", check if "i" is less than "numleds", if this is **true** then do the code, then add 1 to "i" and test it again. If "i" is **not** less than "numleds" then stop looping and move on. 

Remember what "numleds" is for? We use it to tell Arduino how many LEDs are in total are in the chain. That way if we have 1000 LEDs, we only have to change the value of "numleds" to light them all up in the same way!

Something interesting happens next, the variable "i" is also utilised as an operator in the loop itself:

```cpp
pixels.setPixelColor(i, pixels.Color(100,100,100));
```

Remember what this function does? The first argument in the brackets "i" is telling Arduino which LED to preset with a new colour. As the for() loop iterates so the value of "i" is changed, a different LED will be addressed. Here is the complete loop:

```cpp
for(int i = 0; i < numleds; i++) {
    pixels.setPixelColor(i, pixels.Color(100,100,100)); // This command presets one LED at a time
    pixels.show(); // This sends the updated pixel color to all preset LEDs
    delay(delaytime);
  }
```

What happens if you move pixels.show() and delay(delaytime) to lines after the }?

### Loop the loop!

What happens if we place a for() loop within a for() loop? Let's find out! - Open a new sketch in the IDE and copy the following code in (or open the neopixel_looptheloop example):

```cpp
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
    for(int n = 0; n < numleds; n++) { // This is an inner loop
      pixels.setPixelColor(n, pixels.Color(0,0,0)); // This command presets one LED at a time
    }
    pixels.setPixelColor(i, pixels.Color(100,100,100)); // Now turn the next LED on
    pixels.show(); // This sends the updated pixel color to all preset LEDs
    delay(delaytime);
  }
}
```

Upload the code to the Arduino and check out the results!

### Fade Effect

As we can control the brightness of each LED (values from 0 - 255) we can also use a loop to adjust the brightness over time for attractive fade effects. There are a couple of ways to achieve this, here is one to try out - you can either copy the code to a new sketch or open the repository example "neopixel_fade":

```cpp
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
    for(int x = 0; x < numleds; x++) { // This is the inner loop
      pixels.setPixelColor(x, pixels.Color(i,i,i)); // Preset each LED with current fade brightness
    }
    pixels.show(); // This sends the updated pixel color to all preset LEDs
    delay(delaytime);
  }
  
  for(int i = 100; i > 0; i--) {
    for(int x = 0; x < numleds; x++) { 
      pixels.setPixelColor(x, pixels.Color(i,i,i)); 
    }
    pixels.show();
    delay(delaytime);
  }
    
}
```

Upload the code to the Arduino and check out the results. Try to read through the code to see how the for() loop has been exploited to achieve the fade. Try tweaking some of the values to achieve different brightnesses and different fade effects.

So now you have learned some powerful tools which you can go on to conquer the world with, it is time to experiment! If you need some inspiration, why not try the following challenges:

* Light up each led in order with a colour, then light up each led in reverse order with another!
* Fade in and out one colour, then fade in and out with another colour
* Make the Neopixels fade in and out, make the duration of each fade a little faster than the last
* Make the Neopixels fade in and out, each fade cycle gets a little brighter
* Fade/Blend from one colour to another - this is a bit harder! See if you can figure it out
* Make a moving and repeating pattern of LEDs with two or more colours

Most importantly - have fun. Remember that Neopixels can be purchased for making projects in a number of forms - you can get flexible panels, waterproof strips, individual 5mm packages like standard LEDs, sewable boards and more!