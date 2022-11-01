#include "MotorDC.h"

/* -----------------!!!Importan!!!!------------------
  
  Use only the pins 9 and 10 for PWM

*/

MotorDC m1;
MotorDC m2;

void setup() {  

  // PWM, D0, D1

  m1.connectMotor(9,7,6);
  m2.connectMotor(10,11,8); 
  
  // Values from -400 to 400
  m1.setSpeed(400);  
  m2.setSpeed(400); 

}

void loop() {


}
