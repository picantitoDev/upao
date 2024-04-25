#ifndef COLA_H
#define COLA_H

#include "alumno.h"

struct Cola {
    static const int MAX_ALUMNOS = 150; 
    Alumno alumnos[MAX_ALUMNOS]; 
    int front; 
    int rear; // 

    Cola(); // Constructor
    void registroAutomatico();
    void registroManual(); 
    void mostrarCola();
    void atenderAlumno(); 
    void buscarPorId();
    void buscarPorNombre();
};

#endif