#include <cstdlib>
#include <iostream>
#include <string>        
#include "Postfija.h"  


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <iostream>

int main(int argc, char * argv[])
{
    Postfija * eje1 = new Postfija();
	double resultado = eje1->evaluarPost(eje1->convertirInPost("6*(5 + 2)^2/2*(3-1)"));//"1+3*5+10"
	cout<<resultado;
	return 0;
}

	



