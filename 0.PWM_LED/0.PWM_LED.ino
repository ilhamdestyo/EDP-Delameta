void setup() {
  // put your setup code here, to run once:
  //For Function menjadikan fungsi lebih sedikit ketimbang menambahkan banyak koding
  Serial.begin(9600);
  for(float i=5; i<=7; i++){
  pinMode (i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(float i=0; i<=255; i++){
  analogWrite(5,i);
  float hasil=(5.0/255.0)*i;
  delay(100);
  Serial.println("DATA: " + String(hasil) + "Volt");
  }
  for(float i=255; i>=0; i--){
  analogWrite(5,i);
  float hasil=(5.0/255.0)*i;
  delay(100);
  Serial.println("DATA: " + String(hasil) + "Volt");
  }
}
