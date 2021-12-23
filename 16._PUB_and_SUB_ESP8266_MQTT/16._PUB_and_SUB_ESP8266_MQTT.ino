#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspUdp.h>
#include "SoftwareSerial.h"
#include <PubSubClient.h> //


char ssid[] = "delameta"; // your network SSID (name)
char pass[] = "bilano1407"; // your network password
int status = WL_IDLE_STATUS; // the Wifi radio's status
unsigned long lastSend;

//inisialisasi pin LED
int ledR=13;
int ledY=12;
int ledG=11;

int Fl=A2;
int LDR=A3;

// Initialize the Ethernet client object
WiFiEspClient espClient;
PubSubClient client(espClient);

SoftwareSerial Serialx(2,3); // RX, TX   //ESP8266 RX,TX connected to these pins

void setup() {
// initialize serial for debugging
Serial.begin(115200);
// initialize serial for ESP module
Serialx.begin(9600);
// initialize ESP module
WiFi.init(&Serialx);

pinMode(ledR,OUTPUT);pinMode(ledY,OUTPUT);pinMode(ledG,OUTPUT);
pinMode(LDR,INPUT);


// check for the presence of the shield
if (WiFi.status() == WL_NO_SHIELD) {
Serial.println("WiFi shield not present");
// don't continue
while (true);
}

// attempt to connect to WiFi network
while ( status != WL_CONNECTED) {
Serial.print("Attempting to connect to WPA SSID: ");
Serial.println(ssid);
// Connect to WPA/WPA2 network
status = WiFi.begin(ssid, pass);
lastSend = 0;
}

// you're connected now, so print out the data
Serial.println("You're connected to the network");

//connect to MQTT server
client.setServer("192.168.1.45", 1883);
client.setCallback(callback);
}

//print any message received for subscribed topic
void callback(char* topic, byte* payload, unsigned int length) {
Serial.print("Pesan diterima [");
  Serial.print(topic);
  Serial.println("] ");
  //==============================================================
  if (strcmp(topic, "nomadtech4845/lampu1") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(ledR,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(ledR,LOW);
    }
  }
  }
  //==============================================================

  //==============================================================
  if (strcmp(topic, "nomadtech4845/lampu2") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(ledY,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(ledY,LOW);
    }
  }
  }
  //==============================================================

  //==============================================================
  if (strcmp(topic, "nomadtech4845/lampu3") == 0) //Membandingkan 2 buah String
  { 
    for (int i=0;i<length;i++) {
    char receivedChar = (char)payload[i];
    if (receivedChar == '1'){
       //Jalankan Perintah1
       Serial.println("JALANKAN PERINTAH 1");
       digitalWrite(ledG,HIGH);
    }
    if (receivedChar == '0'){
       //Jalankan Perintah0
       Serial.println("JALANKAN PERINTAH 0");
       digitalWrite(ledG,LOW);
    }
  }
  }
  //==============================================================
  
}

void pushdata(){
  //Ambil Data / Baca Sensor
//  char msgBuffer[20];
//  int datax=random(10,100); //Baca data Sensor yang digunakan
  int bacaFL=analogRead(Fl);
  int bacaLDR=analogRead(LDR);
  
  //POST TO SERIAL
//  Serial.println("Sensor 0 :" + String(datax));
  Serial.println("Sensor 1 :" + String(bacaFL));
  Serial.println("Sensor LDR :" + String(bacaLDR));
  
  //POST TO MQTT
//  client.publish("nomadtech4845/datax", dtostrf(nomadtech4845/datax, 6, 2, msgBuffer)); //Convert to String
//  client.publish("nomadtech4845/datax", String(datax).c_str());
  client.publish("nomadtech4845/bacaFL", String(bacaFL).c_str());
  client.publish("nomadtech4845/bacaLDR", String(bacaLDR).c_str()); 
}

void loop() {
// put your main code here, to run repeatedly:
if (!client.connected()) {
reconnect();
}
if ( millis() - lastSend > 3000 ) { // Update and send only after 1 seconds
    pushdata();
    lastSend = millis();
 }
client.loop();
}

void reconnect() {
// Loop until we're reconnected
while (!client.connected()) {
Serial.print("Attempting MQTT connection...");
// Attempt to connect, just a name to identify the client
if (client.connect("nomadtech4845Device001")) {
Serial.println("connected");

//client.publish("outpic","Hello World");
client.subscribe("nomadtech4845/lampu1",0);
client.subscribe("nomadtech4845/lampu2",0);
client.subscribe("nomadtech4845/lampu3",0);

} else {
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println(" try again in 5 seconds");
  // Wait 5 seconds before retrying
  delay(5000);
}
}
}
