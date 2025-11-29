/*
LAB 03: Exportador CSV (Filtro de Aprobados)
    OBJETIVO: Leer datos, aplicar lógica (if) y guardar en formato Excel (.csv).
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // PASO 1: Generar datos de prueba (Base de datos cruda)
    ofstream baseDatos("notas_curso.txt");
    baseDatos << "Juan 2.5\n";    // Reprobado
    baseDatos << "Maria 4.8\n";   // Aprobado
    baseDatos << "Carlos 3.0\n";  // Aprobado (Raspa)
    baseDatos << "Luisa 1.9\n";   // Reprobado
    baseDatos << "Ana 5.0\n";     // Aprobado
    baseDatos.close();
    cout << ">> Base de datos 'notas_curso.txt' generada.\n";

    // PASO 2: Filtrar y Exportar
    ifstream lectura("notas_curso.txt");      // Origen
    ofstream escritura("aprobados_excel.csv"); // Destino (CSV)

    // Escribimos los encabezados para Excel
    escritura << "Nombre Estudiante;Nota Final;Estado\n";

    string nombre;
    float nota;

    cout << "\n--- EXPORTANDO APROBADOS ---\n";

    // El while lee: Primero el nombre (string), luego la nota (float)
    while (lectura >> nombre >> nota) {

        // LOGICA DE NEGOCIO: Solo pasan los de nota >= 3.0
        if (nota >= 3.0) {
            // Guardamos en formato CSV (separado por punto y coma)
            escritura << nombre << ";" << nota << ";APROBADO\n";
            cout << "-> Exportado: " << nombre << endl;
        }
    }

    lectura.close();
    escritura.close();

    cout << "\n>> Proceso terminado. Revisa el archivo 'aprobados_excel.csv'.";

    return 0;
}