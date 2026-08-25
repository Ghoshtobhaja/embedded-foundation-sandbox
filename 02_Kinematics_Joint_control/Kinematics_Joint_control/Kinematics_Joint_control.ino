#include <Servo.h> // This imports the Servo library

Servo myJoint; // Creates a "Servo" object named myJoint
int knobPin = A0; // the analog pin connected to your potentiometer
int knobValue; // Variable to store raw 0-1023 data
int servoAngle; // Variable to store the calculate 0-180 angle

void setup() {
  Serial.begin(9600);
  myJoint.attach(9); // Tells the Arduino the servo signal is on Pin 9
}

void loop() {
  // 1. SENSE: Read the knob
knobValue = analogRead(knobPin);

  // 2. THINK: Translate 0-1023 to 0-180 degrees
  servoAngle = map(knobValue, 0, 1023, 0, 180);

  // 3. ACT: Command the servo to move to that exact angle
  myJoint.write(servoAngle);

  // Print the data to watch the math happens in real-time
  Serial.print("Sensor: ");
  Serial.println(knobValue);
  Serial.print(" ---> Angle : ");
  Serial.println(servoAngle);

  delay(15); //A tiny delay to give the physical motor time to move
}
