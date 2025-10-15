int led=13;
int btn_nhanh=2;
int btn_cham=3;

int blinkDelay =  500;
const int minDelay = 100;
const int maxDelay = 3000;
const int step = 100;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(btn_nhanh, INPUT);
  pinMode(btn_cham, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(btn_nhanh) == LOW) {
    blinkDelay+=step;
    if(blinkDelay >= maxDelay) {
      blinkDelay = maxDelay;
    }
    delay(200);
  }
  if(digitalRead(btn_cham) == LOW) {
    blinkDelay-=step;
    if(blinkDelay <= minDelay) {
      blinkDelay = minDelay;
    }
    delay(200);
  }

  digitalWrite(led, HIGH);
  delay(blinkDelay);
  digitalWrite(led, LOW);
  delay(blinkDelay);
}
