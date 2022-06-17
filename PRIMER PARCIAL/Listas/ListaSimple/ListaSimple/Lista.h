#pragma once
#include <iostream>
#include "Nodo.h"

using namespace std;
class Lista {
	private:
		Nodo* primero;
		Nodo* actual;
		bool ListaVacia() {
			return (this->primero == NULL);
		}
	public:
		Lista() {
			this->primero = NULL;
			this->actual = NULL;
		}

		void Insertar(int v) {
			Nodo* nuevo = new Nodo(v);
			if (ListaVacia()) {
				this->primero = nuevo;
			}
			else {
				this->actual->Siguiente = nuevo;
			}
			this->actual = nuevo;
		}

		void Mostrar() {
			Nodo* tmp = this->primero;
			while (tmp) {
				cout << tmp->Valor << "-->";
				tmp = tmp->Siguiente;
			}
			cout << "NULL\n";
		}
};



