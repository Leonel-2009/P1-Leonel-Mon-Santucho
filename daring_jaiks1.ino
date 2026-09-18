#include <Servo.h>
#define LR 4
#define LV 7
#define LA 8
#define bot 2
#define Pie 5

#define SensorTemp A1

Servo servo1;

void setup()
{
  pinMode(bot, INPUT_PULLUP);
  
  servo1.attach(A0);
  servo1.write(0);
  
  Serial.begin(9800);
}

void loop()
{
  int Botton = digitalRead(bot);
  Serial.println(Botton);
  
  Temperatura();
  
  if(Botton == LOW)
  {
    servo1.write(90);
    delay(1000);
  }
  else if(Botton == HIGH)
  {
    servo1.write(0);
    delay(1000);
  }
  
}

void Temperatura()
{
  int Temp = analogRead(SensorTemp);
  int Grados = map(Temp, 0, 1024, 0, 100);
  
  
  if(Grados > 40)
  {
    digitalWrite(LR, HIGH);
    digitalWrite(LV, LOW);
    digitalWrite(LA, LOW);
  }
  else if(Grados < 10)
  {
    digitalWrite(LR, LOW);
    digitalWrite(LV, LOW);
    digitalWrite(LA, HIGH);
  }
  else if(Pie == HIGH)
  {
    digitalWrite(LR, LOW);
    digitalWrite(LV, HIGH);
    digitalWrite(LA, LOW);
  }
    
}
