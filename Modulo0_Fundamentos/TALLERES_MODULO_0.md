# 🏋️ Mini-Talleres de Práctica: Módulo 0

> **⚠️ Instrucciones de Configuración:** > Para realizar estos ejercicios sin dañar el código base:
> 1. Crea un **nuevo archivo** en Dev-C++ (o tu editor).
> 2. Copia todo el contenido de `main_structs.cpp` y pégalo en tu nuevo archivo.
> 3. Guarda este nuevo archivo como: **`solucion_taller_0.cpp`**.
> 4. Implementa los cambios en ese nuevo archivo.

---

## 🛑 Taller A: Validación de Datos (Data Integrity)

**Contexto del Problema:**
Actualmente, el código base es "ingenuo". Si al registrar un estudiante ingresas una nota de `8.5` o `-20`, el programa la acepta y calcula el promedio mal. En un sistema real ("EstuMercado" o cualquier ERP), esto corrompería la base de datos.

**El Reto:**
En tu archivo `solucion_taller_0.cpp`, modifica la función `registrarEstudiante` para asegurar que las 3 notas ingresadas estén obligatoriamente entre **0.0 y 5.0**. Si el usuario ingresa un valor incorrecto, el programa debe decir "Error" y volver a pedir el dato.

**🛠️ Pista Técnica:**
En lugar de un simple `cin`, necesitarás una estructura repetitiva. El ciclo `do-while` es perfecto para validaciones porque se ejecuta al menos una vez.

```cpp
// Ejemplo de lógica a implementar para CADA nota:
float notaTemporal;
do {
    cout << "Ingrese Nota 1 (0.0 - 5.0): ";
    cin >> notaTemporal;

    if (notaTemporal < 0.0 || notaTemporal > 5.0) {
        cout << "[!] Error: La nota debe estar entre 0 y 5. Intente de nuevo.\n";
    }
} while (notaTemporal < 0.0 || notaTemporal > 5.0);

// Una vez validada, asignarla al struct:
nuevo.nota1 = notaTemporal;
```
## 🏆 Taller B: Búsqueda del Mejor Promedio

**Contexto del Problema:**
El director del curso quiere premiar al estudiante con mejor rendimiento académico. Sin embargo, buscar visualmente en una lista de 50 o 100 estudiantes es ineficiente y propenso a errores.

**El Reto:**
1.  En tu archivo `solucion_taller_0.cpp`, implementa una nueva función llamada:
    `void mostrarMejorEstudiante(const vector<Estudiante> &lista);`
2.  Esta función debe recorrer todo el vector y determinar cuál estudiante tiene el `promedio` más alto.
3.  Imprimir en consola: *"El mejor estudiante es [Nombre] con un promedio de [Promedio]"*.
4.  Agrega una opción en el menú principal (Opción 5) para probar tu función.

**🛠️ Pista Técnica:**
Este es un problema clásico de "Búsqueda del Mayor". Necesitas una variable auxiliar para recordar el récord actual mientras recorres la lista.

```cpp
// Pseudocódigo guía:
if (lista.empty()) return;

int indiceGanador = -1;
float mayorPromedio = -1.0; // Iniciamos con un valor imposiblemente bajo

for (size_t i = 0; i < lista.size(); i++) {
    // Si encuentro un promedio que supera mi récord actual...
    if (lista[i].promedio > mayorPromedio) {
        mayorPromedio = lista[i].promedio; // Actualizo el récord
        indiceGanador = i;                 // Guardo la posición del nuevo líder
    }
}

// Al finalizar el ciclo, indiceGanador tiene la posición del mejor.
cout << "El mejor es: " << lista[indiceGanador].nombre ...
```
## 🚀 Reto Extra (Opcional)

Si lograste el anterior y quieres un desafío de nivel "Parcial" para asegurar tu nota:

**El Escenario:**
¿Qué pasa si **dos o más estudiantes** tienen el mismo promedio más alto (ej: ambos tienen 5.0)? El algoritmo anterior solo mostrará al primero que encuentre y se olvidará del segundo.

**El Reto:**
Modifica tu función `mostrarMejorEstudiante` en `solucion_taller_0.cpp` para que imprima a **TODOS** los estudiantes que estén empatados en el primer lugar.

> **💡 Hint de Lógica (Algoritmo de 2 Pasadas):**
> 1.  **Primer Ciclo:** Recorre la lista completa solo para encontrar cuál es el valor numérico del `mayorPromedio` (sin imprimir nada).
> 2.  **Segundo Ciclo:** Recorre la lista otra vez y, si `lista[i].promedio == mayorPromedio`, imprime los datos de ese estudiante.

```