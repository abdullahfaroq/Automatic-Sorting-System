#include <Servo.h>
#include<LiquidCrystal.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;        

LiquidCrystal lcd(33, 34, 35, 36, 37, 38);  // sets the interfacing pins

int pos = 0;    // variable to store the servo position
int ir1 = 15; //PB_7
int ir2 = 14; //PB_6
int ir3 = 13; //PA_4

int clearcheck = 17;

int buzzer = 5;
int led=4;

int count1=0,count2=0,count3=0;

void setup()
{
  servo1.attach(2); //PB_5
  servo2.attach(3); //PB_0
  servo1.write(0);
  servo2.write(180);

  lcd.begin(16, 2);
    
  pinMode(ir1,INPUT_PULLUP);
 pinMode(ir2,INPUT_PULLUP);
 pinMode(ir3,INPUT_PULLUP);
pinMode(clearcheck,INPUT_PULLUP);
pinMode(buzzer,OUTPUT);
pinMode(led,OUTPUT);


  lcd.clear();
  lcd.setCursor(0,0);        
  lcd.print(">5");
  delay(10);
  lcd.setCursor(4,0);        
  lcd.print("3-5");
  delay(10);
  lcd.setCursor(9,0);        
  lcd.print("Discard");
  delay(10);
  lcd.setCursor(0,1);        
  lcd.print(count1);
  delay(10);
  lcd.setCursor(5,1);        
  lcd.print(count2);
  delay(10);
  lcd.setCursor(12,1);        
  lcd.print(count3);
  delay(10); 
}



void loop()
{ 
 int ir1state= digitalRead(ir1);
 int ir2state= digitalRead(ir2);
 int ir3state= digitalRead(ir3);
 int clearstate=digitalRead(clearcheck);

 if(clearstate==0){
count1=0;
count2=0;
count3=0;
 lcd.setCursor(0,1);        
    lcd.print(count1);
    delay(10);
    
lcd.setCursor(5,1);        
  lcd.print(count2);
  delay(10);
  lcd.setCursor(12,1);        
    lcd.print(count3);
    delay(10);
   
    
    
  }
  
  if (ir1state==0){
    
    count1++;
    lcd.setCursor(0,1);        
    lcd.print(count1);
    delay(10);
  
  
 
  for(pos = 0; pos < 180; pos +=10)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   for(pos = 180; pos>=1; pos-=10)     // goes from 180 degrees to 0 degrees
  {
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }  
}


 if (ir2state==0){

  count2++;
  lcd.setCursor(5,1);        
  lcd.print(count2);
  delay(10);
  
  for(pos = 180; pos>=1; pos-=10)     // goes from 180 degrees to 0 degrees
  {
    servo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for(pos = 0; pos < 180; pos +=10)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    servo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }  
}


if (ir3state==0){
    count3+=1;
     lcd.setCursor(12,1);        
    lcd.print(count3);
    delay(10);
    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(1500);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
    for(pos = 0; pos < 180; pos +=1)
    {
      delay(10);}
   
    
}


}
