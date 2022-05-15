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
#include <iostream>
#include<string>
#include "Ingresar.h"
#include "Transformar.h"

using namespace std;

int main(){
	
	string frase,fra;
	int n = 0;

	Ingresar objIngresar;
	Transformar objTransformar;

	frase = objIngresar.ingresarChar();
	cout << objTransformar.transformarInt(frase);

	/*cout << "*****MENU*****" << endl;
	cout << "1. String a entero" << endl;
	cout << "2. String a flotante" << endl;
	cout << "3. String a char" << endl;
	cout << "DIGITE UNA OPCION" << endl;
	cin >> n;

	switch (n) {
	case 1:
		fflush(stdin);
		frase = objIngresar.ingresarEntero();
		cout << "Numero transformado a entero: " << endl;
		objTransformar.transformarInt(frase);
		break;
	default:
		cout << "Opciones incorrectas..." << endl;
	}*/

}
