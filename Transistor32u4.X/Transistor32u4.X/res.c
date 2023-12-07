/*
 * File:   main.c (PERSONALIZACIÓN CARACTER)
 * 
 * Autores: Oscar David Poblador Parra      20211005116
 *          Juan David Bello Rodriguez      20211005028 
 *          Manuel Alejandro Guio Cardona   20211005061
 * Institución:: Universidad Distrital Francisco José de Caldas
 */


#include <avr/io.h>
#include <xc.h>
#include <avr/io.h>
#include "pinManager.h"
#include "ADC.h"
#include <math.h>
#include <stdio.h>
#include <util/delay.h>
#include "NOKIA.h"
#include "stdlib.h"

void resistencia(void) {
    
    int adc_result = 0;
    int adc_result1 = 0;
    float conversion;//guardar conversiones
    float conversion1;
    float prom;
    float prom1;
    float res = 0;
    float cor=0;
    float vol=0;
    int i;
    int j;
    char buffer[10];
    PORTD = 0;
    DDRD = 0;
    DDRD |=(1<<TP1_1IO)|(1<<TP3_1IO);//TP1 680 OUT, TP3 680 OUT
    PORTD |= (1<<TP1_1);//TP1 5V
    PORTD &= ~(1<<TP3_1);//TP1 5V
    _delay_ms(50);

    for (i = 0; i < 32;i++){
        adc_result = adc_result + ADC_read(7);
    }
    for (i = 0; i < 32;i++){
        adc_result1 = adc_result1 + ADC_read(5);
    }
        
    prom = (float)adc_result / 32;
    prom1 = (float)adc_result1 /32;
    conversion = (prom*5)/1023;
    conversion1 = (prom1*5)/1023;
    cor = (conversion1/680)*1000;
    vol = (conversion-conversion1);
    res = (1000*vol/cor);

    nokia_lcd_set_cursor(10,1);
    nokia_lcd_write_string("RESISTENCIA",1);
    
    res_draw();
    nokia_lcd_set_cursor(22,30);
    nokia_lcd_write_string("R:",1);
    imprimir_f(res,35,30,6);
   
    nokia_lcd_render();
}

void res_draw(void){
            nokia_lcd_set_cursor(0, 12);
            nokia_lcd_set_pixel(19, 15, 1);
            nokia_lcd_set_pixel(20, 15, 1);
            nokia_lcd_set_pixel(21, 15, 1);
            nokia_lcd_set_pixel(22, 15, 1);
            nokia_lcd_set_pixel(23, 15, 1);
            nokia_lcd_set_pixel(24, 15, 1);
            nokia_lcd_set_pixel(25, 15, 1);
            nokia_lcd_set_pixel(26, 15, 1);
            nokia_lcd_set_pixel(27, 14, 1);
            nokia_lcd_set_pixel(28, 12, 1);
            nokia_lcd_set_pixel(29, 10, 1);
            nokia_lcd_set_pixel(30, 12, 1);
            nokia_lcd_set_pixel(31, 14, 1);
            nokia_lcd_set_pixel(32, 16, 1);
            nokia_lcd_set_pixel(33, 18, 1);
            nokia_lcd_set_pixel(34, 20, 1);
            nokia_lcd_set_pixel(35, 18, 1);
            nokia_lcd_set_pixel(36, 16, 1);
            nokia_lcd_set_pixel(37, 14, 1);
            nokia_lcd_set_pixel(38, 12, 1);
            nokia_lcd_set_pixel(39, 10, 1);
            nokia_lcd_set_pixel(40, 12, 1);
            nokia_lcd_set_pixel(41, 14, 1);
            nokia_lcd_set_pixel(42, 16, 1);
            nokia_lcd_set_pixel(43, 18, 1);
            nokia_lcd_set_pixel(44, 20, 1);
            nokia_lcd_set_pixel(45, 18, 1);
            nokia_lcd_set_pixel(46, 16, 1);
            nokia_lcd_set_pixel(47, 14, 1);
            nokia_lcd_set_pixel(48, 12, 1);
            nokia_lcd_set_pixel(49, 10, 1);
            nokia_lcd_set_pixel(50, 12, 1);
            nokia_lcd_set_pixel(51, 14, 1);
            nokia_lcd_set_pixel(52, 15, 1);
            nokia_lcd_set_pixel(53, 15, 1);
            nokia_lcd_set_pixel(54, 15, 1);
            nokia_lcd_set_pixel(55, 15, 1);
            nokia_lcd_set_pixel(56, 15, 1);
            nokia_lcd_set_pixel(57, 15, 1);
            nokia_lcd_set_pixel(58, 15, 1);
            nokia_lcd_set_pixel(59, 15, 1);
            
            nokia_lcd_render(); 
}