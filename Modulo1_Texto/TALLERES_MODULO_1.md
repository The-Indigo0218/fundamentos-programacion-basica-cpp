# 🏋️ Talleres Prácticos: Módulo 1 (Archivos de Texto)

> **Instrucciones Generales:**
> En este módulo se trabajará sobre código preexistente. El repositorio incluye dos archivos funcionales: `main_textos.cpp` y `filtro_csv.cpp`.
>
> El objetivo de estos talleres es **analizar, ejecutar y extender** dicha lógica para resolver problemas de mayor complejidad, simulando requerimientos de un entorno real o una evaluación académica avanzada.

---

## 📊 Taller A: Análisis Avanzado de Texto

**Base de Código:** `main_textos.cpp`

**Contexto del Problema:**
El algoritmo actual cumple con la función básica de contar líneas y palabras. Sin embargo, en el procesamiento de lenguaje natural y en evaluaciones académicas (como el Parcial III), es común requerir métricas más específicas, como la identificación de tokens de longitud máxima.

**Requerimiento:**
1.  Tomar como base el archivo `main_textos.cpp`.
2.  Modificar el algoritmo de análisis para que, simultáneamente al conteo, identifique **cuál es la palabra más larga** contenida en el archivo de texto.
3.  Al finalizar la ejecución, el programa debe imprimir en consola:
    * *"La palabra más larga encontrada es: [Palabra]"*

**🛠️ Pista Técnica:**
Se recomienda declarar una variable auxiliar `string palabraMasLarga = "";` antes del ciclo de lectura. Dentro del bucle de extracción de palabras, se debe comparar la longitud de la palabra actual con la almacenada.

```cpp
// Lógica sugerida para implementar dentro del ciclo while(ss >> palabra):
if (palabra.length() > palabraMasLarga.length()) {
    palabraMasLarga = palabra; // Actualizar el récord si la actual es mayor
}
```

## 🎓 Taller B: Reporte de Riesgo Académico

**Base de Código:** `filtro_csv.cpp`

**Contexto del Problema:**
El sistema actual genera exitosamente un reporte de estudiantes *Aprobados*. No obstante, para la gestión académica es prioritario identificar a los estudiantes en riesgo de deserción o pérdida de asignatura para tomar medidas preventivas.

**Requerimiento:**
1.  Tomar como base el archivo `filtro_csv.cpp`.
2.  Alterar la lógica de negocio para generar un nuevo archivo de salida llamado **`reprobados_alerta.csv`**.
3.  **Criterio de Filtro:** Se deben exportar únicamente los estudiantes con nota definitiva **menor a 3.0**.
4.  **Enriquecimiento de Datos:** El archivo CSV debe incluir una cuarta columna llamada "Accion", determinada por las siguientes reglas:
    * Si la nota es **menor a 2.0**: La acción será "Citacion Padres".
    * Si la nota está **entre 2.0 y 2.9**: La acción será "Refuerzo Academico".

**✅ Formato Esperado del CSV de Salida:**
```csv
Nombre Estudiante;Nota Final;Estado;Accion
Juan;1.5;REPROBADO;Citacion Padres
Luisa;2.8;REPROBADO;Refuerzo Academico
```
