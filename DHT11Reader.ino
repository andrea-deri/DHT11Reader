#include "DHT11Reader.h"

#define DHT_PIN 2

DHT11Reader dhtSensor;

const char VALUES_SEPARATOR[] = ";";
const short VALUES_SIZE = 3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float values[VALUES_SIZE];
  values[0] = dhtSensor.read(DHT_PIN);
  values[1] = dhtSensor.humidity;
  values[2] = dhtSensor.temperature;
  sendData(values, VALUES_SEPARATOR);
  delay(5000);
}

/*
The method permits to send the calculated data to the serial channel
in a stringfied form.
*/
void sendData(const float* data, const char separator) {
  char tempBuffer[6];
  char buffer[150];
  strcpy(buffer, dtostrf(data[0], 3, 1, tempBuffer));
  for (int i = 1; i < VALUES_SIZE; i ++) {
    strcat(buffer, VALUES_SEPARATOR);
    strcat(buffer, dtostrf(data[i], 3, 1, tempBuffer));
  }
  strcat(buffer, VALUES_SEPARATOR);
  Serial.println(buffer);
}




