#include <iostream>
using namespace std;

/*
Escribir un programa que calcule el pago de un trabajador independiente con recibo
por honorarios. El trabajador establece el pago por su servicio y se le descuenta el
7.5% por concepto de impuesto sobre la renta. El programa debe pedir el nombre del
trabajador, el pago por el servicio prestado. Como salida debe imprimir el nombre de
trabajador, pago del servicio, el descuento de renta y el salario a pagar y el pago
después del impuesto
*/

int main()
{
    string nombreTrabajador;
    double pagoPorServicio, descuentoRenta, salarioPagar;

    cout << "Ingrese el nombre del trabajador:";
    getline(cin, nombreTrabajador);

    cout << "Ingrese el pago por servicio:";
    cin >> pagoPorServicio;

    descuentoRenta = pagoPorServicio * 0.075;
    salarioPagar = pagoPorServicio - descuentoRenta;

    cout << "\n--- Recibo por honorarios ---\n";
    cout << "Nombre del trabajador: " << nombreTrabajador << endl;
    cout << "Pago del servicio: $" << pagoPorServicio << endl;
    cout << "Descuento de renta (7.5%): $" << descuentoRenta << endl;
    cout << "Salario a pagar: $" << salarioPagar << endl;

    return 0;
}