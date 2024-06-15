#include <Keypad.h> //header for keypad commands enabling
#include <LiquidCrystal.h> // includes the LiquidCrystal Library
 
LiquidCrystal lcd(33, 34, 35, 36, 37, 38); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 

const byte ROWS = 4; // Four rows

const byte COLS = 4; // Three columns

// Define the Keymap

char keys[ROWS][COLS] = {

  {'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}

};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.

byte rowPins[ROWS] = { 3, 4, 5, 6 };

// Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins.

byte colPins[COLS] = { 7, 8, 9, 10 };

//  Create the Keypad

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int LED = 28; 

const int stepPin = 13; 
const int dirPin = 27; 

char first='0',second='0',third='0',fourth='0';
int count=0;

void setup()

{
   pinMode(LED, OUTPUT); 
   pinMode(stepPin,OUTPUT); 
   pinMode(dirPin,OUTPUT);


   
   lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display

  lcd.clear(); // Clears the display 
 lcd.setCursor(4,0); 
 lcd.print("Welcome"); // Prints "Welcome" on the LCD 
 delay(1000); // 1 seconds delay
 lcd.setCursor(3,1); // Sets the location at which subsequent text written to the LCD will be displayed 
 lcd.print("Group # 06"); 
 delay(4000); 
 lcd.clear(); // Clears the display 
 
 lcd.setCursor(0,0);
 lcd.print("2020-MC-29");
 lcd.setCursor(0,1);
 lcd.print("A.Rehman Farooq");
 delay(2000);  
 lcd.clear();

 
 lcd.setCursor(0,0);
 lcd.print("2020-MC-28");
 lcd.setCursor(0,1);
 lcd.print("Ibrahim Haroon");
 delay(2000);  
 lcd.clear();

  
 lcd.setCursor(0,0);
 lcd.print("2020-MC-27");
 lcd.setCursor(0,1);
 lcd.print("Baqir Zaidi");
 delay(2000);  
 lcd.clear();

 
 lcd.setCursor(0,0);
 lcd.print("2020-MC-15");
 lcd.setCursor(0,1);
 lcd.print("Abdullah Farooq");
 delay(2000);  
 lcd.clear();



 lcd.setCursor(0,0);
 lcd.print("2020-MC-07");
 lcd.setCursor(0,1);
 lcd.print("M. Hammad");
 delay(2000);  
 lcd.clear();

 
 lcd.setCursor(0,0);
 lcd.print("2020-MC-01");
 lcd.setCursor(0,1);
 lcd.print("Rana Umer");
 delay(2000);  
 lcd.clear();
}

void loop()

{
 char key = kpd.getKey(); //storing pressed key value in a char

 if(key == NO_KEY && count==0)
    {lcd.setCursor(0,0);
    lcd.print("Enter Password >> ");
    count++;}
    

START:  
  if (key != NO_KEY)

{
//shift digits  
fourth=third;
third=second;
second=first;
first=key;
lcd.clear();
delay(100);  
lcd.setCursor(0,0);   
lcd.print(char(fourth));
delay(100);
lcd.setCursor(2,0); 
lcd.print(char(third));
delay(100);
lcd.setCursor(4,0); 
lcd.print(char(second));
delay(100);
lcd.setCursor(6,0); 
lcd.print(char(first));
delay(100);
lcd.setCursor(0,1);
lcd.print("Wrong Password");
  }


  

  if (first == '1' && second == '2' && third == '3' && fourth == '4')
{

 //Password is correct
  
 digitalWrite(LED, HIGH);

 lcd.clear(); 
 lcd.setCursor(0,0);
 lcd.print("Press B to ");
 lcd.setCursor(0,1);
 lcd.print("Go Back.");
 delay(1000);

while(1){
//Read keypad input
  char fourth = kpd.getKey();
  
 digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500);}
   
    if(fourth ==  'B'){
      digitalWrite(LED, LOW);
      fourth='1';
      delay(100);
      goto START;
       } 
     }     
}

else{
  // When pass is incorrect
  digitalWrite(LED, LOW);
} 
}
