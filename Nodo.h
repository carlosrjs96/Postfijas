#ifndef NODO_H
#define NODO_H
#include <cstdlib>
#include <iostream>
#include <string> 
#include "Dato.h"

using namespace std;

struct Nodo {
	
	//ATRIBUTOS
	Dato * dato; 
	Nodo * siguiente; // puntero para enlazar nodos
	
	//CONSTRUCTOR SIN PARAMETROS
	Nodo(){
		dato = NULL; // cliente es nulo
		siguiente= NULL; // siguiente es nulo
	}
	
	//CONSTRUCTOR RECIBE UNA ESTRUCTURA CLIENTE
	Nodo(Dato * _dato){
		dato= _dato; // asigna los datos
		siguiente= NULL; // siguiente es nulo
	}
	
	//CONSTRUCTOR RECIBE PARAMETROS PARA CREAR UNA ESTRUCTURA CLIENTE
    Nodo(string _tipo,string _operador,double _numero){
    	dato = new Dato(_tipo,_operador,_numero);
		siguiente= NULL;
	}
};
#endif
