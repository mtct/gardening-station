#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHT_SENSOR_TYPE DHT22
#define DHT_SENSOR_PIN  25
#define SOIL_SENSOR_1_PIN  33
#define SOIL_SENSOR_2_PIN  32
#define SOIL_SENSOR_3_PIN  35

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup() {
  Serial.begin(9600);
  dht_sensor.begin();
}

void loop() {
  // Read humidity from sensor
  float humidity  = dht_sensor.readHumidity();
  // Read temperature from sensor
  float temperature = dht_sensor.readTemperature();

  // Read soil resistance from first sensor
  int sensor1_soil_humidity = analogRead(SOIL_SENSOR_1_PIN);
  // Read soil resistance from second sensor
  int sensor2_soil_humidity = analogRead(SOIL_SENSOR_2_PIN);
  // Read soil resistance from third sensor
  int sensor3_soil_humidity = analogRead(SOIL_SENSOR_3_PIN);

  // check successful read of sensor values
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } 
  else {
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%");

    Serial.print("  |  ");

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("°C");

    Serial.print("\n");
  }

  if (isnan(sensor1_soil_humidity) || isnan(sensor2_soil_humidity) || isnan(sensor3_soil_humidity)) {
    Serial.println("Failed to read from soil sensors!");
  } 
  else{
    Serial.print("Soil humidity 1: ");
    Serial.print(sensor1_soil_humidity);

    Serial.print("  |  ");

    Serial.print("Soil humidity 2: ");
    Serial.print(sensor2_soil_humidity);

    Serial.print("  |  ");

    Serial.print("Soil humidity 3: ");
    Serial.print(sensor3_soil_humidity);

    Serial.print("\n");
  }

  // wait a 5 seconds between readings
  delay(5000);
}