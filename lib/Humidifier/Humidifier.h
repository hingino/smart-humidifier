#pragma once

#include <Arduino.h>

class Humidifier {
public:
  Humidifier() { };
  Humidifier(uint8_t Pin);
  ~Humidifier() { log_w("WARN: Humidifier destructor executed!"); };

  void powerOn();
  void powerOff();
  void powerToggle();
  
  bool getHumidifierState();

private:
  uint8_t pin;
  bool humidifierState = 1;

  void setButtonState(bool state);
};