/*Hangi eleman hangi pine bağlı? */
#define REDPIN 10
#define GREENPIN 9
#define BLUEPIN 3

#define MODPIN 2

#define SPEEDPOT A0
#define BLUEPOT A1
#define REDPOT A2
#define GREENPOT A3

/*Kullanılan değişkenler */
int RedVal = 255;
int GreenVal = 255;
int BlueVal = 255;
int FadeSpeedVal = 50;

boolean Mod = 0;
float rad;
int r, g, b, i, sinOut;

void setup()
{
  Serial.begin(9600);

  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

  pinMode(MODPIN , INPUT_PULLUP );
}

void loop()
{
  if (Mod == 1)
  {
    Serial.println("fade");
    FadeMod();
  }
  if (Mod == 0)
  {
    Serial.println("manual");
    ManualMod();
  }
}
void FadeMod()
{

  analogWrite(REDPIN, 255);
  analogWrite(BLUEPIN, 255);
  analogWrite(GREENPIN, 255);
  for (i = 90; i <= 270; i++)
  {
    CheckModChange();
    if (Mod == 0)
      break;
    CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(GREENPIN, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 90; i <= 270; i++)
  {
    if (Mod == 0)
      break;
    CheckFadeSpeed();
    CheckModChange();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(BLUEPIN, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 270; i >= 90; i--)
  {
    if (Mod == 0)
      break;
    CheckFadeSpeed();
    CheckModChange();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(GREENPIN, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 90; i <= 270; i++)
  {
    if (Mod == 0)
      break;
    CheckFadeSpeed();
    CheckModChange();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(REDPIN, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 270; i >= 90; i--)
  {
    if (Mod == 0)
      break;
    CheckFadeSpeed();
    CheckModChange();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(BLUEPIN, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 90; i <= 270; i++)
  {
    if (Mod == 0)
      break;
    CheckFadeSpeed();
    CheckModChange();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(GREENPIN, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 270; i >= 90; i--)
  {
    if (Mod == 0)
      break;
    CheckFadeSpeed();
    CheckModChange();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(GREENPIN, sinOut);
    analogWrite(REDPIN, sinOut);
    delay(FadeSpeedVal);
  }
}

void ManualMod()
{
  CheckModChange();
  RedVal = analogRead(REDPOT);
  GreenVal = analogRead(GREENPOT);
  BlueVal = analogRead(BLUEPOT);



  b = map(BlueVal, 0, 1023, 0, 255);

  g = map(GreenVal, 0, 1023, 0, 255);

  r = map(RedVal, 0, 1023, 0, 255);

  analogWrite(REDPIN, r);
  analogWrite(GREENPIN, g);
  analogWrite(BLUEPIN, b);
}

void CheckModChange()
{
  if (digitalRead(MODPIN) == 0)
  {
    Mod = !Mod;
    Serial.print("yeni mod= ");
    Serial.print(Mod);
    while (digitalRead(MODPIN) == 0);
  }
}
void CheckFadeSpeed()
{
  FadeSpeedVal = analogRead(SPEEDPOT);
  FadeSpeedVal = map(FadeSpeedVal, 0, 1023, 0, 20);
}
