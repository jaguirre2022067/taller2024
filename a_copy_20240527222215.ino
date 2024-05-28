/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica 6
   Dev: Jose Aguirre
   Fecha: 26 de mayo
 
*/


#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuración del teclado matricial
const byte filas = 4;
const byte columnas = 4;
char keys[filas][columnas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte filPins[filas] = {9, 8, 7, 6};
byte colPins[columnas] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), filPins, colPins, filas, columnas);

// Configuración del servo
Servo servo;

// Configuración de la pantalla LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Pines para LEDs
const int ledPins[4] = {13, 12, 11, 10};

// Configuración de los pines del display de 7 segmentos
const int segmentPins[7] = {A0, A1, A2, A3, A4, A5, 13};

// Variables globales
bool autostate = false;

// Configuración inicial
void setup() {
  Serial.begin(9600);
  servo.attach(9);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Jose Aguirre");
  lcd.setCursor(0, 1);
  lcd.print("Proyecto Final");
  
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

// Función para mostrar el número en el display de 7 segmentos
void displayNumber(int num) {
  // Mapa de segmentos para cada número (0-9)
  byte segmentMap[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
  };
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(segmentMap[num], i));
  }
}

// Función para la animación del auto fantástico
void autoFantastic() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = 2; i >= 1; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    switch (key) {
      case '1':
        for (int counter = 0; counter <= 99; counter++) {
          Serial.println(counter);
          delay(200);
        }
        break;
        
      case '2':
        for (int counter = 99; counter >= 0; counter--) {
          Serial.println(counter);
          delay(200);
        }
        break;
        
      case '3':
        autostate = !autostate;
        break;
        
      case '4':
        for (int i = 0; i <= 9; i++) {
          displayNumber(i);
          delay(500);
        }
        break;
        
      case '5':
        servo.write(180);
        delay(1000);
        servo.write(0);
        delay(1000);
        break;
    }
  }
  if (autostate) {
    autoFantastic();
  }
}