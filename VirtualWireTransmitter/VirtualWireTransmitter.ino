// TRANSMITTER

#include <VirtualWire.h>  // you must download and install the VirtualWire.h to your hardware/libraries folder

int numbers[3]; // Change 3 to number of integers you wish to send.

void setup()
{
  // Initialise the IO and ISR
  vw_set_ptt_inverted(true); // Required for RF Link module
  vw_setup(1000);                 // Bits per sec
  vw_set_tx_pin(3);                // pin 3 is used as the transmit data out into the TX Link module, change this to suit your needs.

  // Initialize to some sample values
  numbers[0] = 32767;
  numbers[1] = -2;
  numbers[2] = 0;
}

void loop()
{
  vw_send( (uint8_t *)numbers, sizeof(numbers));
  vw_wait_tx();  // Wait for message to finish
  delay(1000);

  numbers[0]--;  // decrement
  numbers[1]++;  // increment
  numbers[2]++;  // increment
} 
