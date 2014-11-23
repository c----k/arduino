



// Include the library for Software Serial Ports

#include <SoftwareSerial.h>


//  Must initialize and name variables and constants

SoftwareSerial rfSerial(10,11);
int received;


//  Now we setup the pins and set baud rates
void setup()
{
  // open serial communication to the commputer
  Serial.begin(9600);
  // make a test to see if communication is open
  Serial.println("I'm ready to go");
  
  //set the data rate for the SoftwareSerial port
  rfSerial.begin(4800);
}


// Now it is time to setup a loop
void loop()
{
  transmitPlease(); // hopefully will tansmit data
  recievePlease();  // hopefully will receive data
  printPlease();    // hopefully will print to serial port
}

void transmitPlease()
{
  rfSerial.print(33);
  delay(100);
}

void recievePlease()
{
  if (rfSerial.available() > 0) {
  received = rfSerial.read();
  }
}

void printPlease()
{
  Serial.println(received);
}
