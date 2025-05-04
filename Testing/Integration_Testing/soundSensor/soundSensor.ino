/*
  Integration of Ultrasound sensors and Servo motors
    - Tested what issues do occur when sensors rotated by the servos

*/


#include <Servo.h>
#include <stdlib.h>


short startPin=5, bulb=6;

int trigPin=11, echoPin=12;

Servo servo;
int servoPin=8;

int threshold, condition;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(startPin, INPUT);
  pinMode(bulb, OUTPUT);

    pinMode(servoPin, OUTPUT);
  servo.attach(servoPin);
  servo.write(90);
  delay(3000);

    
    digitalWrite(bulb, HIGH);

  while( digitalRead(startPin) == 0 ){
    delay(250);   }
      threshold = Measure();
    condition = threshold*1.2;
    digitalWrite(bulb, LOW);



}

void loop() {
  
digitalWrite(bulb, LOW);
     if( Measure() <= threshold){
    
    bool dec = Decision();
    dec==1 ? servo.write(180) : servo.write(0);
    digitalWrite(bulb, HIGH);
    delay(2000);
  }
  

}

bool Decision(){
  int left=0, right=0, val;

  for(int x=0; x<=180; x+=20){
    servo.write(x);
    val = Measure();             //change
    Serial.println(val);
    x<90? left+=val : right+=val;
    delay(30);
  }

  servo.write(90);
  return (right >= left);
}

int Measure(){
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo time
  int duration = pulseIn(echoPin, HIGH);
  return duration/100;
}
