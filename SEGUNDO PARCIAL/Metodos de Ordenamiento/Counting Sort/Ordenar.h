#ifndef ORDENAR_H
#define ORDENAR_H
#pragma once

#include<iostream>

using namespace std;

class Ordenar{
	public:
		void mostrar(int*,int);
		int obtenerMaximo(int [],int);
		void countingSort(int*,int);
		char* validarEntero(const char*);
};
#endif
