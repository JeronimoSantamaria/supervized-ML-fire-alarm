/*
  Data reading and saving Sketch (temporarily using a local CSV file to manage data)
  Sensors: MQ2 (gas/smoke), MAX6675 + K-type Thermocouple, DHT11 (temp/humidity)
  Data is saved to a csv file every 5 seconds.

  Required Libraries (install via Library Manager):
  - "MAX6675 library" by Adafruit (or "max6675" by Rob Tillaart)
  - "DHT sensor library" by Adafruit (+ "Adafruit Unified Sensor" dependency)
*/

#include <max6675.h>
#include <DHT.h>

// Pin Definitions
// MQ2
#define MQ2_PIN 12          // analog pin for MQ2

// MAX6675
#define MAX6675_SCK_PIN 27   // SCK pin
#define MAX6675_CS_PIN  26   // CS pin
#define MAX6675_SO_PIN  25   // SO (MISO) pin

// DHT11
#define DHT_PIN 13           // digital pin for DHT11
#define DHT_TYPE DHT11

// Objects
MAX6675 thermocouple(MAX6675_SCK_PIN, MAX6675_CS_PIN, MAX6675_SO_PIN);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  // MAX6675 needs a moment to stabilize after power-up
  delay(500);
}

void loop() {
  // MQ2
  int mq2Value = analogRead(MQ2_PIN);
  // MAX6675 + K-type Thermocouple
  float tempC = thermocouple.readCelsius();
  // DHT11
  float humidity = dht.readHumidity();

  if (isnan(tempC)) {
    Serial.println("Error reading thermocouple! Check wiring/connection.");
  }
  if (isnan(humidity)) {
    Serial.println("Error reading DHT11 sensor!");
  }
  else {;}

  // Creates a CSV string and prints it to the serial monitor to be read 
  String CSVstring = String(mq2Value) + ","
                    + String(tempC) + ","
                    + String(humidity);
  Serial.println(CSVstring);
  
  delay(5000); // wait 5s for the next reading
}
