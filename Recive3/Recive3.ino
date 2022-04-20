//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(10,11);//Rx,Tx
const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;
bool clean = true;
int i=0;
int dataNumber = 0;             // new for this version

void setup() {
    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
    Serial1.begin(9600);
}

void loop() {
    cleanBuffer(i);
    recvWithEndMarker();
    showNewNumber();
    i++;
    i=i%10;
}

void recvWithEndMarker() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
    Serial.println("time to read");
    while (Serial1.available() > 0 && newData == false) {
        rc = Serial1.read();

        if (recvInProgress == true) {
           if (rc != endMarker){
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            recvInProgress = false;
            ndx = 0;
            newData = true;
        }
    }
      else if(rc == startMarker){
        recvInProgress = true;

      }
    }
}

void showNewNumber() {
    if (newData == true) {
        dataNumber = 0;             // new for this version
        dataNumber = atoi(receivedChars);   // new for this version
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        Serial.print("Data as Number ... ");    // new for this version
        Serial.println(dataNumber);     // new for this version
        newData = false;
    }
}
void cleanBuffer(int i)
{
   if(i%10 == 0 or clean == true)
  {
    while(Serial.available()>0)
    {
      Serial.print(Serial.read());      
    }
    while(Serial1.available()>0)
    {
      Serial1.read();      
    }
  clean = false;
  } 
}
