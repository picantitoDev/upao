#include <iostream>
#include <cmath>
using namespace std;

/*
Escribir un programa que permita calcular el promedio que obtendrás en el curso
teniendo en cuenta que las calificación final se calcula de la siguiente manera:
PF=0.25EVP + 0.2 EP1 + 0.30EVF + 0.25EP2.
*/
int main()
{

    double primerComponente, evaluacionParcial, segundoComponente, evaluacionFinal, promedioFinal;

    cout << "Nota del Primer Componente: ";
    cin >> primerComponente;

    cout << "Nota de Evaluacion Parcial: ";
    cin >> evaluacionParcial;

    cout << "Nota del Segundo Componente: ";
    cin >> segundoComponente;

    cout << "Nota de Evaluacion Final: ";
    cin >> evaluacionFinal;

    promedioFinal = (primerComponente * 0.25) +
                    (evaluacionParcial * 0.20) +
                    (segundoComponente * 0.30) +
                    (evaluacionFinal * 0.25);

    cout << "Promedio Final del Curso: " << promedioFinal << endl;
    return 0;
}