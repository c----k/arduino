/*
Hardware connections:

  You'll need eight LEDs, and eight 330 Ohm resistors
  (orange-orange-brown).
	
    For each LED, connect the negative side (shorter leg)
    to a 330 Ohm resistor.
  
    Connect the other side of the resistors to GND.
  
    Connect the positive side (longer leg) of the LEDs
    to Arduino digital pins 2 through 9.
*/

// Set an array
int ledPins[] = {2,3,4,5,6,7,8,9};

// the elements in the index goes from Index 0 to 7
// for the 8 elements
// LED 0 is connected to pin 2

void setup() // this function runs once when the sketch 
             // starts up
{
  int index;
  int bumper;
  for(index = 0; index <= 7; index++)
  {
    pinMode(ledPins[index],OUTPUT);
    // ledPins[index] is replaced by the value in the array.
    // For example, ledPins[0] is 2
  }
}

void loop()
{
 // lightMarker();
  bumperPong();
}

void bumperPong()
{
  int index;
  int bumper;
  bumper = random(8);
  int delayTime = 200;
  
  for(index = 0; index <= bumper; index++)
  {
    digitalWrite(ledPins[bumper], HIGH);  // turn LED on
    delay(bumper * 200);     // pause to slow down
    digitalWrite(ledPins[index], LOW);
    
    for(index = 0; index <= bumper; index++)
  {
    digitalWrite(ledPins[index], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[index], LOW);
  }
  }
  for(index = bumper; index >= 0; index--)
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
  
}


