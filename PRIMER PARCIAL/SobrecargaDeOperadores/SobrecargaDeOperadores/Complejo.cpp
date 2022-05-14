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


