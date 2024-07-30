<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "sensor_data";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

// Get the latest sensor readings
$result = $conn->query("SELECT * FROM readings ORDER BY timestamp DESC LIMIT 1");
$row = $result->fetch_assoc();

$temperature = $row['temperature'];
$humidity = $row['humidity'];
$voltage = $row['voltage'];

// Get user-defined thresholds
$result = $conn->query("SELECT * FROM thresholds WHERE id = 1");
$row = $result->fetch_assoc();

$minTemp = $row['min_temperature'];
$maxTemp = $row['max_temperature'];
$minHumidity = $row['min_humidity'];
$maxHumidity = $row['max_humidity'];
$minVoltage = $row['min_voltage'];
$maxVoltage = $row['max_voltage'];

// Generate instructions
$instructions = "";

if ($temperature < $minTemp) {
  $instructions .= "RELAY_1:1\n"; // Turn on heater
} else {
  $instructions .= "RELAY_1:0\n"; // Turn off heater
}

if ($temperature > $maxTemp) {
  $instructions .= "RELAY_2:1\n"; // Turn on fan
} else {
  $instructions .= "RELAY_2:0\n"; // Turn off fan
}

if ($humidity < $minHumidity) {
  $instructions .= "RELAY_3:1\n"; // Turn on humidifier
} else {
  $instructions .= "RELAY_3:0\n"; // Turn off humidifier
}

if ($humidity > $maxHumidity) {
  $instructions .= "RELAY_4:1\n"; // Turn on dehumidifier
} else {
  $instructions .= "RELAY_4:0\n"; // Turn off dehumidifier
}

if ($voltage < $minVoltage || $voltage > $maxVoltage) {
  $instructions .= "BUZZER:1\n"; // Turn on buzzer
} else {
  $instructions .= "BUZZER:0\n"; // Turn off buzzer
}

echo $instructions;

$conn->close();
?>
