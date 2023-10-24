#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para agregar elementos a la lista
void agregarNodo(Nodo*& cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    }
    else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

// Función para imprimir la lista de números
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

// Función para borrar la lista
void borrarLista(Nodo* cabeza) {
    while (cabeza != nullptr) {
        Nodo* siguiente = cabeza->siguiente;
        delete cabeza;
        cabeza = siguiente;
        cout << "Elemnto borrado";
    }
}

int main() {
    Nodo* cabeza = nullptr;
    int tamanoLista;
    cout << "Ingrese la cantidad de elementos que desea agregar a la lista: ";
    cin >> tamanoLista;

    if (tamanoLista <= 0) {
        cout << "Cantidad de elementos no válida" << endl;
        return 1;
    }

    for (int i = 0; i < tamanoLista; i++) {
        int valor;
        cout << "Ingrese dato " << i + 1 << ": ";
        cin >> valor;
        agregarNodo(cabeza, valor);
    }

    cout << "Imprimiendo Lista de números" << endl;
    imprimirLista(cabeza);

    borrarLista(cabeza);

    return 0;
}
