#include <iostream>
using namespace std;

/*
Escribir un programa que pida el precio de un artículo y calcule su valor aplicándole
un 18% de IGV. El programa debe mostrar el precio del producto, el monto del IGV
y el total a pagar
*/

int main() {
    double precio, montoIGV, total;
    const double IGV = 0.18;

    cout << "Ingrese el precio del producto: ";
    cin >> precio;

    montoIGV = precio * IGV;
    total = precio + montoIGV;

    // Formato para la salida
    cout << "----- Factura -----" << endl;
    cout << "Precio del producto: $" << precio << endl;
    cout << "Monto de IGV: $" << montoIGV << endl;
    cout << "Total a pagar: $" << total << endl;

    return 0;
}