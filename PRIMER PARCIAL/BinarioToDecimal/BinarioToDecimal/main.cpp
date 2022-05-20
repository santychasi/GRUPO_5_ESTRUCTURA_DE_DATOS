/*
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* FUNCION PARA TRANSFORMAR DE BIIARIO A DECIMAL
* NOMBRE: GUALOTUÑA OMAR, CHASILUISA SANTIAGO
* FECHA DE CREACION: 2022/05/19
* FECHA DE MODIFICACION: 2022/05/19
* VERSION 1
* ESTRUCTURA DE DATOS
* NRC: 4683
*/
#include <iostream>
#include "BinarioDecimal.h"

using namespace std;

int main(){

    BinarioDecimal<int> objBin;

    long long int bin;

    cout << "Ingrese un numero binario: " << endl;
    cin >> bin;

    cout << "Numero en decimal -> " << objBin.binarioaDecimal(bin) << endl;

    system("pause");
    return 0;
}
