#include <iostream>
#include <cmath>
using namespace std;

/*
Escriba un programa que realice la conversión de cm. a pies y pulgadas.
Donde 1 pie = 30.48 cm y 1 pulgada = 0.0833333.
Por lo tanto, el usuario proporcionará el dato de N cm. y el programa dirá a cuantas
pies y pulgadas es equivalente.
*/
int main() {
    double medidaCm, medidaFt, medidaIn;

    // Solicitar al usuario que ingrese la medida en centímetros
    cout << "Ingrese la medida (en cm): ";
    cin >> medidaCm;

    // Convertir centímetros a pies
    medidaFt = medidaCm / 30.48;

    // Convertir el residuo de pies a pulgadas
    medidaIn = medidaFt / 0.0833333;

    // Mostrar la medida en pies y pulgadas
    cout << "Medida en pies: " << medidaFt << " pies" << endl;
    cout << "Medida en pulgadas: " << medidaIn << " pulgadas" << endl;

    return 0;
}