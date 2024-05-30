#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase Usuario
class Usuario {
public:
  string nombre;
  string direccion;
  Usuario(string nombre, string direccion)
      : nombre(nombre), direccion(direccion) {}

  string getNombre() const { return nombre; }
  string getDireccion() const { return direccion; }

  // Sobrecarga del operador de igualdad para comparar usuarios
  bool operator==(const Usuario &otro) const {
    return nombre == otro.nombre && direccion == otro.direccion;
  }
};

// Clase Restaurante
class Restaurante {

public:
  string nombre;
  vector<string> comidas;
  vector<string> bebidas;
  Restaurante(string nombre) : nombre(nombre) {}

  void agregarComida(const string &comida) { comidas.push_back(comida); }

  void agregarBebida(const string &bebida) { bebidas.push_back(bebida); }

  bool buscarComida(const string &comida) const {
    return buscarComidaRecursiva(comidas, comida, 0);
  }

  bool buscarBebida(const string &bebida) const {
    return buscarBebidaRecursiva(bebidas, bebida, 0);
  }

  // Busqueda de comidas y bebidas usando recursion :^) hehe
  bool buscarComidaRecursiva(const vector<string> &comidas,
                             const string &comida, int index) const {
    if (index >= comidas.size()) {
      return false;
    }
    if (comidas[index] == comida) {
      return true;
    }
    return buscarComidaRecursiva(comidas, comida, index + 1);
  }

  bool buscarBebidaRecursiva(const vector<string> &bebidas,
                             const string &bebida, int index) const {
    if (index >= bebidas.size()) {
      return false;
    }
    if (bebidas[index] == bebida) {
      return true;
    }
    return buscarBebidaRecursiva(bebidas, bebida, index + 1);
  }

  string getNombre() const { return nombre; }
};

// Clase AppDelivery
class AppDelivery {
public:
  vector<Usuario> usuarios;
  vector<Restaurante> restaurantes;
  vector<string> pedidos;

  void agregarUsuario(const Usuario &usuario) { usuarios.push_back(usuario); }

  void agregarRestaurante(const Restaurante &restaurante) {
    restaurantes.push_back(restaurante);
  }

  void realizarPedido(const Usuario &usuario, const string &comida,
                      const string &bebida) {

    /*
      Usando lambdas para personalizar los mensajes de error y confirmacion
    */
    auto usuarioNoEncontrado = [](const Usuario &usuario) {
      cout << "Error: Usuario no encontrado." << endl;
    };

    if (find(usuarios.begin(), usuarios.end(), usuario) == usuarios.end()) {
      usuarioNoEncontrado(usuario);
      return;
    }

    // Verificar si la comida y la bebida están disponibles en algún restaurante
    bool comidaDisponible = false;
    bool bebidaDisponible = false;
    for (const Restaurante &restaurante : restaurantes) {
      if (restaurante.buscarComida(comida)) {
        comidaDisponible = true;
      }
      if (restaurante.buscarBebida(bebida)) {
        bebidaDisponible = true;
      }
      if (comidaDisponible && bebidaDisponible) {
        break;
      }
    }

    auto comidaNoDisponible = [](const string &comida) {
      cout << "Error: " << comida << " no disponible en ningún restaurante."
           << endl;
    };

    auto bebidaNoDisponible = [](const string &bebida) {
      cout << "Error: " << bebida << " no disponible en ningún restaurante."
           << endl;
    };

    if (!comidaDisponible) {
      comidaNoDisponible(comida);
      return;
    }
    if (!bebidaDisponible) {
      bebidaNoDisponible(bebida);
      return;
    }

    auto pedidoRealizado = [](const Usuario &usuario, const string &comida,
                              const string &bebida) {
      cout << "Pedido realizado con éxito." << endl;
    };

    pedidoRealizado(usuario, comida, bebida);
    pedidos.push_back("Pedido de " + usuario.getNombre() + " (" +
                      usuario.getDireccion() + "): " + comida + ", " + bebida);
  }

  void imprimirPedidos() const {
    cout << "Registro de Pedidos:" << endl;
    for (const string &pedido : pedidos) {
      cout << pedido << endl;
    }
  }

  void imprimirUsuarios() const {
    cout << "Lista de Usuarios:" << endl;
    for (const auto &usuario : usuarios) {
      cout << "Nombre: " << usuario.getNombre()
           << ", Direccion: " << usuario.getDireccion() << endl;
    }
  }

  void imprimirRestaurantes() const {
    cout << "Lista de Restaurantes:" << endl;
    for (const auto &restaurante : restaurantes) {
      cout << "Nombre: " << restaurante.getNombre() << endl;
    }
  }

  /*
    Ordenando los usuarios y los restaurantes haciendo uso de templates
    y del algoritmo de ordenamiento bubbleSort
  */

  template <typename T> void ordenarUsuarios(vector<T> &usuarios) {
    int n = usuarios.size();
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < n - i - 1; ++j) {
        if (usuarios[j].nombre > usuarios[j + 1].nombre) {
          swap(usuarios[j], usuarios[j + 1]);
        }
      }
    }
  }

  template <typename T> void ordenarRestaurantes(vector<T> &restaurantes) {
    int n = restaurantes.size();
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < n - i - 1; ++j) {
        if (restaurantes[j].nombre > restaurantes[j + 1].nombre) {
          swap(restaurantes[j], restaurantes[j + 1]);
        }
      }
    }
  }
};

int main() {
  AppDelivery app;
  Usuario usuario1("Juan", "Calle 123");
  Usuario usuario2("Maria", "Avenida 456");

  Restaurante restaurante1("Pizza Hut");
  restaurante1.agregarComida("Pizza Hawaiana");
  restaurante1.agregarComida("Lasagna");
  restaurante1.agregarBebida("Coca Cola");
  restaurante1.agregarBebida("Awita");

  Restaurante restaurante2("Carbon Grill");
  restaurante2.agregarComida("Hamburguesa");
  restaurante2.agregarBebida("Chica Morada");

  app.agregarUsuario(usuario1);
  app.agregarUsuario(usuario2);
  app.agregarRestaurante(restaurante1);
  app.agregarRestaurante(restaurante2);

  // Ordenar usuarios
  app.ordenarUsuarios(app.usuarios);
  cout << "Usuarios ordenados:" << endl;
  app.imprimirUsuarios();
  cout << endl;

  // Ordenar restaurantes
  app.ordenarRestaurantes(app.restaurantes);
  cout << "Restaurantes ordenados:" << endl;
  app.imprimirRestaurantes();
  cout << endl;

  // Realizar pedidos
  app.realizarPedido(usuario1, "Pizza Hawaiana", "Coca Cola");
  app.realizarPedido(usuario2, "Hamburguesa", "Juguito"); // Juguito no existe
  app.realizarPedido(usuario2, "Hamburguesa", "Coca Cola");

  // Imprimir pedidos
  app.imprimirPedidos();

  return 0;
}