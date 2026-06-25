// Pin definitions
const int trigPin = 10;  // HC-SR04 Trig
const int echoPin = 11;  // HC-SR04 Echo
const int k1 = 2;        // Red LED 1 (top)
const int k2 = 3;        // Red LED 2 (bottom)
const int s1 = 4;        // Yellow LED 1 (top)
const int s2 = 5;        // Yellow LED 2 (bottom)
const int y1 = 6;        // Green LED 1 (top)
const int y2 = 7;        // Green LED 2 (bottom)
const int buzzer = 8;    // Buzzer

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(k1, OUTPUT); pinMode(k2, OUTPUT);
  pinMode(s1, OUTPUT); pinMode(s2, OUTPUT);
  pinMode(y1, OUTPUT); pinMode(y2, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  long duration, cm;

  // Trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calculate distance
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.println(" cm");

  // Reset all LEDs and buzzer
  digitalWrite(k1, LOW); digitalWrite(k2, LOW);
  digitalWrite(s1, LOW); digitalWrite(s2, LOW);
  digitalWrite(y1, LOW); digitalWrite(y2, LOW);
  noTone(buzzer);

  // LED and buzzer control based on distance
  if (cm > 60) {
    digitalWrite(y2, HIGH);                          // Safe — single green
  } else if (cm > 50) {
    digitalWrite(y2, HIGH); digitalWrite(y1, HIGH);  // Safe — double green
  } else if (cm > 40) {
    digitalWrite(s2, HIGH);                          // Caution — single yellow
  } else if (cm > 30) {
    digitalWrite(s2, HIGH); digitalWrite(s1, HIGH);
    tone(buzzer, 1000);                              // Warning — double yellow + buzzer
  } else if (cm > 15) {
    digitalWrite(k2, HIGH);
    tone(buzzer, 2000);                              // Danger — single red
  } else {
    digitalWrite(k2, HIGH); digitalWrite(k1, HIGH);
    tone(buzzer, 3000);                              // Critical — double red
  }

  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  // Speed of sound: 340 m/s = 29 microseconds/cm
  // Signal travels out and back, so divide by 2
  return microseconds / 29 / 2;
}
