// 7-7-22
// Barracuda Arduino
// Simple Serial motor command test

#include <SoftwareSerial.h>

SoftwareSerial mySerial(NOT_A_PIN, 10);   // RX, TX

// Define the relay pins.
int relay1Pin = 6;
int relay2Pin = 7;

// Define the Sabertooth motor driver enable pins.
int ST1enable = 9;
int ST2enable = 8;

// A function to set the speed of any motor.
void setSpeed(int motorNum, int percent) {
  int value;   //   motor speed 0-255
  switch (motorNum) {
    case 1:
      digitalWrite(ST1enable, HIGH);
      value = (int) map(percent, -100, 100, 1, 127);
      mySerial.write(value);
      digitalWrite(ST1enable, LOW);
      break;
    case 2:
      digitalWrite(ST1enable, HIGH);
      value = (int) map(percent, -100, 100, 128, 255);
      mySerial.write(value);
      digitalWrite(ST1enable, LOW);
      break;
    case 3: 
      digitalWrite(ST2enable, HIGH);
      value = (int) map(percent, -100, 100, 1, 127);
      mySerial.write(value);
      digitalWrite(ST2enable, LOW);
      break;
    case 4:
      digitalWrite(ST2enable, HIGH);
      value = (int) map(percent, -100, 100, 128, 255);
      mySerial.write(value);
      digitalWrite(ST2enable, LOW);
      break;
    default:
      digitalWrite(ST1enable, HIGH);
      digitalWrite(ST2enable, HIGH);
      mySerial.write(64);
      mySerial.write(192);
      digitalWrite(ST1enable, LOW);
      digitalWrite(ST2enable, LOW);
      break;
  }
}

void setup() {
  
  // Initialize the relay pins.
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  digitalWrite(relay1Pin, LOW);
  digitalWrite(relay1Pin, LOW);

  // Initialize the enable pins for the Sabertooth drivers.
  pinMode(ST1enable, OUTPUT);
  pinMode(ST2enable, OUTPUT);
  digitalWrite(ST1enable, LOW);   // disables Sabertooth driver
  digitalWrite(ST2enable, LOW);

  // Initialize the software serial port.
  mySerial.begin(9600);
  delay(1000);

  // // Use the .print method
  // digitalWrite(ST1enable, HIGH);
  // mySerial.print(char(96));   // motor1 at 50% = 64 + 32
  // delay(100);
  // mySerial.print(char(64));   // motor1 STOP = 64
  // digitalWrite(ST1enable, LOW);

  // // Use the .write method
  // digitalWrite(ST1enable, HIGH);
  // mySerial.write(byte(0x60));   // motor1 at 50% = 64 + 32
  // delay(100);
  // mySerial.write(byte(0x40));   // motor1 STOP = 64
  // digitalWrite(ST1enable, LOW);

  setSpeed(1,50);
  delay(2000);
  setSpeed(0,99);
  delay(200);
  setSpeed(2,50);
  delay(2000);
  setSpeed(0,99);
  delay(200);
  setSpeed(3,50);
  delay(2000);
  setSpeed(0,99);
  delay(200);
  setSpeed(4,50);
  delay(2000);
  setSpeed(0,99);
  delay(200);

  setSpeed(1,50);
  setSpeed(2,50);
  setSpeed(3,50);
  setSpeed(4,50);
  delay(2000);
  setSpeed(0,99);
  delay(200);

}

void loop() {
  // put your main code here, to run repeatedly:

}
