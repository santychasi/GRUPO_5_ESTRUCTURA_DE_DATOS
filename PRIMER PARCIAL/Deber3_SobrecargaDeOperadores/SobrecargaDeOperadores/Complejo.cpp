/*
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* SOBRECARGAR LOS OPERADORES "-" e "=="
* NOMBRE: GUALOTUÑA OMAR, CHASILUISA SANTIAGO
* FECHA DE CREACION: 2022/05/14
* FECHA DE MODIFICACION: 2022/05/14
* VERSION 1
* ESTRUCTURA DE DATOS
* NRC: 4683
*/


#include<iostream>
#include "Complejo.h"

Complejo Complejo::operator-(Complejo num) {
	int realN = real - num.real;
	int imagN = imag - num.imag;
	Complejo nuevo(realN, imagN);
	return nuevo;
}

bool Complejo::operator==(Complejo num2) {
	if (real == num2.real && imag == num2.imag) {
		return true;
	}else{
		return false;
	}
}

void Complejo::setR(int valorR) {
	real = valorR;
}

void Complejo::setI(int valorI) {
	imag = valorI;
}

int Complejo::getR() {
	return real;
}

int Complejo::getI() {
	return imag;
}


