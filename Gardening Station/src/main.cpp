#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHT_SENSOR_TYPE DHT22
#define DHT_SENSOR_PIN  25

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
    Serial.print("°C \n");
  }

  // wait a 5 seconds between readings
  delay(5000);
}