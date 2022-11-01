
#define		TIMER1_ADDR					0x80	
#define		MODE_NORMAL			0x0000
#define		MODE_PWM_PC_8BITS	0x0001
#define		MODE_PWM_PC_9BITS	0x0010	
#define		MODE_PWM_PC_10BITS	0x0011	
#define		MODE_PWM_PFC		0x1000
#define		PRS_1				0x100
#define		PRS_8				0x200
#define		PRS_64				0x300
#define		PRS_256				0x400
#define		PRS_1024			0x500




struct timer16{
	
	uint16_t TCCRn;
    //uint8_t TCCRnB;
	uint8_t TCCRnC;
	uint8_t res;
	uint16_t TCNTn;
	uint16_t ICRn;
	uint16_t OCRnA;
	uint16_t OCRnB;
	uint16_t OCRnC;

};






