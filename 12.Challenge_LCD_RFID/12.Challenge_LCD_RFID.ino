//Download dan masukan Library MFRC522 
#include <SPI.h> 
#include <MFRC522.h> 
#include <LiquidCrystal_I2C.h>
//Inisialisasi pembuatan variable 
String uidString;
int buzz=6;
int ir=7;
int flag=0;
#define SS_PIN  10 
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 20, 4);  
 
void setup() { 
  //Menentukan Fungsionalitas dari PIN pada Microcontroller 
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  pinMode(buzz,OUTPUT);
  pinMode(ir,INPUT); 
  SPI.begin();      // Initiate  SPI bus 
  mfrc522.PCD_Init();   // Initiate MFRC522
  lcd.begin();
  bunyibuzzeroke();
//  Serial.println("Tempelkan Kartu!");
  lcd.setCursor(0,0); lcd.print("Tempelkan Kartu!");
} 
 
void loop() { 
  //Program yang akan dijalankan berulang-ulang
  int readIr=digitalRead(ir);
 
  if (mfrc522.PICC_IsNewCardPresent() and flag==0) {
    readRFID(); Serial.println("Tag UID: " + String(uidString));
    if(uidString=="2AA5B715"){
      bunyibuzzeroke();
      flag=1;
//      Serial.println("BERHASIL!");
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("    BERHASIL!");
      delay(1000);
//      Serial.println("PALANG DIBUKA");
//      Serial.println("Silahkan Masuk!");
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("    PALANG DIBUKA");
      lcd.setCursor(0,1); lcd.print("    Silahkan Masuk!");
    }else{
//        Serial.println("GAGAL!");
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("    GAGAL");
      bunyibuzzergagal();
//        Serial.println("Tempelkan Kartu!");
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("Tempelkan Kartu!"); 
      }
    }
    
  if(readIr==0 and flag==1){
//    Serial.println("PALANG DITUTUP");
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("    PALANG DITUTUP");
      delay(500);
    bunyibuzzeroke();
    flag=0;
//    Serial.println("Tempelkan Kartu!");
      lcd.clear();
      lcd.setCursor(0,0); lcd.print("Tempelkan Kartu!");  
  }
}

//fungsi RFID
void readRFID(){
  // Select one of the cards 
  mfrc522.PICC_ReadCardSerial();
  //pembatas bisa dirubah sesuai keinginan, disini yang digunakkan "-"
  uidString = String( mfrc522.uid.uidByte[0],HEX)+ "" +
              String( mfrc522.uid.uidByte[1],HEX)+ "" +
              String( mfrc522.uid.uidByte[2],HEX)+ "" +
              String( mfrc522.uid.uidByte[3],HEX);
              uidString.toUpperCase();
}

//Fungsi buzzer ON
void bunyibuzzeroke(){
  digitalWrite(buzz,HIGH);delay(500);digitalWrite(buzz,LOW);
//  tone(buzz, 1000); // buzzer dgn 1KHz tone Freq
//  delay(100);        // ...for 1 sec
//  noTone(buzz);     // Stop sound...
//  delay(100);        // ...for 1sec
}

//Fungsi buzzer OFF
void bunyibuzzergagal(){
  digitalWrite(buzz,HIGH);delay(1000);digitalWrite(buzz,LOW);
//  tone(buzz, 1000); // buzzer dgn 1KHz tone Freq
//  delay(1000);        // ...for 1 sec
//  noTone(buzz);     // Stop sound...
//  delay(1000);        // ...for 1sec
}
