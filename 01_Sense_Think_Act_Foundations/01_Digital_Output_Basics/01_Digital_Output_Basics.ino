void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // Open the communication channel
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("System Status : LED is ON.");
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("System Status : LED is OFF.");
  delay(1000);
}
