//includes
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//defines
#define PIR1 2
#define PIR2 4
#define Pie 7
#define SensorLuz A2
#define Foco 10

LiquidCrystal_I2C lcd(32, 16, 2);

Servo servo1;
Servo servo2;

//tema1
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define G3 196
#define A3 220
#define B3 247
#define C4 262

//tema2
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define C4 262
#define B3 247
#define A3 220
#define G3 196

//variables
int valorMov1 = 0; 
int valorMov2 = 0;

bool puerta = LOW;


//tema1
const int tema1[5][3] = {
 {G3, 200, 50},
 {A3, 200, 50},
 {B3, 200, 50},
 {C4, 200, 50},
 {G3, 300, 50},
};

//tema2
const int tema2[5][3] = {
 {C4, 200, 50},
 {B3, 200, 50},
 {A3, 200, 50},
 {G3, 200, 50},
 {A3, 300, 50},
};

void Musica(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}



//setup
void setup() 
{
  lcd.init();          
  lcd.backlight(); 
  
  lcd.setCursor(0, 0); 
  lcd.print("Cerrado");
  delay(1000);
  
  servo1.attach(A0);
  servo2.attach(A1);
  
  servo1.write(90);
  servo2.write(90);
    
  pinMode(PIR1, INPUT);
  pinMode(PIR2, INPUT);
  
  pinMode(Pie, OUTPUT);
  pinMode(Foco, OUTPUT);
  
  Serial.begin(9800);
}


//loop
void loop()
{
  valorMov1 = digitalRead(PIR1);
  valorMov2 = digitalRead(PIR2);
  
  if(valorMov1 == HIGH && puerta == LOW)
  {
    abrir_servo();
    puerta = HIGH;
  }
  else if(valorMov1 == HIGH && puerta == HIGH)
  {
    cerrar_puerta();
    puerta = LOW;
  }
  
  if(valorMov2 == HIGH && puerta == LOW)
  {
    abrir_servo();
    puerta = HIGH;
  }
  else if(valorMov2 == HIGH && puerta == HIGH)
  {
    cerrar_puerta();
    puerta = LOW;
  }
  
  encender_foco();
  
}

//funciones
void abrir_servo()
{
  servo1.write(0);
  servo2.write(0);
  
  lcd.clear();        
  lcd.setCursor(0, 0);
  lcd.print("Abierto");
  delay(1000);
  
  Musica(Pie, tema1, 5);
  delay(2500);
}

void cerrar_puerta()
{
  servo1.write(90);
  servo2.write(90);
 
  lcd.clear();        
  lcd.setCursor(0, 0);
  lcd.print("Cerrado");
  delay(1000);
  
  Musica(Pie, tema2, 5);
  delay(2500);
}

void encender_foco()
{
  int valorTemp = analogRead(SensorLuz);
  int Grados = map(valorTemp, 344, 1017, 100, 0);
  Serial.println(Grados);
  
  if(Grados < 50)
  {
    digitalWrite(Foco, HIGH);
  }
  else
  {
    digitalWrite(Foco, LOW);
  }
}
