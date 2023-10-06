#define RMpos 13
#define RMneg 12
#define LMpos 11
#define LMneg 10
#define EnableRM A0
#define EnableLM A1

int RMspeed = 200;
int LMspeed = 200;


void forward() {
  Serial.println("Forward");
  digitalWrite(RMpos, HIGH);
  digitalWrite(RMneg, LOW);
  digitalWrite(LMpos, LOW);
  digitalWrite(LMneg, HIGH);
  analogWrite(EnableRM, RMspeed);  // Adjust the speed as needed
  analogWrite(EnableLM, LMspeed);
}

void backward() {
  Serial.println("Backward");
  digitalWrite(RMpos, LOW);
  digitalWrite(RMneg, HIGH);
  digitalWrite(LMpos, HIGH);
  digitalWrite(LMneg, LOW);
  analogWrite(EnableRM, RMspeed);  // Adjust the speed as needed
  analogWrite(EnableLM, LMspeed);
}

void left() {
  Serial.println("Left");
  digitalWrite(RMpos, LOW);
  digitalWrite(RMneg, LOW);
  digitalWrite(LMpos, LOW);
  digitalWrite(LMneg, HIGH);
  analogWrite(EnableRM, RMspeed);  // Adjust the speed as needed
  analogWrite(EnableLM, LMspeed);
}

void right() {
  Serial.println("Right");
  digitalWrite(RMpos, HIGH);
  digitalWrite(RMneg, LOW);
  digitalWrite(LMpos, LOW);
  digitalWrite(LMneg, LOW);
  analogWrite(EnableRM, RMspeed);  // Adjust the speed as needed
  analogWrite(EnableLM, LMspeed);
}

void stop() {
  Serial.println("Stop");
  digitalWrite(RMpos, LOW);
  digitalWrite(RMneg, LOW);
  digitalWrite(LMpos, LOW);
  digitalWrite(LMneg, LOW);
  analogWrite(EnableRM, 0);  // Adjust the speed as needed
  analogWrite(EnableLM, 0);
}

void setup()
{
  Serial.begin(9600);
  pinMode(RMpos,OUTPUT);
  pinMode(LMpos,OUTPUT);
  pinMode(RMneg,OUTPUT);
  pinMode(LMneg,OUTPUT);
  pinMode(EnableRM, OUTPUT);
  pinMode(EnableLM, OUTPUT);
}

void loop()
{
  forward();
  delay(1000);
  stop();
  delay(1000);
  backward();
  delay(1000);
  stop();
  delay(1000);
  right();
  delay(10000);
  stop();
  delay(1000);
  left();
  delay(10000);
  stop();
  delay(1000);
}