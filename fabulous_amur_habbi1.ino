//includes
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//defines
#define LR 13
#define LA 12
#define SensorTemp A2
#define boton1 2
#define boton2 4
#define Pie 7

#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Gb4 415
#define G4 392
#define F4 349
#define E4 330

const int tema1[5][3] = {
 {Gb4, 136, 136},
 {G4, 136, 136},
 {F4, 136, 136},
 {E4, 136, 0},
 {G4, 136, 0},
};

LiquidCrystal_I2C lcd(32, 16, 2);
Servo servo1;
Servo servo2;

//variables
int Grados = 0;

void Musica(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

void setup()
{
  pinMode(LR, OUTPUT);
  pinMode(LA, OUTPUT);
  
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(Pie, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0); 
  lcd.print("Cerrado");
  
  servo1.attach(A0);
  servo2.attach(A1);
  
  servo1.write(90);
  servo2.write(90);
  
  Serial.begin(9800);
}

void loop()
{
  Control_Temp();
  botoncito1();
  botoncito2();
}


void Control_Temp()
{
  int valorTemp = analogRead(SensorTemp);
  Grados = map(valorTemp, 0, 800, 0, 100);
  Serial.println(Grados);
  
  if(Grados < 10)
  {
    digitalWrite(LA, HIGH);
    digitalWrite(LR, LOW);
  }
  else if(Grados > 30)
  {
    digitalWrite(LR, HIGH);
    digitalWrite(LA, LOW);
  }
  else
  {
    digitalWrite(LR, LOW);
    digitalWrite(LA, LOW);
  }
  
}


void botoncito1()
{
  int bot1 = digitalRead(boton1);
  if(bot1 == LOW)
  {
    abrir_servo();
  }
}
void botoncito2()
{
  int bot2 = digitalRead(boton2);
  if(bot2 == LOW)
  {
    cerrar_servo();
  }
}


void abrir_servo()
{
  servo1.write(0);
  servo2.write(0);
  Musica(Pie, tema1, 5);
  
  lcd.clear();        
  lcd.setCursor(0, 0);
  lcd.print("Abierto");
  delay(1000);
}
void cerrar_servo()
{
  servo1.write(90);
  servo2.write(90);
  digitalWrite(Pie, LOW);
  
  lcd.clear();        
  lcd.setCursor(0, 0);
  lcd.print("Cerrado");
  delay(1000);
}