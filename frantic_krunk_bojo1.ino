//includes
#include <Servo.h>

//defines
#define LR 3
#define LA 5
#define LV 6
#define Pie 7

//--------

#define Pot A1
#define SensorTemp A2
#define PIR A3

//Adafruit_LiquidCrystal lcd(36, 16, 2);
Servo servo;

#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Gb3 208
#define C4 262
#define F3 175
#define A3 220

const int tema[10][3] = {
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 115},
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 0},
};

void playMidi(int pin, const int notes[][3], size_t len){
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
  pinMode(LV, OUTPUT);
  pinMode(Pie, OUTPUT);
  
  servo.attach(A0);
  servo.write(0);
  
  Serial.begin(9800);
}

void loop()
{
  TiempoEspera();
  Temperatura();
}

void MoverServo()
{
  servo.write(90);
  delay(1000);
      
  servo.write(0);
  delay(1000);
}

void TiempoEspera()
{
  int valor = analogRead(Pot);
  int porcentaje = map(valor, 0, 675, 0, 100);
  
  if(porcentaje < 10 || PIR == HIGH)
  {
    for(int x = 0; x < 8; x++)
    {
      MoverServo();
    }
    Melodia();
  }
  
  if(porcentaje > 10 && porcentaje < 70)
  {
    for(int x = 0; x < 2; x++)
    {
      MoverServo();
    }
    Melodia();
  }
  
  if(porcentaje > 70)
  {
    for(int x = 0; x < 5; x++)
    {
      MoverServo();
    }
    Melodia();
  }
}

void Temperatura()
{
  int Temp = analogRead(SensorTemp);
  int porcentaje = map(Temp, 20, 358, 0, 100);
  Serial.println(porcentaje);
  if(porcentaje > 40)
  {
    digitalWrite(LR, HIGH);
    digitalWrite(LA, LOW);
    digitalWrite(LV, LOW);
  }
  else if(porcentaje < 40)
  {
    digitalWrite(LR, LOW);
    digitalWrite(LA, HIGH);
    digitalWrite(LV, LOW);
  }
}

void Melodia()
{
  digitalWrite(LV, HIGH);
  digitalWrite(LR, LOW);
  digitalWrite(LA, LOW);
  playMidi(Pie, tema, 5);
}