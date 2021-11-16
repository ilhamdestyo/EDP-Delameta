//include LIBRARY
#include <NewPing.h>

//inisialisasi pembuatan variable
int echo = 2;
int trig=3;
int batas=200;
int buzz=4;
int lR=5,lY=6,lG=7;

NewPing cm(trig,echo,batas);

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Micro
  Serial.begin(115200);
  pinMode(buzz,OUTPUT);
  pinMode(lR,OUTPUT);pinMode(lY,OUTPUT);pinMode(lG,OUTPUT);
}

void loop() {
  // program yang dijalankan
  int jarak=cm.ping_cm();

  //PRINT
  Serial.print("Data jarak: ");
  Serial.print(jarak);
  Serial.print(" cm");
  Serial.println();

  //LOGIKA
   if(jarak <=20 and jarak ==1){digitalWrite(lG,LOW);digitalWrite(lY,LOW);digitalWrite(lR,HIGH);Serial.println("BERHENTI");
                  digitalWrite(buzz,HIGH);delay(100);digitalWrite(buzz,LOW);
  }
  else if(jarak >=21 && jarak <=70){
    digitalWrite(lY,HIGH);digitalWrite(lG,LOW);;digitalWrite(lR,LOW);Serial.println("BAHAYA");
    digitalWrite(buzz,HIGH);delay(1000);digitalWrite(buzz,LOW);
  }
  else{
    digitalWrite(lR,LOW);digitalWrite(lY,LOW);digitalWrite(lG,HIGH);Serial.println("AMAN");digitalWrite(buzz,LOW);
  }
  delay(100);
}
