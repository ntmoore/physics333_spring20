#include "Adafruit_Si7021.h"

#include <LiquidCrystal.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


Adafruit_Si7021 sensor = Adafruit_Si7021();

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  int max_value = -1;

  // wait for serial port to open
  while (!Serial) {
    delay(10);
  }

  Serial.println("Si7021 test!");

  if (!sensor.begin()) {
    Serial.println("Did not find Si7021 sensor!");
    while (true)
      ;
  }

  Serial.print("Found model ");
  switch (sensor.getModel()) {
    case SI_Engineering_Samples:
      Serial.print("SI engineering samples"); break;
    case SI_7013:
      Serial.print("Si7013"); break;
    case SI_7020:
      Serial.print("Si7020"); break;
    case SI_7021:
      Serial.print("Si7021"); break;
    case SI_UNKNOWN:
    default:
      Serial.print("Unknown");
  }
  Serial.print(" Rev(");
  Serial.print(sensor.getRevision());
  Serial.print(")");
  Serial.print(" Serial #"); Serial.print(sensor.sernum_a, HEX); Serial.println(sensor.sernum_b, HEX);
}

void loop() {

  int max_value;


  int temp = sensor.readTemperature() * 1.8 + 32;

  int new_value = temp;

  if (new_value > max_value) {
    max_value = new_value;
  }
  if (new_value < max_value) {
    max_value = max_value;
  }
  Serial.print("max value: ");
  Serial.println(max_value);
  delay(5000);
}
