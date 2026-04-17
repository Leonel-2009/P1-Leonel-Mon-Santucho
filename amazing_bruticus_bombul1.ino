// C++ code
//
void setup()
{
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);

//rojo  
  analogWrite(11, 255); 
  analogWrite(10, 255);
  analogWrite(9, 255);

//magenta
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  
//cian suave
  analogWrite(6, 255);
  analogWrite(5, 255);
  analogWrite(3, 255);
}

void ApagarTodo(){
//rojo  
  analogWrite(11, 0); 
  analogWrite(10, 0);
  analogWrite(9, 0);

//magenta
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  
//cian suave
  analogWrite(6, 0);
  analogWrite(5, 0);
  analogWrite(3, 0);
}

void Naranja(){
  for (int i = 0; i < 4; i++){

  analogWrite(11, 255);
  analogWrite(9, 150);


  digitalWrite(8, 255);
  digitalWrite(4, 150);
  

  analogWrite(6, 255);
  analogWrite(3, 150);
  
  delay(100);
  ApagarTodo();
  delay(100);
  }
}

void loop(){

  ApagarTodo();
  analogWrite(11, 255);
  delay(1000);
    
  Naranja();
  
  ApagarTodo();
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  delay(1000);

  Naranja();
  
  ApagarTodo();
  digitalWrite(5, 100);
  digitalWrite(3, 100);
  delay(1000);

  Naranja();
}





