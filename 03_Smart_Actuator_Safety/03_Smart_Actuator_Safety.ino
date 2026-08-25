#include <Servo.h>

Servo roboticArm;
int joystickPin = A0; //Potentiometer knob
int warningLedPin = 13; //Red LED
int sensorData; //Raw values from 0-1023
int armAngle; // Mapped angles from 0-180

void setup(){
  Serial.begin(9600); 
  roboticArm.attach(9);   // Servo signal wire on Pin 9
  pinMode(warningLedPin, OUTPUT); //LED setup
}

void loop(){
  //1. SENSE
  sensorData = analogRead(joystickPin);

  //2. THINK: Translate to angle
  armAngle = map(sensorData, 0, 1023, 0, 180);

  //3. ACT: Move the arm
  roboticArm.write(armAngle);

  //4. SAFETY OVERRIDE LOGIC
  if (armAngle > 135){
    digitalWrite(warningLedPin, HIGH); //Danger zone : LED ON
    Serial.println("WARNING: Safety Zone Exceeded!");
  }else{
    digitalWrite(warningLedPin, LOW); //Safe zone : LED OFF
    Serial.print("Current Angle: ");
    Serial.println(armAngle);
  }

  delay(15);
}