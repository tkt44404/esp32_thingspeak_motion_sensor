# ESP32 PIR Motion Sensor → ThingSpeak IoT Project

## Overview
This project uses an ESP32 microcontroller with a PIR motion sensor to detect motion and send real-time data to ThingSpeak for cloud monitoring and visualization.

When motion is detected, the ESP32 sends a signal to a ThingSpeak channel, allowing remote tracking and logging of activity over time.


## Features
- PIR motion detection (digital input)
- ESP32 WiFi connectivity
- Real-time data upload to ThingSpeak
- Motion event logging in the cloud
- Cooldown timer to prevent spam updates
- Simple and expandable IoT structure

---

## Hardware Required
- ESP32 development board
- PIR motion sensor (HC-SR501 or similar)
- Jumper wires
- Breadboard (optional)
- USB cable

## Security

This project uses a local config file for sensitive credentials.

- `config_example.h` → template (safe to upload)
- `config.h` → contains secrets (ignored by Git via .gitignore)

ESP32-PIR-ThingSpeak/
│
├── main.ino
├── config.example.h (template - safe to upload)
├── config.h ( DO NOT upload)
├── README.md

Configuration Setup

### Step 1: Create your config file
Copy the example file:
### Step 1: Create your config file

Copy the example configuration:

[config_example.h](./config_example.h) -> Rename it to: config.h

Fill in your credentials
#define WIFI_SSID "YourWiFiName"
#define WIFI_PASS "YourWiFiPassword"
#define API_KEY "YourThingSpeakWriteAPIKey"
#define SERVER "YourThingSpeakServerURL"


