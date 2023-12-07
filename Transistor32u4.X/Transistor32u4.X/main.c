/*
 * File:   main.c (PERSONALIZACIÓN CARACTER)
 * 
 * Autores: Oscar David Poblador Parra      20211005116
 *          Juan David Bello Rodriguez      20211005028 
 *          Manuel Alejandro Guio Cardona   20211005061
 * Institución:: Universidad Distrital Francisco José de Caldas
 */


//SE MANEJA TP1 y TP3 para resistencia, zenner y diodos

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "pinManager.h"
#include "ADC.h"
#include "BJT.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "NOKIA.h"
#include "DIODO.h"
#include "Condensador.h"
#include "MOSFET.h"
#include "res.h"

#define F_CPU 8000000
int contador=0;

int MEDIDA1=0;
int MEDIDA2=0;
int MEDIDA3=0;

int E=0;

int start = 0;
int test;
int beta;
char buffer[10];
int i=0;


int main(void) {
    
    //Inicializacion
    
    ADC_init();
    nokia_lcd_init();
    nokia_lcd_clear();
	DDRC |= (1 << DDC6);
	cli();
	EICRB = (0 << ISC61)|(0 << ISC60);
	EIMSK = (1 << INT6);
	sei();
   
    while (1) {
        
        if(start == 1){
            nokia_lcd_clear();
            nokia_lcd_render();
            PRUEBAS();
            
            start = 0;
        }
        else{
           _delay_ms(1); 
        }
    }
}


ISR(INT6_vect){
	_delay_ms(200);
    E=0;
	start = 1;
}

void PRUEBAS(){
    if(E==0){
        PRUEBA_ZENNER();
        if(E==0){
            PRUEBA_BJT();
            if(E==0){
                PRUEBA_DIODOS();
                if(E==0){
                    PRUEBA_MOSFET();
                    if(E==0){
                        E=1;
                        resistencia();
                    }
                }
            }
        }
    }
    
    
}

void PRUEBA_MOSFET(){
    Polaridad1();
    MEDIDA2=ADC_leer(6);
    if(MEDIDA2>=410 && MEDIDA2<1010){
        MEDIDA3=ADC_leer(5);
        if(MEDIDA3>=410){
            E=1;
            canal_pines();
        }
        else{
            Polaridad2();
        }
    }
    else{
        Polaridad2();
    }
}

void Polaridad1(){
    PORTD |= (1<<TP1_1);
    PORTD |= (1<<TP2_1);
    PORTD &= ~(1<<TP3_1);
}

void Polaridad2(){
    PORTD &= ~(1<<TP1_1);
    PORTD |= (1<<TP2_1);
    PORTD |= (1<<TP3_1);
    
    MEDIDA2=ADC_leer(6);
    if(MEDIDA2>=410){
        MEDIDA1=ADC_leer(7);
        if(MEDIDA1>=410){
            E=1;
            canal_pines();
            
        }
        else{
            Polaridad3();
        }
    }
    else{
        Polaridad3();
    }
    
}

void Polaridad3(){
    PORTD &= ~(1<<TP1_1);
    PORTD &= ~(1<<TP2_1);
    PORTD |= (1<<TP3_1);
    
    MEDIDA2=ADC_leer(6);
    if(MEDIDA2>=410){
        MEDIDA3=ADC_leer(5);
        if(MEDIDA3>410){
            canal_pines();
            E=1;
        }
        else{
            Polaridad4();
        }
    }
    else{
        Polaridad4();
    }
}

void Polaridad4(){
    PORTD |= (1<<TP1_1);
    PORTD &= ~(1<<TP2_1);
    PORTD &= ~(1<<TP3_1);
    
    MEDIDA2=ADC_leer(6);
    if(MEDIDA2>=410){
        MEDIDA1=ADC_leer(7);
        if(MEDIDA1>410){
            E=1;
            canal_pines();
        }
    }
}

void MOSFET(){
    nokia_lcd_set_cursor(30, 24);
    nokia_lcd_write_string("MOSFET", 1);
    nokia_lcd_render();
}

void BJT(){
    nokia_lcd_set_cursor(30, 24);
    nokia_lcd_write_string("BJT", 1);
    nokia_lcd_render();
}

void NOES(){
    nokia_lcd_set_cursor(30, 24);
    nokia_lcd_write_string("NO ES", 1);
    nokia_lcd_render();
}

void RESISTENCIA(){
    nokia_lcd_set_cursor(30, 24);
    nokia_lcd_write_string("RESISTENCIA", 1);
    nokia_lcd_render();
}

void ESDIODO(){
    nokia_lcd_set_cursor(30, 24);
    nokia_lcd_write_string("DIODO", 1);
    nokia_lcd_render();
}


void PRUEBA_BJT(){
    PORTD = 0;
    DDRD = 0;
    _delay_ms(5);
    
    DDRD |=(1<<TP1_1IO);
    DDRD |=(1<<TP2_1IO);
    DDRD |=(1<<TP3_1IO);
    
    PORTD |= (1<<TP1_1);
    PORTD |= (1<<TP3_1);
    PORTD &= ~(1<<TP2_1);
    _delay_ms(5);
    MEDIDA1=ADC_leer(7);
    MEDIDA2=ADC_leer(6);
    MEDIDA3=ADC_leer(5);    
    
    if((fabs(MEDIDA2-MEDIDA1)>128) & (fabs(MEDIDA2-MEDIDA3)>128) & (fabs(MEDIDA2-MEDIDA1)<230) & (fabs(MEDIDA2-MEDIDA3)<230)){
        test = NPN_PNP();
        beta = pines(test);
        Beta(beta);
        E=1;
    }
    else{
        PORTD &= ~(1<<TP1_1);
        PORTD &= ~(1<<TP3_1);
        PORTD |= (1<<TP2_1);
        _delay_ms(5);
        MEDIDA1=ADC_leer(7);
        MEDIDA2=ADC_leer(6);
        MEDIDA3=ADC_leer(5);  
        if((fabs(MEDIDA2-MEDIDA1)>128) & (fabs(MEDIDA2-MEDIDA3)>128) & (fabs(MEDIDA2-MEDIDA1)<230) & (fabs(MEDIDA2-MEDIDA3)<230)){
            test = NPN_PNP();
            beta = pines(test);
            Beta(beta);
            E=1;
        }
    }
}


void PRUEBA_DIODOS(){
    
    DDRD |=(1<<TP2_1IO);
    DDRD |=(1<<TP3_1IO);
    DDRD |=(1<<TP1_1IO);
    
    PORTD &= ~(1<<TP3_1);
    PORTD |= (1<<TP2_1);
    PORTD |= (1<<TP1_1);
    
    MEDIDA3=ADC_leer(5);
    
    PORTD |= (1<<TP3_1);
    PORTD &= ~(1<<TP2_1);
    PORTD &= ~(1<<TP1_1);
    
    
    
    MEDIDA2=ADC_leer(5);
    
    if( (MEDIDA2>20) & (MEDIDA2<964) & ( (MEDIDA3<20) || (MEDIDA3>964) ) ){
        E=1;
        DIODO(3);
    }
    else{
        if( (MEDIDA3>20) & (MEDIDA3<964) & ( (MEDIDA2<20) || (MEDIDA2>964) ) ){
            E=1;
            DIODO(1);
        }
    }
}


void PRUEBA_ZENNER(){
    
    int V_diferencial1=0, V_diferencial2=0;
    
    DDRD |=(1<<TP2_1IO);
    DDRD |=(1<<TP3_1IO);
    DDRD |=(1<<TP1_1IO);
    
    PORTD &= ~(1<<TP1_1);
    PORTD |= (1<<TP3_1);
    _delay_ms(50);
    MEDIDA1=ADC_leer(7);
    MEDIDA2=ADC_leer(5);
    
    V_diferencial1=abs(MEDIDA1-MEDIDA2);
    
    PORTD &= ~(1<<TP3_1);
    PORTD |= (1<<TP1_1);
    _delay_ms(50);
    MEDIDA1=ADC_leer(7);
    MEDIDA2=ADC_leer(5);
    
    V_diferencial2=abs(MEDIDA1-MEDIDA2);
    
    if( (V_diferencial1>30) & (V_diferencial1<964) & (V_diferencial2>30) & (V_diferencial2<964) ){
        if( ( ( abs(V_diferencial1-V_diferencial2) )> 100 ) ){
            E=1;
            Zenner();
        }
    }
}

