# 📘 Documentación Técnica: Módulo 0

Este documento explica las decisiones de diseño y las herramientas de C++ utilizadas en el código `main_structs.cpp`.

## 1. Decisiones de Arquitectura

### ¿Por qué `char nombre[50]` y no `string`?
Aunque `std::string` es más fácil de usar, tiene un tamaño dinámico en memoria RAM.
* **El Problema:** Al guardar un `string` en un archivo binario (tema del próximo módulo), solo se guardaría la dirección de memoria (un puntero), no el texto real. Al cerrar el programa, esa dirección deja de ser válida.
* **La Solución:** Usamos `char[50]` para reservar **50 bytes fijos** dentro de la estructura `Estudiante`. Esto garantiza que al volcar la estructura al disco, el nombre vaya incluido.

### Paso por Referencia (`&`) vs. Valor
Observa la función: `void registrarEstudiante(vector<Estudiante> &lista)`
* **Con `&` (Referencia):** Trabajamos sobre la lista original que está en el `main`. Los cambios persisten.
* **Sin `&` (Valor):** C++ crearía una **copia** temporal de toda la lista. Al terminar la función, la copia se borra y el estudiante nuevo desaparece.

## 2. Herramientas de Formato (`<iomanip>`)

Para imprimir tablas ordenadas, usamos manipuladores de flujo. Imagina que cada dato va en una "caja invisible".

| Comando | Significado | Descripción |
| :--- | :--- | :--- |
| `setw(n)` | Set Width | Crea una caja de ancho `n` para el dato que sigue. Si el dato es más corto, rellena con espacios. |
| `left` | Alineación | Pega el texto a la izquierda de la caja (ideal para nombres). |
| `fixed` | Notación Fija | Evita la notación científica (ej: `1.2e+04`) y fuerza el uso de punto decimal. |
| `setprecision(n)` | Precisión | Define cuántos decimales mostrar después del punto. |

**Ejemplo:**
```cpp
cout << left << setw(10) << "CODIGO";
// Imprime: "CODIGO    " (4 espacios de relleno a la derecha)