int trigPin = 9;
int echoPin = 10;
int A,B;
void setup() {
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 Serial.begin(9600);
}
void loop() {
 digitalWrite(trigPin,LOW);
 delay(500);
 digitalWrite(trigPin,HIGH);
 delay(500);
 digitalWrite(trigPin,LOW);
 A = pulseIn(echoPin,HIGH);
 B = A*0.034/2;
 Serial.print("Distance : ");
 Serial.println(B);
 delay(500);
}
