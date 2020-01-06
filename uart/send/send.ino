#include <stdint.h>

#define transmitPin 3
#define receivePin 2

char text[] = "A";
int receiving[10];
uint8_t a;

void SendBit(int val);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(2400);
  pinMode(transmitPin, OUTPUT);
  pinMode(receivePin, INPUT);

}

void shiftBit(uint8_t val)
{
  uint8_t mask = 1;
  int i = 1;
  int fin = 0;
  while(i < 11)
  {
    uint8_t res = val & mask;
    int sh = 1;
    receiving[i] = res;
    fin += res;
    mask = mask<<(int)(sh);
    sh++;
    i++;
  }
  fin = fin <<1;
  SendBit(fin);
}

void SendBit(int val)
{
  int fin = val | 1;
  uint8_t mask = 1;
  int i = 1;

  Serial.println("send");
  while(i < 11)
  {
    uint8_t res = fin & mask;
    int sh = 1;
    digitalWrite(transmitPin,res);
    
    Serial.println(res, DEC);
    delay(70);
//    Serial.println(res);
    mask = mask<<(int)(sh);
    sh++;
    i++;
  }
  
}
void receive(){
   Serial.println("recieve");
   int fin = 0;
  for(int i=0;i<10;i++){
    int res = digitalRead(receivePin);
    fin += res;
    
    delay(10);
  }
  Serial.println(fin);
  
  
}
void loop() {
      int len = strlen(text);
      Serial.println("Hello world ");
      for(int i = 0; i< len; i++)
      {
        uint8_t myBit = (uint8_t)(text[i]);     
        shiftBit(myBit);
      }

      receive();
}
