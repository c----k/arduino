

/*  This sketch is designed to recieve information from
    Jam Unar as he traverses the world.  */
    
    
    //  Include the library for Software Serial Ports
    
    #include <SoftwareSerial.h>
    
    //  Must Initialize nd name variables and constants
    
    SoftwareSerial rfSerial315(2, 1);      // rx, tx 
    SoftwareSerial rfSerial433(3, 1);      // rx, tx
    
    int rDistance;
    int lDistance;
    
    // setup the pins and baud rates
    
    void setup()
    {
      // Open serial communication to the computer
      Serial.begin(9600);
      // set the data rate for the SoftwareSerial port
      rfSerial315.begin(2400);
      rfSerial433.begin(4800);
    }
    
    // Now it is time to setup a loop
    void loop()
    {
      receiveData();
      
      // Here is a test to check if info is received
      
      Serial.println(rDistance, lDistance);
      delay(500);
    }
    
    void receiveData()
    {
      rDistance = rfSerial315.read();
      lDistance = rfSerial433.read();
    }
    
    
      
    
      
