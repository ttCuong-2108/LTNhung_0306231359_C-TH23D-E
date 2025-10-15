const int redA = 2;
const int greenA = 3;
const int redB = 4;
const int greenB = 5;
const int redC = 6;
const int greenC = 7;

void setup() {
  pinMode(redA, OUTPUT);
  pinMode(greenA, OUTPUT);
  pinMode(redB, OUTPUT);
  pinMode(greenB, OUTPUT);
  pinMode(redC, OUTPUT);
  pinMode(greenC, OUTPUT);
}

void loop() {
  digitalWrite(greenA, HIGH);
  digitalWrite(redA, LOW);
  digitalWrite(redB, HIGH);
  digitalWrite(greenB, LOW);
  digitalWrite(redC, HIGH);
  digitalWrite(greenC, LOW);
  delay(5000);

  digitalWrite(greenA, LOW);
  digitalWrite(redA, HIGH);
  digitalWrite(redB, LOW);
  digitalWrite(greenB, HIGH);
  digitalWrite(redC, HIGH);
  digitalWrite(greenC, LOW);
  delay(5000);

  digitalWrite(greenA, LOW);
  digitalWrite(redA, HIGH);
  digitalWrite(redB, HIGH);
  digitalWrite(greenB, LOW);
  digitalWrite(redC, LOW);
  digitalWrite(greenC, HIGH);
  delay(5000);
}
