/*
 * File:   main.c (PERSONALIZACIÓN CARACTER)
 * 
 * Autores: Oscar David Poblador Parra      20211005116
 *          Juan David Bello Rodriguez      20211005028 
 *          Manuel Alejandro Guio Cardona   20211005061
 * Institución:: Universidad Distrital Francisco José de Caldas
 */

//#define F_CPU 16000000UL
#include <avr/io.h>
#include "ADC.h"
//#include <util/delay.h>

void ADC_init(void) {
	// Configurar la referencia de voltaje (AVCC con referencia a GND)
    //SMCR = (1<<SM0)|(1<<SE);
	ADMUX = (1 << REFS0);
	
	//ADMUX |= (1<<ADLAR);

	// Habilitar el ADC y configurar el prescalador (64 para F_CPU de 8MHz)
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1)|(1<<ADPS0);
    DIDR0 = 1;
	// Configurar el pin como entrada (ADC7 en este caso)
	//DDRC &= ~(1 << PC7);
}

void ADC_read(uint8_t channel) {
	// Seleccionar el canal de ADC (limitar a 4 bits)
 // Seleccionar el canal de ADC (limitar a 4 bits)
	PORTF = 0;
	DDRF = 0;
	channel &= 0x0F;
	ADMUX = (ADMUX & 0xF0) | channel;

	// Iniciar la conversión
   
	ADCSRA |= (1 << ADSC);

	// Esperar a que la conversión termine
	while (ADCSRA & (1 << ADSC));
	//_delay_us(100);
	// Combinar ADCL y ADCH para obtener el resultado completo
    int adc_result;
	adc_result = ADCH;
    
}

