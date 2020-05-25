#include <NewPing.h>

#define SONAR_NUM 2      // Number of sensors.
#define MAX 45 // Maximum distance (in cm) to ping.
#define robo_dis 46
int ir;
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

void ir_reder();

int max_dis=60;
int disR;
int disL;

int disRLZ=3;//if z=1 then :other robot in right ...else :other robot in left
//int smollestDisL;
//void ir_reader();
//void dis();
void forward();
void reverse();
void right();
void left();
void sharpRightTurn();
void sharpLeftTurn();

void stop_bot();

void back_right();
void back_left();

//void trak();
//void trak_Attack();


//IR_sensor
void IR();
void IR_2();
//pins
int ir1=A2;//top right
int ir2=A3;//top left
int ir3=13;//back right
int ir4=12;//back left


//vals
bool ir_read1;
bool ir_read2;
bool ir_read3;
bool ir_read4;

int black=1;
int white=0;
int x=0;

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
void dis();

// Output Pins for Led


NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(6, 7, MAX), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(8, 9, MAX)
  //, NewPing(8, 9, MAX_DISTANCE)
};



void setup() {
  // put your setup code here, to run once:
pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  //IR pins
 pinMode(ir1,INPUT);
 pinMode(ir2,INPUT);
 pinMode(ir3,INPUT);
 pinMode(ir4,INPUT);
 
  Serial.begin(9600);                     //setting serial monitor at a default baund rate of 9600
 
  delay(5000);

}

void loop() {
  // put your main code here, to run repeatedly:
  /*
analogWrite(ENA, motorA_speed);
analogWrite(ENB, motorB_speed);

ir_reader();
Serial.println(ir_read4);
while(ir_read4==white){
ir_reader();

  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
    
}
}
*/

dis();
 if(disR!=0 or disL!=0){
  do{
  forward();
  dis();
  }
  while(disR!=0 or disL!=0);
 }
    else if(disR==0 and disL==0){ //the other robot isn't exist
      if(disRLZ==0){//searching about left recommand 
       do{
        sharpLeftTurn();//just change function defenetion ***********************************************************************
        dis();
        
        }
        while(disRLZ==0 and disR==0 and disL==0);
       }
        //part 2
      else if (disRLZ==1){//searching about right recommand 
        do{
        sharpRightTurn();//just change function defenetion ***********************************************************************
        dis();
        
        }
        while(disRLZ==1 and disR==0 and disL==0);}

        //part 3
       
        else if (disRLZ==3){ //intialize case or first case 
        do{
        sharpLeftTurn();//be attention about function defenetion ***********************************************************************
        dis();}
        while(disR==0 and disL==0);}
}
}


/*sharpRightTurn();
delay(1000);
sharpLeftTurn();
delay(1000);
right();
delay(1000);
left();
delay(1000);
 forward();
 delay(1000);
 reverse();
 delay(1000);
 stop_bot();
 delay(1000);*/



void dis(){//NewPing(8, 9, MAX)=sonar
   disR=sonar[0].ping_cm();
   disL=sonar[1].ping_cm();
   /*Serial.print(disL);
   Serial.print ("    ");
   Serial.println(disR);*/
  
   if (disL==0 and disR!=0 /*and disR<=robo_dis*/){
  
   disRLZ=1;//go to right
   //Serial.println("go to right");
   }
   else if (disL!=0 and disR==0 /*and disL<=robo_dis*/){

   disRLZ=0;//go to left
   //Serial.println("go to left");
   
   
}
//Serial.print("disRLZ=");
//Serial.println(disRLZ);


}

void sharpRightTurn()
{
  /*The pin numbers and high, low values might be different depending on your connections */
   //analogWrite(ENA, motorA1_speed);
  //analogWrite(ENB, motorB1_speed);
  IR();
  if(x==0){
     analogWrite(ENA, motorA_speed);
   analogWrite(ENB, motorB_speed);

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
  }
  else {
IR_2();}

}
void sharpLeftTurn()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  IR();
  if(x==0){
  analogWrite(ENA, motorA_speed);
  analogWrite(ENB, motorB_speed);

  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
  }
  else {
    IR_2();}
}

void right()
{
  /*The pin numbers and high, low values might be different depending on your connections */
   IR();
  if(x==0){
  analogWrite(ENA, motorA_speed);
  analogWrite(ENB, motorB_speed);

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
  }
  else {
    IR_2();}
}
void left()
{
  /*The pin numbers and high, low values might be different depending on your connections */
    IR();
  if(x==0){
     analogWrite(ENA, motorA_speed);
   analogWrite(ENB, motorB_speed);

  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
  } 
  else {
    IR_2();} 

}
void reverse() {
  /*The pin numbers and high, low values might be different depending on your connections */
    IR();
  if(x==0){
     analogWrite(ENA, motorA_speed);
   analogWrite(ENB, motorB_speed);

  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
  }  
  else{
    IR_2();}

}
void forward() {
  /*The pin numbers and high, low values might be different depending on your connections */
    IR();
  if(x==0){
     analogWrite(ENA, motorA_speed);
   analogWrite(ENB, motorB_speed);

  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
  }
  else{
    IR_2();}

}

void stop_bot()
{
   analogWrite(ENA, 0);
   analogWrite(ENB, 0);

  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
void ir_reader(){
ir_read1=digitalRead(ir1);//الحساس 1 من قدام عليمين
ir_read2=digitalRead(ir2);//الساس 2 من قدام عليسار
ir_read3=digitalRead(ir3);//الحساس 3 من وراعليمين
ir_read4=digitalRead(ir4);//الحساس 4 من وراعليسار}}
}
void IR(){
  //ir_read1|2|3
  //black=1
  //white=0
ir_read1=digitalRead(ir1);//الحساس 1 من قدام عليمين
ir_read2=digitalRead(ir2);//الساس 2 من قدام عليسار
ir_read3=digitalRead(ir3);//الحساس 3 من وراعليمين
ir_read4=digitalRead(ir4);//الحساس 4 من وراعليسار


if     (ir_read1==black and ir_read2==black and ir_read3==black and ir_read4==black){
x=0;
}
if     (ir_read1==black and ir_read2==black and ir_read3==black and ir_read4==white){
x=1;
}
else if(ir_read1==black and ir_read2==black and ir_read3==white and ir_read4==black){
x=2;
}
else if(ir_read1==black and ir_read2==black and ir_read3==white and ir_read4==white){
x=3;
}
else if(ir_read1==black and ir_read2==white and ir_read3==black and ir_read4==black){ 
x=4;//4قدام عاليسار 6قدام عاليمين 8 قدام التنين
}
else if(ir_read1==black and ir_read2==white and ir_read3==black and ir_read4==white){ 
x=5;
}

else if(ir_read1==white and ir_read2==black and ir_read3==black and ir_read4==black){
x=6;//
}

else if(ir_read1==white and ir_read2==black and ir_read3==white and ir_read4==black){
x=7;
}

else if(ir_read1==white and ir_read2==white and ir_read3==black and ir_read4==black){
x=8;//
}

else if(ir_read1==white and ir_read2==white and ir_read3==white and ir_read4==white){ // لاي لاي لاي لاي  فشلو
x=9;
}
}
void IR_2(){
  analogWrite(ENA, motorA_speed);
   analogWrite(ENB, motorB_speed);

 if(x==1) {//4 is white**************************************************************************************************
   dis();

    
  ir_reader();
while (ir_read4==white){
  forward();
    ir_reader();
}
forward();
delay(1000);
 
 }
 else if(x==2) {
  

   dis();

    
  ir_reader();
while (ir_read3==white){
  forward();
    ir_reader();
}
forward();
delay(1000);
   
 }
  else if(x==3) {

   dis();

    
  ir_reader();
while(ir_read3==white or ir_read4==white){
  forward();
    ir_reader();
}
forward();
delay(1000);
  
 }
   
  
  
 
  else if(x==4) {////4قدام عاليسار 6قدام عاليمين 8 قدام التنين
      //do{

 
   dis();

    
  ir_reader();
while (ir_read2==white){
reverse();
ir_reader();
}
reverse();
delay(1000);
  
    
 }
  else if(x==5) {




 }
  else if(x==6) {
   dis();
  
    
  ir_reader();
while (ir_read1==white){
reverse();
ir_reader();
}
reverse();
delay(1000);
  } 
  else if(x==7) {
  }
  else if(x==8) {

    
  ir_reader();
while (ir_read1==white or ir_read2==white ){
reverse();
ir_reader();
}
reverse();
delay(1000);
  } 
    
 
  
  else if(x==9) {
  
 }

  }
  

void   trak_Attack(){
//test robot motion
analogWrite(ENA, motorA_speed);
analogWrite(ENB, motorB_speed);




//case 1
//robo_dis=30 || MAX=60
  // part 1
  if ( disR<robo_dis and disR>10 and disL==0){
    
    do{
      
    //forward();
     sharpRightTurn();
    dis();
    delay(30);}
    while( disR<robo_dis and disR>10 and disL==0);
  
  }

  // part 2
  
  else if(disL<robo_dis and disL>10 and disR==0){
    do{
      sharpLeftTurn();
    dis();
    delay(30);}
    while(disL<robo_dis and disL>10 and disR==0);
  }
  /*
   // case 2   //tow sensor sees the other robot
    //part 1   //the other robot in danger zone
else if ((disR!=0 or disL!=0) and  ((disR<10 and disR!=0)  or (disL<10 and disL!=0))  ){//the other robot in danger zone*********************************************************and  or
  do{
    for (int i=0;i<10;i++){ //we use for to divide delay and solve problem of ir sensor ,in case when our robot on edge and mabey it will be out while use delay.
     forward();
    delay(10); //you can decrement delay and increment for repeat to more accuracy and efficiency 
    }
    for (int i=0;i<10;i++){
    right();
    delay(50);
    }
    for (int i=0;i<10;i++){
    left();
    delay(50);
    }
    dis();}
    while((disR!=0 or disL!=0) and  ((disR<10 and disR!=0)  or (disL<10 and disL!=0))  );//(disR!=0 and disL!=0) and  (disR<10  or disL<10));//the other robot in danger zone
  
}

    *///part 2 //the other robot in not danger zone
    
else if ((disR!=0 and disL!=0) /*and  (disR>10  or disL>10) */){//the other robot in not danger zone
  do{
    for(int c=0;c<10;c++){
    forward();
    delay(20);
    dis();}
  }
    while((disR!=0 and disL!=0) /*and  (disR<10  or disL<10)*/);//the other robot in not danger zone
  

     //case 3

     //part 1
}

    else if(disR==0 and disL==0){ //the other robot isn't exist
      if(disRLZ==0){//searching about left recommand 
       do{
        sharpLeftTurn();//just change function defenetion ***********************************************************************
        dis();
        delay(40);
        }
        while(disRLZ==0 and disR==0 and disL==0);
       }
        //part 2
      else if (disRLZ==1){//searching about right recommand 
        do{
        sharpRightTurn();//just change function defenetion ***********************************************************************
        dis();
        delay(40);
        }
        while(disRLZ==1 and disR==0 and disL==0);}

        //part 3
       
        else if (disRLZ==3){ //intialize case or first case 
        do{
        sharpLeftTurn();//be attention about function defenetion ***********************************************************************
        dis();}
        while(disR==0 and disL==0);}
      
       }
       
       
   

 

  }
  void back_right(){
  IR();
  if(x==0){
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW);
    digitalWrite(motorInput3, HIGH);
    digitalWrite(motorInput4, LOW);
  }    else
    IR_2();
}

void back_left(){
  IR();
  if(x==0){
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, HIGH);
    digitalWrite(motorInput3, LOW );
    digitalWrite(motorInput4, LOW);
  }    else
    IR_2();
}


