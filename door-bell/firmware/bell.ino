// This #include statement was automatically added by the Particle IDE.
#include "clickButton/clickButton.h"

int LED = D7;                      
int bellValue = 0;                       
char pubString[40];
ClickButton button(D0, HIGH);

void setup()
{
  pinMode(LED, OUTPUT);   
  pinMode(D0, INPUT); 
  
  button.debounceTime   = 20;   // Debounce timer in ms
  button.multiclickTime = 250;  // Time limit for multi clicks
  button.longClickTime  = 1000; // time until "held-down clicks" register
}

void loop()
{
  button.Update();

  if (button.clicks != 0) {
    bellValue = button.clicks;
    sprintf(pubString, "%d", bellValue);
    Particle.publish("bell", pubString);
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);  
  }
  
  bellValue = 0;
  delay(5);
}
