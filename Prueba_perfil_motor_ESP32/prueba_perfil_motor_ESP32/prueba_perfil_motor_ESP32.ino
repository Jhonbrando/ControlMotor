
  
/*
IBT-2 Motor Control Board driven by Arduino.
 
Speed and direction controlled by a potentiometer attached to analog input 0.
One side pin of the potentiometer (either one) to ground; the other side pin to +5V
 
Connection to the IBT-2 board:
IBT-2 pin 1 (RPWM) to Arduino pin 5(PWM)
IBT-2 pin 2 (LPWM) to Arduino pin 6(PWM)
IBT-2 pins 3 (R_EN), 4 (L_EN), 7 (VCC) to Arduino 5V pin
IBT-2 pin 8 (GND) to Arduino GND
IBT-2 pins 5 (R_IS) and 6 (L_IS) not connected
*/

// the number of the LED pin

// setting PWM properties
const int freq = 2000;
const int ledChannel_1 = 0;
const int ledChannel_2 = 1;
const int resolution = 8;

const int datos_vel[]={0,
6,
12,
19,
25,
31,
38,
44,
51,
57,
63,
70,
76,
82,
89,
95,
102,
108,
114,
121,
127,
133,
140,
146,
153,
159,
165,
172,
178,
184,
191,
197,
204,
210,
216,
223,
229,
235,
242,
248,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
255,
248,
242,
235,
229,
223,
216,
210,
204,
197,
191,
184,
178,
172,
165,
159,
153,
146,
140,
133,
127,
121,
114,
108,
102,
95,
89,
82,
76,
70,
63,
57,
51,
44,
38,
31,
25,
19,
12,
6,
0,
-6,
-12,
-19,
-25,
-31,
-38,
-44,
-51,
-57,
-63,
-70,
-76,
-82,
-89,
-95,
-102,
-108,
-114,
-121,
-127,
-133,
-140,
-146,
-153,
-159,
-165,
-172,
-178,
-184,
-191,
-197,
-204,
-210,
-216,
-223,
-229,
-235,
-242,
-248,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-255,
-248,
-242,
-235,
-229,
-223,
-216,
-210,
-204,
-197,
-191,
-184,
-178,
-172,
-165,
-159,
-153,
-146,
-140,
-133,
-127,
-121,
-114,
-108,
-102,
-95,
-89,
-82,
-76,
-70,
-63,
-57,
-51,
-44,
-38,
-31,
-25,
-19,
-12,
-6,
0,
};
//Se mandan los enable directamente a positivo.

int RPWM_Out = 2; // ESP32 PWM output pin 5; conectado al 1er IBT-2 pin 1 (RPWM) MOTOR IZQUIERDA
int LPWM_Out = 4; // ESP32 PWM output pin 6; conectado al 1er pin 2 (LPWM) MOTOR IZQUIERDA

void setup()
{
   ledcSetup(ledChannel_1, freq, resolution);
   ledcSetup(ledChannel_2, freq, resolution);
   ledcAttachPin(RPWM_Out, ledChannel_1);
   ledcAttachPin(LPWM_Out, ledChannel_2);
   Serial.begin(9600);
}
 
void loop()
{
  for (int i=0;i<240;i++){
    if (datos_vel[i]>=0){
      ledcWrite(ledChannel_1, datos_vel[i]);
      delay(50);//retardo de 50 ms.
      Serial.println(datos_vel[i]);
    }else{
      ledcWrite(ledChannel_2, datos_vel[i]*(-1));
      delay(50);
      Serial.println(datos_vel[i]);
    }
  }
  
  
  //marchaAdelante();
  //delay(1000);
  //marchaAtras();
  //delay(1000);
  //detenerse();
  //delay(1000);
  
}
