//Inisialisasi pembuatan variable
int relay1=7;

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  pinMode(relay1,OUTPUT);
}

void loop() {
  //Program yang akan dijalankan berulang-ulang
  digitalWrite (relay1,HIGH);
  delay(500); //Jeda waktu perulagan seama 500 mili detik
  digitalWrite (relay1,LOW);
  delay(500); //Jeda waktu perulagan seama 500 mili detik
}
