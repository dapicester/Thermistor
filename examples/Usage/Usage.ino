/*
 * Thermistor library - usage.
 *
 * This library provides a simple API for the thermistors.
 * The default configuration assumes that a vultage divider
 * is used.
 * As a reference, please see the thermistor block
 * provided by FlamingoEda.
 *
 * Library written by Paolo D'Apice <paolo.dapice@gmail.com>
 *
 *  This code is in the public domain.
 */

// include the library code
#include <Thermistor.h>

const int sensorPin = A0;
float temperature;
int value;

// initialize thermistor object using default parameters
Thermistor sensor(sensorPin);

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // get the temperature
  temperature = sensor.temperature();
  // get also the sensor value (after the temperature)
  value = sensor.value();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("\tSensor: ");
  Serial.println(value);

  delay(500);
}

