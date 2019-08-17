// librairies
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

// pins
#define pirPin A0
/*
  Hardware SPI:
  MISO -> 12
  MOSI -> 11
  SCK -> 13
  CE -> 8
  CSN -> 7
*/

// variables
boolean detected;
byte detectedSignal = B10011100;

void setup()
{
  Serial.begin(9600); // Serial for debugging
  Serial.println("RF module, Serial communication established");
  
  mirfSetup(); // setup of the antenna
}

void loop()
{
  Mirf.setTADDR((byte *)"dog01"); // Setting target address
  
  // upon seeing a rising edge, sending a signal
  if(digitalRead(pirPin) == HIGH && !detected)
  {
    detected = true; // avoid multiple signals
    
    Serial.println("detected");
    Mirf.send(&detectedSignal);
    
    while(Mirf.isSending()) //attente de l'envoi
    {
      //nothing
    }
  }
  
  // detected comes back at false at falling edges
  if(digitalRead(pirPin) == LOW)
  {
    Serial.println("Done detecting");
    detected = false;
  }
}
