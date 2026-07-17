#define LR 11
#define LA 10
#define LV 9

void setup()
{
  pinMode(LR, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(LV, OUTPUT);
  
  Serial.begin(9800);
  
  randomSeed(analogRead(A0));
}

void loop()
{
  int valor = analogRead(A0);
  int porcentaje = map(valor, 0, 1023, 0, 100);
  
  Serial.print("Potenciometro: ");
  Serial.print(porcentaje);
  Serial.println(" %");
  
  if(porcentaje < 20)
  {
    ejercicio1();
  }
  else if(porcentaje > 20 && porcentaje < 40)
  {
    ejercicio2();
  }
  else if(porcentaje > 40 && porcentaje < 60)
  {
    ejercicio3();
  }
  else if(porcentaje > 60 && porcentaje < 80)
  {
    ejercicio4();
  }
  else
  {
    ejercicio5();
  }
}

void ejercicio1()
{
  int listaNumeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int nuevaLista[10];
  int factor = 2;
  
  for(int x = 0; x < 10; x++)
  {
 	nuevaLista[x] = listaNumeros[x] * factor;
  }
  
  for(int i = 0; i < 3 ; i++)
  {
    digitalWrite(LR, HIGH);
    digitalWrite(LA, HIGH);
    digitalWrite(LV, HIGH);
    
    delay(1000);
    
    digitalWrite(LR, LOW);
    digitalWrite(LA, LOW);
    digitalWrite(LV, LOW);
    
    delay(1000);
  } 
}

void  ejercicio2()
{
  int Notas[] = {10, 10, 10, 10, 10, 9, 9, 9, 9, 10};
  int promedio = 0;
  
  for(int x = 0; x < 10; x++)
  {
 	promedio += Notas[x];
  }
  
  promedio = promedio / 10;
  
  if(promedio >= 1 && promedio <= 5)
  {
    digitalWrite(LR, HIGH);
  }
  else if(promedio >= 6 && promedio <= 8)
  {
    digitalWrite(LV, HIGH);
  }
  else
  {
    digitalWrite(LA, HIGH);
  }
}

void ejercicio3()
{
  int Numeros[15];
  int acum = 0;
  
  for(int x = 0; x < 15; x++)
  {
    acum = Numeros[x];
  
  	if(acum % 2 == 0)
  	{
      digitalWrite(LA, LOW);
      digitalWrite(LV, HIGH);
      digitalWrite(LR, LOW);
  	}
  	else
  	{
      digitalWrite(LA, LOW);
   	  digitalWrite(LR, HIGH);
      digitalWrite(LV, LOW);
  	}
    
    delay(1000);
  }
}

void ejercicio4()
{
  int numeros[30];
  
  int maximo1 = 0;
  int maximo2 = 0;
  int maximo3 = 0;
  
  for(int x = 0; x < 30 ; x++)
  {
    numeros[x] = random(0, 255);
    
    if(numeros[x] > maximo1)
    {
      maximo3 = maximo2;
      maximo2 = maximo1;
      maximo1 = numeros[x];
    }
    else if(numeros[x] > maximo2)
    {
      maximo3 = maximo2;
      maximo2 = numeros[x];
    }
    else
    {
      maximo3 = numeros[x];
    }
  }
  
  Serial.print("Primer numero mayor: ");
  Serial.println(maximo1);
  Serial.print("Segundo numero mayor: ");
  Serial.println(maximo2);
  Serial.print("Tercer numero mayor: ");
  Serial.println(maximo3);
  
  digitalWrite(LR, maximo1);
  digitalWrite(LA, maximo2);
  digitalWrite(LV, maximo3);
  
  delay(2000);
}


void ejercicio5()
{
  int numeros[30];
  
  int minimo1 = 255;
  int minimo2 = 255;
  int minimo3 = 255;
  
  for(int x = 0; x < 30 ; x++)
  {
    numeros[x] = random(0, 256);
    
    if(numeros[x] < minimo1)
    {
      minimo3 = minimo2;
      minimo2 = minimo1;
      minimo1 = numeros[x];
    }
    else if(numeros[x] < minimo2)
    {
      minimo3 = minimo2;
      minimo2 = numeros[x];
    }
    else
    {
      minimo3 = numeros[x];
    }
  }
  
  Serial.print("Primer numero menor: ");
  Serial.println(minimo1);
  Serial.print("Segundo numero menor: ");
  Serial.println(minimo2);
  Serial.print("Tercer numero menor: ");
  Serial.println(minimo3);
  
  digitalWrite(LR, minimo1);
  digitalWrite(LA, minimo2);
  digitalWrite(LV, minimo3);
  
  delay(2000);
}