//include LIBRARY
#include <OneWire.h>
#include<DallasTemperature.h>

//inisialisasi pembuatan variable
int sensorSH = 2;
OneWire oneWire(sensorSH);
DallasTemperature sensors(&oneWire);

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Micro
  Serial.begin(115200);
  sensors.begin();
}

void loop() {
  // program yang dijalankan
  sensors.requestTemperatures();
  float bacaSH = sensors.getTempCByIndex(0);//membaca data di index 0 pada one wire

  //PRINT
  Serial.print("Suhu: ");
  Serial.print(bacaSH);
  Serial.print(" °C");
  Serial.println();

  //LOGIKA
  if(bacaSH != DEVICE_DISCONNECTED_C)
 {
 Serial.print("Data suhu yang terbaca pada bus 1 (index 0): ");
 Serial.println(bacaSH);
 }
 else
 {
 Serial.println("Error: sensor pada index 0 tidak ditemukan!");
 }

}
