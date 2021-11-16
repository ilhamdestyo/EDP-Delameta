int button1=2; // untuk led R
int button2=3; // untuk led Y
int button3=4; // untuk led G
int R=5, Y=6, G=7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
   pinMode(R, OUTPUT);
   pinMode(Y, OUTPUT);
   pinMode(G, OUTPUT);

   pinMode(button1,INPUT);
   pinMode(button2,INPUT);
   pinMode(button3,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int bacaTombol1=digitalRead(button1);
  Serial.print("kondisi tombol 1:"+ String(bacaTombol1));
  int bacaTombol2=digitalRead(button2);
  Serial.print(" | kondisi tombol 2:"+ String(bacaTombol2));
  int bacaTombol3=digitalRead(button3);
  Serial.println(" | kondisi tombol 3:"+ String(bacaTombol3));
  
if(bacaTombol1 && bacaTombol2 ==1){digitalWrite(R,HIGH);}else{digitalWrite(R,LOW);}//logika1
}
