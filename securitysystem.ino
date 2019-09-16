#include <Key.h>
#include <Keypad.h>



String Password ="5986";
String tempPassword="";
const byte ROWS=4;
const byte COLS=4;
char keypressed;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
// DEFINE SYMBOLS ON THE BUTTONS OF THE KEYPAD
byte rowPins[ROWS] = {2,3,5,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7,8,9,10}; 
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  keypressed =myKeypad.getKey();
  if(keypressed)
  Serial.println(keypressed);
  if(keypressed!= NO_KEY)
  {
    if(keypressed=='0'||keypressed=='1'||keypressed=='2'||
    keypressed=='3'||keypressed=='4'||keypressed=='5'||keypressed=='6'||
    keypressed=='7'||keypressed=='8'||keypressed=='9')
    {
      tempPassword += keypressed;
    }
    if(keypressed =='*')
    {
     if(tempPassword ==Password) 
     {
      digitalWrite(12,HIGH);
      
     }
     else
     {
      digitalWrite(11,HIGH);
      
     }
    }
   if(keypressed=='#') 
   {
    tempPassword="";
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    
   }
  }
 
}
