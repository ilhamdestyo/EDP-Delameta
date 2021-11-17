//Download Library LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>

//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  lcd.begin();
}

void loop() {
  //print serial
  Serial.println("HALO SELAMAT DATANG");
  Serial.println("    LCD 20 x 4");
  Serial.println("   TUTORIAL BY");
  Serial.println("Nomaden Tech ID");
  
  //Program yang akan dijalankan berulang-ulang
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  tulisanutama();
  lcd.setCursor(0,3); lcd.print("  Nomaden Tech ID");
  delay(2000);
  
  lcd.clear();
//  lcd.setCursor(0,0); lcd.print("HALO SELAMAT DATANG");
//  lcd.setCursor(0,1); lcd.print("    LCD 20 x 4");
//  lcd.setCursor(0,2); lcd.print("   TUTORIAL BY");
  lcd.setCursor(0,3); lcd.print("Be Stronger Engineer");
  delay(2000);

//  delay(1000); //Jeda waktu perulagan seama 1000 mili detik
}

//FUNGSI
void tulisanutama(){
  lcd.setCursor(0,0); lcd.print("HALO SELAMAT DATANG");
  lcd.setCursor(0,1); lcd.print("    LCD 20 x 4");
  lcd.setCursor(0,2); lcd.print("   TUTORIAL BY");
}
