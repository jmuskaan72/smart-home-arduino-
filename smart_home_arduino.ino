#include<Servo.h>
#include<LiquidCrystal.h>

Servo myservo;
 int pos=0;
 const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setu0p code here, to run once:
  lcd.begin(16,2); //LCD serial communications
  pinMode(A1,INPUT); //soil
  myservo.attach(8); //servo for water flow
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int soil =analogRead(A1);
Serial.print("Soil moisture: ");
Serial.println(soil);
  if(Serial.available()){
        delay(100);
        lcd.clear();
        while(Serial.available()>0){
          lcd.write(Serial.read());
        }
  }
int persoil =(100-((1023-analogRead(A1))*100)/1023); 
if(persoil>=83 && persoil<=100){
       //motor ON water flow starts
        for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 100 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(20);   
        Serial.println("Water flowing starts");
          if(Serial.available()){
            delay(100);
            lcd.clear();
            while(Serial.available()>0){
                  lcd.write(Serial.read());
              }
          }
        }
          Serial.print("persoil: ");
          Serial.println(persoil);
            if(Serial.available()){
                delay(100);
                lcd.clear();
                while(Serial.available()>0){
                      lcd.write(Serial.read());
                }
            }
     delay(3000);
}
else {
  Serial.print("persoil: ");
  Serial.println(persoil);
    delay(1000);
  Serial.println("SOIL BED CONDITION: NORMAL // NO WATER NEEDED");
    if(Serial.available()){
        delay(100);
        lcd.clear();
        while(Serial.available()>0){
          lcd.write(Serial.read());
        }
  }
 }
}
