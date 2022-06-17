#pragma once
#include<iostream>
#include "Nodo.h"

typedef Nodo* nodo;

class Pila {
	private:
		nodo cima;
	public:
        Pila();
        bool PilaVacia();
        void Apilar(int);
        void Cima();
        int Desapilar();
        void MostrarPila();
};

