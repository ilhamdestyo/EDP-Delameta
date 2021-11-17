//INISILISASI
int LedR=PA0; 
int LedY=PA1; 
int LedG=PA2;
int led=PC13;
int Ilm_tb1=PB7; 
int Ilm_tb2=PB4; 
int Ilm_tb3=PB5;

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
//digitalWrite(PC13,HIGH);
//delay(100);
//digitalWrite(PC13,LOW);
//delay(200);

//digitalWrite(PA0,HIGH);
//delay(100);
//digitalWrite(PA0,LOW);
//delay(500);
//
//digitalWrite(PA1,HIGH);
//delay(100);
//digitalWrite(PA1,LOW);
//delay(500);
//
//digitalWrite(PA2,HIGH);
//delay(100);
//digitalWrite(PA2,LOW);
//delay(500);

//Baca data dan Data yang muncul pada serial COM6
  int bacaTB1=digitalRead(Ilm_tb1);
  Serial.print("Tombol 1: " + String(bacaTB1));
  int bacaTB2=digitalRead(Ilm_tb2);
  Serial.print("|| Tombol 2: " + String(bacaTB2));
  int bacaTB3=digitalRead(Ilm_tb3);
  Serial.println("|| Tombol 3: " + String(bacaTB3));

////LOGIKA TOMBOL1 LED1
if (bacaTB1==1){
  digitalWrite(LedR, HIGH);
}else{
  digitalWrite(LedR,LOW);
  }
////LOGIKA TOMBOL2 LED2
if (bacaTB2==1){
  digitalWrite(LedY, HIGH);
}else{
  digitalWrite(LedY,LOW);
  }
////LOGIKA TOMBOL3 LED3
if (bacaTB3==1){
  digitalWrite(LedG, HIGH);
}else{
  digitalWrite(LedG,LOW);
  }
}
