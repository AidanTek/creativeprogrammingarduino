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
