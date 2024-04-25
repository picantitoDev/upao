#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <string>

struct Alumno {
private:
    int ID;
    std::string nombre;
    std::string carrera;
    std::string ciclo;

public:
    // Constructors
    Alumno() : ID(0), nombre(""), carrera(""), ciclo("") {}
    Alumno(int id, std::string nombre, std::string carrera, std::string ciclo) : ID(id), nombre(nombre), carrera(carrera), ciclo(ciclo) {}
    
    // Getters
    int getID() const { return ID; }
    std::string getNombre() const { return nombre; }
    std::string getCarrera() const { return carrera; }
    std::string getCiclo() const { return ciclo; }

    // Setters
    void setID(int id) { ID = id; }
    void setNombre(const std::string& n) { nombre = n; }
    void setCarrera(const std::string& c) { carrera = c; }
    void setCiclo(const std::string& c) { ciclo = c; }
};

#endif