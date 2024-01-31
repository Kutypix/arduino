const int ledPin [] = {4,5,6,7,10,11,12,13};
const int reset = 9;
const int up = 8;
const int down = 3;
byte state = 0;

void setup() {
  Serial.begin(9600);
  for(int l=0; l<8; l++){
    pinMode(ledPin[l], OUTPUT);
    digitalWrite(ledPin[l], LOW);
  }
  pinMode(reset, INPUT_PULLUP);
  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(up) == LOW){
    state++;
    if(state == 256)
      state = 0;
    showBinaryLED(state);
    Serial.println(state);
    delay(250);
  }
  if(digitalRead(reset) == LOW){
    state = 0;
    showBinaryLED(state);
    Serial.println("RESET");
    delay(250);
  }
  if(digitalRead(down) == LOW){
    state --;
    if(state < 0)
      state = 255;
    showBinaryLED(state);
    Serial.println(state);
    delay(250);
  }
}

void showBinaryLED(byte binNumber){
  for(int l=0; l<8; l++){
    if(bitRead(binNumber, l) == 1)
      digitalWrite(ledPin[l], HIGH);
    else
      digitalWrite(ledPin[l], LOW);
  }
}
