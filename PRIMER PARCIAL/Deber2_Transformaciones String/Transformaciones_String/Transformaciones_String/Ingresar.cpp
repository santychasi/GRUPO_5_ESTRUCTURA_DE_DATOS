/*
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* FUNCION PARA INGRESAR UN STRING Y TRANSFORMAR A ENTERO
* NOMBRE: GUALOTUÑA OMAR, CHASILUISA SANTIAGO
* FECHA DE CREACION: 2022/05/12
* FECHA DE MODIFICACION: 2022/05/12
* VERSION 2
* ESTRUCTURA DE DATOS
* NRC: 4683
*/
#include<iostream>
#include<string>
#include<cctype>
#include "Ingresar.h"

using namespace std;

string Ingresar::ingresarEntero(){
	string numero;
	try {
		cout << "Ingrese un numero entero: " << endl;
		getline(cin,numero);
		for (int i = 0; i < numero.length();i++) {
			while (!(isdigit(numero[i]))) {
				cout << "SOLO DEBE INGRESAR UN NUMERO ENTERO !!" << endl;
				cout << "Ingrese nuevamente: " << endl;
				getline(cin,numero);
			}
		}
	}
	catch (const runtime_error& e) {
		cout << e.what();
	}
	return numero;
}

string Ingresar::ingresarFloat() {
	string numero;
	bool band = false;
	try {
		cout << "Ingrese un numero flotante: " << endl;
		getline(cin,numero);
		for (int i = 1; i < numero.size();i++) {
			if (isalpha(numero[i])) {
				do {
					cout<<"SOLO INGRESE NUMEROS DECIMALES!!"<<endl;
					cout << "Ingrese nuevamente: " << endl;
					getline(cin,numero);
					if (!isalpha(numero[i])) {
						band = true;
					}
				} while (band == false);
				if (numero [i-1] == '.') {
					break;
				}
			}
		}
	}
	catch (const runtime_error& e) {
		cout << e.what() << endl;
	}
	return numero;
}

string Ingresar::ingresarChar(){
	string palabra;
	try {
		cout << "Ingrese una palabra: " << endl;
		getline(cin,palabra);
		for (int i = 0; i < palabra.length();i++) {
			while (!(isalpha(palabra[i]))) {
				cout << "SOLO DEBE INGRESAR LETRAS!!" << endl;
				cout << "Ingrese nuevamente: " << endl;
				getline(cin,palabra);
			}
		}
	}
	catch (const runtime_error& e) {
		cout << e.what()<<endl;
	}
	return palabra;
}
