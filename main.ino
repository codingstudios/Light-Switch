int state = 0;
int buttonState = 0;

void setup()
{
  Serial.begin(36000);
  pinMode(2, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  buttonState = digitalRead(2);
}

void whiteColor() {
  analogWrite(11, 255);
  analogWrite(10, 255);
  analogWrite(9, 255);
}

void redColor() {
    analogWrite(11, 255);
    analogWrite(10, 0);
    analogWrite(9, 0);
}

void purpleColor() {
  analogWrite(11, 0);
  analogWrite(10, 153);
  analogWrite(9, 0);
}

void noColor() {
  analogWrite(11, 0);
  analogWrite(10, 0);
  analogWrite(9, 0);
}

void run() {
    state = state+1;
    if(state > 3) {
    state = 0;
    }
 if(state == 0) {
 noColor();
   Serial.println("No Color");
 }
if(state == 1) {
 whiteColor();
     Serial.println("White Color");
}
if(state == 2) {
 redColor();
     Serial.println("Red Color");
}
if(state == 3) {
 purpleColor();
  Serial.println("Purple Color");
}
}

int pressed = 0;
void loop(){
  if (digitalRead(2) == HIGH) {
    pressed = 1;
  }else {
    if(pressed > 0) {
    pressed = 0;
    run();
    }
  }
} 
