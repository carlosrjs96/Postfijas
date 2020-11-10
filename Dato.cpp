#include <cstdlib>
#include <iostream>
#include <string> 
#include "Dato.h"

//using namespace std;

void Dato::imprimirDato(){
	if(tipo == "operador") {
		cout<<operador<<" ";
	}else if (tipo == "numero"){
		cout<<numero<<" ";
	}else{
		cout<<" No tiene tipo "<<endl;
	}
	/*
	cout <<"TIPO : "<<tipo<<endl;
	cout <<"OPERADOR : "<<operador<<endl;
	cout <<"NUMERO : "<<numero<<endl;*/
};
