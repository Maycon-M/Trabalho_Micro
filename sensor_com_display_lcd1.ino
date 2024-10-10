#include <LiquidCrystal.h>

const int pinSensor = A0;
const int pinTransistor = 9;
const int temp1 = 24;
const int temp2 = 36;
const int backlightPin = 10;
LiquidCrystal lcd2(12, 11, 5, 4, 3, 2);

void setup()
{
  pinMode(pinSensor, INPUT);
  pinMode(pinTransistor, OUTPUT);
  pinMode(backlightPin, OUTPUT);
  analogWrite(backlightPin, 255);
  Serial.begin(9600);
  lcd2.begin(15, 2);
  lcd2.print("Temperatura:");
}

void loop()
{
  lcd2.setCursor(0,1);
  int tempValue = analogRead(pinSensor);
  // Converte o valor lido para temperatura em graus Celsius (assumindo um sensor LM35)
  float tempAnalog = (tempValue * 5.0) / 1024;
  float temperature = (tempAnalog - 0.5)*100;
  //Remover quando tiver o Display
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  lcd2.print(temperature);
  Serial.println(" C");
  int motorSpeed = map(temperature, temp1, temp2, 0, 255); // Mapeia a temperatura entre temp1 °C e temp2 °C para valores PWM (0-255)
  //Limitando a velocidade do motor
  motorSpeed = constrain(motorSpeed, 0, 255);
  // Define a velocidade do motor
  analogWrite(pinTransistor, motorSpeed);
  // Aguarda um pequeno intervalo antes de repetir
  delay(500);
}