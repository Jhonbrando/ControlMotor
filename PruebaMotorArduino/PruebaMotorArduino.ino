//Realizado por Jhon Brandol Muñoz
//Estudiante de Ingeniería Mecatrónica de la Universidad Nacional de Colombia
// Potenciometro conectado a GPIO 35
const int portPin = 35;
// Variables del control
const int HighL = 2;
const int LowL = 3;
const int Pwm = 5;
// Almacenamiento del valor de puerto (Rango de 0-4095)
int potValor = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(HighL,OUTPUT);
  pinMode(LowL,OUTPUT);
  pinMode(Pwm,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
potValor = analogRead(portPin)*255/4095;
  // potValor = map(potValor,0,4095,200); // 0 =50 PWM y 4095 es un 200 PWM
    Serial.println(potValor);  //Envío del valor al puerto serie
    digitalWrite(Pwm, HIGH); 
    digitalWrite(HighL, LOW);  
    digitalWrite(LowL, HIGH); 
    delay(3000);
    digitalWrite(Pwm, LOW); 
    delay(3000);
}
