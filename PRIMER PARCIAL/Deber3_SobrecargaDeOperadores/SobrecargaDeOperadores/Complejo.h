#pragma once
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
#include<conio.h>

class Complejo {
	private:
		int real, imag;
	public:
		Complejo(int _real, int _imag) {
			real = _real;
			imag = _imag;
		}

		Complejo() {
			real = imag = 0;
		}
		
		void setR(int valorR);
		void setI(int valorI);
		int getR();
		int getI();

		Complejo operator-(Complejo num);
		bool operator==(Complejo num2);
};