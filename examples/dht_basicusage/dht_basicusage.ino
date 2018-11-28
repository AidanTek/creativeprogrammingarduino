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
