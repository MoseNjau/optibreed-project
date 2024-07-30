#include <DHT.h>
#include <ESP8266WiFi.h>  // or <WiFi.h> for ESP32

#define DHTPIN 2
#define DHTTYPE DHT22
#define DOOR_SENSOR_PIN 3
#define VOLTAGE_SENSOR_PIN A0
#define RELAY_1_PIN 4
#define RELAY_2_PIN 5
#define RELAY_3_PIN 6
#define RELAY_4_PIN 7
#define BUZZER_PIN 8

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
const char* server = "your_server_ip";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(DOOR_SENSOR_PIN, INPUT_PULLUP);
  pinMode(RELAY_1_PIN, OUTPUT);
  pinMode(RELAY_2_PIN, OUTPUT);
  pinMode(RELAY_3_PIN, OUTPUT);
  pinMode(RELAY_4_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int doorState = digitalRead(DOOR_SENSOR_PIN);
  int voltage = analogRead(VOLTAGE_SENSOR_PIN) * (5.0 / 1023.0) * (voltage_divider_ratio); // Adjust based on voltage divider ratio

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Send data to server
  if (client.connect(server, 80)) {
    String url = "/log_data.php?temperature=" + String(temperature) + "&humidity=" + String(humidity) + "&door=" + String(doorState) + "&voltage=" + String(voltage);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + server + "\r\n" + "Connection: close\r\n\r\n");
    client.stop();
  }

  // Receive instructions from server
  if (client.connect(server, 80)) {
    client.print("GET /get_instructions.php HTTP/1.1\r\nHost: " + String(server) + "\r\nConnection: close\r\n\r\n");
    while (client.available()) {
      String line = client.readStringUntil('\r');
      // Parse the instructions from the server
      if (line.startsWith("RELAY_1:")) {
        int state = line.substring(8).toInt();
        digitalWrite(RELAY_1_PIN, state);
      } else if (line.startsWith("RELAY_2:")) {
        int state = line.substring(8).toInt();
        digitalWrite(RELAY_2_PIN, state);
      } else if (line.startsWith("RELAY_3:")) {
        int state = line.substring(8).toInt();
        digitalWrite(RELAY_3_PIN, state);
      } else if (line.startsWith("RELAY_4:")) {
        int state = line.substring(8).toInt();
        digitalWrite(RELAY_4_PIN, state);
      } else if (line.startsWith("BUZZER:")) {
        int state = line.substring(7).toInt();
        digitalWrite(BUZZER_PIN, state);
      }
    }
    client.stop();
  }

  delay(60000); // Send data every minute
}
