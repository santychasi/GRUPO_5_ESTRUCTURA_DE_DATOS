/*
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* FUNCION PARA INGRESAR UN STRING Y TRANSFORMAR A ENTERO
* NOMBRE: GUALOTUÑA OMAR, CHASILUISA SANTIAGO
* FECHA DE CREACION: 2022/05/09
* FECHA DE MODIFICACION: 2022/05/09
* VERSION 1
* ESTRUCTURA DE DATOS
* NRC: 4683
*/
#include <iostream>
#include "Ingresar.h"
#include "Transformar.h"
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    string frase,frase2;
    cout << "Digite un numero:" << endl;
    cin >> frase2;
    Ingresar* objIngresar = new Ingresar();
    frase = objIngresar->ingresar(frase2);
    Transformar* objTransformar = new Transformar();
    cout << objTransformar->transformar(frase) << endl;
    /*Ingresar objIngresar;
    frase = objIngresar.ingresar("85");
    Transformar objTransformar;
    cout << objTransformar.transformar(frase) << endl;*/
    return 0;
}
