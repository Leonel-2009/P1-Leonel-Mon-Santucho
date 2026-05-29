#define LA 2
#define LR 4
#define boton 7
#define SensorLuz A1
#define PIR A0

float porcentajeLuz = 0;
bool valorMovimiento = LOW;

void setup()
{
  Serial.begin(9800);
  pinMode(LA, OUTPUT);
  pinMode(LR, OUTPUT);
  pinMode(PIR, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
}

void loop()
{
  int valorLuz = analogRead(SensorLuz);
  porcentajeLuz = map(valorLuz, 344, 1020, 0, 100);
  
  digitalWrite(LA, LOW);
  digitalWrite(LR, LOW);
    
  digitalWrite(boton, HIGH);
   
  if(digitalRead(boton) == LOW && porcentajeLuz > 50)
  {
    
    valorMovimiento = digitalRead(PIR);
    
    if(valorMovimiento == HIGH)
    { 
    	digitalWrite(LA, HIGH);
    	digitalWrite(LR, HIGH); 
    }
  }
  
}

