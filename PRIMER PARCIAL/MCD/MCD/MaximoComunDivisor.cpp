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
#include "MaximoComunDivisor.h"}

template <class T>
/**
 * Funcion para obtener el Máximo Común Divisor.
 * 
 * \param a
 * \param b
 * \return mcd(b % a,a)
 */
T MaximoComunDivisor<T>::mcd(T a, T b){
	if (a == 0) {
		return b;
	}
	return mcd(b % a,a);
}

template class MaximoComunDivisor <int>;
