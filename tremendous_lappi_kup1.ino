#define LR 8
#define LV 12
#define PIR 2
#define PI 4

bool valor = LOW;

void setup()
{
  pinMode(LR, OUTPUT);
  pinMode(LV, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(PI, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  valor = digitalRead(2);
  digitalWrite(LR, LOW);
  digitalWrite(LV, LOW);
  
    if (valor == HIGH)
    {
  		digitalWrite(LR, HIGH);
        digitalWrite(PI, HIGH);
    }
    else
    {
      	digitalWrite(LV, HIGH);
        digitalWrite(PI, LOW);
    }
}
