const int pinSensor = A0;
const byte pinTransistor = 9;
const int temp1 = 24;
const int temp2 = 36;

void setup()
{
  pinMode(pinSensor, INPUT);
  pinMode(pinTransistor, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int tempValue = analogRead(pinSensor);
  // Converte o valor lido para temperatura em graus Celsius (assumindo um sensor LM35)
  float temperature = (tempValue * 5.0 * 100.0) / 1024;
  //Remover quando tiver o Display
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" C");
  int motorSpeed = map(temperature, temp1, temp2, 0, 255); // Mapeia a temperatura entre temp1 °C e temp2 °C para valores PWM (0-255)
  //Limitando a velocidade do motor
  motorSpeed = constrain(motorSpeed, 0, 255);
  // Define a velocidade do motor
  analogWrite(pinTransistor, motorSpeed);
  // Aguarda um pequeno intervalo antes de repetir
  delay(500);
}