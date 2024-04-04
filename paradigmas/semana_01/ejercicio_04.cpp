#include <iostream>
using namespace std;

/*
Escribir un programa que dada una medida de tiempo expresada en horas, minutos y
segundos con valores arbitrarios, elabore un programa que transforme dicha medida
en una expresión correcta. Por ejemplo, dada la medida 3h 118m 195s, el programa
deberá obtener como resultado 5h 1m 15s
*/

#include <iostream>
using namespace std;

int main() {
    int horas, minutos, segundos;

    cout << "Ingrese el número de horas: ";
    cin >> horas;

    cout << "Ingrese el número de minutos: ";
    cin >> minutos;
    
    cout << "Ingrese el número de segundos: ";
    cin >> segundos;

    minutos += segundos / 60;  
    segundos %= 60;            

    horas += minutos / 60;    
    minutos %= 60;            

    cout << "Hora Real: ";
    cout << horas << "h ";
    cout << minutos << "m ";
    cout << segundos << "s " << endl;

    return 0;
}