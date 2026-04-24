int V = 9;
int A = 10;
int R = 11;

int almacenverde = A1;  
int almacenazul = A2;  
int almacenrojo = A3;

int boton = 2;

int estadoBoton = false;

void setup(){
  
  pinMode(V, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(R, OUTPUT);
  
  pinMode(boton , INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop()
{
    if (digitalRead(boton) == LOW && !estadoBoton){
 	
    estadoBoton = true;
      
    Serial.println("Tiene 10 s para configurar el color del led....");
    
    delay(10000);
      
    int inicio = millis();
      
    int valorRojo = 0;
    int valorAzul = 0;
    int valorVerde = 0;
      
      while (millis() - inicio < 10000){
      
    	valorRojo = analogRead(almacenrojo);
    	valorAzul = analogRead(almacenazul);
    	valorVerde = analogRead(almacenverde);
      
    	valorRojo = map(valorRojo, 0 , 1023, 0, 255);
    	valorAzul = map(valorAzul, 0 , 1023, 0, 255); 
    	valorVerde = map(valorVerde, 0 , 1023, 0, 255);
	
    	analogWrite( R, valorRojo);
    	analogWrite( A, valorAzul);
    	analogWrite( V, valorVerde);
      }
      
    Serial.print("El led esta usando esta configuracion de colores RGB: (");
    Serial.print(valorRojo);  
    Serial.print(", ");
    Serial.print(valorAzul);  
    Serial.print(", ");    
    Serial.print(valorVerde);  
    Serial.println(" )");
      
    analogWrite( R, 0);
    analogWrite( A, 0);
    analogWrite( V, 0);
      
    estadoBoton = false;
  }
}    
   