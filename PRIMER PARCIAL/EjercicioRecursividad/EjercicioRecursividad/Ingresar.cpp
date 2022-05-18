/*
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* RECURSIVIDAD CON CLASES
* NOMBRE: GUALOTUÑA OMAR, CHASILUISA SANTIAGO
* FECHA DE CREACION: 2022/05/16
* FECHA DE MODIFICACION: 2022/05/16
* VERSION 1
* ESTRUCTURA DE DATOS
* NRC: 4683
*/
#include<iostream>
#include<string>
#include "Ingresar.h"

string Ingresar::ingresarEntero(){
	string numero;
	try {
		cout << "Ingrese un numero entero: " << endl;
		getline(cin, numero);
		for (int i = 0; i < numero.length(); i++) {
			while (!(isdigit(numero[i]))) {
				cout << "SOLO DEBE INGRESAR UN NUMERO ENTERO !!" << endl;
				cout << "Ingrese nuevamente: " << endl;
				getline(cin, numero);
			}
		}
	}
	catch (const runtime_error& e) {
		cout << e.what();
	}
	return numero;

}
