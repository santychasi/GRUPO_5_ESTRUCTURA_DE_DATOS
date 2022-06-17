#include <iostream>
#include "Lista.h"

using namespace std;


int main(){

	int n = 0;

	Lista lst;
	
	cout << "Digite el numero de elementos que tendra la lista: " << endl;
	cin >> n;

	for (int i = 1; i <= n;i++) {
		cout << "Digite el elemento en la posicion [" << i << "]" << endl;
		lst.Insertar(i);
	}

	lst.Insertar(1);
	lst.Insertar(3);
	lst.Insertar(100);
	lst.Insertar(5);
	lst.Insertar(6);
	lst.Mostrar();
	return 0;

}

