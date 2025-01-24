#include "Humidifier.h"



Humidifier::Humidifier(uint8_t Pin) {
  pin = Pin;
}

void Humidifier::powerOn() {
  log_v("Starting humidifier power on...");

  setButtonState(1);

  log_v("Complete");
  return;
}

void Humidifier::powerOff() {
  log_v("Starting humidifier power off...");

  setButtonState(0);

  log_v("Complete");
  return;
}

void Humidifier::powerToggle() {
  log_v("Toggling power...");

  if (humidifierState) {
    setButtonState(0);
    return;
  }

  setButtonState(1);
  return;
}

bool Humidifier::getHumidifierState() {
  return humidifierState;
}

void Humidifier::setButtonState(bool state) {
  log_v("Setting button state to %d.", state);

  if (state == humidifierState) {
    log_v("Curent state = desired state. No change.");
    return;
  }

  if (state) {
    log_v("Turning on humidifier.");
    digitalWrite(pin, HIGH);
    humidifierState = 1;
    return;
  }

  log_v("Turning off humidifier.");
  digitalWrite(pin, LOW);
  humidifierState = 0;
  return;
}