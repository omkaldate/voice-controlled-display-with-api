#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C screen(0x27 ,16 , 2);
String data;
String data_1;
int i ;
char in;
int led_interupt=13;
int buzer_interupt=12;
void setup() {
  Serial.begin(9600);
  pinMode(led_interupt , OUTPUT);
   pinMode(buzer_interupt , OUTPUT);
  }


void loop() {
  screen.init();
  screen.backlight();
    
  while(Serial.available()){
    digitalWrite(led_interupt , HIGH);
    digitalWrite(buzer_interupt, HIGH);
       delay(50);
     in=Serial.read();
     delay(10);
     data += in;
        }
        digitalWrite(led_interupt,LOW);
        digitalWrite(buzer_interupt,LOW);
        
        
      if(data.length()>0){
    screen.setCursor(0,0);
   screen.print(data);
    delay(1000);

     for(i=0; i<data.length(); i++){
      screen.scrollDisplayLeft();
      delay(300);
      
      }
//      screen.clear();
         }
    
    if(Serial.available()){
      data="";
        }
   
          
      }
