/*
    TEMA: Módulo 2 - Archivos Binarios (.dat)
    DESCRIPCIÓN: Sistema básico de persistencia binaria.
                 Muestra cómo guardar y leer structs completos usando 'write' y 'read'.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

// --- ESTRUCTURA DE DATOS (Tamaño Fijo) ---
struct Empleado {
    int id;
    char nombre[50]; // OBLIGATORIO: char[] para binarios. string causa error.
    double salario;
    char cargo[30];
};

const char* NOMBRE_ARCHIVO = "empleados.dat";

// --- PROTOTIPOS ---
void agregarEmpleado(vector<Empleado> &lista);
void guardarEnDisco(const vector<Empleado> &lista);
void cargarDesdeDisco(vector<Empleado> &lista);
void mostrarEmpleados(const vector<Empleado> &lista);

// --- MAIN ---
int main() {
    vector<Empleado> nomina;
    int opcion = 0;

    // Al iniciar, intentamos cargar lo que haya en el archivo
    cargarDesdeDisco(nomina);

    do {
        cout << "\n=== SISTEMA DE NOMINA (BINARIO) ===" << endl;
        cout << "1. Agregar Empleado (RAM)" << endl;
        cout << "2. Guardar Cambios en Disco (.dat)" << endl;
        cout << "3. Ver Empleados (RAM)" << endl;
        cout << "4. [Lab 05] Buscar por ID" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: agregarEmpleado(nomina); break;
            case 2: guardarEnDisco(nomina); break;
            case 3: mostrarEmpleados(nomina); break;
            case 4: cout << ">> Funcion a implementar en el Lab 05." << endl; break;
            case 5: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while(opcion != 5);

    return 0;
}

// --- IMPLEMENTACIONES ---

void agregarEmpleado(vector<Empleado> &lista) {
    Empleado emp;
    cout << "\n--- NUEVO EMPLEADO ---" << endl;
    cout << "ID: "; cin >> emp.id; cin.ignore();
    cout << "Nombre: "; cin.getline(emp.nombre, 50);
    cout << "Cargo: "; cin.getline(emp.cargo, 30);
    cout << "Salario: "; cin >> emp.salario;

    lista.push_back(emp);
    cout << ">> Empleado agregado a la lista (Recuerde guardar en disco)." << endl;
}

void guardarEnDisco(const vector<Empleado> &lista) {
    // ios::binary es VITAL. Sin esto, Windows puede corromper los datos.
    ofstream archivo(NOMBRE_ARCHIVO, ios::binary);

    if(!archivo.is_open()) {
        cout << "[Error] No se pudo crear el archivo." << endl;
        return;
    }

    // Recorremos el vector y escribimos cada struct directo a bytes
    for (const auto &emp : lista) {
        archivo.write(reinterpret_cast<const char*>(&emp), sizeof(Empleado));
    }

    archivo.close();
    cout << ">> " << lista.size() << " registros guardados en " << NOMBRE_ARCHIVO << endl;
}

void cargarDesdeDisco(vector<Empleado> &lista) {
    ifstream archivo(NOMBRE_ARCHIVO, ios::binary);
    if(!archivo.is_open()) {
        cout << "[Info] Archivo nuevo o no encontrado. Iniciando vacio." << endl;
        return;
    }

    Empleado emp;
    lista.clear(); // Limpiamos la RAM antes de cargar

    // Leemos bloque por bloque del tamaño de 'Empleado'
    while (archivo.read(reinterpret_cast<char*>(&emp), sizeof(Empleado))) {
        lista.push_back(emp);
    }

    archivo.close();
    cout << ">> Se cargaron " << lista.size() << " empleados desde el disco." << endl;
}

void mostrarEmpleados(const vector<Empleado> &lista) {
    if(lista.empty()) { cout << "Lista vacia." << endl; return; }

    cout << "\n--- NOMINA ---" << endl;
    cout << left << setw(5) << "ID" << setw(30) << "NOMBRE" << setw(20) << "CARGO" << "SALARIO" << endl;
    for(const auto &emp : lista) {
        cout << left << setw(5) << emp.id
             << setw(30) << emp.nombre
             << setw(20) << emp.cargo
             << "$" << fixed << setprecision(0) << emp.salario << endl;
    }
}