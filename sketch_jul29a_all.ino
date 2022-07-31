#include <AFMotor.h>
AF_DCMotor M2(2);
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance; 
int ledPin = 2;
int buzzer = 3;
const int pingPin2 = 8;
int inPin2 = 7;
void setup() {
  M2.setSpeed(150);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  long duration2, cm2;
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2, LOW);
  pinMode(inPin2, INPUT);
  duration2 = pulseIn(inPin2, HIGH);
  cm2 = microsecondsToCentimeters(duration2);
{
  if (cm2 <= 15) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzer, LOW);
  }
  else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzer, HIGH);
  }
  delay(100);
}
Serial.print(cm2);
Serial.print("cm");
Serial.println();
delay(100);
if(distance < 10){M2.run(FORWARD);delay(500);M2.run(RELEASE);delay(1000);}
  else{M2.run(RELEASE);}
}
long microsecondsToCentimeters(long microseconds){
return microseconds / 29 / 2;
}
