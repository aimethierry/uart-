#include <stdint.h>

#define transmitPin 3
#define receivePin 2


int receiving[8];
uint8_t a;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(transmitPin, OUTPUT);
  pinMode(receivePin, INPUT);

}

void shiftBit(uint8_t val)
{
  
}


void loop() {

      if(Serial.available() > 0)
      {
        int readByte = Serial.read();
        Serial.println((char)(readByte));
      }
}
