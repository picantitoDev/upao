#include <iostream>
using namespace std;

/*
Escribir un programa que permita leer el sueldo de tres empleados y aplicarles un
aumento del 10, 12 y 15% respectivamente. Mostrar el sueldo base de cada empleado
con su respectivo aumento.
*/

int main()
{
    // Definir los porcentajes de aumento para cada empleado
    double aumentoPrimerEmpleado = 0.10;
    double aumentoSegundoEmpleado = 0.12;
    double aumentoTercerEmpleado = 0.15;

    // Variables para almacenar los sueldos de los empleados
    double primerSueldo, segundoSueldo, tercerSueldo;

    // Solicitar al usuario que ingrese los sueldos de los tres empleados
    cout << "Ingrese el sueldo de tres empleados: ";
    cin >> primerSueldo >> segundoSueldo >> tercerSueldo;

    // Aplicar aumentos a los sueldos de los empleados
    primerSueldo *= (1 + aumentoPrimerEmpleado);
    segundoSueldo *= (1 + aumentoSegundoEmpleado);
    tercerSueldo *= (1 + aumentoTercerEmpleado);

    // Mostrar los sueldos base de cada empleado con su respectivo aumento
    cout << "Primer Sueldo: " << primerSueldo << endl;
    cout << "Segundo Sueldo: " << segundoSueldo << endl;
    cout << "Tercer Sueldo: " << tercerSueldo << endl;

    return 0;
}