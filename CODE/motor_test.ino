
int motorInput1 = 3;
int motorInput2 = 2;
int motorInput3 = 5;
int motorInput4 = 4;
int ENB = 11;


int motorA_speed=255;
int motorB_speed=255;

int motorA1_speed=255;
int motorB1_speed=255;




void setup()
{
 
 
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

 
  Serial.begin(9600);                     //setting serial monitor at a default baund rate of 9600
 
  delay(5000);

  
}
void loop()
{
  
  analogWrite(10, motorA_speed);
   analogWrite(11, motorB_speed);
forward();
delay(1000);
reverse();
delay(1000);
right();
delay(1000);
left();
delay(1000);
sharpRightTurn();
delay(1000);
sharpLeftTurn();
delay(1000);

}




void sharpRightTurn()
{
  /*The pin numbers and high, low values might be different depending on your connections */
   //analogWrite(ENA, motorA1_speed);
  //analogWrite(ENB, motorB1_speed);
  
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}
void sharpLeftTurn()
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
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}
void left()
{
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
void reverse() {
  /*The pin numbers and high, low values might be different depending on your connections */
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}
void forward() {
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
