#include <NewPing.h>
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#include <Servo.h>

Servo liftServo;
Servo launchServo;
Servo ultraServo;

#define PIN            12
#define NUMPIXELS      6

// Left motor pins
#define enableL 6     // ENA speed pin for left motor
#define LPin1 7       // IN1 on Motor controller board
#define LPin2 8       // IN2
// Right motor pins
#define enableR 11     // ENB speed pin for right motor
#define RPin1 9       // IN3 on Motor controller board
#define RPin2 10       // IN4

//light sensor variables
#define rightSensorPin A0
#define middleSensorPin A1
#define leftSensorPin A2
#define BLACKlimit 800  // typical range white > 100, black <800
#define WHITElimit 100

#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int rightSensor;
int middleSensor;
int leftSensor;
int state = 0;
int flag = 0;
int startPos = 180;
int endPos = 0;
int startPos1 = 0;
int endPos1 = 180;
int currentServoPos1 = 0;


void setup()
{
  Serial.begin (9600);
  // set all the motor control pins to outputs
  pinMode(enableR, OUTPUT);
  pinMode(enableL, OUTPUT);
  pinMode(RPin1, OUTPUT);
  pinMode(RPin2, OUTPUT);
  pinMode(LPin1, OUTPUT);
  pinMode(LPin2, OUTPUT);

  launchServo.attach(3);//left
  liftServo.attach(2);//right
  ultraServo.attach(12);//ultra
  liftServo.write(40);
}

unsigned int integerValue = 0; // Max value is 65535
char incomingByte;

void loop()
{

  if (Serial.available() > 0) {   // something came across serial
    integerValue = 0;         // throw away previous integerValue
    while (1) {           // force into a loop until 'n' is received
      incomingByte = Serial.read();
      if (incomingByte == '9') break;   // exit the while(1), we're done receiving
      if (incomingByte == -1) continue;  // if no characters are in the buffer read() returns -1
      integerValue *= 10;  // shift left 1 decimal place
      // convert ASCII to integer, add, and shift left 1 decimal place
      integerValue = ((incomingByte - 48) + integerValue);
    }
    flag = 0;
  }
  state = integerValue;

  if (state == 0) {
    if (flag == 0) {
      Serial.println("STOP");
      flag = 1;
      motorsOff();
    }
  }

  else if (state == 1)
  {
    if (flag == 0)
    {
      Serial.println("forward");
      flag = 1;
      forward();
    }
  }
  else if (state == 2)
  {
    if (flag == 0)
    {
      Serial.println("reverse");
      flag = 1;
      reverse();
    }
  }
  else if (state == 3)
  {
    if (flag == 0)
    {
      Serial.println("Right turn");
      flag = 1;
      leftWheelForward();
    }
  }
  else if (state == 4)
  {
    if (flag == 0)
    {
      Serial.println("Left turn");
      flag = 1;
      rightWheelForward();
    }
  }
  else if (state == 5)
  {
    Serial.println("Line Following");
    while (state == 5)
    {
      lineFollow();
      delay(100);
    }
  }
  else if (state == 6)
  {
    Serial.println("Follow Duct Tape line");
    while (state == 6)
    {
      ductTape();
      delay(100);
    }
  }
  else if (state == 7)
  {
    if (flag == 0)
    {
      //up 1 degree
      flag = 1;
      oneDegree();
      Serial.println(currentServoPos1);
    }
  }
  else if (state == 8)
  {
    if (flag == 0)
    {
      //up 5 degree
      flag = 1;
      fiveDegree();
      Serial.println(currentServoPos1);
    }
  }
  else if (state == 10)
  {
    if (flag == 0)
    {
        //down 1 degree
      flag = 1;
      oneDegreeDown();
      Serial.println(currentServoPos1);
    }
  }
  else if (state == 11)
  {
    if (flag == 0)
    {
      //down 5 degree
      flag = 1;
      fiveDegreeDown();
      Serial.println(currentServoPos1);
    }
  }
  else if (state == 12)
  {
    if (flag == 0)
    {
      Serial.println("Homing Servos");
      flag = 1;
      homeServos();
      currentServoPos1 = 180;
    }
  }
  else if (state == 13)
  {
    if (flag == 0)
    {
      Serial.println("Maxing Servos");
      flag = 1;
      endServos();
      currentServoPos1 = 0;
    }
  }
  else if (state == 14)
  {
    if (flag == 0)
    {
      flag = 1;
      loadLauncher();
    }
  }
  else if (state == 15)
  {
    if (flag == 0)
    {
      flag = 1;
      launch();
    }
  }
  else if (state == 16)
  {
    Serial.println("Navigating");
    do{
      maze();
      delay(100);
    }while(state != 0);
  }
}
