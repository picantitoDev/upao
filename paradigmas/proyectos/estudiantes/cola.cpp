#include <iostream>
#include "cola.h"
#include <limits>

Cola::Cola() : front(0), rear(0) {}

void Cola::registroAutomatico()
{
    for (int i = 0; i < 100; ++i)
    {
        int id = 10000 + rand() % 10001;
        std::string nombre = "Alumno " + std::to_string(i + 1);
        std::string carrera = "Carrera " + std::to_string(rand() % 5 + 1);
        std::string ciclo = "Ciclo" + std::to_string(rand() % 10 + 1);

        if (rear == MAX_ALUMNOS)
        {
            std::cout << "La cola está llena. No se pueden agregar más alumnos." << std::endl;
            return;
        }

        alumnos[rear].setID(id);
        alumnos[rear].setNombre(nombre);
        alumnos[rear].setCarrera(carrera);
        alumnos[rear].setCiclo(ciclo);
        rear++;
    }
}

void Cola::registroManual()
{
    if (rear == MAX_ALUMNOS)
    {
        std::cout << "La cola está llena. No se pueden agregar más alumnos." << std::endl;
        return;
    }

    int id;
    std::string nombre, carrera, ciclo;

    std::cout << "Ingrese el ID del alumno: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ingrese el nombre del alumno: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese la carrera del alumno: ";
    std::getline(std::cin, carrera);

    std::cout << "Ingrese el ciclo del alumno: ";
    std::getline(std::cin, ciclo);

    alumnos[rear].setID(id);
    alumnos[rear].setNombre(nombre);
    alumnos[rear].setCarrera(carrera);
    alumnos[rear].setCiclo(ciclo);
    rear++;
}

void Cola::buscarPorId()
{
    bool found = false;

    int id;
    std::cout << "Ingrese el ID del alumno: ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = front; i < rear; ++i)
    {
        if (alumnos[i].getID() == id)
        {
            std::cout << "Alumno encontrado:" << std::endl;
            std::cout << "ID: " << alumnos[i].getID() << std::endl;
            std::cout << "Nombre: " << alumnos[i].getNombre() << std::endl;
            std::cout << "Carrera: " << alumnos[i].getCarrera() << std::endl;
            std::cout << "Ciclo: " << alumnos[i].getCiclo() << std::endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Alumno con ID " << id << " no encontrado." << std::endl;
    }
    std::cout << std::endl;
}

void Cola::buscarPorNombre()
{
    bool found = false;
    std::string nombre;
    std::cout << "Ingrese el nombre del alumno: ";
    std::getline(std::cin, nombre);

    for (int i = front; i < rear; ++i)
    {
        if (alumnos[i].getNombre() == nombre)
        {
            std::cout << "Alumno encontrado:" << std::endl;
            std::cout << "ID: " << alumnos[i].getID() << std::endl;
            std::cout << "Nombre: " << alumnos[i].getNombre() << std::endl;
            std::cout << "Carrera: " << alumnos[i].getCarrera() << std::endl;
            std::cout << "Ciclo: " << alumnos[i].getCiclo() << std::endl;
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "Alumno con nombre \"" << nombre << "\" no encontrado." << std::endl;
    }
    std::cout << std::endl;
}

void Cola::mostrarCola()
{
    if (front == rear)
    {
        std::cout << "La cola está vacía!" << std::endl;
    }
    else
    {
        std::cout << "Cola de alumnos:" << std::endl;
        for (int i = front; i < rear; ++i)
        {
            std::cout << "ID: " << alumnos[i].getID() << ", Nombre: " << alumnos[i].getNombre() << std::endl;
        }
    }

    std::cout << std::endl;
}

void Cola::atenderAlumno()
{
    if (front == rear)
    {
        std::cout << "La cola está vacía!" << std::endl;
    }
    else
    {
        std::cout << "Atendiendo al alumno en el frente de la cola." << std::endl;
        std::cout << "ALUMNO: " << alumnos[front].getNombre() << " ID: " << alumnos[front].getID() << " ATENDIDO" << std::endl;

        for (int i = 0; i < rear - 1; ++i)
        {
            alumnos[i] = alumnos[i + 1];
        }
        rear--;
    }
}