//INPUT LIBRARY
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
//INISIALISASI VARIABLE
String uidString;

int ledbuzz=PA3;
int outServo =PA2;
int ir=PA4;
int flag=0;
#define SS_PIN PA0
#define RST_PIN PA1
#define buzz PB0
MFRC522 mfrc522(SS_PIN,RST_PIN);
LiquidCrystal_I2C lcd(0x27, 20 ,4);
Servo myservo;


void setup() {
  //Setting Pin pada MICRO
  Serial.begin(115200);
  pinMode(buzz,OUTPUT);
  pinMode(ledbuzz,OUTPUT);
  pinMode(ir,INPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin();
  myservo.attach(outServo);
  lcd.clear();lcd.setCursor(0,0);lcd.print("TEMPEL KARTU ANDA!");
  delay(500);
}

//FUNGSI YANG DIBUAT
void readRFID(){
  //Pilih salah satu kartu
  mfrc522.PICC_ReadCardSerial();
  //Pembatas bisa dirubah sesuai keinginan dan disini menggunakan;
  uidString = String(mfrc522.uid.uidByte[0],HEX)+ ""+
              String(mfrc522.uid.uidByte[1],HEX)+ ""+
              String(mfrc522.uid.uidByte[2],HEX)+ ""+
              String(mfrc522.uid.uidByte[3],HEX);
              uidString.toUpperCase();
}

//Fungsi buzzer ON
void buzzeroke(){
  for (int i=1; i<5; i++){
    digitalWrite(buzz, HIGH);   
    delay(200);             
    digitalWrite(buzz, LOW);
    delay(200);          
  }
}

  
//Fungsi buzzer OFF
void buzzergagal(){
  digitalWrite(buzz,HIGH);delay(1000);digitalWrite(buzz,LOW);
//  tone(buzz, 1000); // buzzer dgn 1KHz tone Freq
//  delay(1000);        // ...for 1 sec
//  noTone(buzz);     // Stop sound...
//  delay(1000);        // ...for 1sec
}

//Fungsi Servo
void bukaservo(){
  myservo.write(180);
  delay(200);
}
void tutupservo(){
  myservo.write(90);
  delay(200);
}

//Fungsi LED
void ledmenyala(){
  for (int i=1; i<5; i++){
    digitalWrite(ledbuzz, HIGH);   
    delay(100);             
    digitalWrite(ledbuzz, LOW);     
    delay (100);           
  }
}

void ledFail(){
  digitalWrite(ledbuzz,HIGH);
  delay(1500);
  digitalWrite(ledbuzz,LOW);
}

void loop() {
  //PROGRAM YANG DIBERIKAN PADA PENGULANGAN
  int readIR=digitalRead(ir);
  //LOGIKA YANG DIBERIKAN
  if (mfrc522.PICC_IsNewCardPresent() && flag==0){
    readRFID();Serial.println("Tag UID: " + String(uidString));
    lcd.clear(); lcd.setCursor(0,0);lcd.print("Tag UID: " + String(uidString));
    if(uidString=="E59C3437"){
      Serial.println("Selamat datang Ilham Destyo!!!");
      lcd.clear(); lcd.setCursor(0,1);lcd.print("    BERHASIL!");
      buzzeroke();
      delay(1000);
      lcd.clear();lcd.setCursor(0,1);lcd.print("   PALANG DIBUKA");
                  ledmenyala();bukaservo();buzzergagal();
                  lcd.setCursor(0,2);lcd.print("   Silahkan Masuk!");
                  flag=1;
                  
    }
    else if(uidString=="47042AA" && flag==0){
      Serial.println("Pemilik kartu belum kawin!!!");
      lcd.clear();lcd.setCursor(0,1);lcd.print("    BERHASIL!");
      buzzeroke();
      delay(1000);
      lcd.clear();lcd.setCursor(0,1);lcd.print("    PALANG DIBUKA");
                  ledmenyala();bukaservo();buzzergagal();
                  lcd.setCursor(0,2);lcd.print("    Silahkan Masuk!");
                  flag=1;
                  
    }
    else{
      Serial.println("Kartu Blm Terdaftar!");
      buzzergagal();
      lcd.clear();lcd.setCursor(0,1);lcd.print("    GAGAL!");
                lcd.setCursor(0,2);lcd.print("Kartu Blm Terdaftar!");ledFail();
                delay(700);
                lcd.clear();lcd.setCursor(0,3);lcd.print("Atau Coba lagi");
                delay(700);
                lcd.clear();lcd.setCursor(0,1);lcd.print("Tempel Kartu Anda!");
    }
  }
  
  if(readIR==0 && flag==1){
  tutupservo();
  lcd.clear();lcd.setCursor(0,1);lcd.print("    PALANG DITUTUP");
  buzzergagal();
  delay(500);
  flag=0;
  lcd.clear();lcd.setCursor(0,1);lcd.print("Tempel Kartu Anda!");
  }
}
