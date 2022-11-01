#include "Arduino.h"
#include "Timers.h"

#define		MASK_MODE_TIMER		0x1803
#define		MASK_SIGN			0x8000
#define		CONNECT_OCnA		0x80
#define		CONNECT_OCnB		0x20
#define		CONNECT_OCnC		0x08
#define		DIRECT				0x0000
#define		INVERT				0x8000
#define		PERIOD				400


class MotorDC{
	
	volatile uint16_t *_speed;
	volatile timer16 *_tmr;
	volatile uint8_t *_port_pin_dir0;
	volatile uint8_t *_port_pin_dir1;
	uint16_t addr_timer;
	uint8_t	mode_pin_pwm;
	uint8_t	bit_dir0;
	uint8_t	bit_dir1;
	uint16_t dir;
	
	void configTimer(uint8_t pin_pwm);
	
	public:

	void connectMotor(uint8_t motor,uint8_t pin_dir0, uint8_t pin_dir1);
	void setSpeed(int16_t speed);
	void invDirection();
	
};







