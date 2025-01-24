#pragma once

#include <Arduino.h>

class WaterSensor {
public:
  WaterSensor() { }
  WaterSensor(uint8_t Pin);
  ~WaterSensor() { log_w("WARN: Humidifier destructor executed!"); }

  bool getWaterState();

private:
  uint8_t pin;
  uint8_t sensorVal;
  bool waterEmpty = 1;

  void updateWaterState();
};