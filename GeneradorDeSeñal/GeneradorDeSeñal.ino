float Amplitud,FrecuenciaDatos, PeriodoTotal,x,resultados;



void setup() {
  // put your setup code here, to run once:
Amplitud=5;
FrecuenciaDatos=100;
PeriodoTotal=2.7;
Serial.begin(9600);

}

void loop() {
  
        float Intervalo=1/FrecuenciaDatos;
      for (int n=0; n<PeriodoTotal; n++){
      resultados=Amplitud*sin(x);
      
      delay(1000);
      x+=Intervalo;
      Serial.println(x); 
      }

 

}
