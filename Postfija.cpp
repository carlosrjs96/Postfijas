#include <cstdlib>
#include <iostream>
#include <string> 
#include "Postfija.h"
#include <math.h>

//using namespace std;

Lista * Postfija::convertirInPost(string cadena){//************************************
	listaDatos = convertirCadena(cadena);
	int largo = listaDatos->largo();
	//cout<< "tamano: " <<largo<<"  "<<endl ;
	string tipoDato;
	string operadorDato;
	int intDato;
	for(int i = 1 ; i < largo+1; i++ ) {
		
		tipoDato = listaDatos->encontrarNodo(i)->dato->tipo;  
		operadorDato = listaDatos->encontrarNodo(i)->dato->operador;
		intDato = listaDatos->encontrarNodo(i)->dato->numero;
		
		/*cout<< "tipo de Dato: " <<tipoDato<<" << "<<endl;
		cout<< "operador: " <<operadorDato<<" << "<<endl;
		cout<< "numero: " <<intDato<<" << "<<endl;*/
		
		if( tipoDato == "operador"){
			if(operadorDato == "("){
				pila->push(listaDatos->encontrarNodo(i)->dato);	
			}else if (operadorDato == ")"){
				while(pila->peek()->dato->operador != "("){
					inPost->insertarAlFinal(pila->pop()->dato);	
				}	
				pila->pop()->dato;
			}else if (operadorDato == "^" ||operadorDato == "*" ||operadorDato == "/"||operadorDato == "+"||operadorDato == "-"){
				if(pila->empty() || evaluarPrioridad(operadorDato) > evaluarPrioridad(pila->peek()->dato->operador)){
					pila->push(listaDatos->encontrarNodo(i)->dato);
				}else{//revisar
					inPost->insertarAlFinal(pila->pop()->dato);
					i--;
				}		
			}
		}else{
			inPost->insertarAlFinal(listaDatos->encontrarNodo(i)->dato);
		}
	}
	
	while(!pila->empty()){
		inPost->insertarAlFinal(pila->pop()->dato);
	}
	
	//cout<<"<<<<<IMPRIMIENDO PILA>>>>>>>>>"<<endl;
	//pila->imprimirPila();
	cout<<"<<<<<LISTA POSTFIJA>>>>>>>>"<<endl;
	inPost->imprimirLista();
	return inPost;	
};

Lista * Postfija::convertirCadena(string cadena){
	cout<<"CONVIRTIENDO EN LISTA"<<endl;
	for(int i = 0; i < cadena.length() ;i++){
		string dato (1,cadena[i]);
		if (isdigit(cadena[i])){
			int numeroArmado = armarNumero(i,cadena);  
			i = i + intlength(numeroArmado)-1;   		
    		//cout<<" es numero armado:"<<numeroArmado<<endl;
			listaDatos->insertarAlFinal(new Dato("numero","none",numeroArmado));
  		}else if(isOperador(dato)){
		  	//cout<<" es operador :"<<dato<<endl; 
			listaDatos->insertarAlFinal(new Dato("operador",dato,0));
		}else if(isalpha(cadena[i]) || dato == " "){
  			//cout<<" Es una letra o espacio : "<<cadena[i]<<endl;
		}else{	
			//cout<<" Valor Invalido "<<endl;		
		}	
		//cout<<" posicion :"<<i<<endl;
	}
	listaDatos->imprimirLista();
	return listaDatos;
}

int Postfija::intlength(int numero){
	int len = 1;
	if (numero > 0) {
    	for(len = 0;  numero> 0; len++) {
    	    numero = numero / 10;
    	}
	}
	return len;
};


int Postfija::armarNumero(int pos,string cadena){
	//int numero = cadena[pos] - '0';
	string dato (1,cadena[pos]);
	int numero = stoi(dato);
	while(isdigit(cadena[pos+1])){
		int numeroSig = cadena[pos+1] - '0';
		numero = (numero * 10) + numeroSig;
		pos++;
		//cout<<" **posicion :"<<pos<<endl;
		//cout<<" **numero :"<<numero<<endl;
	}
	return numero;
}

int Postfija::evaluarPrioridad(string caracter){
	if(caracter == "^") {
		return 20;
	}else if(caracter == "*") {
		return 10;
	}else if(caracter == "/") {
		return 10;
	}else if(caracter == "+") {
		return 5;
	}else if(caracter == "-") {
		return 5;
	}else if(caracter == "(") {
		return 1;
	}else if(caracter == ")") {
		return 1;
	}else{
		return 0;
	}
};

bool Postfija::isOperador(string caracter){
	if(caracter == "^" ||caracter == "*" ||caracter == "/"||caracter == "+"||caracter == "-"||caracter == "("||caracter == ")") {
		return true;
	}else{
		return false;
	}
};

double Postfija::evaluarPost(Lista * listpostfija){
	int largo = listpostfija->largo();
	//cout<< "tamano: " <<largo<<"  "<<endl ;
	string tipoDato;
	string operadorDato;
	int intDato;
	double resultado;
	int numero1;
	int numero2;
	for(int i = 1 ; i < largo+1; i++ ) {
		tipoDato = listpostfija->encontrarNodo(i)->dato->tipo;  
		operadorDato = listpostfija->encontrarNodo(i)->dato->operador;
		intDato = listpostfija->encontrarNodo(i)->dato->numero;
		if(tipoDato == "numero"){
			pila->push(listpostfija->encontrarNodo(i)->dato);
		}else{
			int numero2 = pila->pop()->dato->numero;
			//cout<< "numero1: " <<numero2<<"  "<<endl ;
			int numero1 = pila->pop()->dato->numero;
			//cout<< "numero2: " <<numero1<<"  "<<endl ;
			//cout<< "operador: " <<operadorDato<<"  "<<endl ;
			resultado = getResultado(operadorDato,numero1,numero2);
			//cout<<"El resultado es :"<<resultado<<endl;
			pila->push(new Dato("numero","none",resultado));
		}
		//pila->imprimirPila();
	}
	cout<<"<<<<<EVALUCACION DEL RESULTADO>>>>>"<<endl;
	//cout<<resultado;
	return resultado;
};

double Postfija::getResultado(string caracter,int numero1,int numero2){
	if(caracter == "^") {
		return pow(numero1, numero2) ;
	}else if(caracter == "*") {
		return numero1 * numero2;
	}else if(caracter == "/") {
		return numero1 / numero2;
	}else if(caracter == "+") {
		return numero1 + numero2;
	}else if(caracter == "-") {
		return numero1 - numero2;
	}else{
		return 0;
	}
	
}



