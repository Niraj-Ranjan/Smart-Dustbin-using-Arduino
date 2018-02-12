#include<Servo.h>              //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle = 0;   
int trig_pin = 3;
int echo_pin = 4; 
const int inter_time = 200;
int time = 0;
 
void setup() 
{ 
  pinMode (trig_pin, OUTPUT);
  pinMode (echo_pin, INPUT);
  servo_test.attach(2);
  Serial.begin(9600);// attach the signal pin of servo to pin9 of arduino
} 
  
void loop() 
{ 


   float duration, distance;
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn (echo_pin, HIGH);
  distance = (duration/2)/29;
  Serial.print(distance);
  Serial.println(" cm");
  time = time + inter_time;
  delay(inter_time);





if(distance <=10)
{
  for(angle = 180; angle>=50; angle-=1)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle); 
    Serial.println("1");
    //command to rotate the servo to the specified angle
      
             
  }


for(angle = 50; angle <=100; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle); 
    Serial.println("2");
    //command to rotate the servo to the specifid angle
    delay(100);  
 
  } 

  
} 
        

    
}
