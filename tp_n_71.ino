#include <Servo.h>
#define boton 2
#define temp A2
#define PIR A3
 
Servo servo1;
Servo servo2;

bool valorMovimiento = LOW;
int Grados;

void setup()
{
  servo1.attach(A0);
  servo1.write(90);
  
  servo2.attach(A1);
  servo2.write(90); 
  
  pinMode(boton, INPUT_PULLUP);
  pinMode(PIR, INPUT);
}

void loop()
{
  valorMovimiento = digitalRead(PIR);
  temperatura();
  botoncito();
}

void botoncito()
{
  if(digitalRead(boton) == LOW)
  {
    movimiento();
  }
  else if(valorMovimiento == HIGH)
  {
    servo0();
  }
  else if(Grados > 35)
  {
    return;
  }
  else if(digitalRead(boton) == HIGH)
  {
    servo45();
  }
}

void temperatura()
{
	int valorTemp = analogRead(temp);
  	Grados = map(((valorTemp - 20) * 3.08), 0, 2000, 0, 100);
} 

void movimiento()
{
  for(int i = 90; i < 180; i+=10)
  {
    servo1.write(i);
    servo2.write(i);
    delay(3000);
  }
}

void servo0()
{
   servo1.write(0);
   servo2.write(0);
   delay(6000);
}

void servo45()
{
  servo1.write(45);
  servo2.write(45);
}