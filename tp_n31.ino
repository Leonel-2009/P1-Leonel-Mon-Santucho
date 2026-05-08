#define LR 12
#define LA 8
#define LV 7

#define SensorLuz A0

#define SensorTemp A1

int Grados;
float PorcentajeLuz;

void setup() {
  Serial.begin(9600);
  
  pinMode(LR, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(LV, OUTPUT);
}

void loop() 
{
  Temperatura();
  Luz();
  
  Serial.print("Nivel de luz actual: ");
  Serial.print(PorcentajeLuz);
  Serial.print(" Nivel de luz actual: ");
  Serial.print(Grados);
  Serial.println("°C");
  
  Control();
}

void Temperatura()
{
	int valorTemp = analogRead(SensorTemp);
  	Grados = map(((valorTemp - 20) * 3.08), 1395, 2000, 0, 100);
} 

void Luz() 
{
	int valorLuz = analogRead(SensorLuz); 	
    PorcentajeLuz = map(valorLuz, 786, 1022, 0, 100);
}

void Control()
{
  digitalWrite(LR, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(LV, LOW);
  
  if (PorcentajeLuz >= 30 && PorcentajeLuz <= 70)
  {
    if (Grados > 90)
    {
      digitalWrite(LR, HIGH);
    }
    else if(Grados < 18)
    {
      digitalWrite(LA, HIGH);
    }
    else
    {
      digitalWrite(LV, HIGH);
    }  
  
  }

}