int button1=2; // untuk led R
int button2=3; // untuk led Y
int button3=4; // untuk led G
int R=5, Y=6, G=7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
   pinMode(R, OUTPUT);
   pinMode(Y, OUTPUT);
   pinMode(G, OUTPUT);

   pinMode(button1,INPUT);
   pinMode(button2,INPUT);
   pinMode(button3,INPUT);

}

void loop() {
//instead of debouncing each button, we'll just have
//one delay at the end of the loop if any button
//has been pressed.  
//(saves having 3 delays when they're all pressed at once)
//bool debounce=false;
//
//if (digitalRead(button1==LOW))
//  {
//  firstLedState=!firstLedState;
//  //this is a shorthand way of saying the oposite of what it is now
//  digitalWrite(R,firstLedState); 
//  debounce=true;
//  }
//  
//if (digitalRead(button2==LOW))
//  {
//  secondLedState=!secondLedState;
//  //this is a shorthand way of saying the oposite of what it is now
//  digitalWrite(Y,secondLedState); 
//  debounce=true;  
//  }
//  
//if (digitalRead(button3==LOW))
//  {
//  thirdLedState=!thirdLedState;
//  //this is a shorthand way of saying the oposite of what it is now
//  digitalWrite(G,thirdLedState); 
//  debounce=true;
//  }
//
//if(debounce==true) 
//  delay(400);
//}
  // put your main code here, to run repeatedly:
  int bacaTombol1=digitalRead(button1);
  Serial.print("kondisi tombol 1:"+ String(bacaTombol1));
  int bacaTombol2=digitalRead(button2);
  Serial.print(" | kondisi tombol 2:"+ String(bacaTombol2));
  int bacaTombol3=digitalRead(button3);
  Serial.println(" | kondisi tombol 3:"+ String(bacaTombol3));
if(bacaTombol1==1){
  digitalWrite(R,HIGH); 
}else{
  digitalWrite(R,LOW); 
}

if(bacaTombol2==1){
  digitalWrite(Y,HIGH); 
}else{
  digitalWrite(Y,LOW); 
}

if(bacaTombol3==1){
  digitalWrite(G,HIGH); 
}else{
  digitalWrite(G,LOW); 
}
}
