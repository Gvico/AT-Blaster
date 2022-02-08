#include <avr/io.h>

void adc_config()
{
	ADMUX  = 0b10000001;
	ADCSRA = 0b10001111;
	ADCSRB = 0b00000000;
	DIDR0  = 0b00000011;
}

int adc_convert()
{
	unsigned int Converted_Value = 0;
	
	ADCSRA |= 0b01000000;
	while(!(ADCSRA & 0b00010000));
	ADCSRA |= 0b00010000;
	
	Converted_Value = ADC; 
	
	return Converted_Value;
}