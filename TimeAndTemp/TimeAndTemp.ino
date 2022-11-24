#include <microDS3231.h>
#include <LiquidCrystal.h>

#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


MicroDS3231 rtc;
LiquidCrystal lcd(12, 5, 9, 8, 7, 6);

void setup() {
  rtc.setTime(COMPILE_TIME);
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(3, 0);
  lcd.print("Time and Temp");

  dht.begin();
}
void loop() {
  float t = dht.readTemperature();

  lcd.setCursor(11, 1);
  lcd.print(t);

  lcd.setCursor(2, 1);

  lcd.print(rtc.getHours());
  lcd.print(":");
  lcd.print(rtc.getMinutes());
  lcd.print(":");
  lcd.print(rtc.getSeconds());
}