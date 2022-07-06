const int MOTORPIN = 5;

void setup() {
  pinMode(MOTORPIN, OUTPUT);

}

void loop() {
  int speed = 225;
  analogWrite(MOTORPIN, speed);

}
