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

int NPN_PNP() {
    uint16_t med;//para guardar mediciones
    float conversion ;//guardar conversiones
    int polarizacion;
    int adc_result;
    const char buffer[4];
    PORTD = 0;
    DDRD = 0;
    DDRD |=(1<<TP2_1IO)|(1<<TP3_1IO);//TP2 680 OUT, TP3 680 OUT
    PORTD |= (1<<TP2_1);//TP2 5V

    
    ADC_read(5);
    adc_result = (ADCH*256)+ADCL;
    conversion = (adc_result*5)/1023;
    med = ADCH;
    if(conversion < 0.5){
        PORTD |= (1<<TP3_1);//TP3 5V
        PORTD &=~(1<<TP2_1);//TP2 GND
        ADC_read(6);
        adc_result = (ADCH*256)+ADCL;
        med = ADCH;
        conversion = (adc_result*5)/1023;
        if(conversion < 0.5){
            nokia_lcd_set_cursor(0, 5);
            nokia_lcd_write_string("Elemento no", 1);
            nokia_lcd_set_cursor(0, 20);
            nokia_lcd_write_string("identificado", 1);
            nokia_lcd_render(); 
        }
        else{
            DDRD |=(1<<TP1_1IO);//TP1 680 OUT
            DDRD &=~(1<<TP3_1IO);//TP3 680 IN
            PORTD |=(1<<TP1_1);// TP1 5V
            ADC_read(6);
            adc_result = (ADCH*256)+ADCL;
            conversion = (adc_result*5.0)/1023.0;
            med = ADCH;
            if(conversion < 0.5){
                nokia_lcd_set_cursor(0, 5);
                nokia_lcd_write_string("Elemento no", 1);
                nokia_lcd_set_cursor(0, 20);
                nokia_lcd_write_string("identificado", 1);
                nokia_lcd_render(); 
            }
            else{
                draw_PNP();
                nokia_lcd_set_cursor(60, 5);
                nokia_lcd_write_string("PNP", 1);
                nokia_lcd_render(); 
                polarizacion = 0;
      
            }
        }
    }
    else{
        DDRD |=(1<<TP1_1IO);//TP1 680 OUT
        DDRD &=~(1<<TP3_1IO);//TP3 680 IN
        
        PORTD &=~(1<<TP1_1);//TP1 GND
        ADC_read(7);
        adc_result = (ADCH*256)+ADCL;
        conversion = (adc_result*5.0)/1023.0;
        med = ADCH;
        if(conversion < 0.5){
            nokia_lcd_set_cursor(0, 5);
            nokia_lcd_write_string("Elemento no", 1);
            nokia_lcd_set_cursor(0, 20);
            nokia_lcd_write_string("identificado", 1);
            nokia_lcd_render(); 
        }
        else{
            //es un transistor NPN
            draw_NPN();
            nokia_lcd_set_cursor(60, 5);
            nokia_lcd_write_string("NPN", 1);
            nokia_lcd_render(); 
            polarizacion = 1;
        }
    }
    
    
    return polarizacion;
}

int pines(int pol){
    uint16_t med;//para guardar mediciones
    int adc_result;
    int sel;
    float conversion1;
    float conversion;//guardar conversiones
    PORTD = 0;
    DDRD = 0;
    
    if(pol == 1){
        DDRD |=(1<<TP1_1IO)|(1<<TP2_2IO)|(1<<TP3_1IO);//TP1 680 OUT, TP2 470 OUT, TP3 680 OUT
       //Polarizacion para NPN
        PORTD |= (1<<TP2_2)|(1<<TP1_1);//TP2 5V,TP1 5V

        //PORTD &=~((1<<TP3_1)|(1<<TP1_2)|(1<<TP2_1)|(2<<TP3_2));//TP3 GND
        ADC_read(5);
        adc_result = (ADCH*256)+ADCL;
        conversion = (adc_result*5.0)/1023.0;
        med = ADCH;
        if(conversion < 0.2){
            
            PORTD |= (1<<TP2_2)|(1<<TP3_1);//TP2 5V,TP3 5V
            PORTD &= ~(1<<TP1_1);
            ADC_read(7);//Lectura en emisor
            adc_result = (ADCH*256)+ADCL;
            conversion = (adc_result*5.0)/1023.0;
            med = ADCH; 
            ADC_read(5);//Lecutra en colector
            adc_result = (ADCH*256)+ADCL;
            conversion1 = 4.9-((adc_result*5.0)/1023.0);
            med = ADCH;          
            if(conversion > conversion1){
                //el pin TP1 es el emisor y TP3 colector
                nokia_lcd_set_cursor(22,26);
                nokia_lcd_write_string("1", 1);
                nokia_lcd_set_cursor(22,1);
                nokia_lcd_write_string("3", 1);
                nokia_lcd_set_cursor(5,40);
                nokia_lcd_write_string("E:1", 1);
                nokia_lcd_set_cursor(30,40);
                nokia_lcd_write_string("B:2", 1);
                nokia_lcd_set_cursor(55,40);
                nokia_lcd_write_string("C:3", 1);
                sel = 0;
                nokia_lcd_render(); 
 
            }
            else{
                nokia_lcd_clear();
                nokia_lcd_set_cursor(2,2);
                nokia_lcd_write_string("Esta Dañado", 1);
                nokia_lcd_render();
                
            }
        }
        else{
            
           
            
            ADC_read(7);//Lecutra en colector
            adc_result = (ADCH*256)+ADCL;
            conversion1 =(4.9)-((adc_result*5.0)/1023.0);
            med = ADCH;
            if(conversion > conversion1){
                //el pin TP3 es el emisor y TP1 colector
                nokia_lcd_set_cursor(22,26);
                nokia_lcd_write_string("3", 1);
                nokia_lcd_set_cursor(22,1);
                nokia_lcd_write_string("1", 1);
                nokia_lcd_set_cursor(5,40);
                nokia_lcd_write_string("E:3", 1);
                nokia_lcd_set_cursor(30,40);
                nokia_lcd_write_string("B:2", 1);
                nokia_lcd_set_cursor(55,40);
                nokia_lcd_write_string("C:1", 1);
                sel = 1;
                nokia_lcd_render(); 
 
            }
            else{
                //nokia_lcd_clear();
                nokia_lcd_set_cursor(2,2);
                nokia_lcd_write_string("Esta Dañado1", 1);
                nokia_lcd_render();
                
            }
            
        }
    }
    else{
        //Polarizacion para PNP
         DDRD |=(1<<TP1_1IO)|(1<<TP2_2IO)|(1<<TP3_1IO);//TP1 680 OUT, TP2 470 OUT, TP3 680 OUT
         PORTD |=(1<<TP1_1);//TP1 5V
         //PORTD &=~((1<<TP3_1)|(1<<TP1_2)|(1<<TP2_1)|(2<<TP3_2));//TP3 GND
        ADC_read(5);
        adc_result = (ADCH*256)+ADCL;
        med = ADCH;
        conversion = (adc_result*5.0)/1023.0;
       
        if(conversion < 0.1){
            
            PORTD |= (1<<TP3_1);//TP2 5V,TP3 5V
            PORTD &= ~(1<<TP1_1);
            adc_result = 0;
            
            ADC_read(7);//Lectura en emisor
            adc_result = (ADCH*256)+ADCL;
            conversion = (adc_result*5.0)/1023.0;
            med = ADCH; 
            ADC_read(5);//Lecutra en colector
            adc_result = (ADCH*256)+ADCL;
            conversion1 = 4.8-((adc_result*5.0)/1023.0);
            med = ADCH;          
            if(conversion > conversion1){
                //el pin TP1 es el emisor y TP3 colector
                nokia_lcd_set_cursor(22,26);
                nokia_lcd_write_string("3", 1);
                nokia_lcd_set_cursor(22,1);
                nokia_lcd_write_string("1", 1);
                nokia_lcd_set_cursor(5,40);
                nokia_lcd_write_string("E:3", 1);
                nokia_lcd_set_cursor(30,40);
                nokia_lcd_write_string("B:2", 1);
                nokia_lcd_set_cursor(55,40);
                nokia_lcd_write_string("C:1", 1);
                sel = 2;
                nokia_lcd_render(); 
 
            }
            else{
                nokia_lcd_clear();
                nokia_lcd_set_cursor(2,2);
                nokia_lcd_write_string("Esta Dañado", 1);
                nokia_lcd_render();
                
            }
        }
        else{
            
            ADC_read(7);//Lecutra en colector
            adc_result = (ADCH*256)+ADCL;
            conversion1 =(4.8)-((adc_result*5.0)/1023.0);
            med = ADCH;
            if(conversion > conversion1){
                //el pin TP3 es el emisor y TP1 colector
                nokia_lcd_set_cursor(22,26);
                nokia_lcd_write_string("1", 1);
                nokia_lcd_set_cursor(22,1);
                nokia_lcd_write_string("3", 1);
                nokia_lcd_set_cursor(5,40);
                nokia_lcd_write_string("E:1", 1);
                nokia_lcd_set_cursor(30,40);
                nokia_lcd_write_string("B:2", 1);
                nokia_lcd_set_cursor(55,40);
                nokia_lcd_write_string("C:3", 1);
                sel = 3;
                nokia_lcd_render(); 
 
            }
            else{
                nokia_lcd_clear();
                nokia_lcd_set_cursor(2,2);
                nokia_lcd_write_string("Esta Dañado1", 1);
                nokia_lcd_render();
                
            }
            
        }
    }
    return sel;
}
void Beta(int sel){
    PORTD = 0;//Init puerto
    DDRD = 0;//Init entradas
    char buffer[10];
    uint16_t med;//para guardar mediciones
    int adc_result;
    float conversion_beta;
    float conversion1;
    float conversion;//guardar conversiones
    DDRD |=(1<<TP1_1IO)|(1<<TP2_2IO)|(1<<TP3_1IO);//TP1 680 OUT, TP2 470 OUT, TP3 680 OUT
    if (sel == 0){
       
       //Polarizacion para NPN con TP1 GND
        PORTD |= (1<<TP2_2)|(1<<TP3_1);//TP2 5V,TP3 5V
        PORTD &= ~(1<<TP1_1);//TP1 GROUND
        ADC_read(5); //Voltaje en Colector
        adc_result = (ADCH*256)+ADCL;
        conversion =(4.9)-((adc_result*5.0)/1023.0);
        med = ADCH;
        ADC_read(6);//Voltaje en BASE
        adc_result = (ADCH*256)+ADCL;
        conversion1 =(4.9)-(adc_result*5.0)/1023.0;
        med = ADCH;
        conversion = conversion / 680.0;//IC
        conversion1 = conversion1 / 470000.0;//IB
        conversion_beta = conversion / conversion1;
        sprintf(buffer,"%f",conversion_beta);
        nokia_lcd_set_cursor(40,20);
        nokia_lcd_write_string("B:",1);
        nokia_lcd_set_cursor(53,20);
        nokia_lcd_write_char(buffer[0], 1);
        nokia_lcd_write_char(buffer[1], 1);
        nokia_lcd_write_char(buffer[2], 1);
        nokia_lcd_write_char(buffer[3], 1);
        nokia_lcd_write_char(buffer[4], 1);
        nokia_lcd_render();
    }
    else if(sel == 1){
        //Polarizacion para NPN con TP3 GND
        PORTD |= (1<<TP2_2)|(1<<TP1_1);//TP2 5V,TP1 5V
        PORTD &= ~(1<<TP3_1);//TP3 GROUND
        ADC_read(7); //Voltaje en Colector
        adc_result = (ADCH*256)+ADCL;
        conversion =(4.8)-((adc_result*5.0)/1023.0);
        med = ADCH;
        ADC_read(6);//Voltaje en BASE
        adc_result = (ADCH*256)+ADCL;
        conversion1 =(4.9)-(adc_result*5.0)/1023.0;
        med = ADCH;
        conversion = conversion / 680.0;//IC
        conversion1 = conversion1 / 470000.0;//IB
        conversion_beta = conversion / conversion1;
        sprintf(buffer,"%f",conversion_beta);
        nokia_lcd_set_cursor(40,20);
        nokia_lcd_write_string("B:",1);
        nokia_lcd_set_cursor(53,20);
        nokia_lcd_write_char(buffer[0], 1);
        nokia_lcd_write_char(buffer[1], 1);
        nokia_lcd_write_char(buffer[2], 1);
        nokia_lcd_write_char(buffer[3], 1);
        nokia_lcd_write_char(buffer[4], 1);
        nokia_lcd_render();
        
    }
    else if (sel == 2){
        //Polarizacion para PNP con TP1 GND
        PORTD |= (1<<TP3_1);//TP3 5V
        PORTD &= ~((1<<TP1_1)|(1<<TP2_2));//TP1,TP2 GROUND
        ADC_read(5); //Voltaje en Colector
        adc_result = (ADCH*256)+ADCL;
        conversion =(4.9)-((adc_result*5.0)/1023.0);
        med = ADCH;
        ADC_read(6);//Voltaje en BASE
        adc_result = (ADCH*256)+ADCL;
        conversion1 = (adc_result*5.0)/1023.0;
        med = ADCH;
        conversion = conversion / 680.0;//IC
        conversion1 = conversion1 / 470000.0;//IB
        conversion_beta = conversion / conversion1;
        sprintf(buffer,"%f",conversion_beta);
        nokia_lcd_set_cursor(40,20);
        nokia_lcd_write_string("B:",1);
        nokia_lcd_set_cursor(53,20);
        nokia_lcd_write_char(buffer[0], 1);
        nokia_lcd_write_char(buffer[1], 1);
        nokia_lcd_write_char(buffer[2], 1);
        nokia_lcd_write_char(buffer[3], 1);
        nokia_lcd_write_char(buffer[4], 1);
        nokia_lcd_render();
        
    }
    else if (sel == 3){
        //Polarizacion para PNP con TP3 GND
        PORTD |= (1<<TP1_1);//TP1 5V
        PORTD &= ~((1<<TP3_1)|(1<<TP2_2));//TP3,TP2 GROUND
        ADC_read(7); //Voltaje en Colector
        adc_result = (ADCH*256)+ADCL;
        conversion =(4.9)-((adc_result*5.0)/1023.0);
        med = ADCH;
        ADC_read(6);//Voltaje en BASE
        adc_result = (ADCH*256)+ADCL;
        conversion1 = (adc_result*5.0)/1023.0;
        med = ADCH;
        conversion = conversion / 680.0;//IC
        conversion1 = conversion1 / 470000.0;//IB
        conversion_beta = conversion / conversion1;
        sprintf(buffer,"%f",conversion_beta);
        nokia_lcd_set_cursor(40,20);
        nokia_lcd_write_string("B:",1);
        nokia_lcd_set_cursor(53,20);
        nokia_lcd_write_char(buffer[0], 1);
        nokia_lcd_write_char(buffer[1], 1);
        nokia_lcd_write_char(buffer[2], 1);
        nokia_lcd_write_char(buffer[3], 1);
        nokia_lcd_write_char(buffer[4], 1);
        nokia_lcd_render();
    }
}


//*****************************************************************************
void draw_NPN(void){
    //BASE
    nokia_lcd_clear();
    nokia_lcd_set_cursor(0, 12);
    nokia_lcd_write_string("2", 1);
 
    nokia_lcd_set_pixel(7, 15, 1);
    nokia_lcd_set_pixel(8, 15, 1);
    nokia_lcd_set_pixel(9, 15, 1);
    nokia_lcd_set_pixel(10, 15, 1);
    nokia_lcd_set_pixel(11, 15, 1);
    nokia_lcd_set_pixel(12, 15, 1);
    nokia_lcd_set_pixel(13, 15, 1);
    nokia_lcd_set_pixel(14, 15, 1);
    
    //LINEA VERTICAL
    nokia_lcd_set_pixel(14, 10, 1);
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
    
    //EMISOR
    nokia_lcd_set_pixel(15, 18, 1);
    nokia_lcd_set_pixel(16, 19, 1);
    nokia_lcd_set_pixel(17, 20, 1);
    nokia_lcd_set_pixel(18, 21, 1);
    nokia_lcd_set_pixel(19, 21, 1);
    nokia_lcd_set_pixel(19, 22, 1);//punta
    nokia_lcd_set_pixel(18, 22, 1);
    nokia_lcd_set_pixel(17, 22, 1);
    nokia_lcd_set_pixel(19, 20, 1);
    nokia_lcd_set_pixel(19, 23, 1);
    nokia_lcd_set_pixel(19, 24, 1);
    nokia_lcd_set_pixel(19, 25, 1);
    nokia_lcd_set_pixel(19, 26, 1);
    
    //Colector
    nokia_lcd_set_pixel(15, 12, 1);
    nokia_lcd_set_pixel(16, 11, 1);
    nokia_lcd_set_pixel(17, 10, 1);
    nokia_lcd_set_pixel(18, 9, 1); 
    nokia_lcd_set_pixel(19, 8, 1);
    nokia_lcd_set_pixel(19, 7, 1);
    nokia_lcd_set_pixel(19, 6, 1);
    nokia_lcd_set_pixel(19, 5, 1);
    nokia_lcd_set_pixel(19, 4, 1);
    
    

    nokia_lcd_render(); 
}

void draw_PNP(void){
    //BASE
    nokia_lcd_clear();
    nokia_lcd_set_cursor(0, 12);
    nokia_lcd_write_string("2", 1);
   
    nokia_lcd_set_pixel(7, 15, 1);
    nokia_lcd_set_pixel(8, 15, 1);
    nokia_lcd_set_pixel(9, 15, 1);
    nokia_lcd_set_pixel(10, 15, 1);
    nokia_lcd_set_pixel(11, 15, 1);
    nokia_lcd_set_pixel(12, 15, 1);
    nokia_lcd_set_pixel(13, 15, 1);
    nokia_lcd_set_pixel(14, 15, 1);
    
    //LINEA VERTICAL
    nokia_lcd_set_pixel(14, 9, 1);
    nokia_lcd_set_pixel(14, 10, 1);
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
    
    
    //EMISOR
    
    nokia_lcd_set_pixel(15, 18, 1);
    nokia_lcd_set_pixel(16, 18, 1);
    nokia_lcd_set_pixel(17, 18, 1);
    nokia_lcd_set_pixel(15, 19, 1);
    nokia_lcd_set_pixel(15, 20, 1);
    
    nokia_lcd_set_pixel(16, 19, 1);
    nokia_lcd_set_pixel(17, 20, 1);
    nokia_lcd_set_pixel(18, 21, 1);
    nokia_lcd_set_pixel(19, 22, 1);
    nokia_lcd_set_pixel(19, 23, 1);
    nokia_lcd_set_pixel(19, 24, 1);
    nokia_lcd_set_pixel(19, 25, 1);
    nokia_lcd_set_pixel(19, 26, 1);
    
    //Colector
    
    nokia_lcd_set_pixel(15, 12, 1);
    nokia_lcd_set_pixel(16, 11, 1);
    nokia_lcd_set_pixel(17, 10, 1);
    nokia_lcd_set_pixel(18, 9, 1); 
    nokia_lcd_set_pixel(19, 8, 1);
    nokia_lcd_set_pixel(19, 7, 1);
    nokia_lcd_set_pixel(19, 6, 1);
    nokia_lcd_set_pixel(19, 5, 1);
    nokia_lcd_set_pixel(19, 4, 1);
    
    
  
    
  
    nokia_lcd_render(); 
}


