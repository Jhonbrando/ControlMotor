//Realizado por Jhon Brandol Muñoz
//Estudiante de Ingeniería Mecatrónica de la Universidad Nacional de Colombia
// Potenciometro conectado a GPIO 35
const int portPin = 35;
// Variables del control
const int Pwm = 32;

// Propiedades PWM Manecilla 
const int frecuencia = 5000;
const int canal = 0;
const int resolucion = 8;
// Propiedades PWM Contra Manecilla 


// Almacenamiento del valor de puerto (Rango de 0-4095)
int potValor = 0;
//

void setup() {
  // put your setup code here, to run once:
  //iniciación de comunicación serial a 9600 baudios
  Serial.begin(9600);
  
  //configuramos la funcionalidad PWM Manecilla
  ledcSetup(canal, frecuencia, resolucion);
  //Se asocia el canal al GPIO Manecilla
  ledcAttachPin( Pwm,canal);

}

void loop() {
  
  //Prueba del perfil de velocidad
  /*
 /for (int i=0;i<270;i++){
   Serial.println(Velocidad[i]); 
   delay(10);
 }*/


   // Lectura del valor en cada vuelta del bucle
  potValor = analogRead(portPin)*255/4095;
  // potValor = map(potValor,0,4095,200); // 0 =50 PWM y 4095 es un 200 PWM
  Serial.println(potValor);  //Envío del valor al puerto serie
  ledcWrite(canal, potValor);  

}