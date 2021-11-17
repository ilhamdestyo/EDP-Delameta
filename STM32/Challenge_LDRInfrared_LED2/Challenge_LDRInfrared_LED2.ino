//INISILISASI
int LedR=PA0; 
int LedY=PA1; 
int LedG=PA2;
int led=PC13;
int ir=PA3;
int ldr=PA4;
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
}

void loop() {
  int bacair=digitalRead(ir);
  int bacaldr=analogRead(ldr);

  baca ldr=map(bacaldr,0,4095,255,0);

  Serial.print("Nilai IR: "+ String(bacair));
  Serial.println(" || Nilai LDR: "+ String(bacaldr));
  Serial.println(flag);

  //Logika
  if(bacair==0 && flag==0){
    flag=1;
    delay(500);
  }else if(bacair==0 && flag==1){
    digitalWrite(ledR,LOW);
    digitalWrite(ledY,LOW);
    digitalWrite(ledG,LOW);
    flag=0;
    delay(500);
  }

  if(bacaldr>=200 && flag==1){
    digitalWrite(ledR,LOW);
    digitalWrite(ledY,LOW);
    digitalWrite(ledG,HIGH);
  }else if(bacaldr>=100 && bacaldr<200 && flag==1){
    digitalWrite(ledR,LOW);
    digitalWrite(ledY,HIGH);
    digitalWrite(ledG,LOW);
  }else if(flag=1){
    digitalWrite(ledR,HIGH);
    digitalWrite(ledY,LOW);
    digitalWrite(ledG,LOW);
  }
}
