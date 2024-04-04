#include <iostream>
#include <cmath>
using namespace std;

/*
Escriba un programa que permita calcular la energía que libera un objeto de masa m
Kg dejada caer desde una altura de 20 m.
*/
int main() {

    double masa, altura, energia;
    const double GRAVEDAD = 9.81;

    cout << "Ingrese la masa del objeto (en kg): ";
    cin >> masa;

    cout << "Ingrese la altura de caida (en m): ";
    cin >> altura;

    energia = masa * GRAVEDAD * altura;

    cout << "Energia del Objeto: " << energia << " J" << endl;
    return 0;
}