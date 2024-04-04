#include <iostream>
#include <cmath>
using namespace std;

/*
Escriba un programa que calcule la hipotenusa de un triángulo rectángulo, dada los
catetos.
*/

int main() {
    double catetoOpuesto, catetoAdyacente, hipotenusa;

    cout << "Ingrese el Cateto Opuesto: ";
    cin >> catetoOpuesto;

    cout << "Ingrese el Cateto Adyacente: ";
    cin >> catetoAdyacente;

    hipotenusa = hypot(catetoOpuesto, catetoAdyacente);

    cout << "Hipotenusa: " << hipotenusa << endl;

    return 0;
}