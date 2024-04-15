#include <iostream>
#include <string>

// Definimos nuestra estructura de datos para representar un contacto
template <typename T>
struct Contacto
{
    T nombre;
    T direccion;
    T numeroDeTelefono;
    T fechaDeNacimiento;

    bool operator==(const Contacto<T> &other) const
    {
        return nombre == other.nombre &&
               direccion == other.direccion &&
               numeroDeTelefono == other.numeroDeTelefono &&
               fechaDeNacimiento == other.fechaDeNacimiento;
    }
};

template <typename T, int maxSize>
class Agenda
{
private:
    Contacto<T> agenda[maxSize];
    int pos = 0;

public:
    void agregarContacto(const Contacto<T> &contacto)
    {
        if (pos >= maxSize)
        {
            std::cout << "La agenda está llena!" << std::endl;
            return;
        }

        agenda[pos++] = contacto;
        std::cout << "Se ha registrado a " << contacto.nombre << " correctamente!" << std::endl;
    }

    void borrarContacto(const Contacto<T> &contacto)
    {
        int index = -1;

        for (int i = 0; i < pos; i++)
        {
            if (agenda[i] == contacto)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            for (int i = index; i < pos - 1; i++)
            {
                agenda[i] = agenda[i + 1];
            }
            pos--;
            std::cout << "Se ha eliminado a " << contacto.nombre << " correctamente." << std::endl;
        }
        else
        {
            std::cout << "No se ha encontrado el contacto en la agenda." << std::endl;
        }
    }

    void buscarContacto(const Contacto<T> &contacto)
    {
        bool found = false;

        for (int i = 0; i < pos; i++)
        {
            if (agenda[i] == contacto)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            std::cout << contacto.nombre << " encontrado en la agenda." << std::endl;
        }
        else
        {
            std::cout << "No se ha encontrado el contacto en la agenda." << std::endl;
        }
    }
};

int main(void)
{
    const int maxSize = 5;
    Agenda<std::string, maxSize> miAgenda;

    Contacto<std::string> contacto1 = {"Juan", "Calle A", "123456", "01/01/1990"};
    Contacto<std::string> contacto2 = {"María", "Calle B", "654321", "02/02/1995"};
    Contacto<std::string> contacto3 = {"Pedro", "Calle C", "987654", "03/03/1985"};

    miAgenda.agregarContacto(contacto1);
    miAgenda.agregarContacto(contacto2);
    miAgenda.agregarContacto(contacto3);

    Contacto<std::string> contactoNoHabido = {"Lolo", "asd", "Asd", "Asd"};
    miAgenda.buscarContacto(contactoNoHabido);
}