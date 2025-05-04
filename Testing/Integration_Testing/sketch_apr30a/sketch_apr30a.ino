/*
  Integration testing for actuators
    - Tested for possible power disruptions, interuptions and insufficient current isuues

*/


#include <Servo.h>
#include <stdlib.h>
#include <SoftwareSerial.h>

// Define Bluetooth serial pins
SoftwareSerial BTSerial(15, 16); // RX, TX

int myVariable = 0;
String inputString = "";  // To store incoming characters
bool inputComplete = false; // Flag when input is complete
int bluetoothSwitch = 13;

//Servo related
Servo servo1,servo2;
short servoPin1=3, servoPin2=11;

// Motor related
short leftF=7, leftB=8;  // turn right
short rightF=9, rightB=10;  //turn left
short pwmPinL=5;
short pwmPinR=6;

int baseSpeed1=150;

//UltraSound related
int trigPin1=12, echoPin1=2;
int trigPin2=19, echoPin2=18;


//pid related
double Kp = 0.01;


void setup() {
  // put your setup code here, to run once:

//bluetooth
  BTSerial.begin(9600);
  pinMode(bluetoothSwitch, INPUT);

//Motor related
  pinMode(leftF, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightF, OUTPUT);
  pinMode(rightB, OUTPUT);
  pinMode(pwmPinL, OUTPUT);
  pinMode(pwmPinR, OUTPUT);

  digitalWrite(leftF, 1);
  digitalWrite(leftB, 0);

  digitalWrite(rightF, 1);
  digitalWrite(rightB, 0);

//Servo related
 pinMode(servoPin1,OUTPUT);
  pinMode(servoPin2,OUTPUT);

  servo1.attach(servoPin1);    //left
  servo2.attach(servoPin2);
  delay(500);

  servo1.write(0);
  servo2.write(180);
  delay(5000);

//Ultrasound related
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);    //left
  pinMode(echoPin2, INPUT);




}



void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pwmPinR, 165);
  analogWrite(pwmPinL, 165);

    for(int c =0; c<=100; c+=5){
    servo1.write(c);
    servo2.write(180-c);
    delay(10);
  }

  servo1.write(0);
  servo2.write(180);
  delay(1000);

}
