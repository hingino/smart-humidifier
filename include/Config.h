#pragma once

#include <Arduino.h>

#define CORE_DEBUG_LEVEL 5

// pin setup
#define BUTTON_PIN 9
#define HUMIDIFIER_PIN D6
#define WATER_SENSOR_PIN A1

// zigbee end device
#define SOC_IEEE802154_SUPPORTED
#define CONFIG_ZB_ENABLED

// serial connections
#define USB_BAUD 115200

// delay times (1000 = 1 sec)
#define LOOP_DELAY 100
#define BUTTON_MIN_HOLD 3000
#define NO_WATER_DELAY 2000
