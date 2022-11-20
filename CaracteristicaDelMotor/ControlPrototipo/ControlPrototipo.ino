//Realizado por Jhon Brandol Muñoz
//Estudiante de Ingeniería Mecatrónica de la Universidad Nacional de Colombia
// Potenciometro conectado a GPIO 35
const int portPin = 35;
// Variables del control
const int HighL = 25;
const int LowL = 33;
const int Pwm = 32;

// Propiedades PWM
const int frecuencia = 5000;
const int canal = 0;
const int resolucion = 8;
// Almacenamiento del valor de puerto (Rango de 0-4095)
int potValor = 0;
//
int Velocidad[ ] = {0,0,0,0,1,1,2,2,3,4,5,6,7,8,9,10,12,13,15,16,18,20,21,23,25,27,29,31,33,35,37,39,41,43,45,48,50,52,54,56,58,60,62,64,66,68,70,72,74,75,77,79,80,82,83,85,86,87,88,89,90,91,92,93,93,94,94,95,95,95,95,95,95,95,94,94,93,93,92,91,90,89,88,87,86,85,83,82,80,79,77,75,74,72,70,68,66,64,62,60,58,56,54,52,50,48,45,43,41,39,37,35,33,31,29,27,25,23,21,20,18,16,15,13,12,10,9,8,7,6,5,4,3,2,2,1,1,0,0,0,0,0,0,-1,-1,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-13,-15,-16,-18,-20,-22,-24,-26,-29,-31,-33,-35,-38,-40,-43,-45,-47,-50,-52,-55,-57,-60,-62,-65,-67,-69,-72,-74,-76,-78,-80,-82,-84,-86,-88,-90,-91,-93,-94,-95,-97,-98,-99,-99,-100,-101,-101,-102,-102,-102,-102,-102,-102,-102,-101,-101,-100,-99,-99,-98,-97,-95,-94,-93,-91,-90,-88,-86,-84,-82,-80,-78,-76,-74,-72,-69,-67,-65,-62,-60,-57,-55,-52,-50,-47,-45,-43,-40,-38,-35,-33,-31,-29,-26,-24,-22,-20,-18,-16,-15,-13,-11,-10,-8,-7,-6,-5,-4,-3,-2,-1,-1,-1,0,0,0};

void setup() {
  // put your setup code here, to run once:
  //iniciación de comunicación serial a 9600 baudios
  pinMode(HighL,OUTPUT);
  pinMode(LowL,OUTPUT);
  //configuramos la funcionalidad PWM
  ledcSetup(canal, frecuencia, resolucion);
  //Se asocia el canal al GPIO
  ledcAttachPin(Pwm,canal);
  Serial.begin(9600);
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
   digitalWrite(HighL, LOW);  
   digitalWrite(LowL, HIGH); 
  ledcWrite(canal, potValor);  
  

 /*  
// Control de motor
  int Vpwm =0;
 for (int i=0;i<270;i++){
   //Giro a la derecha
   if (i<135){
     digitalWrite(HighL, LOW);  
     digitalWrite(LowL, HIGH);  
          Vpwm = Velocidad[i];   
      ledcWrite(canal, Vpwm);
     }else{
//Giro a la Izquierda 
  delay(10);  
    digitalWrite(HighL, HIGH);  
     digitalWrite(LowL, LOW); 
      Vpwm = -Velocidad[i];     
    ledcWrite(canal, Vpwm);
   }
   //Análisis de la gráfica de Velocidad   
  //Serial.println(Velocidad[i]); 
    delay(10);  
  }  
  */

  //delay(10);
}