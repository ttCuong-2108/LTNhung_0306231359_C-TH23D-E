#include <LiquidCrystal.h>

// Khởi tạo LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int lm35Pin = A0;
const int buttonPin = 6;
const int ledGreen = 7;
const int ledYellow = 8;
const int ledRed = 9;

bool showCelsius = true;
int lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Nhiet do:");
}

void loop() {
  // Đọc nút nhấn để chuyển chế độ hiển thị
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    showCelsius = !showCelsius;
    lcd.clear();
    lcd.print(showCelsius ? "Dang hien: C" : "Dang hien: F");
    delay(500);
  }
  lastButtonState = buttonState;

  // Đọc nhiệt độ từ LM35
  int analogValue = analogRead(lm35Pin);
  float voltage = analogValue * (5.0 / 1023.0);
  float tempC = voltage * 100.0;
  float tempF = tempC * 1.8 + 32;

  // Hiển thị nhiệt độ
  lcd.setCursor(0, 1);
  if (showCelsius) {
    lcd.print("Nhiet do: ");
    lcd.print(tempC, 1);
    lcd.print((char)223);
    lcd.print("C ");
  } else {
    lcd.print("Nhiet do: ");
    lcd.print(tempF, 1);
    lcd.print((char)223);
    lcd.print("F ");
  }

  // Điều khiển đèn LED theo nhiệt độ °C
  digitalWrite(ledGreen, tempC < 17 ? HIGH : LOW);
  digitalWrite(ledYellow, (tempC >= 17 && tempC <= 30) ? HIGH : LOW);
  digitalWrite(ledRed, tempC > 30 ? HIGH : LOW);

  delay(500);
}
