/*
 * init.h
 *
 * Created: 23.11.2022. 23:29:54
 *  Author: user
 */ 

// Inicijalizacija

#pragma once 
void init() {
	DDRB = (1 << PORTB0);
	PORTB = (1 << PORTB0);
	DDRD &= ~(1 << PORTD3);		// Enabling the Pull Up Resistor
	EIMSK = (1 << INT1);
}