//int Matrix[1000][9];
int SRi[9];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int k=0;k<1000;k++)
  {
    for(int i=0;i<3;i++)
    {
      int indx=i*2;
      //int ndx2=i*2+1;
      SRi[indx]=random(1000);
      SRi[indx+1]=random(1000);
      //Serial.write(SRi[indx]);
      delay(299);
      //Serial.write(SRi[indx+1]);
      //receive
      float Ri= 4;
      SRi[i+6]=Ri;

    }
    Serial.println(' ');
   for(int i = 0; i < 9; i++) {
    Serial.print(SRi[i]);
    Serial.print(',');
  }
 
  }
  while(true){Serial.println("finish");}
}
