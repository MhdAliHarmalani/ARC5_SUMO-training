#include <NewPing.h>
int disR;
int disL;
int MAX=30;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
disL=NewPing(6,7,MAX).ping_cm();
disR=NewPing(8,9,MAX).ping_cm();

Serial.print("disL=");
Serial.print(disR);
Serial.print("   ");
Serial.print("disR=");
Serial.println(disL);
}
