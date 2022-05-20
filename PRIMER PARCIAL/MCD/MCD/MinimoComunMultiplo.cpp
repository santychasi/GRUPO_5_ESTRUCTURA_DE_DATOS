/*
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* FUNCION PARA OBTENER EL MCD Y MCM DE DOS NUMEROS CON RECURSIVIDAD
* NOMBRE: GUALOTUÑA OMAR, CHASILUISA SANTIAGO
* FECHA DE CREACION: 2022/05/19
* FECHA DE MODIFICACION: 2022/05/19
* VERSION 1
* ESTRUCTURA DE DATOS
* NRC: 4683
*/
#include<iostream>
#include "MinimoComunMultiplo.h"
#include "MaximoComunDivisor.h"

MaximoComunDivisor<int> objM;

template <class T>
/**
 * Funcion para obtener el Mínimo Común Múltiplo.
 * 
 * \param a
 * \param b
 * \return (a * b) / objM.mcd(a, b) 
 */
T MinimoComunMultiplo<T>::mcm(T a, T b){
	return (a * b) / objM.mcd(a, b);

}

template class MinimoComunMultiplo<int>;
