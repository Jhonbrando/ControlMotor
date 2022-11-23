const int channelPinA = 13;
const int channelPinB = 12;

const int timeThreshold = 1;//Valor más cercano para los 180 pulsos en media vuelta
long timeCounter = 0;

const int maxSteps = 360; //360 pulsos por revolución
volatile int ISRCounter = 0;
int counter = 0;

float resolution = 360.0;

unsigned long timeold;


bool IsCW = true;

void setup()
{
   pinMode(channelPinA, INPUT_PULLUP);
   pinMode(channelPinB, INPUT_PULLUP);
   Serial.begin(115200);
   attachInterrupt(digitalPinToInterrupt(channelPinA), doEncodeA, CHANGE);
   attachInterrupt(digitalPinToInterrupt(channelPinB), doEncodeB, CHANGE);
}

void loop()
{
  
   if (counter != ISRCounter)
   {
      counter = ISRCounter;

  if (millis() - timeold >= 1000)
    {
      //Modifica las variables de la interrupción forma atómica
      ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
        //rpm = float(pulsos * 60.0 / 374.22); //RPM
        rpm = float((60.0 * 1000.0 / resolution ) / (millis() - timeold) * counter);
        timeold = millis();
      }
      Serial.print("RPM: ");
      Serial.println(rpm);
    }

   }
   delay(20);//valor más próximo a obtener los 180 pulsos en media vuelta -->se obtienen 171 aprox.
   
}

void doEncodeA()
{
   if (millis() > timeCounter + timeThreshold)
   {
      if (digitalRead(channelPinA) == digitalRead(channelPinB))
      {
         IsCW = true;
         if (ISRCounter + 1 <= maxSteps) ISRCounter++;
          if (ISRCounter>359){
            ISRCounter=0;
          }else if (ISRCounter<1){
            ISRCounter=359;
      }
      }
      else
      {
         IsCW = false;
         if (ISRCounter - 1 >= 0) ISRCounter--;
          if (ISRCounter>359){
            ISRCounter=0;
          }else if (ISRCounter<1){
            ISRCounter=359;
          }
      }
      timeCounter = millis();
      
   }
}

void doEncodeB()
{
   if (millis() > timeCounter + timeThreshold)
   {
      if (digitalRead(channelPinA) != digitalRead(channelPinB))
      {
         IsCW = true;
         if (ISRCounter + 1 <= maxSteps) ISRCounter++;
          if (ISRCounter>359){
            ISRCounter=0;
          }else if (ISRCounter<1){
            ISRCounter=359;
          }
      }
      else
      {
         IsCW = false;
         if (ISRCounter - 1 >= 0) ISRCounter--;
          if (ISRCounter>359){
              ISRCounter=0;
          }else if (ISRCounter<1){
              ISRCounter=359;
          }
      }
      timeCounter = millis();
     
   }
}
