#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip> 

using namespace std;

// --- ESTRUCTURAS ---
struct Estudiante {
    char nombre[50]; // char[] obligatorio para compatibilidad binaria futura
    int codigo;
    float nota1;
    float nota2;
    float nota3;
    float promedio;
};

// --- PROTOTIPOS ---
void registrarEstudiante(vector<Estudiante> &lista);
void listarEstudiantes(const vector<Estudiante> &lista);
void calcularPromedioCurso(const vector<Estudiante> &lista);

// --- MAIN ---
int main() {
    vector<Estudiante> curso; 
    int opcion = 0;

    do {
        cout << "\n=== GESTION DE NOTAS (EN MEMORIA) ===" << endl;
        cout << "1. Registrar Estudiante" << endl;
        cout << "2. Listar Estudiantes" << endl;
        cout << "3. Calcular Promedio del Curso" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore(); 

        switch(opcion) {
            case 1: registrarEstudiante(curso); break;
            case 2: listarEstudiantes(curso); break;
            case 3: calcularPromedioCurso(curso); break;
            case 4: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while(opcion != 4);

    return 0;
}

// --- IMPLEMENTACIONES ---

void registrarEstudiante(vector<Estudiante> &lista) {
    Estudiante nuevo;
    
    cout << "\n--- NUEVO REGISTRO ---" << endl;
    cout << "Codigo: ";
    cin >> nuevo.codigo;
    cin.ignore(); 
    
    cout << "Nombre Completo: ";
    cin.getline(nuevo.nombre, 50); 
    
    cout << "Nota 1 (0.0 - 5.0): "; cin >> nuevo.nota1;
    cout << "Nota 2 (0.0 - 5.0): "; cin >> nuevo.nota2;
    cout << "Nota 3 (0.0 - 5.0): "; cin >> nuevo.nota3;
    
    nuevo.promedio = (nuevo.nota1 + nuevo.nota2 + nuevo.nota3) / 3.0;
    
    lista.push_back(nuevo);
    cout << ">> Estudiante registrado con exito!" << endl;
}

void listarEstudiantes(const vector<Estudiante> &lista) {
    if (lista.empty()) {
        cout << "\n[!] No hay estudiantes registrados." << endl;
        return;
    }

    cout << "\n--- LISTADO DE ESTUDIANTES ---" << endl;
    cout << left << setw(10) << "CODIGO" << setw(30) << "NOMBRE" << setw(10) << "PROMEDIO" << endl;
    cout << "----------------------------------------------------" << endl;
    
    for (size_t i = 0; i < lista.size(); i++) {
        cout << left << setw(10) << lista[i].codigo 
             << setw(30) << lista[i].nombre 
             << fixed << setprecision(1) << lista[i].promedio << endl;
    }
}

void calcularPromedioCurso(const vector<Estudiante> &lista) {
    if (lista.empty()) return;
    
    float sumaTotal = 0;
    for (size_t i = 0; i < lista.size(); i++) {
        sumaTotal += lista[i].promedio;
    }
    
    float promedioGeneral = sumaTotal / lista.size();
    cout << "\n>> El promedio general del curso es: " 
         << fixed << setprecision(2) << promedioGeneral << endl;
}

