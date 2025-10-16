#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int btnA = 6;
const int btnO = 7;
const int btnF = 8;
const int btnS = 9;

int preState_btnA = LOW;
int preState_btnO = LOW;
int preState_btnF = LOW;
int preState_btnS = LOW;

int colCursor = 0;
int preBtn = 0; 

byte char_EE[8] = {
  B01110, 
  B10001, 
  B00000, 
  B01110, 
  B10000, 
  B11111, 
  B10000, 
  B01110,
}; 
byte char_OO[8] = {
  B01110, 
  B10001, 
  B00000, 
  B01110, 
  B10001, 
  B10001, 
  B10001, 
  B01110,
}; 
byte char_EF[8] = {B00100, B01010, B10001, B11111, B10001, B00000, B00000, B00000,}; 
byte char_ES[8] = {B00100, B01010, B10001, B11111, B10001, B00010, B00000, B00000,}; 
byte char_OF[8] = {B01110, B10001, B10001, B01110, B00100, B00000, B00000, B00000,}; 
byte char_OS[8] = {B01110, B10001, B10001, B01110, B00010, B00000, B00000, B00000,}; 

void setup() {
  pinMode(btnA, INPUT_PULLUP);
  pinMode(btnO, INPUT_PULLUP);
  pinMode(btnF, INPUT_PULLUP);
  pinMode(btnS, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.createChar(0, char_EE);
  lcd.createChar(1, char_OO);
  lcd.createChar(2, char_EF);
  lcd.createChar(3, char_ES);
  lcd.createChar(4, char_OF);
  lcd.createChar(5, char_OS);

  lcd.setCursor(0, 0);
  lcd.print("HELLO");
}

void loop() {
  int curA = digitalRead(btnA);
  int curO = digitalRead(btnO);
  int curF = digitalRead(btnF);
  int curS = digitalRead(btnS);

  // Nút A
  if (curA == HIGH && preState_btnA == LOW) {
    if (preBtn == 1) {
      lcd.setCursor(--colCursor, 0);
      lcd.write(byte(0)); // EE → Ê
      preBtn = 0;
    } else {
      lcd.print("A");
      preBtn = 1; 
    }
    colCursor++;
  }
  preState_btnA = curA;

  // Nút O
  if (curO == HIGH && preState_btnO == LOW) {
    if (preBtn == 2) {
      lcd.setCursor(--colCursor, 0);
      lcd.write(byte(1)); // OO → Ô
      preBtn = 0;
    } else {
      lcd.print("O");
      preBtn = 2;
    }
      colCursor++;
  }
  preState_btnO = curO;

  // Nút F
  if (curF == HIGH && preState_btnF == LOW) {
    if (preBtn == 1) {
      lcd.setCursor(--colCursor, 0);
      lcd.write(byte(2)); // EF → È
    } else if (preBtn == 2) {
      lcd.setCursor(--colCursor, 0);
      lcd.write(byte(4)); // OF → Ò
    } else {
      lcd.print("F");
      
    }
    colCursor++;
    preBtn = 0;
  }
  preState_btnF = curF;

  // Nút S
  if (curS == HIGH && preState_btnS == LOW) {
    if (preBtn == 1) {
      lcd.setCursor(--colCursor, 0);
      lcd.write(byte(3)); // ES → É
    } else if (preBtn == 2) {
      lcd.setCursor(--colCursor, 0);
      lcd.write(byte(5)); // OS → Ó
    } else {
      lcd.print("S");
      
    }
    colCursor++;
    preBtn = 0;
  }
  preState_btnS = curS;
}
