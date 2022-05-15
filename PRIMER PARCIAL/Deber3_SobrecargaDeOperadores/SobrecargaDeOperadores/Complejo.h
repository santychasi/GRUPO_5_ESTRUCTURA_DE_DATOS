#pragma once

#include<iostream>
#include<conio.h>

class Complejo {
	private:
		int real,imag;
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
