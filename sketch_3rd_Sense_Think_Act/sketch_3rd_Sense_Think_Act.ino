int sensorValue = 0;
int sensorPin = A0;
int ledPin = LED_BUILTIN;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
 // SENSE: Read the physical knob
 sensorValue = analogRead(sensorPin);

 Serial.print("Knob Position: ");
 Serial.println(sensorValue);

 // THINK & ACT: The Logic Gate
 // 512 is exactly half of range 0-1023 range
 if (sensorValue > 512){
  // If knob is turned past halfway, turn the LED ON
  digitalWrite(ledPin, HIGH);
  Serial.println("WARNING: Threshold Exceeded!");
 } else {
  // If it is below halfway, keep the LED OFF
  digitalWrite(ledPin, LOW);
 }
  delay(100);
}
