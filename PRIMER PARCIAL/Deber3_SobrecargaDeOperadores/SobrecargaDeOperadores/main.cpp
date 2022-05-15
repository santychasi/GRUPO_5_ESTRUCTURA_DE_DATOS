#include <iostream>
#include "Complejo.h"

using namespace std;

int main(){
    Complejo c1(8,25),c2(7,12);
    Complejo c3;
    c3 = c1-c2;

    cout << "La parte real del resultado es: "<<c3.getR() << " Y la parte iamginaria es: " << c3.getI()<<"i\n\n";

    if (c1 == c2) {
        cout << "Son iguales\n";
    }else{
        cout << "Son diferentes\n";
    }

    cin.get();
    return 0;
}
