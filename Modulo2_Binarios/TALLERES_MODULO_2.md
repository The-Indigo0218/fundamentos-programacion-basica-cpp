# 💾 Talleres Prácticos: Módulo 2 (Archivos Binarios)

> **Instrucciones:**
> Utiliza el archivo `main_binarios.cpp` como base. Crea tu propio archivo de solución e implementa las funcionalidades solicitadas.

---

## 🔍 Lab 05: El Buscador Binario

**Contexto:**
En un sistema real con 10,000 empleados, no podemos imprimir toda la lista para buscar a "Juan". Necesitamos una función que busque directamente por su ID.

**El Reto:**
1.  Implementa la función: `void buscarEmpleadoPorID();`
2.  Esta función NO debe buscar en el `vector` (memoria). Debe abrir el archivo `.dat` en modo lectura binaria y buscar el registro directamente en el disco.
3.  Pide al usuario el ID a buscar.
4.  Lee el archivo registro por registro (`while(archivo.read...)`).
5.  Si `empleadoLeido.id == idBuscado`, muestra los datos y detén la búsqueda (`break`).

**Validación:**
Agrega empleados, guarda en disco, cierra el programa. Vuelve a abrirlo, elige la opción de buscar e ingresa un ID. Debe encontrarlo sin cargar toda la lista primero.

---

## ➕ Lab Extra: Append Binario (Agregar sin borrar)

**Problema:**
Actualmente, la función `guardarEnDisco` usa `ofstream archivo(...)`. Esto **borra** el archivo anterior y lo crea de nuevo con los datos del vector (Sobreescritura total).
Si tuviéramos 1 millón de datos, reescribir todo sería muy lento.

**El Reto:**
Modifica la lógica para crear una función `void agregarUnEmpleadoAlFinal(Empleado nuevo)`.
1.  Esta función debe abrir el archivo en modo **Append Binario** (`ios::binary | ios::app`).
2.  Debe escribir **solo** el nuevo registro al final del archivo.
3.  No debe tocar los registros anteriores.

**🛠️ Pista Técnica:**
```cpp
ofstream archivo("empleados.dat", ios::binary | ios::app);
archivo.write(reinterpret_cast<char*>(&nuevo), sizeof(Empleado));
```
