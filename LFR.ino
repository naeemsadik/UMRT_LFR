#define RMpos 13
#define RMneg 12
#define LMpos 11
#define LMneg 10
#define EnableRM A0
#define EnableLM A1
#define s1 0
#define s2 1
#define s3 2
#define s4 3
#define s5 4
#define s5 5

int RMspeed = 200;
int LMspeed = 200;


void forward() {
  Serial.println("Going Forward...");
  digitalWrite(RMpos, HIGH);
  digitalWrite(RMneg, LOW);
  digitalWrite(LMpos, LOW);
  digitalWrite(LMneg, HIGH);
  analogWrite(EnableRM, RMspeed);  // Adjust the speed as needed
  analogWrite(EnableLM, LMspeed);
}

void backward() {
  Serial.println("Going Backward...");
  digitalWrite(RMpos, LOW);
  digitalWrite(RMneg, HIGH);
  digitalWrite(LMpos, HIGH);
  digitalWrite(LMneg, LOW);
  analogWrite(EnableRM, RMspeed);  // Adjust the speed as needed
  analogWrite(EnableLM, LMspeed);
}

void right() {
  Serial.println("Turning Right...");
  digitalWrite(RMpos, LOW);
  digitalWrite(RMneg, LOW);
  digitalWrite(LMpos, LOW);
  digitalWrite(LMneg, HIGH);
  analogWrite(EnableRM, RMspeed);  // Adjust the speed as needed
  analogWrite(EnableLM, LMspeed);
}

void left() {
  Serial.println("Turning Left...");
  digitalWrite(RMpos, HIGH);
  digitalWrite(RMneg, LOW);
  digitalWrite(LMpos, LOW);
  digitalWrite(LMneg, LOW);
  analogWrite(EnableRM, RMspeed);  // Adjust the speed as needed
  analogWrite(EnableLM, LMspeed);
}

void stop() {
  Serial.println("Stoping.....");
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
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
}

void loop()
{
  Serial.println(digitalread(s1));
  forward();
  delay(10000);
  stop();
  delay(1000);
  backward();
  delay(10000);
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