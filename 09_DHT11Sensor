# 09. DHT-11 Sensor 

### Using the DHT-11 Digital Temperature and Humidity Sensor

The DHT-11 is a cheap (rightly so, don't expect scientific accuracy!) temperature and humidity sensor that is widely available. This page is designedto demonstrate how you can use the Arduino to process the input from the sensor to a visual output using the Neopixel leds.

The DHT-11 sensor can be connected to the Arduino like so, note that sometimes the sensor will be on a small pcb and the resistor will already be included:

![Arduino_DHT](https://electricnoodlebox.files.wordpress.com/2018/08/neopixels_arduino_dht_bb.png)

### Basic usage:

The code below demonstrates how to get a reading from the sensor and how to print it over serial. You can view the output in the Serial Monitor. [Make sure you have installed the library](https://github.com/AidanTek/creativeprogrammingarduino/wiki/Installation):

```cpp
/* DHT11 Temperature and Humidity Sensor Example
 *  
 *  Connect the DHT11 to the Arduino, you need 3 wires:
 *  - Connect + to 5V
 *  - Connect - to GND
 *  - Connect S to an unused digital pin, I used pin 7
 *  
 *  The DHT11 is a simple environmental sensor, with a digital interface. Using libraries provided by 
 *  Adafruit, it is easy to get a reading into Arduino. For usage, maintain the sketch as shown below.
 *  Use event.temperature and event.humidity as variables in your own programs.
 *  
 * The Unified Sensor Library was written by Tony DiCola for Adafruit Industries and is provided
 * under a Apache V2.0 license available here: http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Respect is due to Adafruit for their work on the Neopixel library.
 *  
 *  Example by Aidan Taylor. 2018. Cardiff Metropolitan University
 *  Released under a GPLv3 license
 */

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

const byte dhtpin = 7;
DHT_Unified dht(dhtpin, DHT11);

uint32_t sensordelay;

void setup() {
  Serial.begin(9600); 

  // These lines initialise the device:
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
  sensordelay = sensor.min_delay / 1000;
}

void loop() {
  // Delay between measurements.
  delay(sensordelay);
  
  // Get temperature event and print its value.
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if(isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
  }
  
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else {
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }
}
```

### A starting point

The code below demonstrates how you can convert the sensor reading to a visual display using the neopixels - it is by no means perfect! See what you can do to improve the program and experiment with the techniques you now know to see what else you can do!

```cpp
/* Neopixel (WS2812) Temperature gauge using DHT11
 *  
 *  Connect the Neopixel(s) to the Arduino, you need 3 wires:
 *  - Connect 5V to 5V
 *  - Connect GND to GND
 *  - Connect Din or DATAIN to an unused digital pin, I use pin 2
 *  
 *  Connect the DHT11 to the Arduino, you need 3 wires:
 *  - Connect + to 5V
 *  - Connect - to GND
 *  - Connect S to an unused digital pin, I used pin 7
 *  
 *  I have a strip of 8 WS2812 Neopixel LEDs, if you have more or less, change the numleds parameter below
 *  In this example sketch, the temperature reading from the DHT11 is used to set the red brightness of 
 *  the Neopixel LEDs. The map function is used to map the event.temperature variable to a useful range
 *  with the LEDs.
 *  
 * The Unified Sensor Library was written by Tony DiCola for Adafruit Industries and is provided
 * under a Apache V2.0 license available here: http://www.apache.org/licenses/LICENSE-2.0
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

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

const byte dhtpin = 7;
DHT_Unified dht(dhtpin, DHT11);

uint32_t sensordelay;

const byte maxbrightness = 150;

void setup() {
  Serial.begin(9600); 

  // These lines initialise the device:
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
  sensordelay = sensor.min_delay / 1000;

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  byte ledval; // a variable to set the led brightness (this is only for articulation here!) 
  
  // Delay between measurements.
  delay(sensordelay);
  
  // Get temperature event and print its value.
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if(isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
  }

  ledval = map(event.temperature, 0.0, 35.0, 0, maxbrightness);

  for(int i = 0; i < numleds; i++) {
    pixels.setPixelColor(i, pixels.Color(ledval,0,0)); // preset all LEDs
  }
  pixels.show(); // update all LEDs
  
}
```