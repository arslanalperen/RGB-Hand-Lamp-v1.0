int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10;
int led10 = 11;

void setup(){

  pinMode(OUTPUT,led1);
  pinMode(OUTPUT,led2);
  pinMode(OUTPUT,led3);
  pinMode(OUTPUT,led4);
  pinMode(OUTPUT,led5);
  pinMode(OUTPUT,led6);
  pinMode(OUTPUT,led7);
  pinMode(OUTPUT,led8);
  pinMode(OUTPUT,led9);
  pinMode(OUTPUT,led10);

}

void loop(){
  digitalWrite(HIGH,led1);
  delay(200);
  digitalWrite(LOW,led1);

  digitalWrite(HIGH,led2);
  delay(200);
  digitalWrite(LOW,led2);

  digitalWrite(HIGH,led3);
  delay(200);
  digitalWrite(LOW,led3);

  digitalWrite(HIGH,led4);
  delay(200);
  digitalWrite(LOW,led4);

  digitalWrite(HIGH,led5);
  delay(200);
  digitalWrite(LOW,led5);

  digitalWrite(HIGH,led6);
  delay(200);
  digitalWrite(LOW,led6);

  digitalWrite(HIGH,led7);
  delay(200);
  digitalWrite(LOW,led7);

  digitalWrite(HIGH,led8);
  delay(200);
  digitalWrite(LOW,led8);

  digitalWrite(HIGH,led9);
  delay(200);
  digitalWrite(LOW,led9);

  digitalWrite(HIGH,led10);
  delay(200);
  digitalWrite(LOW,led10);
}
