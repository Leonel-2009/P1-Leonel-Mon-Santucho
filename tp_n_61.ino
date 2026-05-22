#include <Servo.h>
#define boton1 1
#define boton2 2

Servo servo1;
Servo servo2;

int rotacion;

void setup() 
{
  servo1.attach(A0);
  servo1.write(0);
  
  servo2.attach(A1);
  servo2.write(0); 
  
  pinMode(boton1 , INPUT_PULLUP);
  pinMode(boton2 , INPUT_PULLUP);
}



void loop() 
{
  botoncito1();
  botoncito2();
}



void avanzar()
{
   rotacion = rotacion + 10;
   servo1.write(rotacion);
   servo2.write(rotacion);
   Serial.print(rotacion);
   delay(1000);
}
void retroceder()
{
   rotacion = rotacion - 10;
   servo1.write(rotacion);
   servo2.write(rotacion);
   delay(1000);
}



void botoncito1()
{
  if(digitalRead(boton1) == LOW)
  {
    avanzar();
  }
}
void botoncito2()
{
  if(digitalRead(boton2) == LOW)
  {
    retroceder();
  }
}