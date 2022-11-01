#include "MotorDC.h"

void MotorDC::configTimer(uint8_t pin_pwm){
		
	
	switch(pin_pwm){
		case 9:
			addr_timer = TIMER1_ADDR;
			mode_pin_pwm = CONNECT_OCnA;
			break;
		
		case 10:
			addr_timer = TIMER1_ADDR;
			mode_pin_pwm = CONNECT_OCnB;
			break;
				
	}
	
	_tmr = ( volatile timer16 *)(addr_timer);
	
	if((_tmr->TCCRn & MASK_MODE_TIMER)== MODE_PWM_PFC){
		_tmr->TCCRn |= mode_pin_pwm ;
	
	}else{
		_tmr->TCCRn = MODE_PWM_PFC | PRS_1 | mode_pin_pwm ;	
		_tmr->ICRn = PERIOD;
	}

}

void MotorDC::connectMotor(uint8_t pin_pwm,uint8_t pin_dir0, uint8_t pin_dir1){

	MotorDC::configTimer(pin_pwm);
	
	switch (mode_pin_pwm){
		
		case CONNECT_OCnA:
			_speed = &(_tmr->OCRnA);
			break;	
		
		case CONNECT_OCnB:
			_speed = &(_tmr->OCRnB);
			break;
		
		case CONNECT_OCnC:
			_speed = &(_tmr->OCRnC);
			break;	
	}
	
	_port_pin_dir0 = portOutputRegister(digitalPinToPort(pin_dir0));
	_port_pin_dir1 = portOutputRegister(digitalPinToPort(pin_dir1));
	
	bit_dir0 = digitalPinToBitMask(pin_dir0);
	bit_dir1 = digitalPinToBitMask(pin_dir1);
	
	pinMode(pin_pwm, OUTPUT);
	pinMode(pin_dir0, OUTPUT);
	pinMode(pin_dir1, OUTPUT);
	
	dir = DIRECT;
	
}

void MotorDC::setSpeed(int16_t speed){
	
	*_speed = abs(speed);	

	if(( speed & MASK_SIGN ) == dir ){
		*_port_pin_dir0 |= bit_dir0;
		*_port_pin_dir1 &= ~bit_dir1;	
	}
	else{
		*_port_pin_dir0 &= ~bit_dir0;
		*_port_pin_dir1 |= bit_dir1;
	}
	
}

void MotorDC::invDirection(){
	
	dir = INVERT;
	
}
