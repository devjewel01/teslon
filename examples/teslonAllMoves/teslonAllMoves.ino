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


void loop() 
{
  Green();
  robot.walk(2, 1000, 1);
  robot.home();
  
  Red();
  robot.walk(2, 1000, -1);
  robot.home();
  
  Blue();
  robot.turn(2, 1000, 1);
  delay(100);
  robot.turn(2, 1000, -1);
  robot.home();

  Blue();
  robot.turn(2, 1000, -1);
  delay(100);
  robot.turn(2, 1000, 1);
  robot.home();
  
  robot._tone(10, 3, 1);
  robot.bendTones (100, 200, 1.04, 10, 10);
  delay(100);
  robot.home();

  robot.bend (1,500,1); 
  robot.bend (1,2000,-1);  
  delay(100);
  robot.home();
  
  robot.moonwalker(3, 1000, 25,1);
  robot.moonwalker(3, 1000, 25,-1);  
  delay(100);
  robot.home();
  
  robot.crusaito(2, 1000, 20,1);
  robot.crusaito(2, 1000, 20,-1);
  delay(100); 
  robot.home();
  
  robot.flapping(2, 1000, 20,1);
  robot.flapping(2, 1000, 20,-1);
  delay(100);
  robot.home();
  
  robot.swing(2, 1000, 20);
  delay(100);
  robot.home();
  
  robot.tiptoeSwing(2, 1000, 20);
  robot.jitter(2, 1000, 20);
  delay(100);
  robot.home();

  robot.updown(2, 1500, 20); 
  delay(100);
  robot.home();
  
  robot.ascendingTurn(2, 1000, 50);
  delay(100);  
  robot.home();

  robot.shakeLeg (1,1500, 1);
  delay(100);
  robot.home();

  robot.shakeLeg (1,1500, -1);
  delay(300);
  robot.home();

  robot.sing(S_cuddly);
  robot.sing(S_OhOoh);
  robot.sing(S_OhOoh2);
  robot.sing(S_surprise);
  robot.sing(S_buttonPushed);       
  robot.sing(S_mode1);        
  robot.sing(S_mode2);         
  robot.sing(S_mode3);  
  robot.sing(S_sleeping);
  robot.sing(S_fart1);
  robot.sing(S_fart2);
  robot.sing(S_fart3);
  robot.sing(S_happy);
  robot.sing(S_happy_short);                   
  robot.sing(S_superHappy);   
  robot.sing(S_sad);               
  robot.sing(S_confused);
  robot.sing(S_disconnection);
  delay(100);

  
  robot.home();
  
}
