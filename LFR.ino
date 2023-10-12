#define RMpos 13
#define RMneg 12
#define LMpos 11
#define LMneg 10
#define EnableRM A0
#define EnableLM A1
#define middleSensor1 0
#define middleSensor2 1
#define rightSensor1 2
#define rightSensor2 3
#define leftSensor1 4
#define leftSensor2 5

void setMotorSpeed(int speed) {
  analogWrite(EnableRM, speed);
  analogWrite(EnableLM, speed);
}

void forward() {
  Serial.println("Going Forward...");
  digitalWrite(RMpos, HIGH);
  digitalWrite(RMneg, LOW);
  digitalWrite(LMpos, LOW);
  digitalWrite(LMneg, HIGH);
  setMotorSpeed(200);
}

void backward() {
  Serial.println("Going Backward...");
  digitalWrite(RMpos, LOW);
  digitalWrite(RMneg, HIGH);
  digitalWrite(LMpos, HIGH);
  digitalWrite(LMneg, LOW);
  setMotorSpeed(200);
}

void right() {
  Serial.println("Turning Right...");
  digitalWrite(RMpos, LOW);
  digitalWrite(RMneg, LOW);
  digitalWrite(LMpos, LOW);
  digitalWrite(LMneg, HIGH);
  setMotorSpeed(200);
}

void left() {
  Serial.println("Turning Left...");
  digitalWrite(RMpos, HIGH);
  digitalWrite(RMneg, LOW);
  digitalWrite(LMpos, LOW);
  digitalWrite(LMneg, LOW);
  setMotorSpeed(200);
}

void stop() {
  Serial.println("Stopping...");
  digitalWrite(RMpos, LOW);
  digitalWrite(RMneg, LOW);
  digitalWrite(LMpos, LOW);
  digitalWrite(LMneg, LOW);
  setMotorSpeed(0);
}

void setup() {
  Serial.begin(9600);
  pinMode(RMpos, OUTPUT);
  pinMode(LMpos, OUTPUT);
  pinMode(RMneg, OUTPUT);
  pinMode(LMneg, OUTPUT);

  TCCR0B = TCCR0B & B11111000 | B00000010;

  pinMode(EnableRM, OUTPUT);
  pinMode(EnableLM, OUTPUT);
  pinMode(middleSensor1, INPUT);
  pinMode(middleSensor2, INPUT);
  pinMode(rightSensor1, INPUT);
  pinMode(rightSensor2, INPUT);
  pinMode(leftSensor1, INPUT);
  pinMode(leftSensor2, INPUT);
}

void loop() {
  int middle1 = digitalRead(middleSensor1);
  int middle2 = digitalRead(middleSensor2);
  int right1 = digitalRead(rightSensor1);
  int right2 = digitalRead(rightSensor2);
  int left1 = digitalRead(leftSensor1);
  int left2 = digitalRead(leftSensor2);

  if (middle1 == 0 && middle2 == 0) {
    forward();
    delay(100);
  } else if (right1 == 0 && right2 == 0) {
    left();
    delay(100);
  } else if (left1 == 0 && left2 == 0) {
    right();
    delay(100);
  } else {
    stop();
    delay(100);
  }
}