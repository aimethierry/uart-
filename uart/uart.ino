#include <stdint.h>

char text[] = "A";
int receiving[8];
uint8_t a;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void getBit()
{
  int len = strlen(text);
  uint8_t mask = 00000001;
  for(int i = 0; i< len; i++)
  {
    uint8_t myBit = (uint8_t)(text[i]);
    uint8_t res = myBit & mask;
  }
}

void shiftBit(uint8_t val)
{
  uint8_t mask = 1;
  int i = 1;
  while(i < 9)
  {
    uint8_t res = val & mask;
    int sh = 1;
    receiving[i] = res;
    mask = mask<<(int)(sh);
    sh++;
    i++;
  }

  showReceived();
}

void ReceivedBit(int val)
{
  int i = 0;
  while(i < 8)
  {
    receiving[i] = (int)(val);
    i++;
  }
}


void showReceived()
{
  int res = 0;
  for(int i =0; i< 8; i++)
  {
    res = res + receiving[i];
    Serial.println(receiving[i]);
    delay(500);
  }

  
//  Serial.println("hello world ");
}


void loop() {
      int len = strlen(text);
      
      for(int i = 0; i< len; i++)
      {
        uint8_t myBit = (uint8_t)(text[i]);
        shiftBit(myBit);
      }
      showReceived();
}
