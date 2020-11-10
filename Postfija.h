#ifndef POSTFIJA_H
#define POSTFIJA_H
#include <cstdlib>
#include <iostream>
#include <string> 
#include "Lista.h"
#include "Pila.h"

using namespace std;

struct Postfija {
    
	//ATRIBUTOS
	//string cadena;
	Pila * pila;
	Lista * listaDatos;
	Lista * inPost;
	
	//CONSTRUCTOR SIN PARAMETROS
	Postfija(){
		//cadena = "";
		pila = new Pila();
		listaDatos = new Lista();
		inPost = new Lista();	
	}
	
	//CONSTRUCTOR RECIBE PARAMETROS PARA CREAR LA ESTRUCTURA DATO
	/*Postfija(string _cadena){
		cadena = _cadena;
		pila = new Pila();
		listaDatos = new Lista();
		inPost = new Lista();
	}*/
	
	Lista * convertirInPost(string cadena);
	Lista * convertirCadena(string cadena);
	int intlength(int numero);
	int armarNumero(int pos,string cadena);
	int evaluarPrioridad(string caracter);
	bool isOperador(string caracter);
	double evaluarPost(Lista * postfija);
	double getResultado(string caracter,int numero1,int numero2);
};
#endif
