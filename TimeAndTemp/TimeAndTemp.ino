#include <microDS3231.h>
#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

MicroDS3231 rtc;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 5, 9, 8, 7, 6);

void setup() {
  rtc.setTime(COMPILE_TIME);
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // set the cursor to column 3, line 0
  lcd.setCursor(3, 0);
  // Print a message to the LCD.
  lcd.print("imp0rtTech");

  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  // set the cursor to column 10, line 1
  lcd.setCursor(10, 1);
  lcd.print(t);

  // set the cursor to column 1, line 1
  lcd.setCursor(1, 1);
  //get time as string
  String s = rtc.getTimeString();
  lcd.print(s);
}
