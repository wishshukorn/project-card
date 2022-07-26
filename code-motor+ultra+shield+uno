#include <AFMotor.h>
AF_DCMotor M2(2);
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance; 
void setup() {
  M2.setSpeed(150);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance < 10){M2.run(FORWARD);}
  else{M2.run(RELEASE);}
}
