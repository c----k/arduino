


// Initialize and Name motor control pins

const int turnBlack = 2;
const int turnWhite = 3;

const int forBlack = 4;
const int forWhite = 5;


void setup()

{
   // Set up motor control pins
      
      pinMode(turnBlack, OUTPUT);
      pinMode(turnWhite, OUTPUT);
      
      pinMode(forBlack, OUTPUT);
      pinMode(forWhite, OUTPUT);
  
}

void loop()

{
  digitalWrite(turnBlack, LOW);
  digitalWrite(turnWhite, LOW);
  
  digitalWrite(forBlack, LOW);
  digitalWrite(forWhite, LOW);
  
}
