#define DEVICE_UUID 1

// https://github.com/adafruit/DHT-sensor-library

#include "DHT.h"
#define DHTPIN 15
#define DHTTYPE DHT11

#include <WiFi.h>
const char ssid[] = "Galaxy Note10+5b9f";
const char pass[] = "tqwh6680";
int oldWifiStatus = WL_IDLE_STATUS;

#include <HTTPClient.h>
#define API "https://kent-iot-api.nathanm.fr/api/sensors"
#define API_BEARER "Bearer c617ccebb4b01836a9da70d9c63040d14600f001c054721ff9c6dd1d16cadc8f328c9bd2984c5ad0bb4a57cdcd5aef79502e93013160e0077b1ce95722f74426c9c76471097097fec91daf6efffd5d10a54343535b67b3f12b31b6da96339ce951f31c1647b211977f2b921d7429bc57acae90732fb82ef4494f5207f140096e"

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  wifiConnect();
  dht.begin();
}

void getHumiditySensorValues(void) {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  float heatIndex = dht.computeHeatIndex(temperature, humidity, false);

  Serial.print(humidity);
  Serial.print(" ");

  Serial.print(temperature);
  Serial.print(" ");

  Serial.println(heatIndex);
}

void wifiConnect(void) {
  Serial.println("Attempting to connect to WPA network...");

  if (WiFi.status() != WL_CONNECTED) {
    oldWifiStatus = WiFi.begin(ssid, pass);
  }
}

bool refreshWifiStatus(void) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Network Connection Error");
    delay(5000);
    wifiConnect();
    return false;
  } else if (WiFi.status() == WL_CONNECTED && oldWifiStatus != WL_CONNECTED) {
    Serial.println("Connection Recovered");
    oldWifiStatus = WL_CONNECTED;
    return true;
  }
}

const String getSensorPayload(int humidity, int temperature, int heatIndex) {
  String payload = String("{\"data\": {\"sensorID\": \"");

  payload.concat(DEVICE_UUID);
  payload.concat("\", \"humidity\": ");
  payload.concat(humidity);
  payload.concat(", \"temperature\": ");
  payload.concat(temperature);
  payload.concat(", \"heatIndex\": ");
  payload.concat(heatIndex);
  payload.concat("}}");

  Serial.println(payload);
  return payload;
}

void sendSensorData(void) {
  if ((WiFi.status() == WL_CONNECTED)) {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    float heatIndex = dht.computeHeatIndex(temperature, humidity, false);
    String payload = getSensorPayload(humidity, temperature, heatIndex);

    HTTPClient http;
 
    http.begin(API);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", API_BEARER);
    int httpCode = http.POST(payload);
 
    if (httpCode > 0) {
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end();
  }
}

void loop() {
  // Refresh WiFi status
  if (refreshWifiStatus() == false)
    return;
  //getHumiditySensorValues();
  sendSensorData();
  delay(5000);
}
