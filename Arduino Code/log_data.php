<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "sensor_data";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$temperature = $_GET['temperature'];
$humidity = $_GET['humidity'];
$door = $_GET['door'];
$voltage = $_GET['voltage'];

$sql = "INSERT INTO readings (temperature, humidity, door, voltage, timestamp) VALUES ('$temperature', '$humidity', '$door', '$voltage', NOW())";

if ($conn->query($sql) === TRUE) {
  echo "New record created successfully";
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
