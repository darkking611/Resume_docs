
//int switchPin=8;
int ledPin=13;
//boolean lastButton= LOW;
//boolean ledOn= false;
void setup() {
pinMode(ledPin,OUTPUT);
//pinMode(switchPin,INPUT);

}

void loop() {
     /*if(digitalRead(switchPin)==HIGH && lastButton== LOW)
     {
      ledOn=!ledOn;
      lastButton=HIGH;
     }
     else
     lastButton=digitalRead(switchPin);*/
     digitalWrite(ledPin,HIGH);
  
  }
