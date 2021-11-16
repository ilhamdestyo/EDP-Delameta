//Inisialisasi
int LDR=A0;
int Fl =A1;
int buzz = 4;
int PIR = 3;
int lR=5, lY=6, lG=7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LDR,INPUT);
  pinMode(Fl,INPUT);
  pinMode(lR,OUTPUT);pinMode(lY,OUTPUT);pinMode(lG,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(PIR,INPUT);

}

void loop() {
  //Baca Data
  int bacaFl=analogRead(Fl);//baca sensor PIR
  bacaFl=map(bacaFl,2,1024,255,0);//mapping(val,fromLOW,fromHIGH,toLOW,toHIGH)

  int bacaPIR=digitalRead(PIR);
  Serial.println("OutputPIR: " + bacaPIR);
  //  delay(100);

  int bacaLDR=analogRead(LDR);
  //  bacaLDR=map(bacaLDR,9,11,0,255);

  Serial.print("Flame value :");
  //PRINT SERIAL
  Serial.print(bacaFl);
  Serial.println();
  delay(100);
 
 //LOGIKA
if (bacaLDR <= 200) {digitalWrite(lR, LOW); Serial.print("Its DARK, Turn on the LED : "); Serial.println(bacaLDR);
}
else { digitalWrite(lR, HIGH); Serial.print("Its BRIGHT, Turn off the LED : "); Serial.println(bacaLDR);}

 
  if(bacaFl <5){digitalWrite(lG,HIGH);digitalWrite(lY,LOW);digitalWrite(lR,LOW);Serial.println("Aman");
  }
  else if(bacaFl >5 && bacaFl <=150){
    digitalWrite(lY,HIGH);digitalWrite(lG,LOW);;digitalWrite(lR,LOW);Serial.println("Warning Silahkan Periksa");
    tone(buzz, 1000); // buzzer dgn 1KHz tone Freq
    delay(1000);        // ...for 1 sec
    noTone(buzz);     // Stop sound...
    delay(1000);        // ...for 1sec
  }
  else{
    digitalWrite(lR,HIGH);digitalWrite(lY,LOW);digitalWrite(lG,LOW);Serial.println("Waspada Harap Mengungsi");
    tone(buzz, 1000); // buzzer dgn 1KHz tone Freq
    delay(100);        // ...for 0,1 sec
    noTone(buzz);     // Stop sound...
    delay(100);        // ...for 0,1sec
  }
  delay(100);
}
