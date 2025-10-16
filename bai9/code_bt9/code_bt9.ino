#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int lm35Pin = A0;
const int btnC = 6;
const int btnF = 7;

bool showCelsius = true;

int lastBtnC = HIGH;
int lastBtnF = HIGH;

void setup() {
  pinMode(btnC, INPUT_PULLUP);
  pinMode(btnF, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.print("Nhiet do:");
}

void loop() {
  int readingC = digitalRead(btnC);
  int readingF = digitalRead(btnF);

  if (readingC == LOW && lastBtnC == HIGH) {
    showCelsius = true;
    lcd.clear();
    lcd.print("Dang hien: C");
    delay(500);
  }
  lastBtnC = readingC;

  if (readingF == LOW && lastBtnF == HIGH) {
    showCelsius = false;
    lcd.clear();
    lcd.print("Dang hien: F");
    delay(500);
  }
  lastBtnF = readingF;

  int analogValue = analogRead(lm35Pin);
  float voltage = analogValue * (5.0 / 1023.0);
  float tempC = voltage * 100.0; // LM35: 10mV/°C
  float tempF = tempC * 1.8 + 32;

  lcd.setCursor(0, 1);
  if (showCelsius) {
    lcd.print("Nhiet do: ");
    lcd.print(tempC, 1);
    lcd.print((char)223); // ký hiệu °
    lcd.print("C ");
  } else {
    lcd.print("Nhiet do: ");
    lcd.print(tempF, 1);
    lcd.print((char)223);
    lcd.print("F ");
  }

  delay(500);
}
