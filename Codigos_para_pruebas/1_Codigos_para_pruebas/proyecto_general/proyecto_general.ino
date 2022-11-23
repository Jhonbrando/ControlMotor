
const int  RPWM_Output = 2;
const int  LPWM_Output = 4;
const int  final_izq = 18;
const int  final_der = 19;

int flag_izq=3;
int flag_der=3;


// Propiedades PWM Manecilla 
const int frecuencia = 15000;
const int canal = 1;
const int resolucion = 8;


//
int Velocidad[ ] = {0,0,0,6,6,7,8,9,11,12,13,15,17,19,21,24,26,29,31,34,37,40,43,46,50,53,57,60,64,67,71,75,78,82,86,90,94,97,101,105,109,112,116,120,123,127,130,133,136,140,143,146,148,151,154,156,158,161,163,164,166,168,169,170,171,172,173,174,174,174,175,174,174,174,173,172,171,170,169,168,166,164,163,161,158,156,154,151,148,146,143,140,136,133,130,127,123,120,116,112,109,105,101,97,94,90,86,82,78,75,71,67,64,60,57,53,50,46,43,40,37,34,31,29,26,24,21,19,17,15,13,12,11,9,8,7,6,6,5,5,5,5,5,4,3,2,1,0,-2,-3,-5,-7,-10,-12,-15,-18,-21,-24,-27,-31,-34,-38,-42,-46,-50,-54,-58,-62,-66,-71,-75,-80,-84,-88,-93,-97,-101,-106,-110,-114,-118,-123,-127,-130,-134,-138,-142,-145,-148,-151,-154,-157,-160,-162,-165,-167,-169,-171,-172,-174,-175,-176,-176,-177,-177,-177,-177,-177,-176,-176,-175,-174,-172,-171,-169,-167,-165,-162,-160,-157,-154,-151,-148,-145,-142,-138,-134,-130,-127,-123,-118,-114,-110,-106,-101,-97,-93,-88,-84,-80,-75,-71,-66,-62,-58,-54,-50,-46,-42,-38,-34,-31,-27,-24,-21,-18,-15,-12,-10,-7,-5,-3,-2,0,0,0,0,0,0,0};
//max 147
// tamaño Velocidad[] 270
int detencion []={50,46,43,40,37,34,31,29,26,24,21,19,17,15,13,12,11,9,8,7,6,6,5,5,5,5,5,4,3,2,1,0};
//tamaño detencion[] 32



void setup() {

  Serial.begin(9600);
  pinMode(RPWM_Output,OUTPUT);
  pinMode(LPWM_Output,OUTPUT);
  pinMode(final_izq,INPUT);
  pinMode(final_der,INPUT);
  //configuramos la funcionalidad PWM Manecilla
  ledcSetup(0, frecuencia, resolucion);
  //Se asocia el canal al GPIO Manecilla
  ledcAttachPin( RPWM_Output,0);
  //configuramos la funcionalidad PWM ContrManecilla
  ledcSetup(1,frecuencia, resolucion);
  //Se asocia el canal al GPIO Manecilla
  ledcAttachPin(LPWM_Output,1);
  
  
}

void loop() {
  

// Control de motor
  int Vpwm =0;
 for (int i=0;i<270;i++){
   //Giro a la derecha
   if (i<135){
      Vpwm = Velocidad[i];      
      ledcWrite(0, Vpwm);
      ledcWrite(1, 0);
     }else{

      Vpwm = -Velocidad[i];
      ledcWrite(0, 0);     
      ledcWrite(1, Vpwm);
   }
   //Análisis de la gráfica de Velocidad   
  Serial.println(Velocidad[i]); 
    delay(10);  
  }  

if (final_izq==HIGH ){
  delay(10);
  //ejecutamos rutina de detención
  for (n=0;n<32;n++){
      Vpwm = detencion[n];      
      ledcWrite(0, Vpwm);
      ledcWrite(1, 0);
      delay(10);
  }

}else if (final_der=HIGH){
  delay(10);
  //ejecutamos rutina de detención
  for (n=0;n<32;n++){
      Vpwm = detención[n];      
      ledcWrite(0, 0);
      ledcWrite(1, Vpwm);
      delay(10);
  }
}
  
  
}
