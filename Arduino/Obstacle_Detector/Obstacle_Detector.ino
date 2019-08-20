/*Obstacle Detector using 3 Ultrasonic Sensor HC-SR04
 */
 
const int trig_f = 12;
const int echo_f = 11;
const int trig_r = 13;
const int echo_r = 10; 
const int trig_l = 8;
const int echo_l = 9;

const int motorL1 = 2;
const int motorL2 = 3;
const int motorR1 = 4; 
const int motorR2 = 5; 
int is_f_wall, is_r_wall, is_l_wall, event, r_way, l_way;
int max_d=12;
int max_speed =150;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig_f, OUTPUT);
  pinMode(echo_f, INPUT);
  pinMode(trig_r, OUTPUT);
  pinMode(echo_r, INPUT);
  pinMode(trig_l, OUTPUT);
  pinMode(echo_l, INPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorR1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR2, OUTPUT);
  event=0;
  Serial.begin(9600);
  }

void loop() {
  // put your main code here, to run repeatedly:
  is_f_wall = f_wall();
  is_r_wall = r_wall();
  is_l_wall = l_wall();
  if(f_wall())
  {
    if(r_wall())
    {
      if(l_wall())
      {
        moveR();
        delay(200);
      }
      else
      {
        moveL();
        delay(200);
      }
    }
    else
     {
      moveR();
      delay(200);
     }
  }

  else
   {
    if(r_way>0 && event)
    {
      if(!(r_wall()))
      {
        moveR();
        delay(200);
      }
      else
       {
        moveF();
        delay(200);
       }
     }

    if(l_way>0&& event)
    {
      if(!(l_wall()))
      {
        moveL();
        delay(200);
      }
      else
       {
        moveF();
        delay(200);
       }
     }

     else
     {
      moveF();
      delay(200);
     }
    
   }
  if(!(is_r_wall))
  {
    r_way = 1;
    l_way = 0; 
  } 
  if(!(is_l_wall))
  {
    l_way = 1;
    r_way = 0;
  }

}

int f_wall()
{ int s;
  int f_dist;
  digitalWrite(trig_f,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_f, HIGH);
  delayMicroseconds(10);
  s=pulseIn(echo_f, HIGH,10000);
  f_dist=(s/2)*0.0343;
  Serial.print(" forward_wall = ");
  Serial.println(f_dist);
  if(f_dist<=max_d&& f_dist>0)
  {
    return 1;
  }
  else
   return 0;
}

int r_wall()
{
  int s;
  int r_dist;
  digitalWrite(trig_r,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_r, HIGH);
  delayMicroseconds(10);
  s=pulseIn(echo_r, HIGH,10000);
  r_dist=(s/2)*0.0343;
  Serial.print(" right_wall = ");
  Serial.println(r_dist);
  if(r_dist<=max_d&& r_dist>0)
  {
    return 1;
  }
  else
   return 0;
}

int l_wall()
{ int s;
  int l_dist;
  digitalWrite(trig_l,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_l, HIGH);
  delayMicroseconds(10);
  s=pulseIn(echo_l, HIGH,10000);
  l_dist=(s/2)*0.0343;
  Serial.println(" left_wall = ");
  Serial.println(l_dist);
  if(l_dist<=max_d&& l_dist>0)
  {
    return 1;
  }
  else
   return 0;
}

void moveF()
{
 stop();
 delay(20);
 analogWrite(motorL1,0);
 analogWrite(motorR1,max_speed);
 analogWrite(motorL2,max_speed);
 analogWrite(motorR2,0);

  
}

void moveR()
{
  stop();
 delay(20);
 analogWrite(motorL1,0);
 analogWrite(motorR1,0);
 analogWrite(motorL2,max_speed);
 analogWrite(motorR2,max_speed);
  
}

void moveL()
{
   stop();
 delay(20);
 analogWrite(motorL1,max_speed);
 analogWrite(motorR1,max_speed);
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
