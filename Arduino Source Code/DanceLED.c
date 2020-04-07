#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    60
CRGB leds[NUM_LEDS];
const int flex1 = A0;
const int flex2 = A1;
const int flex3 = A2;
const int flex4 = A3;
const int flex5 = A4;
const int flex6 = A5;
int i = 0;
const float VCC = 4.98;
const float R_DIV = 47500.0;
const float STRAIGHT_RESISTANCE = 37300.0;
const float BEND_RESISTANCE = 90000.0;
int R,G,B;
void setup()
{
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
  pinMode(flex1, INPUT);
  pinMode(flex2, INPUT);
  pinMode(flex3, INPUT);
  pinMode(flex4, INPUT);
  pinMode(flex5, INPUT);
  pinMode(flex6, INPUT);
}
void loop()
{
  float flex_1 = map(R_DIV*((1023/analogRead(flex1))-1.0),STRAIGHT_RESISTANCE,BEND_RESISTANCE,0,90.0);
  float flex_2 = map(R_DIV*((1023/analogRead(flex2))-1.0),STRAIGHT_RESISTANCE,BEND_RESISTANCE,0,90.0);
  float flex_3 = map(R_DIV*((1023/analogRead(flex3))-1.0),STRAIGHT_RESISTANCE,BEND_RESISTANCE,0,90.0);
  float flex_4 = map(R_DIV*((1023/analogRead(flex4))-1.0),STRAIGHT_RESISTANCE,BEND_RESISTANCE,0,90.0);
  float flex_5 = map(R_DIV*((1023/analogRead(flex5))-1.0),STRAIGHT_RESISTANCE,BEND_RESISTANCE,0,90.0);
  float flex_6 = map(R_DIV*((1023/analogRead(flex6))-1.0),STRAIGHT_RESISTANCE,BEND_RESISTANCE,0,90.0);
  if(flex_1>70.0 && flex_2>70.0 && flex_3>40.0 && flex_4>40.0 && flex_5>70.0 && flex_6>70.0)
  {
    for(int j=0;j<60;j++)
    {
      leds[j] = CRGB(R,G,B);
    }
  }
  else
  {
    for(int j=0;j<60;j++)
    {
      leds[j] = CRGB(0,0,0);
    }
  }
  if(flex1>70.0)
  {
    for(int j=0;j<15;j++)
    {
      leds[j] = CRGB(R,G,B);
    }
  }
  else
  {
    for(int j=0;j<15;j++)
    {
      leds[j] = CRGB(0,0,0);
    }
  }
  if(flex2>70.0)
  {
    for(int j=15;j<20;j++)
    {
      leds[j] = CRGB(R,G,B);
    }
  }
  else
  {
    for(int j=15;j<20;j++)
    {
      leds[j] = CRGB(R,G,B);
    }
  }
  if(flex3>70.0)
  {
    for(int j=25;j<31;j++)
    {
      leds[j] = CRGB(R,G,B);
    }
  }
  else
  {
    for(int j=25;j<31;j++)
    {
      leds[j] = CRGB(0,0,0);
    }
  }
  if(flex4>70.0)
  {
    for(int j=35;j<41;j++)
    {
      leds[j] = CRGB(R,G,B);
    }
  }
  else
  {
    for(int j=35;j<41;j++)
    {
      leds[j] = CRGB(0,0,0);
    }
  }
  if(flex5>70.0)
  {
    for(int j=41;j<48;j++)
    {
      leds[j] = CRGB(R,G,B);
    }
  }
  else
  {
    for(int j=41;j<48;j++)
    {
      leds[j] = CRGB(0,0,0);
    }
  }
  if(flex6>70.0)
  {
    for(int j=48;j<60;j++)
    {
      leds[j] = CRGB(R,G,B);
    }
  }
  else
  {
    for(int j=48;j<60;j++)
    {
      leds[j] = CRGB(0,0,0);
    }
  }
  colorchange_check(i);
  FastLED.show();
  i++;

}

void colorchange_check(int i)
{
  if(i>15)
  {
    R=256;
    G=0;
    B=0;
  }
  if(i>30)
  {
    R=0;
    G=256;
    B=0;
  }
  if(i>45)
  {
    R=0;
    G=0;
    B=256;
    i=0;
  }
}


