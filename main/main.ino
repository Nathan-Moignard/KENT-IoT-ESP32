// https://github.com/adafruit/DHT-sensor-library

// SSL/TLS Certificate for API usage
const char[] CERT = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIGhjCCBW6gAwIBAgISBJqe0b/qX7oBXC7Rwgn7xHVQMA0GCSqGSIb3DQEBCwUA" \
"MDIxCzAJBgNVBAYTAlVTMRYwFAYDVQQKEw1MZXQncyBFbmNyeXB0MQswCQYDVQQD" \
"EwJSMzAeFw0yMjAzMzAyMjMxNTdaFw0yMjA2MjgyMjMxNTZaMBUxEzARBgNVBAMT" \
"Cm5hdGhhbm0uZnIwggIiMA0GCSqGSIb3DQEBAQUAA4ICDwAwggIKAoICAQCzr6+X" \
"se0zQYN/NMHTS0gj+9lCcEtl1ttHAzXHMwjlWribTx8pjTOG3YTJmHY/bepH8Bv0" \
"c8A361ZVp42GFpB5H6q7d4BFxzj7TGjAyGFxUfL5aUnZG0H6rRFjb5Gtqdcdl7cV" \
"knRYnRh2tM+XupsM0hT8wH7IunOixOvQmj+LzntH/O+yjJA3dZR43oB7zt/IsJlx" \
"E168DJ/rs1BFLL54Jy45eviV4/J5mObKaiU1Ybg0c1EdKu1fyQkhNYQd3XTN7szi" \
"fTSb/qjqfJz5NwbGSEsclevXJnloQS5gX844fzTaOkPIti1tR3v/tg0d/kliBA8J" \
"nhaLPWkUvWfRWEC5QdxMYj2ginYiA6sSizs/mV9pLJY1e3hw3T5Hr3PMjhrFnpsr" \
"lTTxIMuEfM305iLWVj1HPqnzLzzfM0OtuhcrfY9GbbLofAB0PSq2rx1UM6eFHKz5" \
"4PKxEGAQFApz5UFiyDK3Sm5OYsQkTiaFkiypHjkBxwyUShpxL5+FJCcCadzdxy8B" \
"BygLK7l8Y1abgEpy7K9XYC19S+Yqy8s+4htUa2VuaDADCQDdzi5+dpIzbRfuJ3Eb" \
"mQXX8lpSmJ2ia1ukOhgtdEeJW2TcclYZ+csUHL/sqGfSD2ZDoMlnicJXP0Sz4OkJ" \
"s3HmNzS/nNJMjz9MXw012wsbQvqA5f+4MG4ndQIDAQABo4ICsTCCAq0wDgYDVR0P" \
"AQH/BAQDAgWgMB0GA1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcDAjAMBgNVHRMB" \
"Af8EAjAAMB0GA1UdDgQWBBTatHovP9yG5a9LHG5dkpx3LfTvTzAfBgNVHSMEGDAW" \
"gBQULrMXt1hWy65QCUDmH6+dixTCxjBVBggrBgEFBQcBAQRJMEcwIQYIKwYBBQUH" \
"MAGGFWh0dHA6Ly9yMy5vLmxlbmNyLm9yZzAiBggrBgEFBQcwAoYWaHR0cDovL3Iz" \
"LmkubGVuY3Iub3JnLzCBgAYDVR0RBHkwd4ISYXp1cmlvbS5uYXRoYW5tLmZyghdr" \
"ZW50LWlvdC1hcGkubmF0aGFubS5mcoIQbWVkaWEubmF0aGFubS5mcoIKbmF0aGFu" \
"bS5mcoIUbmV4dGNsb3VkLm5hdGhhbm0uZnKCFHBvcnRhaW5lci5uYXRoYW5tLmZy" \
"MEwGA1UdIARFMEMwCAYGZ4EMAQIBMDcGCysGAQQBgt8TAQEBMCgwJgYIKwYBBQUH" \
"AgEWGmh0dHA6Ly9jcHMubGV0c2VuY3J5cHQub3JnMIIBBAYKKwYBBAHWeQIEAgSB" \
"9QSB8gDwAHYA36Veq2iCTx9sre64X04+WurNohKkal6OOxLAIERcKnMAAAF/3Svr" \
"UAAABAMARzBFAiAhuuMwimRmB+e5Oaa/ceNDgHvsOL1psHB2NObYnfbydgIhAMt4" \
"ESsEwp78YrXIIRY+5Ahzbz7EsQ1wLASLUtwtxve0AHYARqVV63X6kSAwtaKJafTz" \
"fREsQXS+/Um4havy/HD+bUcAAAF/3Svr/wAABAMARzBFAiB317ZLB0ZyAHRpz52B" \
"Nj1SEDwUF+Z7CAWRoQOr4TmbvAIhAKlbkfA3Sji/daPntPvj+Pb20aNbMHzmOYlI" \
"wNR8nOgkMA0GCSqGSIb3DQEBCwUAA4IBAQCbz4jVV1eokBNFuVJ3DkfKNeUMavME" \
"FCTkEgTfKjvN/WLrKSNFF0ndGkgS9y5K7w6h2FAsyYFQZQOUDAckCfQexG9SFx5g" \
"kphO+HEzbH6FcP2xbmiVbgvl6HyZnGCyHjy6dWD11kZw/iu9Ftj78B6wjIemYEos" \
"z5+4392VdLqZE1U9gul86aM+EozflpB2ugqLFz9T0nTfSQ+VCUcScJfYGf7J6PYa" \
"Te8G9nJrFvJKjm1cGKVdGs6FzNhLtu43DicGCNBIZ7tJMKfMO8q4/7I6e5v+OOT1" \
"V8T6ge1XGHho3IL1NiHs7cymgpducIJQjRFu9TbitxBlg+uEXs5H8N9S" \
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
