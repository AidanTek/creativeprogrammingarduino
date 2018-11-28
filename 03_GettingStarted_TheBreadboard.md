# 03. Getting Started: The Breadboard

In this section we are going to expand on blink a bit further by using some external LEDs. The purpose of this section is to introduce you to connecting circuits to the Arduino and using a breadboard.

## The Breadboard

The breadboard is a simple device that is designed for prototyping electronic circuits. Building circuits is complicated and requires some patience to learn about - but the breadboard itself is very simple! They come in a variety of shapes and sizes but mostly will be some close variation on the graphic below:

![Breadboard image](https://electricnoodlebox.files.wordpress.com/2018/09/breadboard.jpg)

A breadboard is nothing more than a set of strips of conductive material that are separated underneath a piece of moulded plastic. The conductive strips are arranged in rows and columns. The two rows on either side of the board are normally made up by a single piece of metal per row that runs horizontally across the entire length of the board (beware, some larger boards will have a break in the middle). The rows do not connect to each other at any point. The columns work in a similar manner, they are arranged in groups of 5 holes running vertically in the centre of the board. The groove in the middle of the breadboard breaks the columns so they do not run across the entire width of the board. 

I know this is a lot to take in, but remember to refer back to this any time you need to if you are unsure. The diagram below highlights where all the conductive material is positioned:

![Breadboard Links](https://electricnoodlebox.files.wordpress.com/2018/09/breadboardconnect.jpg)

## Power Supply basics

The rows on a breadboard are normally used to connect the power supply of a circuit. This is because you often need to connect the power supply to several points in the circuit. In a standard DC circuit (direct current) as we will be using throughout these tutorials, the power supply will have a positive (+) and negative (-) terminal, just like the terminals of a battery. These terminals represent a voltage difference and every circuit needs some difference in voltage in order to work. We will be building circuits that have a positive of 5 volts or **+5V** and a negative of 0 volts which we will refer to as Ground or **GND**. The Arduino itself can act as the power supply, behaving just like a battery pack, as it can share the 5 volts provided by the USB connection. Using the USB connection for power has some limitations, but is more than sufficient for all of the circuits covered in these tutorials.

When you plug a component or a signal like a DC voltage into a row or column of a breadboard, that entire row/column becomes an extension of your connection. This makes it like a miniature junction box, you can easily split a row or column to another just by adding a wire between them.

The diagram below shows how you can connect the Arduino to the breadboard to share the 5 volt power supply:

![Arduino as PSU](https://electricnoodlebox.files.wordpress.com/2018/09/arduinopsu.jpg)


## Building a Circuit 

Let's make a very simple circuit - add an external LED to the Arduino. We will connect it to Digital Pin 13, which is the same pin used for the internal LED. Any sketches you made in the previous section will work the same, but will light up the external LED.

The LED has two legs, the longer leg is called the anode and the shorter is the cathode. The basic operation can be described like this: when the anode is *more positive* in voltage than the cathode, the LED will light up. We also need a resistor for this circuit, a 470ohm will be perfect - but a near value will be fine.

* Plug the LED into the breadboard so the legs cross two columns, remember which side is the anode and which is the cathode. 
* Connect a wire from Digital Pin 13 to the column that connects the anode of the LED. This is the same as directly connecting the anode to Digital Pin 13.
* Connect the resistor from the cathode column of the LED to the **GND** row on the breadboard - this is the same as connecting the resistor directly to GND on the Arduino.

n.b the resistor does not have polarity like the LED, you can connect it either way.

![Arduino LED](https://electricnoodlebox.files.wordpress.com/2018/09/arduinoextled.jpg)

Once you have built this circuit, try running any of your sketches from the previous section. You should see the external LED light up along with the internal LED - if it doesn't then check over your connections and make sure you didn't plug in the LED back to front!

## Two LEDs 

Let's add a little more complexity by adding a second LED. This part of the circuit will work exactly the same way except we should try using a separate digital pin - this way we can control each LED individually.

Try connecting a new LED to Digital Pin 12 by following the diagram below:

![Twoleds](https://electricnoodlebox.files.wordpress.com/2018/09/arduinotwoled.jpg)

Try this basic program to light them up in a sequence, notice we need to have a separate variable for the second LED, and we also need to tell Arduino that Digital Pin 12 will behave as an output by announcing this with pinMode() in void setup():

```cpp
/* Blink for two LEDs example
 *  
 *  Connect two external LEDs to the Arduino Uno. One LED is connected
 *  by anode (long leg) to Digital Pin 12, and the other to Digital Pin 13.
 *  A resistor should be used to connect the cathode (short leg) of each
 *  LED to GND.
 *  
 *  Example by Aidan Taylor. 2018. Cardiff Metropolitan University
 *  Released under a GPLv3 license
 */

// We can refer to each digital pin with a sensible name:
const byte led1pin = 13;
const byte led2pin = 12;

// Some variables for the loop:
int ontime = 200;
int offtime = 500;

void setup() {
  // Tell Arduino the digital pins are outputs:
  pinMode(led1pin, OUTPUT);
  pinMode(led2pin, OUTPUT);
}

void loop() {
  digitalWrite(led1pin, HIGH); // Turn on LED 1
  delay(ontime); // wait a set time in ms

  digitalWrite(led1pin, LOW); // Turn off LED 1
  delay(offtime); // wait a set time in ms
  
  digitalWrite(led2pin, HIGH); // Turn on LED 2
  delay(ontime); // wait a set time in ms

  digitalWrite(led2pin, LOW); // Turn off LED 2
  delay(offtime); // wait a set time in ms

  digitalWrite(led1pin, HIGH); // Turn on LED 1
  digitalWrite(led2pin, HIGH); // Turn on LED 2
  delay(ontime); // wait a set time in ms

  digitalWrite(led1pin, LOW); // Turn off LED 1
  digitalWrite(led2pin, LOW); // Turn off LED 2
  delay(offtime); // wait a set time in ms
}
```

Upload the code to the Arduino to see the results.

## Things to try:

* Try making your own sequence of blinks with different timed delays
* Try adding a third LED and add this to your sketch
* Below is another sketch for two LEDs, but it has a number of errors. Try fixing the errors to make the program run:

```cpp
/* Blink for two LEDs example
 *  
 *  Connect two external LEDs to the Arduino Uno. One LED is connected
 *  by anode (long leg) to Digital Pin 12, and the other to Digital Pin 13.
 *  A resistor should be used to connect the cathode (short leg) of each
 *  LED to GND.
 *  
 *  Example by Aidan Taylor. 2018. Cardiff Metropolitan University
 *  Released under a GPLv3 license
 */

// We can refer to each digital pin with a sensible name:
const byte led1pin = 13
const byte led2pin = 12

// Some variables for the loop:
int ontime = 200;
int offtime = 500;

void setup() {
  // Tell Arduino the digital pins are outputs:
  pinMode(led1pin, OUTPUT);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  digitalWrite(led1pin, HIGH); 
  delay(ontime);

  digitalWrite(led1pin, LOW); 
  delay(offtime); 
  
  digitalWrite(led2pin, HIGH); 
  delay(ontime); 

  digitalWrite(led2pin, LOW);
  delay(offtime) 

  digitalWrite(led1pin, HIGH); 
  delay(ontime); 
  digitalWrite(led1pin, LOW); 
  delay(ontime); 
  digitalWrite(ledpin, HIGH);
  delay(ontime);
  digitalWrite(led1pin, LOW); 
  delay(ontime); 

  digitalWrite(led2pin, HIGH); 
  delay(ontime); 
  digitalWrite(led2pin, LOW); 
  delay(ontime); 
  dgitalWrite(led2pin, HIGH);
  delay(ontime);
  digitalWrite(led2pin, LOW); 
  delay(ontime); 
}
```




