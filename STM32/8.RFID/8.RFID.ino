//Download dan masukan Library MFRC522 
#include <SPI.h> 
#include <MFRC522.h> 
 
//Inisialisasi pembuatan variable 
#define SS_PIN  PA0 
#define RST_PIN PA1
int buzz = PC13; 
 
MFRC522 mfrc522(SS_PIN, RST_PIN);  
 
void setup() { 
  //Menentukan Fungsionalitas dari PIN pada Microcontroller 
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer 
  SPI.begin();      // Initiate  SPI bus 
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(buzz,OUTPUT);  
} 
 
void loop() { 
  //Program yang akan dijalankan berulang-ulang 
  if ( ! mfrc522.PICC_IsNewCardPresent()) {return;} 
  // Select one of the cards 
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;} 
   
  //Show UID on serial monitor 
  Serial.print("UID tag :"); 
  String content= ""; 
  byte letter; 
  for (byte i = 0; i < mfrc522.uid.size; i++)  
  { 
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""); 
     Serial.print(mfrc522.uid.uidByte[i], HEX); 
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "")); 
     content.concat(String(mfrc522.uid.uidByte[i], HEX)); 
  } 
  Serial.println(); 
  Serial.print("Message : "); 
  content.toUpperCase(); 
//  if (content.substring(1) == "6B A7 EF 0D") //Sesuaikan dengan ID kartu anda 
//  { 
//    Serial.println("Selamat datang iwan cilibur!!!");
//    digitalWrite 
//    delay(2000); 
//  }else{ 
//    Serial.println("Kartu Belum Terdaftar!"); 
//  } 
//  Serial.println("Tempelkan Kartu!"); 
//  delay(500); //Jeda waktu perulagan seama 500 mili detik

   if (content == "E59C3437") //Sesuaikan dengan ID kartu anda 
  {Serial.println("Selamat datang Ilham Destyo!!!");digitalWrite(buzz,HIGH);delay(500);digitalWrite(buzz,LOW); 
  }else if (content == "1A 0CE980") //Sesuaikan dengan ID kartu anda 
  {Serial.println("Selamat datang Para pencari Tuhan!!!");digitalWrite(buzz,HIGH);delay(500);digitalWrite(buzz,LOW); 
  }else if (content == "047042AA442E80")
  {Serial.println("Pemilik kartu belum kawin!!!");digitalWrite(buzz,HIGH);delay(500);digitalWrite(buzz,LOW);
  }else
  {Serial.println("Kartu Belum Terdaftar!");digitalWrite(buzz,HIGH);delay(1000);digitalWrite(buzz,LOW);
  }
  Serial.println("Tempelkan Kartu!"); 
  delay(500); //Jeda waktu perulagan seama 500 mili detik
}
