/*
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* RECURSIVIDAD CON CLASES
* NOMBRE: GUALOTUÑA OMAR, CHASILUISA SANTIAGO
* FECHA DE CREACION: 2022/05/16
* FECHA DE MODIFICACION: 2022/05/16
* VERSION 1
* ESTRUCTURA DE DATOS
* NRC: 4683
*/
#include <iostream>
#include "Suma.h"
#include "Factorial.h"
#include "Ingresar.h"
#include "Transformar.h"

using namespace std;

int main(){
	
	string num;
	int n;
	Ingresar objIngresar;
	Transformar objTransformar;
	Suma objSuma;
	Factorial objFactorial;

	num = objIngresar.ingresarEntero();
	n = objTransformar.transformarInt(num);

	for (int i = 1; i <= n;i++) {
		cout << "SUMA: " << objSuma.suma(i)<<"	";
		cout << "FACTORIAL: " << objFactorial.factorial(i)<<endl;
	}
}

