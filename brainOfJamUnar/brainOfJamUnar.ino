

/*  Un-Named Autonomous Robot A.K.A. Jam UNAR bin Babinah
    
    Arduino Nano w/ ATmega328
    
    Power Supply Components:
    
    The Microcontroller and sensors are mounted to a RadioShack Printed
    Circuit board.
    
      9V Battery Holder
      9V Battery
      6v Slide Switch
    
    The Hexbug Spider XL is currently using its original power supply.
    
      3 AA Batteries - 1.5 Volts
      Slide Switch
    
    Power Suppling Connections:
    
    Positive is 9V Positive terminal to one side of slide switch 
    (using both terminals) then center of Slide Switch (using both 
     terminals) to Vin (Voltage Input) on Arduino
    
    Negative is 9V Negative terminal to opposite side of slide switch 
    (using both terminals) and to GND on Arduino.  The Hexbug Spider XL
    is also grounded to the RadioShack Printed Circuit board.
    
    Sensory Input Components:
    
    3 x HC-SR04 Ultrasonic Ranging Module
    
    Sensory Input Connections:
    
    All power to 5V Arduino with red
    All Gnd to Gnd Arduino with black or orange
    All Trig cables yellow
    All Echo cables green
    
    frontSensor  trig to D5
                 echo to D4
    rightSensor  trig to D12
                 echo to D13
    leftSensor   trig to D6
                 echo to D7

    Transmitter Components:
    
    R433A Transistor
    R315A Transistor
    
    Transistor Connections:
    
    R433A cables brown to D3
    R315A cables green to D2
    
    Robotic Components:
    
    Hexbug Spider XL
    
    Using unknown motor driver.  Numbered left to right
    with the dot in the top right:
    
        Top 2 - forward, Orange
        Top 3 - backwards, Purple
        Top 5 - turn right, Grey
        Top 6 - turn left,  White
        Bottom 2 - LED, Blue
    
    Robotic Connections:
    
    FOR wired Orange to Arduino D11
    BAC  wired Purple to Arduino D8 
    
    TRIGHT wired Orange to Arduino D9
    TLEFT wired Yellow to Arduino D10
    
    LED wired to Positive
    
    */
    
    // Include Libraries
    
    // Must include library for Software Serial Ports for 
    // rfTransmittors, we'll use VirtualWire Code based on
    // Marus Ulfberg's code
    
    #include <VirtualWire.h>
    
    // Now to declare variables
    
    // declare integer constants and initialize them to specific variables
    // for sensory input pins
    
    const int trigPinFrontSensor = 5;
    const int echoPinFrontSensor = 4;
    
    const int trigPinRightSensor = 12;
    const int echoPinRightSensor = 13;
    
    const int trigPinLeftSensor  = 6;
    const int echoPinLeftSensor  = 7;
    
  //  int fDistance;
  //  int rDistance;
  //  int lDistance;
    
    // Initialize and name pins for rf tranmission
    
  //  int numbers[3]; // Change to number of integers you wish to spend
    
    // Initialize and name motor control pins
    
    const int FOR = 11; // Input pin that enable/disable drivers O1/O2
    const int BAC  = 8; // Input pin that determines driving mode(forward,
                   // reverse, standby)
                  
    const int TRIGHT = 9; // Input pin that enable/disable drivers O3/O4
    const int TLEFT  = 10; // Input pin that determines driving mode(forward,
                   // reverse, standby)
                   
    int itteration = 0;
    int i = 0;
    
    // Setup Arduino Nano for UNAR
    
    void setup()
    {
      // set baud rate for communication
      
      Serial.begin(9600);
   /*   
      // set the data rate for tranmission
      vw_setup(2000);
      // Initialise the IO and ISR
      vw_set_ptt_inverted(true);    // Required for RF Link module
      vw_setup(1000);               // Bits per sec
      vw_set_tx_pin(3);   // pin 3 is used as the transmit data out into the TX Link module, change this to suit your needs.
*/
      // Initialize to some sample values
  //    numbers[0] = 32767;
  //    numbers[1] = -2;
  //    numbers[2] = 0;
      // set up sensor pin modes
      
      pinMode(trigPinFrontSensor, OUTPUT);
      pinMode(echoPinFrontSensor, INPUT);
    
      pinMode(trigPinRightSensor, OUTPUT);
      pinMode(echoPinRightSensor, INPUT);
    
      pinMode(trigPinLeftSensor, OUTPUT);
      pinMode(echoPinLeftSensor, INPUT);
      
      
      // Set up motor control pins
      
      pinMode(FOR, OUTPUT);
      pinMode(BAC, OUTPUT);
      
      pinMode(TRIGHT, OUTPUT);
      pinMode(TLEFT, OUTPUT);
      
    }
    
 
    // Now finally for the Actual program
    
    void loop()
    {  
      delay(4000);
      digitalWrite(FOR, HIGH);
      digitalWrite(BAC, LOW);
      digitalWrite(TRIGHT, LOW);
      digitalWrite(TLEFT, LOW);
      delay(10000);
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, LOW);
      digitalWrite(TRIGHT, LOW);
      digitalWrite(TLEFT, LOW);
      delay(100000);
      // sensorCollectData();
      // transmitData();
      // reactToData();
    }
    
//    void reactToData()
//    {
//     wallWalkerRight();
//    }
    
/*    void wallWalkerRight()
    {
     // findWall();
      secureRightWall();
    }
    
    void secureRightWall()
    {
      if ( fDistance > 20 ){
       if (10 <= rDistance <= 15){
     moveForward();
   } 
     if ( 25 > rDistance > 15) {
       moveRightSlightly();
     } 
     if (rDistance >= 25) {
       turnRight();
     }
       if (rDistance < 10) {
         moveLeftSlightly();
       }
   
    } else {
      turnLeft();
    }
    }
    
    
    
    
    void moveForward()
    {
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, HIGH);
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, LOW);
    }
    
    void moveBackward()
    {
      digitalWrite(FOR, HIGH);
      digitalWrite(BAC, HIGH);
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, LOW);
    }
    
    void moveRight()
    {
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, LOW);
      digitalWrite(FOR, HIGH);
      digitalWrite(BAC, HIGH);
    }FOR
    
    void turnRight()
    {
      moveRight();
      delay(450);
      moveForward();
      delay(50);
    }
    
    void moveLeft()
    {
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, LOW);
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, HIGH);
    }

void turnLeft()
    {
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, LOW);
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, HIGH);
      delay(500);
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, HIGH);
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, LOW);
      delay(150);
    }

    void moveRightSlightly()
    {
      moveRight();
      delay(200);
      moveForward();
      delay(10);
    }
    
    void moveLeftSlightly()
    {
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, LOW);
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, HIGH);
      delay(50);
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, HIGH);
      digitalWrite(FOR, LOW);
      digitalWrite(BAC, LOW);
      delay(50);
    }
    // This program collects the data for the three sensors
    
    void sensorCollectData()
    {
     frontSensorDistance();
     rightSensorDistance();
     leftSensorDistance();
    
  //Below is a test print course only to be used to check function
     
  // for the front sensor
   /*  
  if (fDistance >= 200 || fDistance <= 0){
  Serial.println("Out of Range");
  }
  else {
    Serial.print("Front: ");
    Serial.print(fDistance);
    Serial.println(" cm");
  }
  delay(500);
  
  // for the right sensor
  
  if (rDistance >= 200 || rDistance <= 0){
    Serial.println("Out of Range");
  }
  else {
    Serial.print("Right: ");
    Serial.print(rDistance);
    Serial.println(" cm");
  }
  delay(500);
  
  // for the left sensor
  
  if (lDistance >= 200 || lDistance <= 0){
    Serial.println("Out of Range");
  }
  else {
    Serial.print("Left: ");
    Serial.print(lDistance);
    Serial.println(" cm");
  }
  delay(500);
     */
 /*   }
  

// Now for the program to transmit data
void transmitData()
{
  vw_send( (uint8_t *)numbers, sizeof(numbers));
  vw_wait_tx();  // Wait for message to finish
  delay(1000);

}
  
void frontSensorDistance()
{
  int duration;
  digitalWrite(trigPinFrontSensor, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPinFrontSensor,LOW);
  duration = pulseIn(echoPinFrontSensor, HIGH);
  fDistance = (duration/2) / 29.1;
}
   
void rightSensorDistance()
{
  int duration;
  digitalWrite(trigPinRightSensor, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPinRightSensor,LOW);
  duration = pulseIn(echoPinRightSensor, HIGH);
  rDistance = (duration/2) / 29.1;
}

void leftSensorDistance()
{
  int duration;
  digitalWrite(trigPinLeftSensor, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPinLeftSensor,LOW);
  duration = pulseIn(echoPinLeftSensor, HIGH);
  lDistance = (duration/2) / 29.1;
}
 */
