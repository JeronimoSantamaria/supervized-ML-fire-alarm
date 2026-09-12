/*
  Multi-Sensor Read Testing Sketch
  Sensors: MQ2 (gas/smoke), MAX6675 + K-type Thermocouple, DHT11 (temp/humidity)
  Data is printed to the Serial Monitor every 5 seconds.

  Required Libraries (install via Library Manager):
  - "MAX6675 library" by Adafruit (or "max6675" by Rob Tillaart)
  - "DHT sensor library" by Adafruit (+ "Adafruit Unified Sensor" dependency)
*/

#include <max6675.h>
#include <DHT.h>

// Pin Definitions
// MQ2
#define MQ2_PIN 12        // analog pin for MQ2

// MAX6675
#define MAX6675_SCK_PIN 27   // SCK pin
#define MAX6675_CS_PIN  26   // CS pin
#define MAX6675_SO_PIN  25   // SO (MISO) pin

// DHT11
#define DHT_PIN 13          // digital pin for DHT11
#define DHT_TYPE DHT11

// Objects
MAX6675 thermocouple(MAX6675_SCK_PIN, MAX6675_CS_PIN, MAX6675_SO_PIN);
DHT dht(DHT_PIN, DHT_TYPE);

// Timing
const unsigned long READ_DELAY = 5000; // 5 seconds

void setup() {
  Serial.begin(9600);
  dht.begin();

  // MAX6675 needs a moment to stabilize after power-up
  delay(500);

  Serial.println("=== Sensor Monitoring Started ===");
}

void loop() {
  // MQ2
  int mq2Value = analogRead(MQ2_PIN);
  Serial.println("---- MQ2 Gas Sensor ----");
  Serial.print("Raw Analog Value: ");
  Serial.println(mq2Value);
  delay(READ_DELAY);

  // MAX6675 + K-type Thermocouple
  float tempC = thermocouple.readCelsius();
  float tempF = thermocouple.readFahrenheit();
  Serial.println("---- MAX6675 Thermocouple ----");
  if (isnan(tempC)) {
    Serial.println("Error reading thermocouple! Check wiring/connection.");
  } else {
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print(" C / ");
    Serial.print(tempF);
    Serial.println(" F");
  }
  delay(READ_DELAY);

  // DHT11
  float humidity = dht.readHumidity();
  float dhtTempC = dht.readTemperature();
  Serial.println("---- DHT11 Temp & Humidity ----");
  if (isnan(humidity) || isnan(dhtTempC)) {
    Serial.println("Error reading DHT11 sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(dhtTempC);
    Serial.print(" C   Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }
  Serial.println("================================");
  delay(READ_DELAY);
}
