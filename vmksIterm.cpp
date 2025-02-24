#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float a, previousTemp;

void setup() {
  lcd.begin(16, 2);
  pinMode(6, OUTPUT);
  previousTemp = -999;
}

void loop() {
  a = analogRead(1);
  a = a * 0.0048828125;
  a = (a - 0.5) * 100;

  if (a != previousTemp) {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(a);
    lcd.print(" C   "); 
    previousTemp = a; 
  }


  if (a > 70) {
    digitalWrite(6, HIGH);
  } else {
    if (a < 0) {
      digitalWrite(6, HIGH);
    } else {
      digitalWrite(6, LOW);
    }
  }
}