#include <iostream>
#include "Ordenar.h"
#include <algorithm>
#include <conio.h>

void Ordenar::mostrar(int *arr, int tam) {
   for(int i = 1; i <= tam; i++)
      cout << arr[i] << " ";
   cout << endl;
}

int Ordenar::obtenerMaximo(int arr[], int tam) {
   int max = arr[1];
   for(int i = 2; i<=tam; i++) {
      if(arr[i] > max)
         max = arr[i];
   }
   return max; //el numero maximo del arreglo
}

void Ordenar::countingSort(int *arr, int tam) {
   int salida[tam + 1];
   int max = obtenerMaximo(arr, tam);
   int contador[max+1];     
   for(int i = 0; i<=max; i++)
      contador[i] = 0;     
   for(int i = 1; i <= tam; i++)
      contador[arr[i]]++;     
   for(int i = 1; i<=max; i++)
      contador[i] += contador[i-1];     
   for(int i = tam; i>=1; i--) {
      salida[contador[arr[i]]] = arr[i];
      contador[arr[i]] -= 1; 
   }
   for(int i = 1; i <= tam; i++) {
      arr[i] = salida[i]; 
   }
}

char* Ordenar::validarEntero(const char* msg)
{
	char *dato  = new char[10];//asignar memoria
	char c;
	int i = 0;
	printf("%s\n", msg);
	while ((c = getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			dato[i++] = c;
		}
	}
	dato[i] = '\0';
	return dato;
}
