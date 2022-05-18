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
#include<iostream>
#include "Suma.h"

int Suma::suma(int n){
	if (n==0) {
		return 0;
	}
	else {
		return n + suma(n-1);
	}
}
