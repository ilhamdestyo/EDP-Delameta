//INISILISASI
int LedR=PA0; 
int LedY=PA1; 
int LedG=PA2;
int led=PC13;
int Ilm_tb1=PA3; 
int Ilm_tb2=PA4; 
int Ilm_tb3=PA5;
int flag=0;


//Program yang buat
void setup() {
  //KONFIGURASI
Serial.begin(115200);
//SEBAGAI INPUT
pinMode(LedR,OUTPUT);
pinMode(LedY,OUTPUT);
pinMode(LedG,OUTPUT);
pinMode(led,OUTPUT);
//SEBAGAI OUTPUT
pinMode(Ilm_tb1,INPUT);
pinMode(Ilm_tb2,INPUT);
pinMode(Ilm_tb3,INPUT);
}

void loop() {
//Baca data
  int bacaTB1=digitalRead(Ilm_tb1);
  int bacaTB2=digitalRead(Ilm_tb2);
  int bacaTB3=digitalRead(Ilm_tb3);
  
//Data yang muncul pada serial COM6
  Serial.print("Tombol 1: " + String(bacaTB1));
  Serial.print("|| Tombol 2: " + String(bacaTB2));
  Serial.println("|| Tombol 3: " + String(bacaTB3));

////LOGIKA TOMBOL1 LED1
if (bacaTB1==1 && flag==0){
    delay(500);
    digitalWrite(LedR,HIGH);
    flag=1;
  }else if(bacaTB1==1 && flag==1){
    delay(500);
    digitalWrite(LedR,LOW);
    flag=0;
}

////LOGIKA TOMBOL1 LED2
if (bacaTB2==1 && flag==0){
    delay(500);
    digitalWrite(LedY,HIGH);
    flag=1;
  }else if(bacaTB2==1 && flag==1){
    delay(500);
    digitalWrite(LedY,LOW);
    flag=0;
}

////LOGIKA TOMBOL1 LED3
if (bacaTB3==1 && flag==0){
    delay(500);
    digitalWrite(LedG,HIGH);
    flag=1;
  }else if(bacaTB3==1 && flag==1){
    delay(500);
    digitalWrite(LedG,LOW);
    flag=0;
}

}
