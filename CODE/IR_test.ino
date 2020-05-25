int ir1=12;//top right
int ir2=13;//top left
int ir3=A3;//back right
int ir4=A4;//back left

bool ir_read1;
bool ir_read2;
bool ir_read3;
bool ir_read4;

void setup() {
  // put your setup code here, to run once:
 pinMode(ir1,INPUT);
 pinMode(ir2,INPUT);
 pinMode(ir3,INPUT);
 pinMode(ir4,INPUT);
 Serial.begin(9600);
 delay(5000);
}
// white=0
//black=1 
void loop() {
  // put your main code here, to run repeatedly:
ir_read1=digitalRead(ir1);//الحساس 1 من قدام عليمين
ir_read2=digitalRead(ir2);//الساس 2 من قدام عليسار
ir_read3=digitalRead(ir3);//الحساس 3 من وراعليمين
ir_read4=digitalRead(ir4);//الحساس 4 من وراعليسار

Serial.print("ir1=");
Serial.print(ir_read1);
Serial.print("   ");

Serial.print("ir2=");
Serial.print(ir_read2);
Serial.print("   ");

Serial.print("ir3=");
Serial.print(ir_read3);
Serial.print("   ");

Serial.print("ir4=");
Serial.println(ir_read4);

}
