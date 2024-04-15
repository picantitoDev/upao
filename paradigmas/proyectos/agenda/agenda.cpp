#include <iostream>
#include <algorithm> 
#include <cstdlib>   
#include <ctime>     
#include <string>

template <typename T, typename U, typename V, typename W>
struct Contacto
{
    T nombre;
    U direccion;
    V numeroDeTelefono;
    W fechaDeNacimiento;

    bool operator==(const Contacto<T, U, V, W> &contacto) const
    {
        return nombre == contacto.nombre &&
               direccion == contacto.direccion &&
               numeroDeTelefono == contacto.numeroDeTelefono &&
               fechaDeNacimiento == contacto.fechaDeNacimiento;
    }
};

template <typename T, typename U, typename V, typename W, int maxSize>
class Agenda
{
private:
    Contacto<T, U, V, W> agenda[maxSize];
    int pos = 0;

public:
    void agregarContacto(const Contacto<T, U, V, W> &contacto)
    {
        if (pos >= maxSize)
        {
            std::cout << "La agenda está llena!" << std::endl;
            return;
        }

        agenda[pos++] = contacto;
        std::cout << "Se ha registrado a " << contacto.nombre << " correctamente!" << std::endl;
    }

    void borrarContacto(const Contacto<T, U, V, W> &contacto)
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

    void buscarContacto(const Contacto<T, U, V, W> &contacto)
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

    template <typename Compare>
    void ordenarContactos(Compare comp)
    {
        for (int i = 0; i < pos - 1; ++i)
        {
            for (int j = 0; j < pos - i - 1; ++j)
            {
                if (comp(agenda[j], agenda[j + 1]) == false)
                {
                    std::swap(agenda[j], agenda[j + 1]);
                }
            }
        }
    }

    void desordenarContactos()
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        std::random_shuffle(std::begin(agenda), std::begin(agenda) + pos);
    }

    void buscarContactosPorNombre(const std::string &cadenaBusqueda, int inicio, int fin, std::vector<Contacto<T, U, V, W>> &resultados) const {
        if (inicio > fin) {
            return;
        }

        int medio = inicio + (fin - inicio) / 2;

        // Si el nombre del contacto en la posición media coincide con la cadena de búsqueda, lo agregamos a los resultados
        if (agenda[medio].nombre == cadenaBusqueda) {
            resultados.push_back(agenda[medio]);
        }

        // Buscamos en la mitad izquierda del arreglo si el nombre de la cadena de búsqueda es menor que el nombre del contacto en la posición media
        buscarContactosPorNombre(cadenaBusqueda, inicio, medio - 1, resultados);

        // Buscamos en la mitad derecha del arreglo si el nombre de la cadena de búsqueda es mayor que el nombre del contacto en la posición media
        buscarContactosPorNombre(cadenaBusqueda, medio + 1, fin, resultados);
    }

    // Función pública para buscar contactos por nombre
    std::vector<Contacto<T, U, V, W>> buscarContactosPorNombre(const std::string &cadenaBusqueda) const {
        std::vector<Contacto<T, U, V, W>> resultados;
        buscarContactosPorNombre(cadenaBusqueda, 0, pos - 1, resultados);
        return resultados;
    }

    void mostrarContactos() const
    {
        for (int i = 0; i < pos; ++i)
        {
            std::cout << "Nombre: " << agenda[i].nombre << ", Dirección: " << agenda[i].direccion
                      << ", Teléfono: " << agenda[i].numeroDeTelefono << ", Fecha de Nacimiento: " << agenda[i].fechaDeNacimiento << std::endl;
        }
    }


};

int main() {

}