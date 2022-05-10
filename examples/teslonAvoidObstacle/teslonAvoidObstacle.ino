#include <teslon.h>
teslon robot; 

#define LeftLeg 2
#define RightLeg 3
#define LeftFoot 4
#define RightFoot 5
#define touch 6
#define Buzzer  7
#define Trigger 9
#define Echo 8
#define red 10
#define green 11
#define blue 12

long ultrasonic() 
{
   long duration, distance;
   digitalWrite(Trigger,LOW);
   delayMicroseconds(2);
   digitalWrite(Trigger, HIGH);
   delayMicroseconds(10);
   digitalWrite(Trigger, LOW);
   duration = pulseIn(Echo, HIGH);
   distance = duration/58;
   return distance;
}

void setup() 
{
  robot.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
  robot.home();
  delay(50);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(Trigger, OUTPUT); 
  pinMode(Echo, INPUT); 
}

void Green()
{
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(red, HIGH);
}
void Red()
{
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}
void Blue()
{
  digitalWrite(blue, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
}




int count=0;
void loop() 
{
    if(ultrasonic() <= 7) 
    {
       Red();
      robot.sing(S_confused);
      robot.walk(3,1000,-1); 
      Blue();
      if(count&1)
        robot.turn(3,1000,1); 
      else
        robot.turn(3,1000,-1);
      
      count++;
    }
    else
     {
         Green();              
         robot.walk(1,1000,1); 
     }

}
