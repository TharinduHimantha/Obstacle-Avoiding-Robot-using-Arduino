#include <Servo.h>
#include <stdlib.h>


short irPinL, irPinR;
short servoPinL, servoPinR;

short leftF=6, leftB=7;  // turn right
short rightF=8, rightB=9;  //turn left
short pwmPinL=5;
short pwmPinR=10;
short startPin;

int speed1=165, speed2;
Servo finderL, finderR;
int threshold;

void setup() {
  // put your setup code here, to run once:

  pinMode(leftF, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightF, OUTPUT);
  pinMode(rightB, OUTPUT);
  pinMode(pwmPinL, OUTPUT);
  pinMode(pwmPinR, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  goForward(speed1);
  goForward(0);

}

void goForward(int speed){
  digitalWrite(leftF, 1);
  digitalWrite(leftB, 0);

  digitalWrite(rightF, 1);
  digitalWrite(rightB, 0);
 
  analogWrite(pwmPinR, speed);
  speed = (speed != 0) ? speed+15 : 0;
  analogWrite(pwmPinL, speed);
  delay(1500);
}
