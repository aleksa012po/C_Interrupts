/*
 * C_Arduino_Asembler_Interapti.c
 *
 * Created: 23.11.2022. 23:06:25
 * Author : Aleksandar Bogdanovic
 */ 

// AVR-C Interrupts
// External interrupt
// EICRA - External Interrupt Control Register A
// EIMSK - External Interrupt Mask Register
// ---------------------------------------------------------------
// 0 I 0 - The low level of INT1 generates an interrupt request
// 0 I 1 - Any logical change on INT1 generates an interrupt request
// 1 I 0 - The falling edge of INT1 generates an interrupt request
// 1 I 1 - The rising edge of INT1 generates an interrupt request
// ---------------------------------------------------------------

#define F_CPU 16000000		// 16 MHz

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "init.h"

int cliFlag = 0;

int main(void) {
	
		init();
	
	while(1) {
		if(cliFlag == 0) {
			sei();			// SEI – Set Global Interrupt Flag, Cycles 1 in asm
			} else {
			cli();			// CLI – Clear Global Interrupt Flag, Cycles 1 in asm
			_delay_ms(1000);
			cliFlag = 0;
		}
	}
}

ISR(INT1_vect) {

	PORTB ^= (1 << PORTB0);		// ^= - Bitwise XOR
	cliFlag = 1;
}
