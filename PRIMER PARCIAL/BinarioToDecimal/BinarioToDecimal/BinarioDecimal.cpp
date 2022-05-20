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
#include<iostream>
#include "BinarioDecimal.h" 

template <class T>
/**
 * Funcion para transformar de binario a decimal usando recursividad.
 * 
 * \param bin
 * \return 
 */
T BinarioDecimal<T>::binarioaDecimal(T bin){ 
	if (bin == 0) {
		return bin;
	}
	return (bin%10 + 2*binarioaDecimal(bin/10));
}

template class BinarioDecimal<int>;
