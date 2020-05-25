
#include <NewPing.h>

#define SONAR_NUM 2      // Number of sensors.
#define MAX 60 // Maximum distance (in cm) to ping.
#define robo_dis 30
//speed vals

int speeed ;
long duration1;
long duration2;
int distance1;
int distance2;
float traveled_distance;
unsigned long time1;
unsigned long time2;
float elapsed_time;
float measured_speed;

const int trigger_pin = 9;
const int echo_pin = 8;



int max_dis=60;
int disR;
int disL;
int R;
int L;
int R1;
int wait;
int disRLZ=3;//if z=1 then :other robot in right ...else :other robot in left
//int smollestDisL;
void dis();
void forward();
void reverse();
void right();
void left();
void sharpRightTurn();
void sharpLeftTurn();

void stop_bot();





// Motor Variables
int ENA = 10;
int motorInput1 = 3;
int motorInput2 = 2;
int motorInput3 = 5;
int motorInput4 = 4;
int ENB = 11;


int motorA_speed=255;
int motorB_speed=255;

int motorA1_speed=255;
int motorB1_speed=255;


// Output Pins for Led


NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(6, 7, MAX), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(8, 9, MAX)
  //, NewPing(8, 9, MAX_DISTANCE)
};



void setup()
{
 
 
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

 
  Serial.begin(9600);                     //setting serial monitor at a default baund rate of 9600
 
  delay(1000);

  
}
void loop()
{
   analogWrite(ENA, motorA_speed);
   analogWrite(ENB, motorB_speed);
   
  dis();
  
  if(disR!=0 and disR<50){
    right();
  }
else if(disL!=0 and disL<50){
    left();
}
  
}
  /*
  Speed();
  if(speeed<=65){
  sharpLeftTurn();
  reverse();
  while(disR==0){
  right();
  }
  trak();
  delay(5000);
  }
  else if(speeed>65){
reverse();
}
}



*/
void forward()
{
  /*The pin numbers and high, low values might be different depending on your connections */
   //analogWrite(ENA, motorA1_speed);
  //analogWrite(ENB, motorB1_speed);
  
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}
void reverse()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}

void right()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
void left()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}
void sharpLeftTurn() {
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}
void sharpRightTurn() {
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}

void stop_bot()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
void dis(){
   disR=sonar[0].ping_cm();
   disL=sonar[1].ping_cm();
   if (disL==0 and disR!=0 and disR<=robo_dis){
  
   disRLZ=1;
   R=disR;
   }
   else if (disL!=0 and disR==0 and disL<=robo_dis){

   disRLZ=0;
   L=disL;
}
}

/*void study_Speed(){
//study

R1=R;
dis();
delay(300);
dis();

if(R-R1>=6){
reverse();
delay(600);
sharpLeftTurn();
delay(900);
dis();
//moving
//
if((disR!=0 and disR<=max_dis)or(disL!=0 and disL<=max_dis)){
do{
forward();
delay(200)
}
while(disR!=0 and disR<=max_dis)or(disL!=0 and disL<=max_dis);
}

else if(disR==0 and disL==0){
dis();
if(wait>=1500){
  do{
left();//or right cheack the func
  
  }
while(disR==0);


}
else {
delay(100);
wait=wait+100;
}
}
}



else if(R-R1<=6){

}
}*/
float Speed (){
  time1 = millis();
  digitalWrite(trigger_pin, LOW);   // clear the trigger_pin
  delayMicroseconds(2);
  
  // Set the trigger_pin on HIGH state for 10 micro seconds:
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  
  // Read the echo_pin and return the sound wave travel time in microseconds:
  duration1 = pulseIn(echo_pin, HIGH);
  // Calculate the distance:
  distance1 = duration1*0.034/2;

  delay(200);


  // Second ultrasonic measurement...
  time2 = millis();
  // Set the trigger_pin on HIGH state for 10 micro seconds:
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  
  // Read the echo_pin and return the sound wave travel time in microseconds:
  duration2 = pulseIn(echo_pin, HIGH);
  // Calculate the distance:
  distance2 = duration2*0.034/2;  
  
 
  // Compute traveled distance, elapsed time and speed:
  traveled_distance = distance1-distance2;
  elapsed_time = time2-time1;
  measured_speed = (traveled_distance/elapsed_time*36);//*(1000/3600);

  // Print speed only if object final distance is less than 0.5 m away...
  if (distance2<50)
  {
    if ((fabs(traveled_distance) > 1.0))  // Print speed only if object moves for at least 1 cm...
    {
      // Print current distance of a object
      //Serial.print("Objekt je oddaljen ");
      //Serial.print(distance2);

      // Print if object is approaching or moving away
      if (measured_speed > 0)
      {
        //Serial.print("cm, in se približuje s hitrostjo ");
      }
      else
      {
        //Serial.print("cm, in se oddaljuje s hitrostjo ");
      }
      // Print speed of an object
      //Serial.print(fabs(measured_speed));
      //Serial.println(" km/h.");
      speeed=fabs(measured_speed);
      return (speeed);
      
    }
  }
}
void trak(){
//test robot motion
   analogWrite(ENA, motorA_speed);
   analogWrite(ENB, motorB_speed);

  
 
  

  
  

//case 1

  // part 1
  if ( disR<robo_dis and disR>10 and disL==0){
    
    do{
 ;     
    //forward();
     sharpLeftTurn();
    dis();}
    while( disR<robo_dis and disR>10 and disL==0);
  
  }

  // part 2
  
  else if(disL<robo_dis and disL>10 and disR==0){
    do{
      sharpRightTurn();
    
    dis();}
    while(disL<robo_dis and disL>10 and disR==0);
  }
  
   // case 2

else if ((disR!=0 and disL!=0) and  (disR<10  or disL<10) ){//the other robot in danger zone
  do{
    forward();
    delay(100);
    dis();}
    while((disR!=0 and disL!=0) and  (disR<10  or disL<10));//the other robot in danger zone
  
}



     //case 3

     //part 1
     
    else if(disR==0 and disL==0){//the other robot isn't exist
      if(disRLZ==0){//searching about left recommand 
       do{
        sharpLeftTurn();
        dis();}
        while(disR==0 and disL==0);
       }
        //part 2
      else if (disRLZ==1){//searching about right recommand 
        do{
        sharpRightTurn();//حط while
        dis();}
        while(disR==0 and disL==0);}

        //part 3
       
        else if (disRLZ==3){
        do{
        sharpLeftTurn();
        dis();}
        while(disR==0 and disL==0);}
      
       }
       
       
    //case 4
     
        //part 1
        if (disR!=0 and disL==0 and disR>robo_dis and disR<max_dis  ){ //the other robot is exist but in out of attack range
    
            do{
            sharpLeftTurn();
            dis();}
            while(disR!=0 and disL==0 and disR>robo_dis and disR<max_dis);
  
         }

         //part 2
         
        else if(disL!=0 and disR==0 and disL>robo_dis and disL<max_dis){
          
            do{
            sharpRightTurn();
            dis();}
            while(disR==0 and disL!=0);  
        }
  
 
  }




  
  /*Serial.print(disL);
  Serial.print("   ");
  Serial.println(disR);
*/
