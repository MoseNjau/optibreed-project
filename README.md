# IoT-Based Environmental Monitoring and Control System

This project is an IoT-based solution for monitoring and regulating storage conditions for breeding materials. The system includes a web application for user interaction, a backend server for processing data, an Arduino for sensor readings and control, and a database for storing sensor data and user-defined thresholds.

## Table of Contents
1. [Overview](#overview)
2. [Project Structure](#project-structure)
3. [How It Works](#how-it-works)
4. [Setup](#setup)
   - [Step 1: Clone the Repository](#step-1-clone-the-repository)
   - [Step 2: Open the Web Application](#step-2-open-the-web-application)
5. [Contributors](#contributors)

## Overview

The system monitors temperature, humidity, door status, and voltage levels in storage rooms. It automatically regulates these conditions based on user-defined thresholds to ensure optimal storage conditions. The system also sends alerts if conditions go beyond acceptable ranges.

## Project Structure

- **Application-code**: Contains the web application code.
- **Website**: Contains information about our solution for monitoring storage conditions for breeding materials.
- **Arduino Code**: Contains the code for the Arduino responsible for sensor readings and control.

## How It Works

1. **Arduino**: The Arduino collects data from sensors (temperature, humidity, door status, and voltage levels) and sends it to the backend server. It also receives control instructions from the server to regulate conditions via relays and a buzzer.

2. **Backend Server**: The server processes the sensor data, compares it with user-defined thresholds, and generates control instructions for the Arduino. It also logs sensor data into a database.

3. **Database**: The database stores sensor readings and user-defined thresholds.

4. **Web Application**: The web application allows users to set and update thresholds for temperature, humidity, and voltage levels. Users can also view current and historical sensor data.

### Arduino Code Functionality

- Collects data from sensors.
- Sends sensor data to the server.
- Receives control instructions from the server and acts accordingly.

### Backend PHP Scripts

#### log_data.php

- Receives sensor data from the Arduino.
- Logs the received data into the MySQL database.

#### get_instructions.php

- Retrieves the latest sensor readings from the database.
- Compares the sensor readings with user-defined thresholds.
- Generates control instructions and sends them back to the Arduino.

### Web Application

- Provides a form for users to enter and update min/max values for temperature, humidity, and voltage.
- Stores these thresholds in a database table.
- Updates the thresholds based on user inputs.

## Setup

### Step 1: Clone the Repository

Download or clone this repository by using the command given below:

```
https://github.com/MoseNjau/optibreed-project/
```

## Contributors <a id="contributors"></a>

- Moses Njau  
  [![Github](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/MoseNjau)
- Rotich Kibet  
  [![Github](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Kibet-Rotich)
- Sifa Collins  
  [![Github](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/SifaKasena)
- Kevin Mwirigi  
  [![Github](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/MykOnTV)
- Christine Nyaga  
  [![Github](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/KristyNyaga)