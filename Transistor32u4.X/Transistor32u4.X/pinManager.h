/*
 * File:   main.c (PERSONALIZACIÓN CARACTER)
 * 
 * Autores: Oscar David Poblador Parra      20211005116
 *          Juan David Bello Rodriguez      20211005028 
 *          Manuel Alejandro Guio Cardona   20211005061
 * Institución:: Universidad Distrital Francisco José de Caldas
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

//***************************************************************************
//Definiciones para numero de pin del puerto D (PORT), conrolan el testeo
#define TP1_1 PORTD0 
#define TP1_2 PORTD6
#define TP2_1 PORTD2 
#define TP2_2 PORTD3 
#define TP3_1 PORTD4 
#define TP3_2 PORTD7 

//Definiciones para numero de pin del puerto D (DDR), conrolan el testeo
#define TP1_1IO DDD0
#define TP1_2IO DDD6
#define TP2_1IO DDD2
#define TP2_2IO DDD3
#define TP3_1IO DDD4
#define TP3_2IO DDD7


//Definiones para numero de pin del puerto B, controlan Pantalla
#define SS PORTB0
#define D_C PORTB4
#define RST PORTB5

//***************************************************************************

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

