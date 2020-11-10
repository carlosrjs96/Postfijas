#ifndef DATO_H
#define DATO_H

#include <cstdlib>
#include <iostream>
#include <string> 

using namespace std;

struct Dato{
	
	//ATRIBUTOS
	string tipo;
	string operador;
	int numero;
	
	//CONSTRUCTOR SIN PARAMETROS
	Dato(){
		tipo = "";		
		operador = "";	
		numero = 0;
	}
	
	//CONSTRUCTOR RECIBE PARAMETROS PARA CREAR LA ESTRUCTURA DATO
	Dato(string _tipo,string _operador,int _numero){
		tipo = _tipo;		
		operador = _operador;	
		numero = _numero;
	}
	
	//METODOS
	void imprimirDato();
	
};
#endif
