//Download dan masukan Library 
#include <Servo.h>
#define Servo_PWM PA0//Pin untuk Servo
//Inisialisasi pembuatan variable
Servo myservo;

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  myservo.attach(Servo_PWM); 
}

void loop() {
  //Program yang akan dijalankan berulang-ulang
  Serial.println("0");
  myservo.write(0); //0-180
  delay(1000); //Jeda waktu perulagan seama 1000 mili detik
  myservo.detach();
  delay(500);
  Serial.println("0");
  myservo.write(90); //0-180
  delay(1000); //Jeda waktu perulagan seama 1000 mili detik
  myservo.detach();
  delay(500);
  myservo.attach(Servo_PWM);
  
}
