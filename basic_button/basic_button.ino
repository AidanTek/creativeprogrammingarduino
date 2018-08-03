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
