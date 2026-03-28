# 🚀 Guía de Estudio: Persistencia y Estructuras de Datos en C++

Bienvenido al repositorio central de estudio para **Programación II**. Este proyecto nace con el objetivo de consolidar los conocimientos necesarios para dominar el manejo de datos en C++, desde la lógica modular básica hasta la persistencia avanzada en archivos binarios.

Este material está diseñado para preparar a estudiantes de Ingeniería de Sistemas para:
1.  **Parciales de Corte:** Manejo de archivos de texto y binarios.
2.  **Proyecto Final:** Sistemas de gestión (tipo "EstuMercado" o ERPs básicos).

---

## 📂 Estructura del Plan de Estudio.

El contenido está dividido en 4 módulos progresivos. Cada módulo contiene explicaciones teóricas breves y ejercicios prácticos de referencia.

### 🧱 Módulo 0: Fundamentos y Estructuras en Memoria:
*Antes de guardar datos, debemos saber cómo organizarlos en la RAM.*

**Temas Clave:**
* **Modularidad:** División del código en funciones (`void` vs retorno).
* **Paso de Parámetros:** Diferencia crítica entre Valor (copia) y Referencia (`&`).
* **Structs (Registros):** Diseño de entidades (`Estudiante`, `Producto`).
* **Arrays de Caracteres vs String:** Por qué usamos `char[]` para archivos binarios.

| Actividad Sugerida | Descripción | Código |
| :--- | :--- | :---: |
| **Lab 01** | Crear un sistema de registro de notas usando Arreglos de Structs (sin archivos). | [📂 Ver Código](./Modulo0_Fundamentos/) |

---

### 📄 Módulo 1: Archivos de Texto (.txt y .csv);
*La persistencia legible por humanos. Ideal para reportes e intercambio de datos.*

**Temas Clave:**
* **Librería `<fstream>`:** Uso de `ofstream` (escribir) y `ifstream` (leer).
* **Formatos:** Escritura plana vs. Formato CSV (valores separados por comas).
* **Tokenización:** Uso de `stringstream` para separar palabras o datos.
* **Validaciones:** Comprobar `is_open()` y manejo de errores.

| Actividad Sugerida | Descripción | Código |
| :--- | :--- | :---: |
| **Lab 02** | Algoritmo para contar líneas y palabras en un documento. | [📂 Ver Código](./Modulo1_Texto/) |
| **Lab 03** | **Exportador CSV:** Filtrar estudiantes aprobados y guardar en Excel (.csv). | [📂 Ver Código](./Modulo1_Texto/) |

---

### 💾 Módulo 2: Archivos Binarios (.dat):
*La persistencia eficiente. El corazón de los sistemas transaccionales.*

**Temas Clave:**
* **Concepto Binario:** Diferencia entre guardar "100" (texto) y el byte del entero (binario).
* **Escritura (`write`):** Uso de `reinterpret_cast` y `sizeof`.
* **Lectura (`read`):** Recuperación de bloques de memoria (Structs completos).
* **Modo de Apertura:** Importancia del flag `ios::binary`.

> **⚠️ Nota Importante:** En este módulo es obligatorio usar `char[]` en lugar de `string` dentro de los structs para asegurar un tamaño fijo de registro.

| Actividad Sugerida | Descripción | Código |
| :--- | :--- | :---: |
| **Lab 04** | **Serializador:** Guardar y recuperar un arreglo de structs en un archivo `.dat`. | [📂 Ver Código](./Modulo2_Binarios/) |
| **Lab 05** | **Buscador:** Encontrar un registro específico por ID dentro del archivo binario. | [📂 Ver Código](./Modulo2_Binarios/) |

---

### 🛠️ Módulo 3: Manipulación Avanzada (CRUD):
*Aplicación de conocimientos para el Proyecto Final.*

**Temas Clave:**
* **Punteros de Archivo:** Uso de `seekg` (lectura) y `seekp` (escritura) para moverse en el archivo.
* **Update (Actualizar):** Modificar un saldo o stock sin reescribir todo el archivo.
* **Delete (Eliminar):**
    * *Eliminación Lógica:* Marcar con un flag `bool activo = false`.
    * *Eliminación Física:* Algoritmo de copia a `temp.dat` y renombrado.

| Actividad Sugerida | Descripción | Código |
| :--- | :--- | :---: |
| **Proyecto** | **Mini-Gestor de Inventario:** CRUD completo (Crear, Leer, Actualizar, Borrar) validando duplicados. | [📂 Ver Código](./Modulo3_CRUD/) |

---

## 💻 Requisitos Previos:

Para ejecutar los ejemplos de este repositorio necesitas:
* Compilador de C++ (G++ o MinGW).
* IDE recomendado: **Dev-C++** (Versión 5.11 o superior) o **VS Code**.
* Conocimientos básicos de lógica de programación (ciclos, condicionales).

## 🤝 Contribuciones

Este es un repositorio educativo. Si tienes una forma más eficiente de resolver un ejercicio o encuentras un error, ¡haz un Pull Request o abre un Issue!

---
*Universidad de Cartagena - Ingeniería de Sistemas*
