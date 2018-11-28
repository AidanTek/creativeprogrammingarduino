## 08. Basic Control Input

Now you know how to make the Neopixels do some neat things, lets take a look at how we can manipulate them with physical controls. All of the following projects can be completed without solder by using breadboard and jumper wires. In this section, we are going to try two very common parts which are used for all kinds of commercial and industrial interfaces - buttons and knobs. We will also take a look at using the Arduino's Serial interface. Serial is a simple digital method of communicating data between devices and it is connected to the Arduino's USB port so we can use it to send data from a hardware project back to the computer.

---

### Button

The most simple form of hardware input to any computer is a button (at least that I can think of!). It is a classical component in computer and mechanical systems that of course is still in everyday use. The device itself is simply two separate conductive contacts, and then another piece of conductive material that will connect them when the button is pressed (usually mounted on a spring so it releases automatically). That is to say you have a circuit that is manually connected or disconnected.

![button_crosssection](https://electricnoodlebox.files.wordpress.com/2018/09/buttoncrosssection.png)

The following code demonstrates how to most easily get an input from a button, further wizardry can be applied to get better results, but worry about that later on! First, assemble the new part of the circuit as shown in the diagram. The kind of button shown should be oriented so that it comfortably fits across the groove in the middle of the breadboard. Two wires are required to connect back to the Arduino. One of these will connect one of the button contacts to ground or GND, the other needs to connect to a free digital pin on the Arduino. I chose digital pin 4 in this example:

![arduino_button](https://electricnoodlebox.files.wordpress.com/2018/08/neopixels_arduino_button_bb.png)

Let's jump straight in and test this input circuit with a simple program. Either type or copy the code below into the Arduino IDE or you can open the basic_button example from the repository. Upload the sketch to the Arduino when you are ready:

```cpp
/* Basic Push Button Example
 *  
 *  Connect the push button to the Arduino, you need 2 wires:
 *  - Connect one side of the button to GND
 *  - Connect the other side of the button to an unused digital pin, I used pin 4
 *  
 *  This sketch is a very simple example of how to read from a button. Once you
 *  have loaded the sketch, open the serial monitor by clicking the magnifying
 *  glass in the top right hand corner of the screen. The 1 and 0 shows the 
 *  button status in near real time. A boolean variable is used to store the
 *  value of the button, a boolean has one of 2 states, 1 or 0 (or true/false)
 *  
 *  We have to tell Arduino if a digital pin is an input or output, we can also
 *  use the INPUT_PULLUP command, this means the button value defaults to 1
 *  (not pressed) but means we don't need to use an external resistor.
 *  
 *  Example by Aidan Taylor. 2018. Cardiff Metropolitan University
 *  Released under a GPLv3 license
 */

const byte buttonpin = 4; // The pin used to read from the button

void setup() {
  Serial.begin(9600); // Start the serial monitor with 9600 baud rate

  pinMode(buttonpin, INPUT_PULLUP); // Tell Arduino that pin 4 is an input
}

void loop() {
  boolean buttonval; // variable used to store the button value

  buttonval = digitalRead(buttonpin); // write the state of pin 4 to variable

  // Print out the state:
  Serial.print("Button State = ");
  Serial.println(buttonval);

  delay(100); // slow things down so the serial monitor isn't flooded!
}
```
This sketch is fairly minimal, it constantly reads the state of digital pin 4 and reports it in something called the *Serial Monitor*. Digital pin 4 can have one of two input states, which are technically high or low voltage, we can think of this as *on* or *off*, *true* or *false* - or we can describe it the same way as a computer does with a *1* or *0* - all of these things are the same!

Open the Serial Monitor by clicking the large magnifying glass in the top right hand corner of the screen: ![serial_monitor](https://electricnoodlebox.files.wordpress.com/2018/09/serialmonitor_icon.png)

You should see a stream of 1's in the window that opens. When you press the button down the 1's become 0's. This is because the default state of digital pin 4 is "high" or "1" and pressing the button pulls it "low" to "0".

Take a look over the code now. When you want to use a digital pin for an input of some kind you need to tell Arduino that this is the case in order for it to work. This is achieved with the pinMode() command which sets a digital pin to be an input or output. The argument INPUT speaks for itself, the _PULLUP is an optional addition which guarantees that the normal state of the pin is "high", if you don't do this then you will need to do it with additional hardware instead, so doing it in code is easier! [There is more detailed information about this here](https://www.arduino.cc/en/Tutorial/DigitalPins).

```cpp
pinMode(buttonPin, INPUT_PULLUP);
```
To check the state of the button we use the digitalRead() command. This can be achieved in a number of ways, but here we immediately write the current state of the digital pin into the variable *buttonval*. buttonval is a *boolean* variable - it only ever has a state of 1 or 0, perfect for reading from a button!:

```cpp
buttonval = digitalRead(buttonPin);
```

We can now print the updated value stored in buttonval to the Serial Monitor. In order to use serial, we first had to activate Serial communication in void setup() with the Serial.begin() command. This command needs an argument included which is called the baud rate, for now you can think of this as the transfer speed, 9600 is a common rate to use. Note that the Serial Monitor needs to also be set to the same baud rate to work correctly:

```cpp
Serial.begin(9600);
```
Now we can send data back to the computer as the Arduino serial interface is connected to the USB port. This is achieved with the Serial.print() and Serial.println() commands. print() will print contents directly, and println() will print the contents and then move to a new line:

```cpp
Serial.print("This is a message ");
Serial.println("from the Arduino!");
```
Take a minute to read over the code again to take in these new commands.

Now let's do something more interesting with the button, the following sketch will trigger the Neopixels to start a sequence. Type or copy the code below into the Arduino IDE, or open the neopixel_triggeronpress sketch from the repository. Once you have entered the code, upload it to the Arduino and observe the results when you press the button:

```cpp
/* Neopixel (WS2812) Fade on Trigger Example
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  Connect the push button to the Arduino, you need 2 wires:
 *  - Connect one side of the button to GND
 *  - Connect the other side of the button to an unused digital pin, I used pin 4
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
 *  This sketch combines the push button example with the neopixel fade example. When the push button is 
 *  pressed, the fade will happen once. This is achieved using the if() function. if() is simple and 
 *  fundamental, you input an argument in the brackets, the if() checks if it is true and if it is then
 *  it will carry out the associated line(s) of code. Use parenthesis {} to specify a section of code for
 *  the if().
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

const byte buttonpin = 4; // The pin used to read from the button

const int delaytime = 10; // Parameter used to set the pace of the sketch

void setup() {
  pinMode(buttonpin, INPUT_PULLUP); // Tell Arduino that pin 4 is an input

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  boolean buttonval; // variable used to store the button value

  buttonval = digitalRead(buttonpin); // write the state of pin 4 to variable

  if(buttonval == 0) { // Remember that 0 is a registered press not 1!
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
}
```
You should be fairly comfortable with most of this code by now, but a new command is included which is fundamentally important in computing, the *"if"*. if() is used to make things happen in a program, but only if the contents of the accompanying argument turn out to be true. In the sketch we ask if the button is being pressed with the command:

```cpp
if(buttonval == 0) {
  // do something
}
```
The command translates as if the variable "buttonval" is equal to 0, then do this next section of code. Notice the use of { } brackets, the code we want to activate on button press needs to be associated and isolated with the if() command, if the test argument fails then that code will be skipped and the program will move on - make sense? Take a minute to read over the code again to take in what you have done.

---

### Potentiometer

Next let's take a look at another common and classic control which is the potentiometer. You may not have heard that name before, it is the proper name for a panel knob that might be used for something like a volume control on a stereo. The potentiometer is a control that allows us to dial in a precise setting. The control itself will allow you to adjust a voltage that can be measured by the Arduino, and the Arduino interprets this voltage as a number that can be used in a program. In this case, we need to use an *Analog* pin (note that analog is the Americanised spelling of analogue!). Digital pins can only switch between one of two states so they won't be practical for an input which can be more complicated than simply on or off. An analog pin can *sample* a changing voltage within a set range, so that is perfect for this kind of control.

Add the additional parts to the breadboard as shown below. You will need a potentiometer that can slot into the breadboard and three jumper wires. The potentiometer has three legs that need to cross three of the breadboard columns. Connect one of the outside legs of the potentiometer to GND and the opposite outer leg to 5V. The middle leg of the potentiometer is called the wiper and this is where the measurement is taken, connect this leg to the A0 pin on the Arduino:

![Arduino_Potentiometer](https://electricnoodlebox.files.wordpress.com/2018/08/neopixels_arduino_pot_bb.png)

Check over your connections before you provide power to the Arduino. The following Sketch is a basic example that will read the state of Analog Pin 0, store it in a variable and report it to the Serial Monitor, much like the earlier button Sketch. Type or copy the code below or open the basic_potentiometer sketch from the repository. Once you have entered the code, upload the sketch to the Arduino:

```cpp
/* Potentiometer Example
 *  
 *  Connect the 10k Potentiometer to the Arduino, you need 3 wires:
 *  - Connect the left leg to GND
 *  - Connect the right leg to 5V
 *  - Connect the middle pin to an unused Analog pin, I used A0
 *  
 *  The Arduino can also take a variable reading using its built in Analog input. Where
 *  digital will only ever be a value between 0 and 1, analog is more like 0% to 100%.
 *  The Analog pins actually measure voltage and have a range of 0V to 5V. The 
 *  potentiometer is a control that is typically used to change the "voltage potential"
 *  that is set by the difference in voltage on the outer legs. Turning the knob will
 *  adjust the voltage on the middle pin between those two points.
 *  
 *  Example by Aidan Taylor. 2018. Cardiff Metropolitan University
 *  Released under a GPLv3 license
 */

const byte potpin = A0;

void setup() {
  Serial.begin(9600); // start the serial monitor with 9600 baud rate

  // We don't need to configure analog pins!
}

void loop() {
  int potval; // create a variable to store the potentiometer reading

  potval = analogRead(potpin); // write the analog reading into the variable

  // Print out the value to the serial monitor:
  Serial.print("Pot value = ");
  Serial.println(potval);

  delay(100);
}
```
Open the Serial Monitor by pressing the magnifying glass in the corner of the IDE window: ![serial_monitor](https://electricnoodlebox.files.wordpress.com/2018/09/serialmonitor_icon.png)
Turn the potentiometer and watch the result on the computer screen.

Analog pins can only ever be inputs, so we don't need to use pinMode() as we do with a digital pin. In void loop we created a *int* variable type, this is a variable that can store a big number.

```cpp
int potval; 
```

Just as we did with the button, the next step is to store the state of the analog pin into the variable, this is achieved with the analogRead() command:

```cpp
potval = analogRead(potpin);
```

You should see in the Serial Monitor that the full range of the potentiometer turn is represented as a number between 0 and 1023, this is the maximum range of an analog pin and this corresponds to a voltage between 0V and 5V. Take a minute to read over the example sketch and take in these new commands.

Now let's do something interesting with the potentiometer, the following example uses the stored value of the potentiometer to adjust the brightness of the Neopixels. Type or copy the code below, or open the neopixel_setfadepotentiometer example from the repository. Once you have the code in the IDE, upload it to the Arduino:

```cpp
/* Neopixel (WS2812) Fade to Potentiometer Example
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  Connect the 10k Potentiometer to the Arduino, you need 3 wires:
 *  - Connect the left leg to GND
 *  - Connect the right leg to 5V
 *  - Connect the middle pin to an unused Analog pin, I used A0
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
 *  This sketch demonstrates how the potentiometer value can be used to change something, such as the LED
 *  brightness. The WS2812 LEDs have a brightness range of 0 to 255 for each colour - 255 is very bright!
 *  Here we introduce the map() function to change the potentiometer value to a suitable range for the 
 *  LEDs - notice the use of the maxbrightness variable below.
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

const byte potpin = A0;
const byte maxbrightness = 150;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  
}

void loop() {
  int potval; // create a variable to store the potentiometer reading
  byte ledval; // a variable to set the led brightness (this is only for articulation here!)

  potval = analogRead(potpin); // write the analog reading into the variable
  
  // map potval to a more suitable range
    // map() arguments work like this: map(variable, in low, in high, out low, out high)
  ledval = map(potval, 0, 1023, 0, maxbrightness);

  for(int i = 0; i < numleds; i++) {
    pixels.setPixelColor(i, pixels.Color(ledval,ledval,ledval)); // preset all LEDs
  }
  pixels.show(); // update all LEDs

  delay(delaytime);
}
```
Once the sketch has uploaded, try adjusting the potentiometer and observe the results. In order for this sketch to work, a couple of additional variables and a new command was required. You might remember that the maximum brightness of the Neopixels is the value 255, but the potentiometer has a range of 0 to 1023 - unless we do something about this, the raw value of the potentiometer will cause incorrect behaviour with the Neopixels.

A simple fix in this case would be to divide the potentiometer reading like so:

```cpp
potval = analogRead(potpin)
ledval = potval/4 
```
Because 1023/4 = 255.75 (but will result in 255 in Arduino). However, you will see that in the example this conversion is handled differently, in this case we used the map() command. map() takes an input number and *scales* it to a new range, this is a little more complicated to understand, but map() is a very flexible function that can be used to manipulate numbers in a range of ways. I also made a variable called maxbrightness (preset to 150) to limit the output range, as I find greater values to be too bright! 

```cpp
ledval = map(potval, 0, 1023, 0, maxbrightness);
```

map() has 5 arguments in total that are ordered like this: 1) the input number to scale 2) the low *input* range 3) the high *input* range 4) the low *output* range and 5) the high *output* range. 

To get an idea how map() works and to get a glimpse of how it is flexible, try changing the line like so:

```cpp
ledval = map(potval, 1023, 0, 0, maxbrightness);
```

Upload the sketch again and adjust the potentiometer - now the fade is reversed.

Moving on, notice that the new resulting variable "ledval" is used in the neopixel commands to change the brightness of the LEDs in real time. Take a moment to read over the sketch and take in these new commands.

---

### Experiments:

Try out these ideas to demonstrate that you understand how to connect hardware and write basic programs for it, are you ready for a challenge?! 

* Add a second button to the breadboard, pressing the second button activates a *different* Neopixel sequence.
* Use the potentiometer to change the speed of a Neopixel sequence
* Use the potentiometer and button together: Use the potentiometer to set the brightness of the Neopixels, but only update the brightness when the button is pressed
* Use three potentiometers to set the red, green and blue brightness of the Neopixels

---

### Further notes from this section:

* If you understand how a button works mechanically and electronically then you will see that it is very easy to be creative and create your own from scratch - you could create a switch that is activated by a closing door, or something that activates when a person sits on a chair cushion. Conductive paint and fabric also can be used to make buttons and switches without too much effort.
* "=" vs "==", what the heck?! "=" is actually very different to "==". It can be easy to mix up their use, and this can lead to some odd error messages! A single = sign actually means *replace* the left side with the right side, whereas two equals == means test if the left and right objects are equal:
```cpp
// Replace "buttonval" with the state of a digital pin:
buttonval = digitalRead(buttonPin);

// test if "buttonval" is the same as a value:
if(buttonval == 0) {
  // do something...
}
```
