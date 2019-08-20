#include<SoftwareSerial.h>
SoftwareSerial gsm(2,3);

void setup() {
  // put your setup code here, to run once:
gsm.begin(115200);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
if(gsm.available())
{
  Serial.write(gsm.read());
}
if(Serial.available())
{
  byte a = Serial.read();
  if(a=='#')
  {
    gsm.write(char(26));
  }
  else
   gsm.write(a);
}
}
