
const int motorL1 = 2;
const int motorL2 = 3;
const int motorR1 = 4; 
const int motorR2 = 5; 
void setup() {
  // put your setup code here, to run once:
   pinMode(motorL1, OUTPUT);
  pinMode(motorR1, OUTPUT);
     pinMode(motorL2, OUTPUT);
  pinMode(motorR2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  moveL();
  delay(200);
 /*Serial.print("Motor L 1 = ");
 Serial.print(motorL1);
 Serial.print("Motor L 2 = ");
 Serial.print(motorL2);
 Serial.print("Motor R 1 = ");
 Serial.print(motorR1);
 Serial.print("Motor R 2 = ");
 Serial.println(motorR2);
*/
}

void moveF()
{
 stop();
 delay(20);
 analogWrite(motorL1,0);
 analogWrite(motorR1,150);
 analogWrite(motorL2,150);
 analogWrite(motorR2,0);

  
}

void moveR()
{
  stop();
 delay(20);
 analogWrite(motorL1,0);
 analogWrite(motorR1,0);
 analogWrite(motorL2,150);
 analogWrite(motorR2,150);
  
}

void moveL()
{
   stop();
 delay(20);
 analogWrite(motorL1,150);
 analogWrite(motorR1,150);
 analogWrite(motorL2,0);
 analogWrite(motorR2,0);
  
}

void stop()
{
 analogWrite(motorL1,0);
 analogWrite(motorR1,0);
 analogWrite(motorL2,0);
 analogWrite(motorR2,0);
}
