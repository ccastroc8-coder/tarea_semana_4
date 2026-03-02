#include <iostream>
#include <string>
using namespace std;

struct Producto {
    int codigo;
    string nombre;
    double precio;
};

struct Nodo {
    Producto data;
    Nodo* siguiente;
};

int main() {
    cout << "Nombre: Carlos Daniel Castro Cáceres" << endl;
    cout << "------------------------------------" << endl;

    Nodo* primero = nullptr;
    Nodo* ultimo = nullptr;
    double total = 0.0;

    for (int i = 0; i < 4; i++) {
        Nodo* nuevo = new Nodo;

        cout << "Ingrese código del producto " << i + 1 << ": ";
        cin >> nuevo->data.codigo;

        cin.ignore();
        cout << "Ingrese nombre del producto " << i + 1 << ": ";
        getline(cin, nuevo->data.nombre);

        cout << "Ingrese precio del producto " << i + 1 << ": Q";
        cin >> nuevo->data.precio;

        nuevo->siguiente = nullptr;

        if (primero == nullptr) {
            primero = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }

        cout << "-----------------------------" << endl;
    }

    cout << "\n Lista de productos:\n";
    cout << "=============================\n";

    Nodo* actual = primero;
    while (actual != nullptr) {
        cout << "Código: " << actual->data.codigo << endl;
        cout << "Nombre: " << actual->data.nombre << endl;
        cout << "Precio: Q" << actual->data.precio << endl;
        cout << "-----------------------------" << endl;
        total += actual->data.precio;
        actual = actual->siguiente;
    }

    cout << " Total acumulado: Q" << total << endl;

    actual = primero;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    primero = nullptr;
    ultimo = nullptr;

    cout << "\nMemoria liberada correctamente.\n";

    return 0;
}