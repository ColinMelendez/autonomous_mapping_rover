#define trigPin 6
#define echoPin 5
#define enableLeft 6
#define leftForward 4
#define leftBackward 3
#define enableRight 5
#define rightForward 8
#define rightBackward 7
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance >= 400 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if(distance > 20) {
    digitalWrite(rightBackward, LOW);
    digitalWrite(rightForward, HIGH);
    digitalWrite(leftBackward, LOW);
    digitalWrite(leftForward, HIGH);
    analogWrite(enableRight, 200);
    analogWrite(enableLeft, 200);
  } else {
    digitalWrite(rightBackward, LOW);
    digitalWrite(rightForward, HIGH);
    digitalWrite(leftBackward, HIGH);
    digitalWrite(leftForward, LOW);
    analogWrite(enableRight, 200);
    analogWrite(enableLeft, 200);
    delay(100);
  }
}