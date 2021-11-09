int ldr = A0;
int ledR = 5, ledY=6, ledG=7;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  Serial.begin(115200);
  digitalWrite(ledG,HIGH);
}

void loop() {
  int baca = analogRead(ldr);
//  int nilaildr= 5/255*baca;
  //jika menggunakan mapping
  //map(value, fromLow, fromHigh, toLow, toHigh)
  int nilaildr= map(baca,0,1024,0,100);
    Serial.print("Nilai LDR: ");
  Serial.println(nilaildr);

  if (nilaildr <= 50) {delay(500);digitalWrite(ledG, LOW);digitalWrite(ledR, LOW);}
  else {delay(500);digitalWrite(ledR, HIGH);}

}
