#include <LiquidCrystal.h>
const int numRows = 2;
const int numCols = 16;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte AA[8]={
  B00100,
  B01010,
  B00000,
  B00100,
  B01010,
  B01110,
  B10001,
  B00000
};
byte AW[8]={
  B01010,
  B00100,
  B00000,
  B00100,
  B01010,
  B01110,
  B10001,
  B00000
};
byte DD[8]={
  B01100,
  B01010,
  B01001,
  B11101,
  B01001,
  B01010,
  B01100,
  B00000
};
byte EE[8]={
  B00100,
  B01010,
  B11111,
  B10000,
  B11111,
  B10000,
  B11111,
  B00000
};
byte OO[8]={
  B00100,
  B01010,
  B00000,
  B01110,
  B10001,
  B10001,
  B01110,
  B00000
};
byte OW[8]={
  B00000,
  B00110,
  B00010,
  B01110,
  B10001,
  B10001,
  B01110,
  B00000
};
byte UW[8]={
  B00000,
  B00011,
  B00001,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};


void setup() {
  lcd.begin(numCols, numRows); 
  lcd.createChar(0,AW);
  lcd.createChar(1,AA);
  lcd.createChar(2,DD);
  lcd.createChar(3,EE);
  lcd.createChar(4,OO);
  lcd.createChar(5,OW);
  lcd.createChar(6,UW);
  lcd.setCursor(0, 0);
  for(int i=0;i<7;i++){
    lcd.print(char(i));
  }
  
}

void loop() { 
  
}
  
 
