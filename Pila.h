#ifndef PILA_H
#define PILA_H
#include <cstdlib>
#include <iostream>
#include <string> 
#include "Nodo.h"


using namespace std;

struct Pila {
       // solo con pN es suficiente
       Nodo * tope;
       
       Pila(){
            tope = NULL;
       }
       // encabezados de funcion
       void push (Dato * dato);
       Nodo* pop (void);
       Nodo* peek(void);
       bool empty(void);
       void imprimirPila(void);
};
#endif
