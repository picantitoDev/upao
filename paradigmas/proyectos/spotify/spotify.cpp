#include <iostream>
#include <cstdlib>

template <typename T, int maxSize>
struct Playlist
{
    T canciones[maxSize];
    int pos;

    Playlist() : pos(0) {}

    void agregarCancion(T cancion)
    {
        if (pos < maxSize)
        {
            canciones[pos++] = cancion;
        }
        else
        {
            std::cout << "Error: La lista de reproduccion esta llena." << std::endl;
        }
    }

    void imprimirLista()
    {
        for (int i = 0; i < pos; ++i)
        {
            std::cout << canciones[i] << std::endl;
        }
    }

    void desordenarLista()
    {
        for (int i = pos - 1; i > 0; --i)
        {
            int j = rand() % (i + 1);
            std::swap(canciones[i], canciones[j]);
        }
    }

    void burbuja()
    {
        for (int i = 0; i < pos - 1; ++i)
        {
            for (int j = 0; j < pos - i - 1; ++j)
            {
                if (canciones[j] > canciones[j + 1])
                {
                    std::swap(canciones[j], canciones[j + 1]);
                }
            }
        }
    }

    void seleccion()
    {
        for (int i = 0; i < pos - 1; ++i)
        {
            int minIndex = i;
            for (int j = i + 1; j < pos; ++j)
            {
                if (canciones[j] < canciones[minIndex])
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                std::swap(canciones[i], canciones[minIndex]);
            }
        }
    }

    void insercion()
    {
        for (int i = 1; i < pos; ++i)
        {
            T key = canciones[i];
            int j = i - 1;
            while (j >= 0 && canciones[j] > key)
            {
                canciones[j + 1] = canciones[j];
                j--;
            }
            canciones[j + 1] = key;
        }
    }

    void intercambio()
    {
        for (int i = 0; i < pos - 1; ++i)
        {
            for (int j = i + 1; j < pos; ++j)
            {
                if (canciones[j] < canciones[i])
                {
                    std::swap(canciones[i], canciones[j]);
                }
            }
        }
    }

    void busqueda(std::string cadena, int index = 0)
    {
        if (index >= pos)
        {
            return;
        }

        if (canciones[index].find(cadena) != std::string::npos)
        {
            std::cout << canciones[index] << std::endl;
        }

        busqueda(cadena, ++index);
    }
};

int main(void)
{
    const int maxSize = 10;                    // Tamaño máximo de la lista de reproducción
    Playlist<std::string, maxSize> myPlaylist; // Crear una lista de reproducción de canciones

    // Canciones
    myPlaylist.agregarCancion("Arctic Monkeys - Do I Wanna Know?");
    myPlaylist.agregarCancion("Arctic Monkeys - Do I Wanna Know?");
    myPlaylist.agregarCancion("Arctic Monkeys - Do I Wanna Know?");
    myPlaylist.agregarCancion("Arctic Monkeys - Do I Wanna Know?");
    myPlaylist.agregarCancion("The Strokes - Reptilia");
    myPlaylist.agregarCancion("Tame Impala - The Less I Know The Better");
    myPlaylist.agregarCancion("Foster The People - Pumped Up Kicks");

    // Imprimir Lista
    std::cout << "Lista de reproduccion original:" << std::endl;
    myPlaylist.imprimirLista();

    // Burbuja
    std::cout << "\nOrdenando la lista de reproduccion utilizando el metodo de burbuja:" << std::endl;
    myPlaylist.burbuja();
    myPlaylist.imprimirLista();
    myPlaylist.desordenarLista();

    // Seleccion
    std::cout << "\nOrdenando la lista de reproduccion utilizando el metodo de seleccion:" << std::endl;
    myPlaylist.burbuja();
    myPlaylist.imprimirLista();
    myPlaylist.desordenarLista();

    // Insercion
    std::cout << "\nOrdenando la lista de reproduccion utilizando el metodo de insercion:" << std::endl;
    myPlaylist.burbuja();
    myPlaylist.imprimirLista();
    myPlaylist.desordenarLista();

    // Intercambio
    std::cout << "\nOrdenando la lista de reproduccion utilizando el metodo de intercambio:" << std::endl;
    myPlaylist.burbuja();
    myPlaylist.imprimirLista();
    myPlaylist.desordenarLista();

    // Busqueda

    std::cout << "\nBusqueda en la lista de reproduccion utilizando la busqueda secuencial:" << std::endl;
    myPlaylist.busqueda("Arctic Monkeys - Do I Wanna Know?", 0);

    return 0;
}