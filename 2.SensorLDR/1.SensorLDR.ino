//Inisialisasi
int LDR =A0;
int led=5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LDR,INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int bacaLDR=analogRead(LDR);//baca sensor PIR
//  bacaLDR=map(bacaLDR,0,1024,0,255);//mapping(val,fromLOW,FromHIGH,toLOW,toHIGH)

 //PRINT SERIAL
 Serial.print("Nilai LDR :");
 Serial.print(bacaLDR);
 Serial.println();

 //LOGIKA
  analogWrite(led,bacaLDR);
}
