int sensorValue = 0;
int sensorPin = A0;
int ledPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  
  Serial.print("Knob Postion: ");
  Serial.println(sensorValue);

  // Logic gate
  if (sensorValue < 512){
    digitalWrite(ledPin, LOW);
  }else{
    digitalWrite(ledPin, HIGH);
    Serial.println("WARNING : THRESHOLD EXCEEDED");
  }
  delay(1000);
}
