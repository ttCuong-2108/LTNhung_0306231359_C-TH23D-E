#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int btn = 6;
int led = 7;
int lassBtn = LOW;
int currentBtn = LOW;
int lcdState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentBtn = digitalRead(btn);

  delay(200);
  if (lassBtn == HIGH && currentBtn == LOW) {
    lcdState = !lcdState;

    if(lcdState == 1) {
      lcd.print("Hello!");
      digitalWrite(led, LOW);
    } else {
      lcd.clear();
      digitalWrite(led, HIGH);;
    }
  }
  lassBtn = currentBtn;
}
