//Server:Uno
#include <SoftwareSerial.h>
//SoftwareSerial mySerial(10,11);//Rx,Tx
String m[] ={"<123>","<234>","<345>","<678>"};
//int m[] ={"123","234,345,678};
//int m[]= {11,22,44,45};
// Example 4 - Receive a number as text and convert it to an int
/*
const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;

int dataNumber = 0;             // new for this version
*/
String num;
int i=0;
int j=0;

bool clean = true;

void setup() {
    Serial.begin(9600);
    //mySerial.begin(9600);
    Serial.println("<Arduino is ready>");
}

void loop() {
  cleanBuffer(j);

  num = m[i];  

  //Serial.print("Sent:");
  //mySerial.print(num);
  Serial.print(num);

  i++;
  i=i%4;
  j++;
  j =j%10;
/*  while(Serial.available()>0)
{
  Serial.read();      
}*/
}
void cleanBuffer(int j)
{
   if(j%10 == 0 or clean == true)
  {
    while(Serial.available()>0)
    {
      Serial.print(Serial.read());      
    }
    /*while(mySerial.available()>0)
    {
      mySerial.read();      
    }*/
  clean = false;
  } 
}
