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
#include "Factorial.h"

int Factorial::factorial(int n){
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n-1);
	}
}
