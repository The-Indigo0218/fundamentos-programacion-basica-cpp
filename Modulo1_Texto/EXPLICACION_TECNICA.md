# 🏋️ Talleres Prácticos: Módulo 1 (Archivos de Texto)

> **⚠️ Instrucciones de Configuración:**
> 1. Crea un nuevo archivo en Dev-C++ llamado `solucion_lab_02_03.cpp`.
> 2. Copia todo el contenido del archivo `main_textos.cpp` y pégalo allí.
> 3. Implementa las funciones vacías siguiendo las instrucciones de abajo.

---

## 📊 Lab 02: Algoritmo de Conteo (Análisis de Texto)

**Objetivo:**
Manipular un archivo de texto desestructurado para extraer métricas básicas. Este ejercicio entrena la lógica requerida para el punto *"Contar líneas y palabras"* del parcial.

**Contexto:**
Al iniciar el programa base, este genera automáticamente un archivo llamado `documento_lab02.txt` con varios párrafos de prueba. Tu misión es crear el motor de análisis.

**El Reto:**
Implementa la función `void analizarDocumento()` que debe:
1.  Abrir el archivo `documento_lab02.txt` en modo lectura (`ifstream`).
2.  Recorrer el archivo línea por línea.
3.  Calcular e imprimir en consola:
    * **Total de Líneas:** Cantidad de renglones de texto.
    * **Total de Palabras:** Cantidad de palabras separadas por espacios.

**🛠️ Pista Técnica:**
Para contar palabras dentro de una línea, la herramienta más eficiente es `stringstream`.

```cpp
// Snippet de ayuda para tu función:
string linea, palabra;
int lineas = 0, palabras = 0;

while (getline(archivo, linea)) {
    lineas++; // Contamos la línea leída
    
    stringstream ss(linea); // Convertimos la línea en un flujo de datos
    while (ss >> palabra) { // El operador >> extrae palabra por palabra ignorando espacios
        palabras++;
    }
}

```
## 🎓 Lab 03: Exportador CSV (Filtro de Aprobados)

**Objetivo:**
Aprender a filtrar información de una base de datos de texto plano y exportarla a un formato compatible con Excel (.csv).

**Contexto:**
La coordinación académica necesita un reporte urgente. Usando la **Opción 1** del menú en tu código base, has registrado a varios estudiantes en el archivo `estudiantes_db.txt`.
> *Nota: Asegúrate de registrar al menos un estudiante con promedio menor a 3.0 para probar que el filtro funciona.*

**El Reto:**
Implementa la función `void exportarAprobadosCSV()` en tu archivo de solución. Esta función debe:
1.  Abrir el archivo `estudiantes_db.txt` en modo lectura.
2.  Crear un nuevo archivo llamado `aprobados.csv` en modo escritura.
3.  Leer estudiante por estudiante y verificar: **¿Su promedio es mayor o igual a 3.0?**
4.  Si cumple la condición, escribir sus datos en el archivo CSV separados por **punto y coma (;)**.
    * *Formato esperado:* `Nombre;Edad;Promedio`

**✅ Validación:**
Al terminar la ejecución, busca el archivo `aprobados.csv` en la carpeta de tu proyecto. Ábrelo con Excel o el Bloc de Notas.
* **Éxito:** Solo deben aparecer los estudiantes que ganaron la materia.
* **Error:** Si el archivo está vacío o aparecen reprobados, revisa tu condición `if`.

**🛠️ Pista Técnica:**
Excel usa separadores especiales para dividir las columnas. En Latinoamérica, usamos el punto y coma (`;`).

```cpp
// Snippet de ayuda para el ciclo de exportación:
while (lectura >> nombre >> edad >> promedio) {
    // Lógica de Negocio: Solo pasan los aprobados
    if (promedio >= 3.0) {
        // Guardamos concatenando el separador ";"
        escritura << nombre << ";" << edad << ";" << promedio << endl;
        cout << "-> Estudiante exportado: " << nombre << endl;
    }
}
```


