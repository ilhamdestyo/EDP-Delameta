//Inisialisasi
int Fl =PB0;
//int lR=5, lY=6, lG=7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(Fl,INPUT);
//  pinMode(lR,OUTPUT);pinMode(lY,OUTPUT);pinMode(lG,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int bacaFl=analogRead(Fl);//baca sensor PIR
  bacaFl=map(bacaFl,2,1024,255,0);//mapping(val,fromLOW,fromHIGH,toLOW,toHIGH)

 Serial.print("Flame value :");
 //PRINT SERIAL
 Serial.print(bacaFl);
 Serial.println();

 //LOGIKA
 
  if(bacaFl <5){Serial.println("Aman");
  }
  else if(bacaFl >5 && bacaFl <=150){Serial.println("Warning Silahkan Periksa");
  }
  else{Serial.println("Waspada Harap Mengungsi");
  }
  delay(100);
}
