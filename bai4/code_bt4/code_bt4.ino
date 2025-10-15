int ledYellow = 2;
int ledRed = 3;
int btn = 4;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(btn, INPUT_PULLUP);

  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btnState = digitalRead(btn);

  delay(200);
  if(btnState == HIGH) {
    count++;
    switch (count % 4) {
      case 1:
        digitalWrite(ledYellow, HIGH);
        digitalWrite(ledRed, HIGH);
        break;
      case 2:
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledRed, LOW);
        break;
      case 3:
        digitalWrite(ledYellow, HIGH);
        digitalWrite(ledRed, LOW);
        break;
      case 0:
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledRed, HIGH);
        break;
    }
    delay(200);
  }
}
