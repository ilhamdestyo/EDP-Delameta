#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoJson.h> //6.17.3
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

// replace the MAC address below by the MAC address printed on a sticker on the Arduino Shield 2
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetClient client;

int    HTTP_PORT   = 80;
String HTTP_METHOD = "GET";
char   HOST_NAME[] = "192.168.1.14"; // change to your PC's IP address
String PATH_NAME   = "/ilm_rfidui/data-api.php";
String getData;

  
#define SS_PIN 9
#define RST_PIN 8
#define buzzer 6

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
LiquidCrystal_I2C lcd(0x27, 20, 4);  // Set LCD 20x4

String asal = "GT JATILUHUR";
String tujuan = "GT PADALARANG";

void setup() {
  Serial.begin(115200);
  pinMode(buzzer,OUTPUT);
  while(!Serial);
  SPI.begin();      // Initiate  SPI bus
  lcd.begin();

  //delay(3000);

  //Start Ethernet Connection
  Serial.println("Initialize Ethernet with DHCP:");
  if (Ethernet.begin(mac) == 0){
    Serial.println("Failed to configure Ethernet using DHCP");
    if (Ethernet.hardwareStatus() == EthernetNoHardware){
      Serial.println("Ethernet Shield was not found. Sorry can't run without hardware. :(");
    } else if(Ethernet.linkStatus() == LinkOFF){
      Serial.println("Ethernet cable is not connected.");
    }
    while (true){delay(1);}
  }
  //Print local IP and END DHCP scan
  delay(2500);
  Serial.print("IP address: ");
  Serial.println(Ethernet.localIP());
  client.connect (HOST_NAME,HTTP_PORT);
  Serial.println("Automatic Line Barrier is Ready!");
  lcd.clear();lcd.setCursor(0,0);lcd.print("ETHERNET TERHUBUNG");
              lcd.setCursor(0,1);lcd.print("TOL SYSTEM READY!");

    //disable Ethernet
//  pinMode(10,OUTPUT);
//  digitalWrite(10,HIGH);
//
//  //disable SD
//  pinMode(4,OUTPUT);
//  digitalWrite(4,HIGH);

  mfrc522.PCD_Init();   // Initiate MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  
}

void loop() {
  //Baca data
   //Program yang akan dijalankan berulang-ulang
  //look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
  
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String uidString;
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     uidString.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "" : ""));
     uidString.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.print("Message : ");
  uidString.toUpperCase();
  Serial.println(uidString);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);


  //POST TO WEB
    client.connect(HOST_NAME, HTTP_PORT);
    client.println(HTTP_METHOD + " " + PATH_NAME + 
                   "?rfid=" + String(uidString) + 
                   "&asalperjalanan=" + String(asal) + 
                   "&tujuanperjalanan=" + String(tujuan) + 
                   " HTTP/1.1");
    client.println("Host: " + String(HOST_NAME));
    client.println("Connection: close");
    client.println(); // end HTTP header
  
    while(client.connected()) {
      if(client.available()){
        char endOfHeaders[] = "\r\n\r\n";
        client.find(endOfHeaders);
        getData = client.readString();
        getData.trim();
        Serial.println(getData);
        
        //AMBIL DATA JSON
        const size_t capacity = JSON_OBJECT_SIZE(10) + 200; //cari dulu nilainya pakai Arduino Json 5 Asisten
        DynamicJsonDocument doc(capacity);
        //StaticJsonDocument<192> doc;
        DeserializationError error = deserializeJson(doc, getData);
      
//        const char* id_dibaca       = doc["id"]; 
//        const char* rfid_dibaca     = doc["rfid"]; 
//        const char* nama_dibaca     = doc["nama"]; 
//        const char* alamat_dibaca   = doc["alamat"]; 
//        const char* telepon_dibaca  = doc["telepon"]; 
//        const char* tanggal_dibaca  = doc["tanggal"]; 

        const char* id_dibaca = doc["id"]; // "4"
        const char* rfid_dibaca = doc["rfid"]; // "E59C3437"
        const char* nama_dibaca = doc["nama"]; // "TapCash"
        const char* alamat_dibaca = doc["alamat"]; // "BNI"
        const char* telepon_dibaca = doc["telepon"]; // "1 500 046"
        const char* emoney_dibaca = doc["emoney"]; // "-6335"
        const char* tanggal_dibaca = doc["tanggal"]; // "2021-12-10 14:31:30"
        const char* asalperjalanan_dibaca = doc["asalperjalanan"]; // "GT PADALARANG"
        const char* tujuanperjalanan_dibaca = doc["tujuanperjalanan"]; // "GT BAROS"
        const char* tarif_dibaca = doc["tarif"]; // "2000"
      
       //LOGIKA
       if(String(nama_dibaca)!=""){
        buzzeroke();
        Serial.println("Kartu Terdaftar!");
        Serial.println(getData);
        //POST TO SERIAL
//         Serial.print("ID       = ");Serial.println(id_dibaca);
//         Serial.print("RFID     = ");Serial.println(rfid_dibaca);
//         Serial.print("Nama     = ");Serial.println(nama_dibaca);
//         Serial.print("Alamat   = ");Serial.println(alamat_dibaca);
//         Serial.print("Telepon  = ");Serial.println(telepon_dibaca);
//         Serial.print("emoney   = ");Serial.println(emoney_dibaca);
//         Serial.print("Waktu    = ");Serial.println(tanggal_dibaca);
//         Serial.print("Asal     = ");Serial.println(asalperjalanan_dibaca);
//         Serial.print("Tujuan   = ");Serial.println(tujuanperjalanan_dibaca);
//         Serial.print("Tarif    = ");Serial.println(tarif_dibaca);
//         Serial.println("Kartu Terdaftar!");
       }else{
        buzzergagal();
        Serial.println("Kartu Tidak terdaftar!");
       }
      } 
    }
    //delay(1000);
}

void buzzeroke(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}

void buzzergagal(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(10);
}
