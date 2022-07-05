// code ที่ส่งมาครั้งแรก

int ledPin = 2;
int buzzer = 3;
const int pingPin = 10;
int inPin = 9;
const int pingPin2 = 8;
int inPin2 = 7;
void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
long duration1, cm1;
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingPin, LOW);
pinMode(inPin, INPUT);
duration1 = pulseIn(inPin, HIGH);
cm1 = microsecondsToCentimeters(duration1);

long duration2, cm2;
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
}
long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
