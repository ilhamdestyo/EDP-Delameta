//include LIBRARY
#include <Wire.h>
#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

//inisialisasi pembuatan variable
int LedR=PA0; 
int LedY=PA1; 
int LedG=PA2;
int led=PC13;
int pir=PB0;
int echo=PA7;
int trig=PA6;
int batas=400;
int flag=0;

NewPing cm(trig,echo,batas);
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(LedR,OUTPUT);
pinMode(LedY,OUTPUT);
pinMode(LedG,OUTPUT);
pinMode(led,OUTPUT);
pinMode(pir,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int bacaPIR=digitalRead(pir);
//  
  int jarak=cm.ping_cm();
  if (bacaPIR==1 && flag==0){
    delay(100);
    setledR();
    setledY();
    setledG();
    flag=1;
  }else if(bacaPIR==1 && flag==1){
    delay(100);
    flag=0;
  }

}


//Fungsi yang dibuat
void setledR(){
  int jarak=cm.ping_cm();
  if(jarak <=20 and jarak ==1){
  digitalWrite(LedG,LOW);digitalWrite(LedY,LOW);digitalWrite(LedR,HIGH);
  lcd.setCursor(0,0); lcd.print("BERHENTI!");
  }
}
  
void setledY(){
  int jarak=cm.ping_cm();
  if(jarak >=21 && jarak <=70){
    digitalWrite(LedY,HIGH);digitalWrite(LedG,LOW);;digitalWrite(LedR,LOW);
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("WARNING");
  }
}

void setledG(){
    int jarak=cm.ping_cm();
    if(jarak>=70){digitalWrite(LedR,LOW);digitalWrite(LedY,LOW);digitalWrite(LedG,HIGH);
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("AMAN");
    }
  }
