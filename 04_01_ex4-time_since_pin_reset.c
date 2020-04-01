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
  // reading from digital pin 3 which is manually toggeled from High to Low 
  // with a breadboarding wire
  pinMode(3,INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("d3 low for (ms)");
  t0 = millis();
}

void loop() {
  // write time in the second row
  //lcd.setCursor(column, row);
  if (digitalRead(3)==1) {
    t0 = millis();
    lcd.setCursor(0, 1);
    lcd.print(0);
  } else {
    lcd.setCursor(0, 1);
    lcd.print(millis() - t0);
    delay(random(100, 900));
  }
  // Note, this is buggy.  Afer a reset, the second row of the display will read something like 0953
  // after being in 2953 when the D3 signal wire was at LOW and the counter was incementing properly
  // How can we fix this?
}
