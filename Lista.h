#ifndef LISTA_H
#define LISTA_H
#include <cstdlib>
#include <iostream>
#include <string> 
#include "Nodo.h"

using namespace std;

struct Lista{
	
	//ATRIBUTOS
	Nodo * primerNodo;
	Nodo * ultimoNodo;
	
	//CONSTRUCTOR
	Lista(){
		primerNodo = ultimoNodo = NULL;
	}
	
	//METODOS
	void imprimirLista();
	void insertarAlInicio(Dato * dato);
	void insertarAlFinal(Dato * dato);
	Nodo * borrarAlInicio();
	Nodo * borrarAlFinal();
	int largo();
	bool empty();
	//Nodo * buscar(int _id);
	Nodo * encontrarNodo(int posicion);
};
#endif
