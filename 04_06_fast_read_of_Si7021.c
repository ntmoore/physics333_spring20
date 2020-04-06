#include "Adafruit_Si7021.h"

Adafruit_Si7021 sensor = Adafruit_Si7021();

void setup() {
  Serial.begin(115200);

  // wait for serial port to open
  while (!Serial) {
    delay(10);
  }

  Serial.println("Si7021 test!");

  if (!sensor.begin()) {
    Serial.println("Did not find Si7021 sensor!");
    while (true);
  }
}

void loop() {
  float hum[15], temp[15];
  long t[15];
  int i;

  // measure humidity
  for (i = 0; i < 15; i++) {
    hum[i] = sensor.readHumidity();
    t[i] = micros();
  }
  // print
  for (i = 1; i < 15; i++) {
    Serial.print(t[i]);
    Serial.print("\t");
    Serial.print(t[i] - t[i - 1]);
    Serial.print("\t");
    Serial.println(hum[i]);
  }
  Serial.println();
  // measure temperature
  for (i = 0; i < 15; i++) {
    temp[i] = sensor.readTemperature();
    t[i] = micros();
  }
  // print results
  for (i = 1; i < 15; i++) {
    Serial.print(t[i]);
    Serial.print("\t");
    Serial.print(t[i] - t[i - 1]);
    Serial.print("\t");
    Serial.println(temp[i]);
  }
  Serial.println("----------");
  delay(2000);
}
