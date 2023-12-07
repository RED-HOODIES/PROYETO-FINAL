/*
 * File:   main.c (PERSONALIZACIÓN CARACTER)
 * 
 * Autores: Oscar David Poblador Parra      20211005116
 *          Juan David Bello Rodriguez      20211005028 
 *          Manuel Alejandro Guio Cardona   20211005061
 * Institución:: Universidad Distrital Francisco José de Caldas
 */


#include <xc.h>
#include <avr/io.h>
#include "pinManager.h"
#include "ADC.h"
#include <math.h>
#include <stdio.h>
#include <util/delay.h>
#include "NOKIA.h"

void canal_pines(void) {
    int adc_result;
    float conversion ;//guardar conversiones
    float conversion1;
    float med;
    PORTD = 0;
    DDRD = 0;
    DDRD |=(1<<TP1_1IO)|(1<<TP3_1IO)|(1<<TP2_1IO);//TP2 680 OUT, TP3 680 OUT
    PORTD |= (1<<TP1_1)|(1<<TP2_1);//TP1 5V
    adc_result = ADC_read(7);
    conversion=adc_result*5.0/1023.0;
    adc_result=ADC_read(5);
    conversion1=adc_result*5.0/1023.0;
    if((conversion > 1) && (conversion1 > 1)){
        //canal n y entrada tp1 gate
        adc_result = ADC_read(6);//Voltaje en drain
        conversion = (adc_result*5.0)/1023.0;
        med = conversion - conversion1;
        if (med > 0.5){
            PORTD &= ~((1<<TP1_1)|(1<<TP2_1));//TP1 GROUND
            PORTD |= (1<<TP3_1);//TP3 5V
            adc_result = ADC_read(6);
            conversion=adc_result*5.0/1023.0;
            adc_result=ADC_read(5);
            conversion1=adc_result*5.0/1023.0;
            med = conversion - conversion1;
            if (med < 0.2){
                 nokia_lcd_clear();
                 draw_p();
                 nokia_lcd_set_cursor(40,5);
                 nokia_lcd_write_string("CANAL P",1);
                 nokia_lcd_set_cursor(5,40);
                 nokia_lcd_write_string("G:1",1);
                 nokia_lcd_set_cursor(33,40);
                 nokia_lcd_write_string("D:2",1);
                 nokia_lcd_set_cursor(65,40);
                 nokia_lcd_write_string("S:3",1);
                 nokia_lcd_render();
                 
            }
            else{
                 nokia_lcd_clear();
                 nokia_lcd_set_cursor(20,40);
                 nokia_lcd_write_string("Esta Dañado",1);
                 nokia_lcd_render();
                
            }
            
            
        }
        else{
            adc_result = ADC_read(6);
            conversion=adc_result*5.0/1023.0;
            adc_result=ADC_read(5);
            conversion1=adc_result*5.0/1023.0;
            med = conversion -conversion1;
            if(med < 0.2){
                nokia_lcd_clear();
                draw_n();
                nokia_lcd_set_cursor(40,5);
                nokia_lcd_write_string("CANAL N",1);
                nokia_lcd_set_cursor(5,40);
                nokia_lcd_write_string("G:1",1);
                nokia_lcd_set_cursor(33,40);
                nokia_lcd_write_string("D:2",1);
                nokia_lcd_set_cursor(65,40);
                nokia_lcd_write_string("S:3",1);
                nokia_lcd_render();
                
            }
                
            else{
                nokia_lcd_clear();
                nokia_lcd_set_cursor(20,40);
                nokia_lcd_write_string("Esta Dañado",1);
                nokia_lcd_render();
            }
        }
       
    }
    else{
        PORTD &= ~(1<<TP1_1);//TP1 GROUND
        PORTD = 0;
        PORTD |= (1<<TP3_1)|(1<<TP2_1);
        adc_result = ADC_read(7);
        conversion = (adc_result*5.0)/1023.0;
        adc_result = ADC_read(5);
        conversion1 = (adc_result*5.0)/1023.0;
        if((conversion > 1) && (conversion1 > 1)){
            adc_result = ADC_read(6);//voltaje drain
            conversion1 = adc_result*5.0/1023.0;
            med = conversion1 - conversion;
            
            if(med > 0.5){
                PORTD &= ~((1<<TP3_1)|(1<<TP2_1));//TP3 GROUND_TP2 GROUND
                PORTD |= (1<<TP1_1);//TP1 5V
                adc_result = ADC_read(6);
                conversion=adc_result*5.0/1023.0;
                adc_result=ADC_read(7);
                conversion1=adc_result*5.0/1023.0;
                med = conversion - conversion1;
                if (med < 0.2){
                    nokia_lcd_clear();
                    draw_p();
                    nokia_lcd_set_cursor(40,5);
                    nokia_lcd_write_string("CANAL P",1);
                    nokia_lcd_set_cursor(5,40);
                    nokia_lcd_write_string("G:3",1);
                    nokia_lcd_set_cursor(33,40);
                    nokia_lcd_write_string("D:2",1);
                    nokia_lcd_set_cursor(65,40);
                    nokia_lcd_write_string("S:1",1);
                    nokia_lcd_render();
                }
                else{
                    
                    nokia_lcd_clear();
                    nokia_lcd_set_cursor(20,40);
                    nokia_lcd_write_string("Esta Dañado",1);
                    nokia_lcd_render();
                
                }
                
            }
            else{
                adc_result = ADC_read(6);
                conversion=adc_result*5.0/1023.0;
                adc_result=ADC_read(5);
                conversion1=adc_result*5.0/1023.0;
                med = conversion -conversion1;
                if(med < 0.2){
                    nokia_lcd_clear();
                    draw_n();
                    nokia_lcd_set_cursor(40,5);
                    nokia_lcd_write_string("CANAL N",1);
                    nokia_lcd_set_cursor(5,40);
                    nokia_lcd_write_string("G:3",1);
                    nokia_lcd_set_cursor(33,40);
                    nokia_lcd_write_string("D:2",1);
                    nokia_lcd_set_cursor(65,40);
                    nokia_lcd_write_string("S:1",1);
                    nokia_lcd_render();
                }
                else{
                    nokia_lcd_clear();
                    nokia_lcd_set_cursor(20,40);
                    nokia_lcd_write_string("Esta Dañado",1);
                    nokia_lcd_render();
                }
            }
        }
        else{
            nokia_lcd_clear();
            nokia_lcd_set_cursor(20,40);
            nokia_lcd_write_string("Esta Dañado",1);
            nokia_lcd_render();
        }
    }  
}
void draw_n(void){
            nokia_lcd_clear();
            nokia_lcd_set_cursor(0, 22);
            nokia_lcd_write_string("G", 1);

            nokia_lcd_set_pixel(7, 29, 1);
            nokia_lcd_set_pixel(8, 29, 1);
            nokia_lcd_set_pixel(9, 29, 1);
            nokia_lcd_set_pixel(10, 29, 1);
            nokia_lcd_set_pixel(11, 29, 1);
            nokia_lcd_set_pixel(12, 29, 1);
            nokia_lcd_set_pixel(13, 29, 1);
            nokia_lcd_set_pixel(14, 29, 1);

            //LINEA VERTICAL
            nokia_lcd_set_pixel(14, 11, 1);            
            nokia_lcd_set_pixel(14, 12, 1);
            nokia_lcd_set_pixel(14, 13, 1);
            nokia_lcd_set_pixel(14, 14, 1);
            nokia_lcd_set_pixel(14, 15, 1);
            
            nokia_lcd_set_pixel(14, 16, 1);           
            nokia_lcd_set_pixel(14, 17, 1);

            nokia_lcd_set_pixel(14, 18, 1);
            nokia_lcd_set_pixel(14, 19, 1);
            nokia_lcd_set_pixel(14, 20, 1);
            nokia_lcd_set_pixel(14, 21, 1);
            nokia_lcd_set_pixel(14, 22, 1);
            
            nokia_lcd_set_pixel(14, 23, 1);
            nokia_lcd_set_pixel(14, 24, 1);
            
            nokia_lcd_set_pixel(14, 25, 1);
            nokia_lcd_set_pixel(14, 26, 1);
            nokia_lcd_set_pixel(14, 27, 1);
            nokia_lcd_set_pixel(14, 28, 1);
            nokia_lcd_set_pixel(14, 29, 1);


            //DRAIN SOURCE
            nokia_lcd_set_pixel(16, 11, 1);
            nokia_lcd_set_pixel(16, 12, 1);
            nokia_lcd_set_pixel(16, 13, 1);
            nokia_lcd_set_pixel(16, 14, 1);
            nokia_lcd_set_pixel(16, 15, 1);
            
            
            nokia_lcd_set_pixel(16, 18, 1);
            nokia_lcd_set_pixel(16, 19, 1);
            nokia_lcd_set_pixel(16, 20, 1);
            nokia_lcd_set_pixel(16, 21, 1);
            nokia_lcd_set_pixel(16, 22, 1);
            
            nokia_lcd_set_pixel(16, 25, 1);
            nokia_lcd_set_pixel(16, 26, 1);
            nokia_lcd_set_pixel(16, 27, 1);
            nokia_lcd_set_pixel(16, 28, 1);
            nokia_lcd_set_pixel(16, 29, 1);

            //Lineas
            
            nokia_lcd_set_pixel(17, 13, 1);
            nokia_lcd_set_pixel(18, 13, 1);
            nokia_lcd_set_pixel(19, 13, 1);
            nokia_lcd_set_pixel(20, 13, 1);
            nokia_lcd_set_pixel(21, 13, 1);
            
                      //Flecha
            nokia_lcd_set_pixel(17, 20, 1);
            nokia_lcd_set_pixel(18, 19, 1);
            nokia_lcd_set_pixel(18, 20, 1);
            nokia_lcd_set_pixel(18, 21, 1);
            nokia_lcd_set_pixel(19, 18, 1);
            nokia_lcd_set_pixel(19, 22, 1);
            nokia_lcd_set_pixel(19, 19, 1);
            nokia_lcd_set_pixel(19, 20, 1);
            nokia_lcd_set_pixel(19, 21, 1);
            nokia_lcd_set_pixel(20, 20, 1);
            nokia_lcd_set_pixel(21, 20, 1);
            
            nokia_lcd_set_pixel(17, 27, 1);
            nokia_lcd_set_pixel(18, 27, 1);
            nokia_lcd_set_pixel(19, 27, 1);
            nokia_lcd_set_pixel(20, 27, 1);
            nokia_lcd_set_pixel(21, 27, 1);
            
            //Drain

            nokia_lcd_set_pixel(22, 6, 1);
            nokia_lcd_set_pixel(22, 7, 1);
            nokia_lcd_set_pixel(22, 8, 1);
            nokia_lcd_set_pixel(22, 9, 1);
            nokia_lcd_set_pixel(22, 10, 1);
            nokia_lcd_set_pixel(22, 11, 1);
            nokia_lcd_set_pixel(22, 12, 1);
            nokia_lcd_set_pixel(22, 13, 1); 
            nokia_lcd_set_cursor(25, 5);
            nokia_lcd_write_string("D", 1);
            
            //source
            
            nokia_lcd_set_pixel(22, 20, 1);
            nokia_lcd_set_pixel(22, 21, 1);
            nokia_lcd_set_pixel(22, 22, 1);
            nokia_lcd_set_pixel(22, 23, 1);
            nokia_lcd_set_pixel(22, 24, 1);
            nokia_lcd_set_pixel(22, 25, 1);
            nokia_lcd_set_pixel(22, 26, 1);
            nokia_lcd_set_pixel(22, 27, 1);
            nokia_lcd_set_pixel(22, 28, 1);
            nokia_lcd_set_pixel(22, 29, 1);
            nokia_lcd_set_pixel(22, 30, 1);
            nokia_lcd_set_pixel(22, 31, 1);
            nokia_lcd_set_pixel(22, 32, 1);
            nokia_lcd_set_pixel(22, 33, 1);
            
            nokia_lcd_set_cursor(25, 28);
            nokia_lcd_write_string("S", 1);
            nokia_lcd_render();
}
void draw_p(void){
            nokia_lcd_clear();
            nokia_lcd_set_cursor(0, 22);
            nokia_lcd_write_string("G", 1);

            nokia_lcd_set_pixel(7, 29, 1);
            nokia_lcd_set_pixel(8, 29, 1);
            nokia_lcd_set_pixel(9, 29, 1);
            nokia_lcd_set_pixel(10, 29, 1);
            nokia_lcd_set_pixel(11, 29, 1);
            nokia_lcd_set_pixel(12, 29, 1);
            nokia_lcd_set_pixel(13, 29, 1);
            nokia_lcd_set_pixel(14, 29, 1);

            //LINEA VERTICAL
            nokia_lcd_set_pixel(14, 11, 1);            
            nokia_lcd_set_pixel(14, 12, 1);
            nokia_lcd_set_pixel(14, 13, 1);
            nokia_lcd_set_pixel(14, 14, 1);
            nokia_lcd_set_pixel(14, 15, 1);
            
            nokia_lcd_set_pixel(14, 16, 1);           
            nokia_lcd_set_pixel(14, 17, 1);

            nokia_lcd_set_pixel(14, 18, 1);
            nokia_lcd_set_pixel(14, 19, 1);
            nokia_lcd_set_pixel(14, 20, 1);
            nokia_lcd_set_pixel(14, 21, 1);
            nokia_lcd_set_pixel(14, 22, 1);
            
            nokia_lcd_set_pixel(14, 23, 1);
            nokia_lcd_set_pixel(14, 24, 1);
            
            nokia_lcd_set_pixel(14, 25, 1);
            nokia_lcd_set_pixel(14, 26, 1);
            nokia_lcd_set_pixel(14, 27, 1);
            nokia_lcd_set_pixel(14, 28, 1);
            nokia_lcd_set_pixel(14, 29, 1);


            //DRAIN SOURCE
            nokia_lcd_set_pixel(16, 11, 1);
            nokia_lcd_set_pixel(16, 12, 1);
            nokia_lcd_set_pixel(16, 13, 1);
            nokia_lcd_set_pixel(16, 14, 1);
            nokia_lcd_set_pixel(16, 15, 1);
            
            
            nokia_lcd_set_pixel(16, 18, 1);
            nokia_lcd_set_pixel(16, 19, 1);
            nokia_lcd_set_pixel(16, 20, 1);
            nokia_lcd_set_pixel(16, 21, 1);
            nokia_lcd_set_pixel(16, 22, 1);
            
            nokia_lcd_set_pixel(16, 25, 1);
            nokia_lcd_set_pixel(16, 26, 1);
            nokia_lcd_set_pixel(16, 27, 1);
            nokia_lcd_set_pixel(16, 28, 1);
            nokia_lcd_set_pixel(16, 29, 1);

            //Lineas
            
            nokia_lcd_set_pixel(17, 13, 1);
            nokia_lcd_set_pixel(18, 13, 1);
            nokia_lcd_set_pixel(19, 13, 1);
            nokia_lcd_set_pixel(20, 13, 1);
            nokia_lcd_set_pixel(21, 13, 1);
            
                      //Flecha
            nokia_lcd_set_pixel(17, 20, 1);
            nokia_lcd_set_pixel(18, 19, 1);
            nokia_lcd_set_pixel(18, 20, 1);
            nokia_lcd_set_pixel(18, 21, 1);
            nokia_lcd_set_pixel(18, 18, 1);
            nokia_lcd_set_pixel(18, 22, 1);
            nokia_lcd_set_pixel(19, 19, 1);
            nokia_lcd_set_pixel(19, 20, 1);
            nokia_lcd_set_pixel(19, 21, 1);
            nokia_lcd_set_pixel(20, 20, 1);
            nokia_lcd_set_pixel(21, 20, 1);
            
            nokia_lcd_set_pixel(17, 27, 1);
            nokia_lcd_set_pixel(18, 27, 1);
            nokia_lcd_set_pixel(19, 27, 1);
            nokia_lcd_set_pixel(20, 27, 1);
            nokia_lcd_set_pixel(21, 27, 1);
            
            //Drain

            nokia_lcd_set_pixel(22, 6, 1);
            nokia_lcd_set_pixel(22, 7, 1);
            nokia_lcd_set_pixel(22, 8, 1);
            nokia_lcd_set_pixel(22, 9, 1);
            nokia_lcd_set_pixel(22, 10, 1);
            nokia_lcd_set_pixel(22, 11, 1);
            nokia_lcd_set_pixel(22, 12, 1);
            nokia_lcd_set_pixel(22, 13, 1); 
            nokia_lcd_set_cursor(25, 5);
            nokia_lcd_write_string("D", 1);
            
            //source
            
            nokia_lcd_set_pixel(22, 20, 1);
            nokia_lcd_set_pixel(22, 21, 1);
            nokia_lcd_set_pixel(22, 22, 1);
            nokia_lcd_set_pixel(22, 23, 1);
            nokia_lcd_set_pixel(22, 24, 1);
            nokia_lcd_set_pixel(22, 25, 1);
            nokia_lcd_set_pixel(22, 26, 1);
            nokia_lcd_set_pixel(22, 27, 1);
            nokia_lcd_set_pixel(22, 28, 1);
            nokia_lcd_set_pixel(22, 29, 1);
            nokia_lcd_set_pixel(22, 30, 1);
            nokia_lcd_set_pixel(22, 31, 1);
            nokia_lcd_set_pixel(22, 32, 1);
            nokia_lcd_set_pixel(22, 33, 1);
            
            nokia_lcd_set_cursor(25, 28);
            nokia_lcd_write_string("S", 1);
            nokia_lcd_render();
}