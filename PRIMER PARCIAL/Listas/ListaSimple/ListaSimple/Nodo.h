#pragma once
#include<iostream>

class Nodo {
	private:
		int Valor;
		Nodo* Siguiente;
	public:
		Nodo(int v, Nodo* sig = NULL) {
			this->Valor = v;
			this->Siguiente = sig;
		}
		friend class Lista;
};

