int R=5,Y=6,G=7;

// void setup adalah booting yang dilakukan dalam satu kali jalan
void setup() {
  // put your setup code here, to run once:
  pinMode (R,OUTPUT);
  pinMode (Y,OUTPUT);
  pinMode (G,OUTPUT);
 

}

//void loop adalah proses pengulangan yang dilakukan
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(R,HIGH);
  digitalWrite(Y,HIGH);
  digitalWrite(G,HIGH);
  delay(1000);
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  delay(1000);
}
