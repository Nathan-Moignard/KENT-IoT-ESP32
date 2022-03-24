// https://github.com/adafruit/DHT-sensor-library
const char[] CERT = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIGdzCCBV+gAwIBAgISBFjGLJ5tqLRY5BtdlBBLXXuGMA0GCSqGSIb3DQEBCwUA" \
"MDIxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBFbmNyeXB0MQswCQYDVQQD" \
"EwJSMzAeFw0yMjAxMzEyMjIzNDJaFw0yMjA1MDEyMjIzNDFaMBUxEzARBgNVBAMT" \
"Cm5hdGhhbm0uZnIwggIiMA0GCSqGSIb3DQEBAQUAA4ICDwAwggIKAoICAQDj0us3" \
"87kTxpRHV3KVqfpzFF5wsnvds6C/vkVaQZi1HHyQSzz4/BV3gb+wuza0xIQrectU" \
"IEkbCktVRsJuLy/xyP+tRrXrxRn3nmvmIJ4EMZE8/63ei8Ta87yZK+WglNtftqCD" \
"CjjVaehv4lsINB3TwI3wN5yhswUG+Lt7mkDXClWPcR61fUxUC54ywrczPLtTWoWb" \
"4NpN4KQ3ZR4MpLz8STDdOgQBS/+g2uyYrnqj7VqpJzWQrwLd2VBE4czmXUf5RITZ" \
"u6U72bYgLOMNUxZKDudbDNddDSpjXFyLXkPqmy6qXC4UY1cVFsCmZzLSGZsV4lOv" \
"TUwZB4kfFjzpN48+9n7fo0VgkbvhnrjOTnE9rjmeC42/qJ84GKoH61RvkyU8roqI" \
"dhqCvBs4voTpSc5ur4Hnc/gwcMbMN3vTelC+KFj6Lf8Gj7VTZZin+0bVP2bU4g3K" \
"OTEIA4z8w5H0uvosccEdgeSpG7kpNCNnLeB0vzQWngCsdA7k4OTzhkISAEDbYlkY" \
"goRCnaPG0LIYeSai+61EJUAk2qIUMQ8zk1ROoJn9cqg2X3aPsxVQJnpwZeoUt0XB" \
"dLxJP4rZ8i5t8uZe6dkmaJutxhPGKwjLb25aK/0PnlvSQr5xnVDgpfkOeu45u3vR" \
"rxDOKRVCA96+sz8gM6vgj6lGSkFEHp3Gi9+vNQIDAQABo4ICojCCAp4wDgYDVR0P" \
"AQH/BAQDAgWgMB0GA1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcDAjAMBgNVHRMB" \
"Af8EAjAAMB0GA1UdDgQWBBQwUgG4qB6vBZk0/Vndi4SnTPmvPDAfBgNVHSMEGDAW" \
"gBQULrMXt1hWy65QCUDmH6+dixTCxjBVBggrBgEFBQcBAQRJMEcwIQYIKwYBBQUH" \
"MAGGFWh0dHA6Ly9yMy5vLmxlbmNyLm9yZzAiBggrBgEFBQcwAoYWaHR0cDovL3Iz" \
"LmkubGVuY3Iub3JnLzBxBgNVHREEajBogiJrZW50LXByb2plY3QtYmlvbWV0cmlj" \
"cy5uYXRoYW5tLmZygg5tYXAubmF0aGFubS5mcoIQbWVkaWEubmF0aGFubS5mcoIK" \
"bmF0aGFubS5mcoIUcG9ydGFpbmVyLm5hdGhhbm0uZnIwTAYDVR0gBEUwQzAIBgZn" \
"gQwBAgEwNwYLKwYBBAGC3xMBAQEwKDAmBggrBgEFBQcCARYaaHR0cDovL2Nwcy5s" \
"ZXRzZW5jcnlwdC5vcmcwggEFBgorBgEEAdZ5AgQCBIH2BIHzAPEAdgDfpV6raIJP" \
"H2yt7rhfTj5a6s2iEqRqXo47EsAgRFwqcwAAAX6yc4gtAAAEAwBHMEUCIQDGFGk1" \
"X7G4q641GsN0XcIkwhiRwq0aHnIn2k3irQVfIgIgPtcpdS3NUopF1fkDeXq/T9oR" \
"rtnNVzaBhZHFDVHVz/AAdwBGpVXrdfqRIDC1oolp9PN9ESxBdL79SbiFq/L8cP5t" \
"RwAAAX6yc4huAAAEAwBIMEYCIQCyHwJ6g/ZCoKJXTnU6jRrq2wB4lPgGDvRv9/us" \
"PgNh9wIhAIFZWficFKKd40XKDifHzttOkolhHhxVaNL7UmGOPW7SMA0GCSqGSIb3" \
"DQEBCwUAA4IBAQApGlmGgHopbzOTZB8TG+XhbS/yfes20WEJtJYygHumKj07V1d6" \
"XrNeJ6DMbJlHC89eX+27jG9iTu9Wm6Unm82HUaF3F6WGAq18FviqrdPQEHUWyiU3" \
"bucdOAoEy19zU+X5gFkQyx8C5vbBHwVD6NzFQQtGp12p0vNFGRjMI68aMMoBv/+r" \
"RGpRg6g942dCgIgKasTH4YJ+CcjmJ9/15cWX4V7Tc1Ahw7zh06EQt/NccSVLAPex" \
"rECxfpNdmekREOF/vjlQlfDBouXI+ltBQtQFzUSuCsZJJaeU4e98lwGSSFd9JB9a" \
"NxGywTq9qDTEF5Uf7JKGj/HQn1FNYhMrm38X" \
"-----END CERTIFICATE-----\n";

#include "DHT.h"
#define DHTPIN 15
#define DHTTYPE DHT11

#include <WiFi.h>
const char ssid[] = "Galaxy Note10+5b9f";
const char pass[] = "tqwh6680";
int oldWifiStatus = WL_IDLE_STATUS;

#include <HTTPClient.h>
#define API "https://kent-iot-api.nathanm.fr/api/sensors"

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

void sendSensorData(void) {
  WiFiClient client;
  HTTPClient http;

  http.begin(client, API, CERT);
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Authorization", "896d49601017c8b6fe247d3dccdd8a37019d6c6fecf80a74d2706df18cccfb20adf5038ca7a7f653cc24127ffcc5c60e903c3774295a0a29a19765245b8af0fb302fb42b025eee92ed85cea856704255ac2be1d013b11224c4758c9cd83e9efc197ed2828ee2e549c4302790f397619ca3dc9056d04cef88029a82297f5f0402");
  int httpResponseCode = http.POST("{\"data\":\"{\"sensorID\":\"1\",\"value\":{}\"}}");
  
  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);

  http.end();
}

void loop() {
  // Refresh WiFi status
  if (refreshWifiStatus() == false)
    return;
  getHumiditySensorValues();

  delay(1000);
}

const char[] CERT = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIGdzCCBV+gAwIBAgISBFjGLJ5tqLRY5BtdlBBLXXuGMA0GCSqGSIb3DQEBCwUA" \
"MDIxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBFbmNyeXB0MQswCQYDVQQD" \
"EwJSMzAeFw0yMjAxMzEyMjIzNDJaFw0yMjA1MDEyMjIzNDFaMBUxEzARBgNVBAMT" \
"Cm5hdGhhbm0uZnIwggIiMA0GCSqGSIb3DQEBAQUAA4ICDwAwggIKAoICAQDj0us3" \
"87kTxpRHV3KVqfpzFF5wsnvds6C/vkVaQZi1HHyQSzz4/BV3gb+wuza0xIQrectU" \
"IEkbCktVRsJuLy/xyP+tRrXrxRn3nmvmIJ4EMZE8/63ei8Ta87yZK+WglNtftqCD" \
"CjjVaehv4lsINB3TwI3wN5yhswUG+Lt7mkDXClWPcR61fUxUC54ywrczPLtTWoWb" \
"4NpN4KQ3ZR4MpLz8STDdOgQBS/+g2uyYrnqj7VqpJzWQrwLd2VBE4czmXUf5RITZ" \
"u6U72bYgLOMNUxZKDudbDNddDSpjXFyLXkPqmy6qXC4UY1cVFsCmZzLSGZsV4lOv" \
"TUwZB4kfFjzpN48+9n7fo0VgkbvhnrjOTnE9rjmeC42/qJ84GKoH61RvkyU8roqI" \
"dhqCvBs4voTpSc5ur4Hnc/gwcMbMN3vTelC+KFj6Lf8Gj7VTZZin+0bVP2bU4g3K" \
"OTEIA4z8w5H0uvosccEdgeSpG7kpNCNnLeB0vzQWngCsdA7k4OTzhkISAEDbYlkY" \
"goRCnaPG0LIYeSai+61EJUAk2qIUMQ8zk1ROoJn9cqg2X3aPsxVQJnpwZeoUt0XB" \
"dLxJP4rZ8i5t8uZe6dkmaJutxhPGKwjLb25aK/0PnlvSQr5xnVDgpfkOeu45u3vR" \
"rxDOKRVCA96+sz8gM6vgj6lGSkFEHp3Gi9+vNQIDAQABo4ICojCCAp4wDgYDVR0P" \
"AQH/BAQDAgWgMB0GA1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcDAjAMBgNVHRMB" \
"Af8EAjAAMB0GA1UdDgQWBBQwUgG4qB6vBZk0/Vndi4SnTPmvPDAfBgNVHSMEGDAW" \
"gBQULrMXt1hWy65QCUDmH6+dixTCxjBVBggrBgEFBQcBAQRJMEcwIQYIKwYBBQUH" \
"MAGGFWh0dHA6Ly9yMy5vLmxlbmNyLm9yZzAiBggrBgEFBQcwAoYWaHR0cDovL3Iz" \
"LmkubGVuY3Iub3JnLzBxBgNVHREEajBogiJrZW50LXByb2plY3QtYmlvbWV0cmlj" \
"cy5uYXRoYW5tLmZygg5tYXAubmF0aGFubS5mcoIQbWVkaWEubmF0aGFubS5mcoIK" \
"bmF0aGFubS5mcoIUcG9ydGFpbmVyLm5hdGhhbm0uZnIwTAYDVR0gBEUwQzAIBgZn" \
"gQwBAgEwNwYLKwYBBAGC3xMBAQEwKDAmBggrBgEFBQcCARYaaHR0cDovL2Nwcy5s" \
"ZXRzZW5jcnlwdC5vcmcwggEFBgorBgEEAdZ5AgQCBIH2BIHzAPEAdgDfpV6raIJP" \
"H2yt7rhfTj5a6s2iEqRqXo47EsAgRFwqcwAAAX6yc4gtAAAEAwBHMEUCIQDGFGk1" \
"X7G4q641GsN0XcIkwhiRwq0aHnIn2k3irQVfIgIgPtcpdS3NUopF1fkDeXq/T9oR" \
"rtnNVzaBhZHFDVHVz/AAdwBGpVXrdfqRIDC1oolp9PN9ESxBdL79SbiFq/L8cP5t" \
"RwAAAX6yc4huAAAEAwBIMEYCIQCyHwJ6g/ZCoKJXTnU6jRrq2wB4lPgGDvRv9/us" \
"PgNh9wIhAIFZWficFKKd40XKDifHzttOkolhHhxVaNL7UmGOPW7SMA0GCSqGSIb3" \
"DQEBCwUAA4IBAQApGlmGgHopbzOTZB8TG+XhbS/yfes20WEJtJYygHumKj07V1d6" \
"XrNeJ6DMbJlHC89eX+27jG9iTu9Wm6Unm82HUaF3F6WGAq18FviqrdPQEHUWyiU3" \
"bucdOAoEy19zU+X5gFkQyx8C5vbBHwVD6NzFQQtGp12p0vNFGRjMI68aMMoBv/+r" \
"RGpRg6g942dCgIgKasTH4YJ+CcjmJ9/15cWX4V7Tc1Ahw7zh06EQt/NccSVLAPex" \
"rECxfpNdmekREOF/vjlQlfDBouXI+ltBQtQFzUSuCsZJJaeU4e98lwGSSFd9JB9a" \
"NxGywTq9qDTEF5Uf7JKGj/HQn1FNYhMrm38X" \
"-----END CERTIFICATE-----\n";
