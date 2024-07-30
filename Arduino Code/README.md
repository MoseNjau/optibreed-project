# IoT-Based Environmental Monitoring and Control System

This project involves an IoT-based system to monitor and regulate environmental conditions such as temperature, humidity, door status, and voltage levels. The system consists of an Arduino for data acquisition, a backend server for processing, a database for storage, and a web application for user interaction.

## Table of Contents
1. [Overview](#overview)
2. [Hardware Components and Connections](#hardware-components-and-connections)
3. [Arduino Code Functionality](#arduino-code-functionality)
4. [Backend PHP Scripts](#backend-php-scripts)
   - [log_data.php](#log_dataphp)
   - [get_instructions.php](#get_instructionphp)
5. [Web Application](#web-application)
6. [Summary](#summary)

## Overview

By separating the data acquisition from the control logic, the system becomes more flexible and easier to maintain. The Arduino collects data from the sensors and sends it to the server. The server processes the data, applies the user-defined thresholds, and sends back instructions to the Arduino for regulating the conditions. The database stores the sensor data and user-defined thresholds. Communication between the Arduino and the server is handled using HTTP requests.

## Hardware Components and Connections

- **Arduino Uno** (or ESP8266/ESP32)
- **DHT22 Sensor** (for temperature and humidity)
- **Door Sensor** (e.g., magnetic switch)
- **Voltage Sensor** (e.g., voltage divider)
- **Relay Module** (for controlling actuators)
- **Buzzer** (for alerts)
- **WiFi Module** (if using Arduino Uno, otherwise use ESP8266/ESP32)

### Connections
1. **DHT22 Sensor**:
    - VCC to 5V
    - GND to GND
    - Data to D2
2. **Door Sensor**:
    - One end to GND
    - Other end to D3 (with internal pull-up resistor)
3. **Voltage Sensor**:
    - VCC to voltage source
    - GND to GND
    - Analog output to A0
4. **Relay Module**:
    - IN1 to D4 (Heater)
    - IN2 to D5 (Fan)
    - IN3 to D6 (Humidifier)
    - IN4 to D7 (Dehumidifier)
    - VCC to 5V
    - GND to GND
5. **Buzzer**:
    - Positive to D8
    - Negative to GND

## Arduino Code Functionality

The Arduino is responsible for:
- Collecting data from the DHT22 sensor (temperature and humidity), door sensor, and voltage sensor.
- Sending the collected data to the server via HTTP requests.
- Receiving control instructions from the server based on the user-defined thresholds and acting accordingly (e.g., turning on/off relays for heater, fan, humidifier, and dehumidifier, and activating/deactivating the buzzer).

## Backend PHP Scripts

### log_data.php

This script is responsible for:
- Receiving sensor data from the Arduino.
- Logging the received data into the MySQL database, including temperature, humidity, door status, and voltage levels.

### get_instructions.php

This script is responsible for:
- Retrieving the latest sensor readings from the database.
- Comparing the sensor readings with user-defined thresholds stored in the database.
- Generating control instructions based on the comparisons (e.g., turn on/off specific relays or the buzzer).
- Sending these control instructions back to the Arduino.

## Web Application

### User Interface
- Provides a form for users to enter and update min/max values for temperature, humidity, and voltage.

### Database
- Stores sensor readings and user-defined thresholds in appropriate tables.

### Backend Logic
- Updates the thresholds in the database based on user inputs from the web interface.

## Summary

- **Arduino**: Collects data from sensors, sends it to the server, and receives control instructions.
- **Backend**: Processes sensor data, compares it with user-defined thresholds, and sends instructions back to the Arduino.
- **Database**: Stores sensor readings and user-defined thresholds.
- **Web Application**: Allows users to set and update thresholds.

This approach decouples data collection and control logic, making the system more flexible and easier to manage.
