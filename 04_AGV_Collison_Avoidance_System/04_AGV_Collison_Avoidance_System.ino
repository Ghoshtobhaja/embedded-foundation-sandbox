// Pin Definitions
int trigPin = 11; //The "Speaker"
int echoPin = 12; // The "Microphone"
int warningLedPin = 13; // The Emergency Brake Light

// Variables to store data
long duration;  //Time it takes for sound to return
int distanceCm; // The calculated distance in centimeters

void setup(){
  Serial.begin(9600);

  //Configure the pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(warningLedPin, OUTPUT);
}

void loop(){
  // 1. SENSE: Fire the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Clear the Pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //Fire a 10 microseconds blast of sound
  digitalWrite(trigPin, LOW);

  // 2. Read the returning echo (measure time in microseconds)
  duration =pulseIn(echoPin, HIGH);

  // 3. THINK: Convert time into distance
  // Speed of sound is ~0.034cm per microsecond. Divide by 2 because the sound travel out and back.
  distanceCm = duration * 0.034 / 2;

  // 4. ACT: Collision Avoidance Logic
  if (distanceCm > 0 && distanceCm <= 15){
    digitalWrite(warningLedPin, HIGH); //Danger: Apply brakes!
    Serial.println("EMERGENCY STOP: Obstacle Detected!");
  }else{
    digitalWrite(warningLedPin, LOW); //Safe : Keep moving
    Serial.print("Path clear. Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");
  }

  delay(50); //Short delay to prevent the sensor pulses from overlapping
  }