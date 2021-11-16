//inisiasi variable
int tombol1=2;
int sensor1=3;

int R=5;
int Y=6;
int G=7;

//Fungsi yang dijalankan
void setup() {
  Serial.begin(9600); //baudrate
  pinMode(tombol1,INPUT);
  pinMode(sensor1,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  digitalWrite(R,HIGH);
  Serial.println("SYSTE START!");
}

//looping
void loop() {
   int bacaTombol1=digitalRead(tombol1);
   int bacaSensor1=digitalRead(sensor1);
   Serial.println("Kondisi tombol:" + String(bacaTombol1) +
   " | " + String (bacaSensor1));  
   
    if (bacaTombol1==1){ 
      delay(500);
      Serial.println("SELAMAT DATANG SILAHKAN AMBIL TIKET");
      Serial.println("PALANG DIBUKA");
      digitalWrite(R,LOW);
      digitalWrite(Y,HIGH);
      delay(1000);
      digitalWrite(Y,LOW);
      delay(100);
      digitalWrite(G,HIGH);
    }
    
    if (bacaSensor1==0){ 
      delay(500);
      Serial.println("PALANG DITUTUP");
      digitalWrite(G,LOW);
      digitalWrite(R,HIGH);
    }  
    
}
