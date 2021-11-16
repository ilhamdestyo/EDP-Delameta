int R=5;
int Y=6;
int G=7;

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
  delay(10000);
  digitalWrite(R,LOW);
  digitalWrite(Y,HIGH);
  delay(2000);
  digitalWrite(Y,LOW);
  digitalWrite(G,HIGH);
  delay(8000);
  digitalWrite(G,LOW);
  digitalWrite(Y,HIGH);
  delay(2000);
  digitalWrite(Y,LOW);
  
}
