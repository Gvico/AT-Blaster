#ifndef DEFINES_H_
#define DEFINES_H_
/*
#ifndef DEBUG_FVG
#define DEBUG_FVG
#endif
*/
#ifndef F_CPU
#define F_CPU 16000000UL  // 16 MHz
#endif

#ifndef true
#define true	0xff
#endif

#ifndef false
#define false	0x00
#endif

#ifndef byte
#define byte	unsigned char
#endif

#ifndef uint
#define uint	unsigned int
#endif

#ifndef ulong
#define ulong	unsigned long
#endif

#ifndef TIMER1_PRESCALE_1
#define TIMER1_PRESCALE_1 1
#endif

#ifndef TIMER1_PRESCALE_8
#define TIMER1_PRESCALE_8 2
#endif

#ifndef TIMER1_PRESCALE_64
#define TIMER1_PRESCALE_64 3
#endif

#ifndef TIMER1_PRESCALE_256
#define TIMER1_PRESCALE_256 4
#endif

#ifndef TIMER1_PRESCALE_1024
#define TIMER1_PRESCALE_1024 5
#endif


#ifndef UNIT_ID
#define UNIT_ID 0x02	// Unique ID to identify each pistol
#endif

#ifndef IR_ON
#define IR_ON PORTD |= 0b01000000
#endif

#ifndef IR_OFF
#define IR_OFF PORTD &= 0b10111111
#endif

#ifndef INCOMING_IR
#define INCOMING_IR (PINB & (1 << PINB2)) != (1 << PINB2)	// PINB2 low when IR input
#endif

#ifndef TRIGGER_PULLED
#define TRIGGER_PULLED (PIND & (1 << PIND7)) == (1 << PIND7)	// PIND7 high when trigger pulled
#endif

#endif /* DEFINES_H_ */