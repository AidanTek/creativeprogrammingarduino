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
