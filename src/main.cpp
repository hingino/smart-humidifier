#include "Config.h"
#include "Humidifier.h"
#include "WaterSensor.h"

Humidifier humidifier = Humidifier(HUMIDIFIER_PIN);
WaterSensor waterSensor = WaterSensor(WATER_SENSOR_PIN);
bool waterEmpty;
bool humidifierOn;

void setup() {
  Serial.begin(USB_BAUD);
  delay(LOOP_DELAY);

  pinMode(HUMIDIFIER_PIN, OUTPUT);
  pinMode(WATER_SENSOR_PIN, INPUT);

  humidifier.powerOff();

  analogReadResolution(12);

  log_v("Enabling onboard button.");
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  humidifierOn = humidifier.getHumidifierState();
  waterEmpty = waterSensor.getWaterState();

  if (waterEmpty && humidifierOn) {
    log_v("No water. Turning off humidifier.");
    delay(NO_WATER_DELAY);
    humidifier.powerOff();
    return;
  }

  if(waterEmpty) {
    log_v("Water empty. Awaiting refill.");
    delay(NO_WATER_DELAY);
    return;
  }

  if (digitalRead(BUTTON_PIN) == LOW)
  { 
    bool buttonHeld = 0;
    log_v("Push button pressed");
    delay(100);     // delay for key debounce 

    int startTime = millis();
    while (digitalRead(BUTTON_PIN) == LOW)
    {
      delay(50);
      if ((millis() - startTime) > BUTTON_MIN_HOLD)
      {
        buttonHeld = 1;
        log_v("Button is held!");
      }
    }
  
    if (buttonHeld) {
      return;
    }

    humidifier.powerToggle();
  }

  delay(LOOP_DELAY);
}
