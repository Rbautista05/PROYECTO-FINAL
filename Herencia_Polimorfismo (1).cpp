﻿#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase base: Producto
class Producto
{
public:
    Producto(const string &nombre, double precio)
        : nombre(nombre), precio(precio) {}

    virtual void mostrarDetalles() const
    {
        cout << "Nombre: " << nombre << "\n";
        cout << "Precio: Q" << precio << "\n";
    }

protected:
    string nombre;
    double precio;
};

// Clase derivada: Ropa
class Ropa : public Producto
{
public:
    Ropa(const string &nombre, double precio, const string &talla)
        : Producto(nombre, precio), talla(talla) {}

    void mostrarDetalles() const override
    {
        Producto::mostrarDetalles();
        cout << "Talla: " << talla << "\n";
    }

private:
    string talla;
};

// Clase derivada: Electrónica
class Electronica : public Producto
{
public:
    Electronica(const string &nombre, double precio, const string &marca)
        : Producto(nombre, precio), marca(marca) {}

    void mostrarDetalles() const override
    {
        Producto::mostrarDetalles();
        cout << "Marca: " << marca << "\n";
    }

private:
    string marca;
};

// Clase derivada: Libros
class Libros : public Producto
{
public:
    Libros(const string &nombre, double precio, const string &autor)
        : Producto(nombre, precio), autor(autor) {}

    void mostrarDetalles() const override
    {
        Producto::mostrarDetalles();
        cout << "Autor: " << autor << "\n";
    }

private:
    string autor;
};

// Función para mostrar el menú
void mostrarMenu()
{
    cout << "\t------------------------" << endl;
    cout << "\t Selecciona un producto " << endl;
    cout << "\t------------------------" << endl;
    cout << "[1] Ropa\n";
    cout << "[2] Electronica\n";
    cout << "[3] Libros\n";
    cout << "[4] Mostrar productos registrados\n";
    cout << "Opcion: ";
}

// Función para mostrar los productos por categoría
void mostrarProductosRegistrados(const vector<Ropa> &ropas, const vector<Electronica> &electronicas, const vector<Libros> &libros)
{
    cout << "\n--- Productos Registrados ---\n";
    cout << "Ropa:\n";
    for (const auto &ropa : ropas)
    {
        ropa.mostrarDetalles();
        cout << "\n";
    }

    cout << "Electronica:\n";
    for (const auto &electronica : electronicas)
    {
        electronica.mostrarDetalles();
        cout << "\n";
    }

    cout << "Libros:\n";
    for (const auto &libro : libros)
    {
        libro.mostrarDetalles();
        cout << "\n";
    }
}

int main()
{
    // Vectores para almacenar los productos ingresados
    vector<Ropa> ropas;
    vector<Electronica> electronicas;
    vector<Libros> libros;

    int opcion;

    do
    {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea después de ingresar la opción

        if (opcion == 4)
        {
            mostrarProductosRegistrados(ropas, electronicas, libros);
        }
        else
        {
            string nombre;
            double precio;
            string talla;
            string marca;
            string autor;

            cout << "Ingrese el nombre del producto: ";
            getline(cin, nombre);
            cout << "Ingrese el precio del producto: ";
            cin >> precio;
            cin.ignore(); // Ignorar el salto de línea después de ingresar el precio

            switch (opcion)
            {
            case 1:
            {
                cout << "Ingrese la talla de la ropa: ";
                getline(cin, talla);
                Ropa nuevaRopa(nombre, precio, talla);
                ropas.push_back(nuevaRopa);
                break;
            }
            case 2:
            {
                cout << "Ingrese la marca de la electronica: ";
                getline(cin, marca);
                Electronica nuevaElectronica(nombre, precio, marca);
                electronicas.push_back(nuevaElectronica);
                break;
            }
            case 3:
            {
                cout << "Ingrese el autor del libro: ";
                getline(cin, autor);
                Libros nuevoLibro(nombre, precio, autor);
                libros.push_back(nuevoLibro);
                break;
            }
            default:
                cout << "Invalido.\n";
            }
        }
        cout << "Desea regresar a la seleccion de productos? (s/n): ";
        char regresar;
        cin >> regresar;
        cin.ignore(); // Ignorar el salto de línea después de ingresar la opción
        if (regresar == 'n' || regresar == 'N')
        {
            break;
        }
    } while (true);

    return 0;
}
