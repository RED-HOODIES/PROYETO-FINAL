/*
 * File:   main.c (PERSONALIZACIÓN CARACTER)
 * 
 * Autores: Oscar David Poblador Parra      20211005116
 *          Juan David Bello Rodriguez      20211005028 
 *          Manuel Alejandro Guio Cardona   20211005061
 * Institución:: Universidad Distrital Francisco José de Caldas
 */

#include <avr/io.h>
#include <stdio.h>
#include "pinManager.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "NOKIA.h"

void draw_DiodoSi(void){
    //BASE
    nokia_lcd_clear();
    nokia_lcd_set_cursor(7, 26);
    nokia_lcd_write_string("S", 1);
        nokia_lcd_set_cursor(13, 26);
    nokia_lcd_write_string("i", 1);
   
    
    //LINEA VERTICAL
    
    nokia_lcd_set_pixel(12, 6, 1);
    nokia_lcd_set_pixel(12, 7, 1);
    nokia_lcd_set_pixel(12, 8, 1);
    nokia_lcd_set_pixel(12, 9, 1);
    nokia_lcd_set_pixel(12, 10, 1);
    nokia_lcd_set_pixel(12, 11, 1);
    nokia_lcd_set_pixel(12, 12, 1);
    
    nokia_lcd_set_pixel(12, 13, 1); 
    nokia_lcd_set_pixel(12, 14, 1);
    
    ////////////////////// FINAL DIOODO
    
    nokia_lcd_set_pixel(8, 12, 1);
    nokia_lcd_set_pixel(9, 12, 1);
    nokia_lcd_set_pixel(10, 12, 1);
    nokia_lcd_set_pixel(11, 12, 1);
    nokia_lcd_set_pixel(12, 12, 1); ////////////////////// LINEA DIODO HOR SUP
    nokia_lcd_set_pixel(13, 12, 1);
    nokia_lcd_set_pixel(14, 12, 1);
    nokia_lcd_set_pixel(15, 12, 1);
    nokia_lcd_set_pixel(16, 12, 1);
    
    ////////////////////// MITAD DIODO
    
    nokia_lcd_set_pixel(8, 17, 1);
    nokia_lcd_set_pixel(9, 17, 1);
    nokia_lcd_set_pixel(10, 17, 1);
    nokia_lcd_set_pixel(11, 17, 1);
    nokia_lcd_set_pixel(12, 17, 1); ////////////////////// LINEA DIODO HOR INF
    nokia_lcd_set_pixel(13, 17, 1);
    nokia_lcd_set_pixel(14, 17, 1);
    nokia_lcd_set_pixel(15, 17, 1);
    nokia_lcd_set_pixel(16, 17, 1);
    
    
    ////////// LINEA DIODO DIAG DER /////////////
    
    nokia_lcd_set_pixel(13, 14, 1);
    nokia_lcd_set_pixel(14, 15, 1);
    nokia_lcd_set_pixel(15, 16, 1);
    
    ////////// LINEA DIODO DIAG IZQ /////////////
    
    nokia_lcd_set_pixel(11, 14, 1);
    nokia_lcd_set_pixel(10, 15, 1);
    nokia_lcd_set_pixel(9, 16, 1);
    
    ///////////////// COLOR /////////////////////
    
    nokia_lcd_set_pixel(10, 16, 1);
    nokia_lcd_set_pixel(11, 16, 1);
    nokia_lcd_set_pixel(12, 16, 1);
    nokia_lcd_set_pixel(13, 16, 1);
    nokia_lcd_set_pixel(14, 16, 1);
   
    nokia_lcd_set_pixel(11, 15, 1);
    nokia_lcd_set_pixel(12, 15, 1);
    nokia_lcd_set_pixel(13, 15, 1);
    
    /////////////////////////////////////////////
    
    nokia_lcd_set_pixel(12, 18, 1);
    nokia_lcd_set_pixel(12, 19, 1);
    nokia_lcd_set_pixel(12, 20, 1);
    nokia_lcd_set_pixel(12, 21, 1);
    nokia_lcd_set_pixel(12, 22, 1);
    nokia_lcd_set_pixel(12, 23, 1);
  
    nokia_lcd_render(); 
}

void draw_DiodoGe(void){
    //BASE
    nokia_lcd_clear();
    nokia_lcd_set_cursor(7, 26);
    nokia_lcd_write_string("G", 1);
        nokia_lcd_set_cursor(13, 26);
    nokia_lcd_write_string("e", 1);
   
    
    //LINEA VERTICAL
    
    nokia_lcd_set_pixel(12, 6, 1);
    nokia_lcd_set_pixel(12, 7, 1);
    nokia_lcd_set_pixel(12, 8, 1);
    nokia_lcd_set_pixel(12, 9, 1);
    nokia_lcd_set_pixel(12, 10, 1);
    nokia_lcd_set_pixel(12, 11, 1);
    nokia_lcd_set_pixel(12, 12, 1);
    
    nokia_lcd_set_pixel(12, 13, 1); 
    nokia_lcd_set_pixel(12, 14, 1);
    
    ////////////////////// FINAL DIOODO
    
    nokia_lcd_set_pixel(8, 12, 1);
    nokia_lcd_set_pixel(9, 12, 1);
    nokia_lcd_set_pixel(10, 12, 1);
    nokia_lcd_set_pixel(11, 12, 1);
    nokia_lcd_set_pixel(12, 12, 1); ////////////////////// LINEA DIODO HOR SUP
    nokia_lcd_set_pixel(13, 12, 1);
    nokia_lcd_set_pixel(14, 12, 1);
    nokia_lcd_set_pixel(15, 12, 1);
    nokia_lcd_set_pixel(16, 12, 1);
    
    ////////////////////// MITAD DIODO
    
    nokia_lcd_set_pixel(8, 17, 1);
    nokia_lcd_set_pixel(9, 17, 1);
    nokia_lcd_set_pixel(10, 17, 1);
    nokia_lcd_set_pixel(11, 17, 1);
    nokia_lcd_set_pixel(12, 17, 1); ////////////////////// LINEA DIODO HOR INF
    nokia_lcd_set_pixel(13, 17, 1);
    nokia_lcd_set_pixel(14, 17, 1);
    nokia_lcd_set_pixel(15, 17, 1);
    nokia_lcd_set_pixel(16, 17, 1);
    
    
    ////////// LINEA DIODO DIAG DER /////////////
    
    nokia_lcd_set_pixel(13, 14, 1);
    nokia_lcd_set_pixel(14, 15, 1);
    nokia_lcd_set_pixel(15, 16, 1);
    
    ////////// LINEA DIODO DIAG IZQ /////////////
    
    nokia_lcd_set_pixel(11, 14, 1);
    nokia_lcd_set_pixel(10, 15, 1);
    nokia_lcd_set_pixel(9, 16, 1);
    
    ///////////////// COLOR /////////////////////
    
    nokia_lcd_set_pixel(10, 16, 1);
    nokia_lcd_set_pixel(11, 16, 1);
    nokia_lcd_set_pixel(12, 16, 1);
    nokia_lcd_set_pixel(13, 16, 1);
    nokia_lcd_set_pixel(14, 16, 1);
   
    nokia_lcd_set_pixel(11, 15, 1);
    nokia_lcd_set_pixel(12, 15, 1);
    nokia_lcd_set_pixel(13, 15, 1);
    
    /////////////////////////////////////////////
    
    nokia_lcd_set_pixel(12, 18, 1);
    nokia_lcd_set_pixel(12, 19, 1);
    nokia_lcd_set_pixel(12, 20, 1);
    nokia_lcd_set_pixel(12, 21, 1);
    nokia_lcd_set_pixel(12, 22, 1);
    nokia_lcd_set_pixel(12, 23, 1);
  
    nokia_lcd_render(); 
}

void draw_DiodoZe(void){
    //BASE
    nokia_lcd_clear();
    nokia_lcd_set_cursor(7, 26);
    nokia_lcd_write_string("Z", 1);
        nokia_lcd_set_cursor(13, 26);
    nokia_lcd_write_string("e", 1);
   
    
    //LINEA VERTICAL
    
    nokia_lcd_set_pixel(12, 6, 1);
    nokia_lcd_set_pixel(12, 7, 1);
    nokia_lcd_set_pixel(12, 8, 1);
    nokia_lcd_set_pixel(12, 9, 1);
    nokia_lcd_set_pixel(12, 10, 1);
    nokia_lcd_set_pixel(12, 11, 1);
    nokia_lcd_set_pixel(12, 12, 1);
    
    nokia_lcd_set_pixel(12, 13, 1); 
    nokia_lcd_set_pixel(12, 14, 1);
    
    ////////////////////// FINAL DIOODO
    
    nokia_lcd_set_pixel(5, 9, 1);
    nokia_lcd_set_pixel(6, 10, 1);
    nokia_lcd_set_pixel(7, 11, 1);
    
    nokia_lcd_set_pixel(8, 12, 1);
    nokia_lcd_set_pixel(9, 12, 1);
    nokia_lcd_set_pixel(10, 12, 1);
    nokia_lcd_set_pixel(11, 12, 1);
    nokia_lcd_set_pixel(12, 12, 1); ////////////////////// LINEA DIODO HOR SUP
    nokia_lcd_set_pixel(13, 12, 1);
    nokia_lcd_set_pixel(14, 12, 1);
    nokia_lcd_set_pixel(15, 12, 1);
    nokia_lcd_set_pixel(16, 12, 1);
    
    nokia_lcd_set_pixel(17, 13, 1);
    nokia_lcd_set_pixel(18, 14, 1);
    nokia_lcd_set_pixel(19, 15, 1);
    
    ////////////////////// MITAD DIODO
    
    nokia_lcd_set_pixel(8, 17, 1);
    nokia_lcd_set_pixel(9, 17, 1);
    nokia_lcd_set_pixel(10, 17, 1);
    nokia_lcd_set_pixel(11, 17, 1);
    nokia_lcd_set_pixel(12, 17, 1); ////////////////////// LINEA DIODO HOR INF
    nokia_lcd_set_pixel(13, 17, 1);
    nokia_lcd_set_pixel(14, 17, 1);
    nokia_lcd_set_pixel(15, 17, 1);
    nokia_lcd_set_pixel(16, 17, 1);
    
    
    ////////// LINEA DIODO DIAG DER /////////////
    
    nokia_lcd_set_pixel(13, 14, 1);
    nokia_lcd_set_pixel(14, 15, 1);
    nokia_lcd_set_pixel(15, 16, 1);
    
    ////////// LINEA DIODO DIAG IZQ /////////////
    
    nokia_lcd_set_pixel(11, 14, 1);
    nokia_lcd_set_pixel(10, 15, 1);
    nokia_lcd_set_pixel(9, 16, 1);
    
    ///////////////// COLOR /////////////////////
    
    nokia_lcd_set_pixel(10, 16, 1);
    nokia_lcd_set_pixel(11, 16, 1);
    nokia_lcd_set_pixel(12, 16, 1);
    nokia_lcd_set_pixel(13, 16, 1);
    nokia_lcd_set_pixel(14, 16, 1);
   
    nokia_lcd_set_pixel(11, 15, 1);
    nokia_lcd_set_pixel(12, 15, 1);
    nokia_lcd_set_pixel(13, 15, 1);
    
    /////////////////////////////////////////////
    
    nokia_lcd_set_pixel(12, 18, 1);
    nokia_lcd_set_pixel(12, 19, 1);
    nokia_lcd_set_pixel(12, 20, 1);
    nokia_lcd_set_pixel(12, 21, 1);
    nokia_lcd_set_pixel(12, 22, 1);
    nokia_lcd_set_pixel(12, 23, 1);
  
    nokia_lcd_render(); 
}

void draw_DiodoSh(void){
    //BASE
    nokia_lcd_clear();
    nokia_lcd_set_cursor(7, 26);
    nokia_lcd_write_string("S", 1);
        nokia_lcd_set_cursor(13, 26);
    nokia_lcd_write_string("h", 1);
   
    
    //LINEA VERTICAL
    
    nokia_lcd_set_pixel(12, 6, 1);
    nokia_lcd_set_pixel(12, 7, 1);
    nokia_lcd_set_pixel(12, 8, 1);
    nokia_lcd_set_pixel(12, 9, 1);
    nokia_lcd_set_pixel(12, 10, 1);
    nokia_lcd_set_pixel(12, 11, 1);
    nokia_lcd_set_pixel(12, 12, 1);
    
    nokia_lcd_set_pixel(12, 13, 1); 
    nokia_lcd_set_pixel(12, 14, 1);
    
    ////////////////////// FINAL DIOODO
    
    nokia_lcd_set_pixel(5, 9, 1);
    nokia_lcd_set_pixel(5, 10, 1);
    nokia_lcd_set_pixel(5, 11, 1);
    
    nokia_lcd_set_pixel(5, 12, 1);
    nokia_lcd_set_pixel(6, 12, 1);
    nokia_lcd_set_pixel(7, 12, 1);
    nokia_lcd_set_pixel(8, 12, 1);
    nokia_lcd_set_pixel(9, 12, 1);
    nokia_lcd_set_pixel(10, 12, 1);
    nokia_lcd_set_pixel(11, 12, 1);
    nokia_lcd_set_pixel(12, 12, 1); ////////////////////// LINEA DIODO HOR SUP
    nokia_lcd_set_pixel(13, 12, 1);
    nokia_lcd_set_pixel(14, 12, 1);
    nokia_lcd_set_pixel(15, 12, 1);
    nokia_lcd_set_pixel(16, 12, 1);
    nokia_lcd_set_pixel(17, 12, 1);
    nokia_lcd_set_pixel(18, 12, 1);
    nokia_lcd_set_pixel(19, 12, 1);
    
    nokia_lcd_set_pixel(19, 13, 1);
    nokia_lcd_set_pixel(19, 14, 1);
    nokia_lcd_set_pixel(19, 15, 1);
    
    ////////////////////// MITAD DIODO
    
    nokia_lcd_set_pixel(8, 17, 1);
    nokia_lcd_set_pixel(9, 17, 1);
    nokia_lcd_set_pixel(10, 17, 1);
    nokia_lcd_set_pixel(11, 17, 1);
    nokia_lcd_set_pixel(12, 17, 1); ////////////////////// LINEA DIODO HOR INF
    nokia_lcd_set_pixel(13, 17, 1);
    nokia_lcd_set_pixel(14, 17, 1);
    nokia_lcd_set_pixel(15, 17, 1);
    nokia_lcd_set_pixel(16, 17, 1);
    
    
    ////////// LINEA DIODO DIAG DER /////////////
    
    nokia_lcd_set_pixel(13, 14, 1);
    nokia_lcd_set_pixel(14, 15, 1);
    nokia_lcd_set_pixel(15, 16, 1);
    
    ////////// LINEA DIODO DIAG IZQ /////////////
    
    nokia_lcd_set_pixel(11, 14, 1);
    nokia_lcd_set_pixel(10, 15, 1);
    nokia_lcd_set_pixel(9, 16, 1);
    
    ///////////////// COLOR /////////////////////
    
    nokia_lcd_set_pixel(10, 16, 1);
    nokia_lcd_set_pixel(11, 16, 1);
    nokia_lcd_set_pixel(12, 16, 1);
    nokia_lcd_set_pixel(13, 16, 1);
    nokia_lcd_set_pixel(14, 16, 1);
   
    nokia_lcd_set_pixel(11, 15, 1);
    nokia_lcd_set_pixel(12, 15, 1);
    nokia_lcd_set_pixel(13, 15, 1);
    
    /////////////////////////////////////////////
    
    nokia_lcd_set_pixel(12, 18, 1);
    nokia_lcd_set_pixel(12, 19, 1);
    nokia_lcd_set_pixel(12, 20, 1);
    nokia_lcd_set_pixel(12, 21, 1);
    nokia_lcd_set_pixel(12, 22, 1);
    nokia_lcd_set_pixel(12, 23, 1);
  
    nokia_lcd_render(); 
}

void draw_DiodoLed(void){
    //BASE
    nokia_lcd_clear();
    nokia_lcd_set_cursor(4, 26);
    nokia_lcd_write_string("LED", 1);
   
    
    //LINEA VERTICAL
    
    nokia_lcd_set_pixel(12, 6, 1);
    nokia_lcd_set_pixel(12, 7, 1);
    nokia_lcd_set_pixel(12, 8, 1);
    nokia_lcd_set_pixel(12, 9, 1);
    nokia_lcd_set_pixel(12, 10, 1);
    nokia_lcd_set_pixel(12, 11, 1);
    nokia_lcd_set_pixel(12, 12, 1);
    
    nokia_lcd_set_pixel(12, 13, 1); 
    nokia_lcd_set_pixel(12, 14, 1);
    
    ////////////////////// FINAL DIOODO
    
    nokia_lcd_set_pixel(8, 12, 1);
    nokia_lcd_set_pixel(9, 12, 1);
    nokia_lcd_set_pixel(10, 12, 1);
    nokia_lcd_set_pixel(11, 12, 1);
    nokia_lcd_set_pixel(12, 12, 1); ////////////////////// LINEA DIODO HOR SUP
    nokia_lcd_set_pixel(13, 12, 1);
    nokia_lcd_set_pixel(14, 12, 1);
    nokia_lcd_set_pixel(15, 12, 1);
    nokia_lcd_set_pixel(16, 12, 1);
    
    ////////// FLECHAS /////////////
    
    nokia_lcd_set_pixel(18, 13, 1);
    nokia_lcd_set_pixel(19, 12, 1);
    nokia_lcd_set_pixel(20, 11, 1);//
    
    nokia_lcd_set_pixel(20, 10, 1);
    nokia_lcd_set_pixel(21, 10, 1);
    nokia_lcd_set_pixel(21, 11, 1);
    
    
    nokia_lcd_set_pixel(18, 17, 1);
    nokia_lcd_set_pixel(19, 16, 1);
    nokia_lcd_set_pixel(20, 15, 1);//
    
    nokia_lcd_set_pixel(20, 14, 1);
    nokia_lcd_set_pixel(21, 14, 1);
    nokia_lcd_set_pixel(21, 15, 1);
    
    //////// MITAD DIODO ///////////
    
    nokia_lcd_set_pixel(8, 17, 1);
    nokia_lcd_set_pixel(9, 17, 1);
    nokia_lcd_set_pixel(10, 17, 1);
    nokia_lcd_set_pixel(11, 17, 1);
    nokia_lcd_set_pixel(12, 17, 1); ////////////////////// LINEA DIODO HOR INF
    nokia_lcd_set_pixel(13, 17, 1);
    nokia_lcd_set_pixel(14, 17, 1);
    nokia_lcd_set_pixel(15, 17, 1);
    nokia_lcd_set_pixel(16, 17, 1);
    
    
    ////////// LINEA DIODO DIAG DER /////////////
    
    nokia_lcd_set_pixel(13, 14, 1);
    nokia_lcd_set_pixel(14, 15, 1);
    nokia_lcd_set_pixel(15, 16, 1);
    
    ////////// LINEA DIODO DIAG IZQ /////////////
    
    nokia_lcd_set_pixel(11, 14, 1);
    nokia_lcd_set_pixel(10, 15, 1);
    nokia_lcd_set_pixel(9, 16, 1);
    
    ///////////////// COLOR /////////////////////
    
    nokia_lcd_set_pixel(10, 16, 1);
    nokia_lcd_set_pixel(11, 16, 1);
    nokia_lcd_set_pixel(12, 16, 1);
    nokia_lcd_set_pixel(13, 16, 1);
    nokia_lcd_set_pixel(14, 16, 1);
   
    nokia_lcd_set_pixel(11, 15, 1);
    nokia_lcd_set_pixel(12, 15, 1);
    nokia_lcd_set_pixel(13, 15, 1);
    
    /////////////////////////////////////////////
    
    nokia_lcd_set_pixel(12, 18, 1);
    nokia_lcd_set_pixel(12, 19, 1);
    nokia_lcd_set_pixel(12, 20, 1);
    nokia_lcd_set_pixel(12, 21, 1);
    nokia_lcd_set_pixel(12, 22, 1);
    nokia_lcd_set_pixel(12, 23, 1);
  
    nokia_lcd_render(); 
}

void draw_Cap(void){
    //BASE
    nokia_lcd_clear();
    nokia_lcd_set_cursor(4, 26);
    nokia_lcd_write_string("CAP", 1);
   
    
    //LINEA VERTICAL
    
    nokia_lcd_set_pixel(12, 6, 1);
    nokia_lcd_set_pixel(12, 7, 1);
    nokia_lcd_set_pixel(12, 8, 1);
    nokia_lcd_set_pixel(12, 9, 1);
    nokia_lcd_set_pixel(12, 10, 1);
    nokia_lcd_set_pixel(12, 11, 1);
    nokia_lcd_set_pixel(12, 12, 1);
    nokia_lcd_set_pixel(12, 13, 1); 
    nokia_lcd_set_pixel(12, 14, 1);
    nokia_lcd_set_pixel(12, 15, 1);
    
    ///////// Linea Hor Sup ////////////
    
    nokia_lcd_set_pixel(8, 15, 1);
    nokia_lcd_set_pixel(9, 15, 1);
    nokia_lcd_set_pixel(10, 15, 1);
    nokia_lcd_set_pixel(11, 15, 1);
    nokia_lcd_set_pixel(12, 15, 1);/////////
    nokia_lcd_set_pixel(13, 15, 1);
    nokia_lcd_set_pixel(14, 15, 1);
    nokia_lcd_set_pixel(15, 15, 1);
    nokia_lcd_set_pixel(16, 15, 1);
    
    
    nokia_lcd_set_pixel(8, 17, 1);
    nokia_lcd_set_pixel(9, 17, 1);
    nokia_lcd_set_pixel(10, 17, 1);
    nokia_lcd_set_pixel(11, 17, 1);
    nokia_lcd_set_pixel(12, 17, 1);///////////
    nokia_lcd_set_pixel(13, 17, 1);
    nokia_lcd_set_pixel(14, 17, 1);
    nokia_lcd_set_pixel(15, 17, 1);
    nokia_lcd_set_pixel(16, 17, 1);
    
    
    ///////// Linea Hor Inf ///////////
    
    nokia_lcd_set_pixel(12, 17, 1);
    nokia_lcd_set_pixel(12, 18, 1);
    nokia_lcd_set_pixel(12, 19, 1);
    nokia_lcd_set_pixel(12, 20, 1);
    nokia_lcd_set_pixel(12, 21, 1);
    nokia_lcd_set_pixel(12, 22, 1);
    nokia_lcd_set_pixel(12, 23, 1);
  
    nokia_lcd_render(); 
}

void draw_CapTriste(void){
    //BASE
    nokia_lcd_clear();
    nokia_lcd_set_cursor(4, 26);
    nokia_lcd_write_string("CAP", 1);
   
    
    //LINEA VERTICAL
    
    nokia_lcd_set_pixel(12, 6, 1);
    nokia_lcd_set_pixel(12, 7, 1);
    nokia_lcd_set_pixel(12, 8, 1);
    nokia_lcd_set_pixel(12, 9, 1);
    nokia_lcd_set_pixel(12, 10, 1);
    nokia_lcd_set_pixel(12, 11, 1);
    nokia_lcd_set_pixel(12, 12, 1);
    nokia_lcd_set_pixel(12, 13, 1); 
    nokia_lcd_set_pixel(12, 14, 1);
    nokia_lcd_set_pixel(12, 15, 1);
    
    ///////// Linea Hor Sup ////////////
    
    nokia_lcd_set_pixel(8, 15, 1);
    nokia_lcd_set_pixel(9, 15, 1);
    nokia_lcd_set_pixel(10, 15, 1);
    nokia_lcd_set_pixel(11, 15, 1);
    nokia_lcd_set_pixel(12, 15, 1);/////////
    nokia_lcd_set_pixel(13, 15, 1);
    nokia_lcd_set_pixel(14, 15, 1);
    nokia_lcd_set_pixel(15, 15, 1);
    nokia_lcd_set_pixel(16, 15, 1);
    
    
    nokia_lcd_set_pixel(8, 19, 1);
    nokia_lcd_set_pixel(9, 18, 1);
    nokia_lcd_set_pixel(10, 18, 1);
    nokia_lcd_set_pixel(11, 17, 1);
    nokia_lcd_set_pixel(12, 17, 1);///////////
    nokia_lcd_set_pixel(13, 17, 1);
    nokia_lcd_set_pixel(14, 18, 1);
    nokia_lcd_set_pixel(15, 18, 1);
    nokia_lcd_set_pixel(16, 19, 1);
    
    
    ///////// Linea Hor Inf ///////////
    
    nokia_lcd_set_pixel(12, 17, 1);
    nokia_lcd_set_pixel(12, 18, 1);
    nokia_lcd_set_pixel(12, 19, 1);
    nokia_lcd_set_pixel(12, 20, 1);
    nokia_lcd_set_pixel(12, 21, 1);
    nokia_lcd_set_pixel(12, 22, 1);
    nokia_lcd_set_pixel(12, 23, 1);
  
    nokia_lcd_render(); 
}
