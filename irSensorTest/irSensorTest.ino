

/*  HC-SR04 Ping Distance Sensor
    VCC to arduino 5v
    GND to arduino GND
    
    trig to arduino pin 2
    echo to arduino pin 3
*/

// Initialize and name variables

const int trigPin = 9;
const int echoPin = 8;

void setup() {
  
  //  set the baud rate
  Serial.begin (9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


//  Now for the program
void loop() {
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of Range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
