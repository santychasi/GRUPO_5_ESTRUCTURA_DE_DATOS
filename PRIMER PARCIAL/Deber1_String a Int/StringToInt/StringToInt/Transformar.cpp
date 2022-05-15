/*
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* FUNCION PARA INGRESAR UN STRING Y TRANSFORMAR A ENTERO
* NOMBRE: GUALOTUÑA OMAR, CHASILUISA SANTIAGO
* FECHA DE CREACION: 2022/05/09
* FECHA DE MODIFICACION: 2022/05/09
* VERSION 1
* ESTRUCTURA DE DATOS
* NRC: 4683
*/

#include<iostream>
#include<string>
#include "Transformar.h"

using namespace std;

int Transformar::transformar(string frase) {
	int num;
	num = stoi(frase);
	return num;
}
