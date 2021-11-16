//Inisialisasi
int PIRsensor =2;
int buzzer=5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIRsensor,INPUT);
  pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int bacaPIR=digitalRead(PIRsensor);//baca sensor PIR

 //PRINT SERIAL
 Serial.print("Nilai PIR :");
 Serial.print(bacaPIR);
 Serial.println();

 //LOGIKA
 if(bacaPIR==1){ 
  int freq=1020;
  tone(buzzer,5);
  digitalWrite(buzzer,HIGH);Serial.println("ADA MALING!!");}
  else{digitalWrite(buzzer,LOW);}

}
