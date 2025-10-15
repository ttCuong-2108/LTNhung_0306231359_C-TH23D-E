#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int btnTat = 8;
int btnTrai = 9;
int btnPhai = 10;
int viTri = 0;
bool lcdOn = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(btnTat, INPUT_PULLUP);
  pinMode(btnTrai, INPUT_PULLUP);
  pinMode(btnPhai, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.setCursor(viTri, 0);
  lcd.print("HELLO");
}

void loop() {
  // put your main code here, to run repeatedly:
  //a
  if(digitalRead(btnTat) == HIGH) {
    delay(200);
    lcdOn = !lcdOn;
    if(lcdOn) {
      lcd.setCursor(viTri, 0);
      lcd.print("HELLO");
    } else {
      lcd.clear();
    }
  }
  //b
  if(digitalRead(btnTrai) == HIGH) {
    delay(200);
    if(viTri >= 2) {
      viTri -= 2;
    } else {
      viTri = 0;
    }
    if(lcdOn) {
      lcd.clear();
      lcd.setCursor(viTri, 0);
      lcd.print("HELLO");
    }
  }
  //c
  if(digitalRead(btnPhai) == HIGH) {
    delay(200);
    if(viTri <= 9) {
      viTri += 2;
    } else {
      viTri = 11;
    }
    if(lcdOn) {
      lcd.clear();
      lcd.setCursor(viTri, 0);
      lcd.print("HELLO");
    }
  }
}
