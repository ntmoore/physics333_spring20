/* My daughter Olivia created this program and Arduino interface to measure what
happened to a room's humidity after someone took a shower, ran a bathroom vent fan,
or ran the woodstove, etc.  She worked off Adafruit's "Fridgelogger" design.
https://learn.adafruit.com/adafruit-data-logger-shield/light-and-temperature-logger 
*/

/* Olivia Moore
    2017-12-21
    measuring relative humidity along with temperature and time in milliseconds.
  2017-12-22
  records to the SD cards
  still need all the data files to have a time stamp like the code below
  char filename[25];
    sprintf(filename,"datalog.%ld.csv",now.unixtime());
    Serial.print("new filename is:");
    Serial.println(filename);
  2017-12-28
  the name of the datafile is now the date
  when making a filename it MUST be 8.3
  2018-01-03
  prints the file name with all months. The problem was that when the
  arduino save the filenames it did not save " 1 31127.csv" because
  of the " %2d" that was in the code. so it was changed to " %d",
  which worked.
*/
#include <SPI.h>
#include <SD.h>
const int chipSelect = 10;


#include "Adafruit_Si7021.h"
Adafruit_Si7021 sensor = Adafruit_Si7021();

// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
RTC_PCF8523 rtc;
char filename[40];


// this is what i need to do the LCD:
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup() {
  Serial.begin(115200);
  // wait for serial port to open
  while (!Serial) {
    delay(10);
  }

  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print("relative humidity");
  lcd.setCursor(0, 2);
  lcd.print("temp (C)");

  Serial.println("Si7021 test!");
  if (!sensor.begin()) {
    Serial.println("Did not find Si7021 sensor!");
    while (true);
  }

  Serial.print("Initializing SD card...");
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.initialized()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }


  DateTime now = rtc.now();
  //the filename has to follow 8.3 format
  sprintf(filename, "%d%d%d%d.csv",
          now.month(), now.day(), now.hour(), now.minute());
  Serial.print("new filename is:");
  Serial.println(filename);

}

void loop() {
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open(filename, FILE_WRITE);

  unsigned long ltime = millis();
  float humidity = sensor.readHumidity();
  float Temperature = sensor.readTemperature();

  lcd.setCursor(0, 1);
  lcd.print(humidity, 2);
  lcd.setCursor(0, 3);
  lcd.print(Temperature, 2);

  Serial.print("time(ms),");
  Serial.print(ltime);
  Serial.print(",Humidity:(%rh),"); Serial.print(humidity, 2);
  Serial.print(",Temperature:(C),"); Serial.print(Temperature, 2);
  Serial.println(",");

  if (dataFile) {
    dataFile.print("time(ms),");
    dataFile.print(ltime);
    dataFile.print(",Humidity:(%rh),"); dataFile.print(humidity, 2);
    dataFile.print(",Temperature:(C),"); dataFile.print(Temperature, 2);
    dataFile.println(",");
    dataFile.close();
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.print("error opening ");
    Serial.println(filename);
  }

  delay(1000);
}
