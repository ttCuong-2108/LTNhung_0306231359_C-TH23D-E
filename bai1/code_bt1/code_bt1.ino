const int ledPins[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int btnPin = 12;

bool lastBtnState = LOW;
bool currentBtnState = LOW;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  pinMode(btnPin, INPUT_PULLUP);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  currentBtnState = digitalRead(btnPin);

  if (lastBtnState == HIGH && currentBtnState == LOW) {
    for (int i = 0; i < 10; i++) {
      int ranNum = random(1, 11);
      if (ranNum % 2 == 1) {
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }
    delay(200);
  }
  lastBtnState = currentBtnState;
}
