/* building off the system liquid crystal library */
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
// added per sparkfun tutorial at
// https://learn.sparkfun.com/tutorials/basic-character-lcd-hookup-guide
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned int t0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  t0 = millis();
}

void loop() {
  unsigned int tnow;
  int adc;
  tnow = millis() - t0;
  adc = analogRead(A4);

  //lcd.setCursor(column, row);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("t_s=");
  lcd.print(tnow / 1000);
  lcd.print(" ");
  lcd.print("adc=");
  lcd.print(adc);

  float voltage_V = (float)adc * 5.0 / 1024.0;
  // https://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf
  // recall TMP 36 is 10mV/C and has intercept of 0.5V at 0C, so
  //float temp_C = (voltage_V-0.5)/0.010;
  // but this is dumb, right, because 1/0.01 = 100 so?
  float temp_C = (voltage_V - 0.5) * 100.0;
  lcd.setCursor(0, 1);
  lcd.print("V=");
  lcd.print(voltage_V,3);
  lcd.print(" ");
  lcd.print(temp_C);
  lcd.print("oC");
  delay(1000);
}
