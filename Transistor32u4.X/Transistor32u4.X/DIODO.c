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
#include "Dibujos.h"

int V_diodo=0;
int medida1=0, medida2=0;
float Voltaje_diodo=0;
float V_Zenner;
int medidaZ1=0,medidaZ2=0;
float medidaZ1_T=0, medidaZ2_T=0;
char buffer[10];

uint16_t ADC_leer(uint8_t canal){
	canal&=0b00001111;				//Limitar la entrada a 5
	ADMUX = (ADMUX & 0xF0)|canal;  //Limpiar los últimos 4 bits de ADMUX, OR con ch
	ADCSRA|=(1<<ADSC);				//Inicia la conversión
	while((ADCSRA)&(1<<ADSC));		//Hasta que se complete la coversión
	return(ADC);					//devuelve el valor del adc
}

void F1_D(){
    PORTD = 0;
    DDRD = 0;
    
    DDRD |=(1<<TP1_1IO);
    DDRD |=(1<<TP3_1IO);
    PORTD |= (1<<TP1_1);//TP2 5V
    
    medida1=ADC_leer(5); //TP3
    medida2=ADC_leer(7); //TP1
}

void F2_D(){
    PORTD = 0;
    DDRD = 0;
    
    DDRD |=(1<<TP1_1IO);
    DDRD |=(1<<TP3_1IO);
    PORTD |= (1<<TP3_1);//TP2 5V
    
    medida1=ADC_leer(5); //TP3
    medida2=ADC_leer(7); //TP1
}
/*
void F3_D(){
    PORTD = 0;
    DDRD = 0;
    
    DDRD |=(1<<TP1_1IO);
    DDRD |=(1<<TP2_1IO);
    PORTD |= (1<<TP1_1);//TP2 5V
    
    medida1=ADC_leer(6); //TP3
    medida2=ADC_leer(7); //TP1
    
    A=1;
    C=2;
}

void F4_D(){
    PORTD = 0;
    DDRD = 0;
    
    DDRD |=(1<<TP1_1IO);
    DDRD |=(1<<TP2_1IO);
    PORTD |= (1<<TP2_1);//TP2 5V
    
    medida1=ADC_leer(6); //TP3
    medida2=ADC_leer(7); //TP1
    
    A=2;
    C=1;
}

void F5_D(){
    PORTD = 0;
    DDRD = 0;
    
    DDRD |=(1<<TP3_1IO);
    DDRD |=(1<<TP2_1IO);
    PORTD |= (1<<TP2_1);//TP2 5V
    
    medida1=ADC_leer(5); //TP1
    medida2=ADC_leer(6); //TP2
    
    A=2;
    C=3;
}

void F6_D(){
    PORTD = 0;
    DDRD = 0;
    
    DDRD |=(1<<TP3_1IO);
    DDRD |=(1<<TP2_1IO);
    PORTD |= (1<<TP3_1);//TP2 5V
    
    medida1=ADC_leer(5); //TP1
    medida2=ADC_leer(6); //TP2
    
    A=3;
    C=2;
}
*/
/*
void F1_Z(){
    int tierra=0;
    //Fuentes pines 1 y 3
    
    for(int i=0;i<10;i++){
        
        PORTD = 0;
        DDRD = 0;
        _delay_ms(500);

        tierra=abs(ADC_leer(5)); //TP3

        DDRD |=(1<<TP1_1IO);
        DDRD |=(1<<TP3_1IO);
        PORTD |= (1<<TP1_1);//TP2 5V
        _delay_ms(500);

        medida1=abs(ADC_leer(5)); //TP3
        medida2=abs(ADC_leer(7)); //TP1
        medidaZ1=abs(medida1-medida2)-tierra;
        medidaZ1_T=medidaZ1_T+(float)medidaZ1;

        PORTD = 0;
        DDRD = 0;
        _delay_ms(500);

        DDRD |=(1<<TP1_1IO);
        DDRD |=(1<<TP3_1IO);
        PORTD |= (1<<TP3_1);//TP2 5V
        _delay_ms(500);

        medida1=abs(ADC_leer(5)); //TP3
        medida2=abs(ADC_leer(7)); //TP1
        medidaZ2=abs(medida1-medida2)-tierra;
        medidaZ2_T=medidaZ2_T+(float)medidaZ2;
    }
    medidaZ1_T=medidaZ1_T/10;
    medidaZ2_T=medidaZ2_T/10;
}
*/

/*
void F3_Z(){
    int tierra=0;
    //Fuentes pines 2 y 3
    medidaZ1_T=0;
    medidaZ2_T=0;
    for(int i=0;i<10;i++){
        
        PORTD = 0;
        DDRD = 0;
        _delay_ms(500);

        tierra=abs(ADC_leer(5)); //TP3

        DDRD |=(1<<TP2_1IO);
        DDRD |=(1<<TP3_1IO);
        PORTD |= (1<<TP2_1);//TP2 5V
        _delay_ms(500);

        medida1=abs(ADC_leer(5)); //TP3
        medida2=abs(ADC_leer(7)); //TP1
        medidaZ1=abs(medida1-medida2)-tierra;
        medidaZ1_T=medidaZ1_T+(float)medidaZ1;

        PORTD = 0;
        DDRD = 0;
        _delay_ms(500);

        DDRD |=(1<<TP2_1IO);
        DDRD |=(1<<TP3_1IO);
        PORTD |= (1<<TP3_1);//TP2 5V
        _delay_ms(500);

        medida1=abs(ADC_leer(5)); //TP3
        medida2=abs(ADC_leer(7)); //TP1
        medidaZ2=abs(medida1-medida2)-tierra;
        medidaZ2_T=medidaZ2_T+(float)medidaZ2;
    }
    medidaZ1_T=medidaZ1_T/10;
    medidaZ2_T=medidaZ2_T/10;
}*/

void DIODO(int A){
    int C=0;
    float V_diodo;
    int adc_result=0;
    int tipo=0;
    char buffer[10];
    
    if(A==1){
        F1_D();
        C=3;
    }
    if(A==3){
        F2_D();
        C=1;
    }
    
    
    V_diodo=medida1-medida2;
    Voltaje_diodo=fabs(((5*((float)V_diodo)) / 1023));
    
    if(0<Voltaje_diodo && Voltaje_diodo<0.4){
        //DIODO SHOCKLEY
        draw_DiodoSh();
    }
    if(0.4<Voltaje_diodo && Voltaje_diodo<0.5){
        //DIODO GERMANIO
        draw_DiodoGe(); 
    }
    if(0.5<Voltaje_diodo && Voltaje_diodo<0.9){
        //DIODO SILICIO
        draw_DiodoSi();
    }
    if(0.9<Voltaje_diodo && Voltaje_diodo<3){
        //DIODO LED
        draw_DiodoLed();
    }
    nokia_lcd_set_cursor(30, 12);
    nokia_lcd_write_string("Vdiodo", 1);
    nokia_lcd_set_pixel(70, 15, 1);
    nokia_lcd_set_pixel(71, 15, 1);
    nokia_lcd_set_pixel(72, 15, 1);
    nokia_lcd_set_pixel(72, 16, 1);
    nokia_lcd_set_pixel(72, 17, 1);
    nokia_lcd_set_pixel(72, 18, 1);
    nokia_lcd_set_pixel(71, 18, 1);
    nokia_lcd_set_pixel(73, 18, 1);
    nokia_lcd_set_pixel(72, 19, 1);
    nokia_lcd_set_cursor(40, 22);
    
    nokia_lcd_set_cursor(30, 33);
    nokia_lcd_write_string("A: ", 1);
    imprimir_d(A,42,33,1);
    
    nokia_lcd_set_cursor(55, 33);
    nokia_lcd_write_string("C: ", 1);
    imprimir_d(C,67,33,1);
    nokia_lcd_render();
    
    imprimir_f(Voltaje_diodo,40,22,5);
}

void F_Z(){
    
    //Fuentes pines 1 y 2
    int tierra=0;
    
    
    for(int i=0;i<10;i++){
        
        PORTD = 0;
        DDRD = 0;
        _delay_ms(500);

        tierra=ADC_leer(5); //TP3

        DDRD |=(1<<TP1_1IO);
        DDRD |=(1<<TP3_1IO);
        PORTD |= (1<<TP1_1);//TP2 5V
        _delay_ms(500);

        medida1=ADC_leer(6); //TP2
        medida2=ADC_leer(7); //TP1
        
        
        medidaZ1=medida1-medida2-tierra;
        medidaZ1_T=medidaZ1_T+(float)medidaZ1;
        
        PORTD = 0;
        DDRD = 0;
        _delay_ms(500);

        DDRD |=(1<<TP1_1IO);
        DDRD |=(1<<TP3_1IO);
        PORTD |= (1<<TP3_1);//TP2 5V
        _delay_ms(500);

        medida1=ADC_leer(6); //TP2
        medida2=ADC_leer(7); //TP1
        medidaZ2=medida1-medida2-tierra;
        medidaZ2_T=medidaZ2_T+(float)medidaZ2;
    }
    
    
    medidaZ1_T=medidaZ1_T/10;
    medidaZ2_T=medidaZ2_T/10;
}
/*
void Zenner(){
    float Vdirecto=0, Vinverso=0;
    draw_DiodoZe();
    F_Z();
    
    if(medidaZ1_T>medidaZ2_T){
        Vdirecto=fabs(((5*(medidaZ2_T)) / 1023));
        Vinverso=fabs(((5*(medidaZ1_T)) / 1023));
    }
    else{
        Vdirecto=fabs(((5*(medidaZ1_T)) / 1023));
        Vinverso=fabs(((5*(medidaZ2_T)) / 1023));
    }
    
    medidaZ1_T=0;
    medidaZ2_T=0;
    
    nokia_lcd_set_cursor(30, 2);
    nokia_lcd_write_string("Vdirecto", 1);
    nokia_lcd_render();

    imprimir_f(medidaZ1_T,30,10,4);
    
    nokia_lcd_set_cursor(30, 24);
    nokia_lcd_write_string("Vinverso", 1);
    nokia_lcd_render();

    imprimir_f(medidaZ2_T,30,32,4);
    _delay_ms(1000);
}*/

void Zenner(){
    
    float Vdirecto=0, Vinverso=0;
    draw_DiodoZe();
    F_Z();
    
    medidaZ1_T=fabs(medidaZ1_T);
    medidaZ2_T=fabs(medidaZ2_T);    
           
    
    if(medidaZ1_T>medidaZ2_T){
        Vdirecto=fabs(((5*((float)medidaZ2_T)) / 1023));
        Vinverso=fabs(((5*((float)medidaZ1_T)) / 1023));
    }
    else{
        Vdirecto=fabs(((5*((float)medidaZ1_T)) / 1023));
        Vinverso=fabs(((5*((float)medidaZ2_T)) / 1023));
    }

    nokia_lcd_set_cursor(30, 2);
    nokia_lcd_write_string("Vdirecto", 1);
    nokia_lcd_render();

    imprimir_f(Vdirecto,30,10,4);
    
    nokia_lcd_set_cursor(30, 24);
    nokia_lcd_write_string("Vinverso", 1);
    nokia_lcd_render();

    imprimir_f(Vinverso,30,32,4);
    _delay_ms(100);
}

void imprimir_f (float valor,int x, int y, int j){
    sprintf(buffer,"%.3f",valor);
    nokia_lcd_set_cursor(x, y);
    for (int i=0; i<j; i++){
        nokia_lcd_write_char(buffer[i], 1); 
    }
    nokia_lcd_render();
}

void imprimir_d (int valor, int x, int y, int j){
    sprintf(buffer,"%d",valor);
    nokia_lcd_set_cursor(x, y);
    for (int i=0; i<j; i++){
        nokia_lcd_write_char(buffer[i], 1); 
    }
    nokia_lcd_render();
}