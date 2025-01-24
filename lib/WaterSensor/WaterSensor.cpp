#include "WaterSensor.h"

WaterSensor::WaterSensor(uint8_t Pin) {
  pin = Pin;
}

bool WaterSensor::getWaterState() {
  updateWaterState();
  return waterEmpty;
}

void WaterSensor::updateWaterState() {
  sensorVal = analogRead(pin);
  log_v("Sensor val: %d", sensorVal);

  if (sensorVal < 20) {
    log_v("Water detected");
    waterEmpty = 0;
    return;
  }

  log_v("Water not detected");
  waterEmpty = 1;
  return;
}