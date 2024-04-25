#include <iostream>
#include "cola.h"

int main()
{
    Cola cola;

    // Registro automático de alumnos
    cola.registroAutomatico();

    // Mostrar la cola antes de atender alumnos
    std::cout << "Mostrando la cola antes de atender alumnos:" << std::endl;
    cola.mostrarCola();

    // Atender a algunos alumnos
    cola.atenderAlumno();

    // Mostrar la cola después de atender alumnos
    std::cout << "Mostrando la cola después de atender alumnos:" << std::endl;
    cola.mostrarCola();

    // Registro manual de Alumno
    cola.registroManual();
    cola.mostrarCola();

    // Buscar por ID 
    cola.buscarPorId();

    // Buscar por Nombre
    cola.buscarPorNombre();
    
    return 0;
}