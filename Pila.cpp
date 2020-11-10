#include <cstdlib>
#include <iostream>
#include <string> 
#include "Pila.h"

//using namespace std;

//INSERTAR AL INICIO
void Pila::push (Dato * dato){
    if (empty ()){
    	tope = new Nodo(dato); // ambos apuntan al nuevo en memoria
    }else{
        Nodo * nuevo = new Nodo(dato); // a lo que apunta pN ahora es el segundo por eso, nuevo->siguiente es pN 
        nuevo->siguiente = tope; // ahora devolvemos pN a que apunte al nuevo // y primero de las lista
        tope = nuevo; // el puntero nuevo deja de existir, no se libera // memoria porque se pierde la info
    }
}

// funcion que elimina el primer elemento de las lista
// entradas: no tiene
// salidas: el puntero al primer nodo. Este puntero
// en siguiente apuntara a null. No se libera memoria


//BORRAR AL INICIO DE LA PILA**
Nodo * Pila::pop(){
    // si no hay elementos, no borra nada, retorna null
	if (empty()){
        return NULL;
    }else{
		Nodo * temporal = tope; // un puntero que apunta al nodo que se // "despegara" de la lista y se retorna
        tope = tope->siguiente; // pN se pasa al segundo de la lista // porque el primero se eliminara          
        temporal->siguiente = NULL;// el nodo borrado, se debe despegar // entonces siguiente apunta a null y no // al segundo de la lista que ahora es pN
    	return temporal;// aca se deberia liberar la memoria si no se // retornara el borrado
    }
};

//DETERMINA SI LA PILA ESTA VACIA **
bool Pila::empty(){
     if (tope == NULL){
	 	return true; 
	 }else{
	 	return false;
	 }
         
}

//IMPRIME LA PILA **
void Pila::imprimirPila(){
     cout << "tope" << endl;
     Nodo * temporal = tope; // puntero temporal que avanza // por toda la lista // apunta a los mismo que pN
     while (temporal != NULL){ // mientras tmp no sea nulo, avanza
        temporal->dato->imprimirDato();// imprime el dato del nodo en el que esta tmp
        temporal = temporal->siguiente;// tmp avanza al siguiente nodo // esto no puede faltar porque se encicla
     }
     cout << "fondo" << endl;
};


//RETORNA EL TOPE( PRIMER NODO ) **
Nodo * Pila::peek(){
     return tope;
};

