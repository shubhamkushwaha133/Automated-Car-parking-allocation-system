
#include <Servo.h> //includes the servo library
#include <Wire.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
//LiquidCrystal_I2C lcd(0x27, 20, 4);
Servo myservo;
#define ir_enter 2
#define ir_back  4
#define ir_car1 5
#define ir_car2 6
#define ir_car3 7
int S1=0, S2=0, S3=0;
int S1_init=0,S2_init=0,S3_init=0;
int flag1=0, flag2=0; 
int slot = 3;
bool slots = false,slots_init = false;  

//----------------------------------------------------------------------------

extern "C"
{
  //void main();
  //void _start();
}


//--------------------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


pinMode(ir_car1, INPUT);
pinMode(ir_car2, INPUT);
pinMode(ir_car3, INPUT);

pinMode(ir_enter, INPUT);
pinMode(ir_back, INPUT);
  
myservo.attach(3);
myservo.write(90);

lcd.begin(20, 4);  
lcd.setCursor (0,1);
lcd.print("    Car  parking  ");
lcd.setCursor (0,2);
lcd.print("       System     ");
delay (2000);
lcd.clear();   

Read_Sensor();

int total = S1+S2+S3;
slot = slot-total;
}



//------------------------------------------------------------------------------------

void loop() {
  // put your main code here, to run repeatedly:
 
Read_Sensor();

lcd.setCursor (0,0);
lcd.print("   Have Slot: "); 
lcd.print(slot);
lcd.print("    ");  

lcd.setCursor (0,1);
if(S1==1&&S1_init==0){lcd.print("S1:Fill ");
          Serial.print("\nS1:Full");
          S1_init=1;
          }
     else if(S1==0&&S1_init==1){lcd.print("S1:Empty");
           Serial.print("\nS1:Empty");
           S1_init=0;
           }

lcd.setCursor (10,1);
if(S2==1&&S2_init==0){
  lcd.print("\nS2:Fill ");
  Serial.print("\nS2:Full");
  S2_init=1;}
     else if(S2==0&&S2_init==1){
      lcd.print("\nS2:Empty");
      Serial.print("\nS2:Empty");
      S2_init=0;}

lcd.setCursor (0,2);
if(S3==1&&S3_init==0){
  lcd.print("\nS3:Fill ");
  Serial.print("\nS3:Full");
  S3_init=1;}
     else if(S3==0&&S3_init==1){
      lcd.print("\nS3:Empty");
      Serial.print("\nS3:Empty");
      S3_init=0;}



   

if(digitalRead (ir_enter) == 0 && flag1==0){
if(slot>0){flag1=1;
if(flag2==0){myservo.write(180); slot = slot-1;}
}else{
lcd.setCursor (0,0);
lcd.print(" Sorry Parking Full ");  
delay(1500);
}   
}

if(S1==1&&S2==1&&S3==1){
slots=true;
}
else{
  slots=false;
}
if(slots==true&&slots_init==false){
  Serial.print("\nSorry All Slots are Full, parking not available");
  slots_init=true;
}
else if(slots==false){
  slots_init==false;
}
if(digitalRead (ir_back) == 0 && flag2==0){flag2=1;
if(flag1==0){myservo.write(180); slot = slot+1;}
}

if(flag1==1 && flag2==1){
delay (1000);
myservo.write(90);
flag1=0, flag2=0;
}

delay(1);
}

//-------------------------------------------------------------------------

void Read_Sensor(){
S1=0, S2=0, S3=0;

if(digitalRead(ir_car1) == 0){S1=1;}
if(digitalRead(ir_car2) == 0){S2=1;}
if(digitalRead(ir_car3) == 0){S3=1;}
}
