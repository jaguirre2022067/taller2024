/*
  Fundacion Kinal
  Centro educativo tecnico laboral kinal
  Quinto perito
  Quinto electronica
  Codigo tecnico: EB5AM
  Curso: Taller de electronica digital y reparecion de computadoras
  Proyecto: secuancia de leds y display 
  Dev:Jose Aguirre
  Fecha:29 de abril
*/



int contador = 0;  
int contador_4 = 0;
int tiempo = 0;
int texto = 0;

void setup(){
  Serial.begin(9600);
  //Entradas
  pinMode(13, INPUT);    
  pinMode(12, INPUT);
  pinMode(2, INPUT);    
  pinMode(3, INPUT);
  //Salidas
  pinMode(4, OUTPUT);    
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);    
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);    
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);    
  pinMode(11, OUTPUT);
}
void loop(){
  
  if(digitalRead(3) == HIGH){
  Serial.println("Practica 4");
  Serial.println("Jose Andres Aguirre Castillo");
    delay(4000);
  }
      if(digitalRead(2) == HIGH){
  contador =(contador + 1);
    tiempo = 500;
      if(contador > 15){
       contador = 2;
   }
  }else if(digitalRead(3)==LOW){
      contador = 0;
  }
 
  delay(tiempo);
  //secuencia
  if (contador == 1){
    digitalWrite(4, HIGH);
  } else{
    digitalWrite(4, LOW);  
  }
    if (contador == 2){
    digitalWrite(5, HIGH);
  } else{
    digitalWrite(5, LOW);  
  }
    if (contador == 3){
    digitalWrite(6, HIGH);
  } else{
    digitalWrite(6, LOW);  
  }
  if (contador == 4){
    digitalWrite(7, HIGH);
   } else{
    digitalWrite(7, LOW);  
  }
  if (contador == 5){
    digitalWrite(8, HIGH);
  } else{
    digitalWrite(8, LOW);  
  }
  if (contador == 6){
    digitalWrite(9, HIGH);
  } else{
    digitalWrite(9, LOW);  
  }
  if (contador == 7){
    digitalWrite(10, HIGH);
  } else{
    digitalWrite(10, LOW);  
  }
  if (contador == 8){
    digitalWrite(11, HIGH);
  } else{
    digitalWrite(11, LOW);  
  }
  //secuencia en reversa
  if (contador == 9){
    digitalWrite(10, HIGH);
  }
  if (contador == 10){
    digitalWrite(9, HIGH);
  }
  if (contador == 11){
    digitalWrite(8, HIGH);
  }
  if (contador == 12){
    digitalWrite(7, HIGH);
  }
  if (contador == 13){
    digitalWrite(6, HIGH);
  }
  if (contador == 14){
    digitalWrite(5, HIGH);
  }
  if (contador == 15){
    digitalWrite(4, HIGH);
}
 //Cuatro
    if(digitalRead(12) == HIGH){
  contador_4 =(contador_4 + 1);
    tiempo = 2000;
      if(contador_4 > 6){
       contador_4 = 1;
   }
  }else if(digitalRead(12)==LOW){
      contador_4 = 0;
  }
  delay(500);
  //C
    if (contador_4 == 1){
    digitalWrite(4, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
  }
  //U
    if (contador_4 == 2){
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
  }
  //A
    if (contador_4 == 3){
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(10, HIGH);
  }
   //T
    if (contador_4 == 4){
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
  }
  //R
    if (contador_4 == 5){
    digitalWrite(4, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
  }
  //O
    if (contador_4 == 6){
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    }
   //gracias por su atencion
 if(digitalRead(2) == HIGH && digitalRead(13) == HIGH ){
   Serial.println("Gracias por su atencion ");
  }
}