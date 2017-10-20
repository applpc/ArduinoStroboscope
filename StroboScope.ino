//Stroboscope Code
//Kenny Adams
//10/13/17
//Rev. 10/20/17
#define mosfetPin 11
#define upButtonPin 9
#define downButtonPin 8

int freq = 100; // stropes/s
int waitTime = (1000/freq); //ms
int upButtonState;
int downButtonState;

void setup() {
  Serial.begin(9600);
  pinMode(mosfetPin, OUTPUT);
  pinMode(upButtonPin, INPUT_PULLUP);
  pinMode(downButtonPin, INPUT_PULLUP);
}

void loop() {
  Serial.println(freq);
  upButtonState = digitalRead(upButtonPin);
  downButtonState = digitalRead(downButtonPin);
  if(upButtonState == LOW){
    freq = freq + 5;
    delay(100);
  }
  if(downButtonState == LOW){
    if(freq > 5){
      freq = freq - 5;
      delay(100);
    } else{
      freq = 100;
      delay(100);
    }
  }
  waitTime = (1000/freq);
  digitalWrite(mosfetPin, HIGH);
  delay(waitTime);
  digitalWrite(mosfetPin, LOW);
  delay(waitTime);
  
}
