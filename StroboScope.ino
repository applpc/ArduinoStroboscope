//Stroboscope Code
//Kenny Adams
//10/13/17
#define mosfetPin 11;
#define upButtonPin 2;
#define downButtonPin 3;

int waitTime = 10; //ms
int freq = (1000/waitTime); // stropes/s

void setup() {
  pinMode(mosfetPin, OUTPUT);
  pinMode(upButtonPin, INPUT);
  pinMode(downButtonPin, INPUT);
}

void loop() {
  upButtonState = digitalRead(upButtonPin);
  downButtonState = digitalRead(downButtonPin);
  if(upButtonState == HIGH){
    waitTime++;
  }
  if(downButtonState == HIGH){
    waitTime--;
  }
  digitalWrite(mosfetPin, HIGH);
  delay(waitTime);
  digitalWrite(mosfetPin, LOW);
  delay(waitTime);
  
}
