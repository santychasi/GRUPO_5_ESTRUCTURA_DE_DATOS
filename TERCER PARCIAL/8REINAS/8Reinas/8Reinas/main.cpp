#include <iostream>
#include<fstream>
#include "Reina.h"
using namespace std;

int main(){
	int n;
	cout << "\tIngrese el numero de Reinas" << endl;
	cin >> n;
	Reina* obj = new Reina(n);
	obj->solucionReinas();
	cout << "Se creo el archivo txt" << endl;
	
	system("PAUSE");
	return 0;
}

