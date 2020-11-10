#include <cstdlib>
#include <iostream>
#include <string> 
#include "Lista.h"

using namespace std;

//IMPRIMIR LOS NODOS DE LA LISTA**
void Lista::imprimirLista(){
	Nodo * temporal = primerNodo;
	while(temporal!=NULL){
		if(temporal->dato!=NULL) {
			temporal->dato->imprimirDato();
		temporal = temporal->siguiente;
		}
	}
	cout<<" "<<endl;
};



//INSERTA AL INICIO DE LA LISTA
void Lista::insertarAlInicio(Dato * dato){
	if(primerNodo==NULL) {
		ultimoNodo = primerNodo = new Nodo(dato);
	}else{
		Nodo * nuevo =  new Nodo(dato);
		nuevo->siguiente = primerNodo;
		primerNodo = nuevo; 
	}
}

//INSERTA AL FINAL DE LA LISTA
void Lista::insertarAlFinal(Dato * dato){
	if(primerNodo==NULL) {
		ultimoNodo = primerNodo = new Nodo(dato);
	}else{
		ultimoNodo->siguiente =  new Nodo(dato);
		ultimoNodo = ultimoNodo->siguiente;
	}
	//cout<<"INSERTADO"<<endl;
}

//BORRA AL INICIO DE LA LISTA
Nodo * Lista::borrarAlInicio(){
	if(primerNodo==NULL){
		return NULL;
	}else if(primerNodo == ultimoNodo){
		Nodo * temporal = primerNodo;
		primerNodo = ultimoNodo = NULL;
		return temporal;
	}else{
		Nodo * temporal = primerNodo;
		primerNodo = primerNodo->siguiente;
		temporal->siguiente = NULL;
		return temporal;
	}
}

//BORRA AL FINAL DE LA LISTA
Nodo * Lista::borrarAlFinal(){
	if(primerNodo==NULL){
		return NULL;
	}else if(primerNodo == ultimoNodo){
		Nodo * temporal = primerNodo;
		primerNodo = ultimoNodo = NULL;
		return temporal;
	}else{
		Nodo * temporal = primerNodo;
		while(temporal->siguiente->siguiente != NULL){
			temporal = temporal->siguiente;
		}
		ultimoNodo = temporal;
		temporal = temporal->siguiente;
		ultimoNodo->siguiente = NULL;
		return temporal;
	}
}

//DETERMINA EL LARGO DE UNA LISTA
int Lista::largo(){
	int i = 0;
	Nodo * temporal = primerNodo;
	while (temporal!=NULL){
		i++;
		temporal = temporal->siguiente;
	}
	return i;
}

//DETERMINA SI LA PILA ESTA VACIA **
bool Lista::empty(){
     if (primerNodo == NULL){
	 	return true; 
	 }else{
	 	return false;
	 }
         
}


// ENCUENTRA UN NODO EN LA POSICION DETERMINADA DE LA LISTA
Nodo * Lista::encontrarNodo(int posicion){
	Nodo * temporal = primerNodo;
	while(temporal!=NULL){
		if(posicion==1){
			return temporal; 
		}
		temporal = temporal->siguiente;
		posicion--;
	}
};

//BUSCA UN NODO EN ESPECIFICO Y LO IMPRIME
/*Nodo * Lista::buscar(int _id){
	Nodo * temporal = primerNodo;
	while(temporal!=NULL) {
		if(temporal->cliente->id==_id) {
			temporal->cliente->imprimirCliente();
			return temporal; 
		}
		temporal = temporal->siguiente;
	}
	return NULL;
}*/
