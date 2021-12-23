//LED setting
const int lR = PA0;
const int lY = PA1;
const int lG = PA2;

//button setting
const int button1 = PA3;
const int button2 = PA4;
const int button3 = PA5;

//state setting
int buttonState1, buttonState2, buttonState3;
int oldButton1, oldButton2, oldButton3 = 0;
int state1, state2, state3 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(lR, OUTPUT);
pinMode(lY, OUTPUT);
pinMode(lG, OUTPUT);

pinMode(button1, INPUT_PULLUP);
pinMode(button2, INPUT_PULLUP);
pinMode(button3, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

//state yang dilakukan input
//baca data
int buttonState1 = digitalRead(button1);
int buttonState2 = digitalRead(button2);
int buttonState3 = digitalRead(button3);


//logic start 1
if(!buttonState1 && !oldButton1){
if(state1 == LOW){
digitalWrite(lR, LOW);
state1 = 1;
}else{
digitalWrite(lR, HIGH);
state1 = 0;
}
oldButton1 = 1;
}else if(buttonState1 && oldButton1){
oldButton1 = 0;
}
//logic end 1

//logic start 2
if(!buttonState2 && !oldButton2){
if(state2 == 0){
digitalWrite(lY, LOW);
state2 = 1;
}else{
digitalWrite(lY, HIGH);
state2 = 0;
}
oldButton2 = 1;
}else if(buttonState2 && oldButton2){
oldButton2 = 0;
}
//logic end 2

//logic start 3
if(!buttonState3 && !oldButton3){
if(state3 == 0){
digitalWrite(lG, LOW);
state3 = 1;
}else{
digitalWrite(lG, HIGH);
state3 = 0;
}
oldButton3 = 1;
}else if(buttonState3 && oldButton3){
oldButton3 = 0;
}
//logic end 3

////serial monitor
//Serial.print("tombol 1: " +String(buttonState1) + "kunci1: " + String(oldButton1));
//Serial.print("| tombol 2: " +String(buttonState2) + "kunci2: " + String(oldButton2));
//Serial.print("| tombol 3: " +String(buttonState3) + "kunci3: " + String(oldButton3));
//Serial.println();
}
