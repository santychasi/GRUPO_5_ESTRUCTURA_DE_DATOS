#pragma once
#include<iostream>
#include "Nodo.h"

typedef Nodo* nodo;

class Pila {
	private:
		nodo cima;
	public:
        Pila(void);
        bool PilaVacia();
        void Apilar(int);
        void Cima();
        int Desapilar();
        void MostrarPila();
};

