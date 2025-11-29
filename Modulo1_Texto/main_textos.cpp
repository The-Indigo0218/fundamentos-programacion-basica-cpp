/*
LAB 02: Contador de Palabras y Líneas
    OBJETIVO: Entender cómo leer un archivo y procesar su contenido.
*/

#include <iostream>
#include <fstream>  // Manejo de archivos
#include <sstream>  // Manejo de flujos de texto (para partir palabras)
#include <string>

using namespace std;

int main() {
    // PASO 1: Crear el archivo de prueba (Escritura)
    // -----------------------------------------------------
    ofstream archivoEscritura("texto_analisis.txt");
    archivoEscritura << "Hola mundo desde C++\n";
    archivoEscritura << "Aprender a programar requiere practica\n";
    archivoEscritura << "Archivos de texto y binarios";
    archivoEscritura.close(); // ¡Importante! Guardar cambios.
    cout << ">> Archivo 'texto_analisis.txt' creado exitosamente.\n";

    // PASO 2: Analizar el archivo (Lectura)
    // -----------------------------------------------------
    ifstream archivoLectura("texto_analisis.txt");

    if (!archivoLectura.is_open()) {
        cout << "Error: No se pudo abrir el archivo.";
        return 1;
    }

    string linea;
    string palabra;
    int totalLineas = 0;
    int totalPalabras = 0;

    cout << "\n--- INICIO DEL ANALISIS ---\n";

    // Leemos el archivo línea por línea hasta el final
    while (getline(archivoLectura, linea)) {
        totalLineas++;

        // TRUCO: Usamos stringstream para 'romper' la línea en palabras
        stringstream ss(linea);

        // Mientras 'ss' pueda sacar una palabra, sumamos 1
        while (ss >> palabra) {
            totalPalabras++;
        }
    }

    archivoLectura.close();

    // PASO 3: Mostrar Resultados
    cout << "Total de Lineas: " << totalLineas << endl;
    cout << "Total de Palabras: " << totalPalabras << endl;

    return 0;
}