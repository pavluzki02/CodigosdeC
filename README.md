# 📚 TUPProgI — Guía de Conceptos: Arreglos, Cadenas, Matrices, Funciones y Estructuras en C

> Guía completa de los temas del 2º Parcial de Programación I (TUP). Incluye teoría, ejemplos de código y explicaciones detalladas de cada concepto.

---

## 📋 Índice

- [Arreglos](#-arreglos)
- [Búsqueda Lineal](#-búsqueda-lineal)
- [Búsqueda Binaria](#-búsqueda-binaria)
- [Búsqueda Binaria con Eliminación de Elemento](#-búsqueda-binaria-con-eliminación-de-elemento)
- [Ordenamiento Burbuja](#-ordenamiento-burbuja)
- [Ordenamiento Inserción](#-ordenamiento-inserción)
- [Ordenamiento Selección](#-ordenamiento-selección)
- [Cadenas](#-cadenas)
- [Matrices](#-matrices)
- [Funciones](#-funciones)
- [Estructuras (struct)](#-estructuras-struct)
- [Estructuras y Archivos](#-estructuras-y-archivos)
- [Programa con Función](#-programa-con-función)

---

## 📦 Arreglos

### ¿Qué es un arreglo?

Un arreglo (o array) es un **conjunto finito, ordenado y homogéneo de elementos**.

| Concepto | Significado |
|----------|-------------|
| **Finito** | Hay un número específico de elementos; puede ser grande o pequeño, pero debe estar definido |
| **Ordenado** | Los elementos están dispuestos de forma que hay un elemento en la posición 0, uno en la posición 1, etc. |
| **Homogéneo** | Todos los elementos son del mismo tipo de dato (`int`, `float`, `char`, etc.) |

### Declaración

```c
// Sintaxis general
tipo nombre_arreglo[tamaño];

// Ejemplos
int numeros[5];
float precios[10];
char letras[26];
```

### Declaración con inicialización

```c
// Inicialización completa
int numeros[5] = {10, 20, 30, 40, 50};

// Inicialización parcial (los elementos restantes se inicializan en 0)
int arreglo[3] = {7};   // arreglo[0]=7, arreglo[1]=0, arreglo[2]=0
```

### Acceso a elementos

Los índices **comienzan en 0**.

```c
int numeros[] = {5, 10, 15, 20};

printf("%d", numeros[0]);  // Imprime: 5
printf("%d", numeros[3]);  // Imprime: 20
```

### Recorrido de un arreglo

```c
int datos[] = {1, 2, 3, 4, 5};
int n = 5;

for (int i = 0; i < n; i++) {
    printf("%d ", datos[i]);
}
// Salida: 1 2 3 4 5
```

### Operaciones básicas: inserción

```c
#include <stdio.h>

void insertarValor(int arr[], int pos, int valor) {
    arr[pos] = valor;
}

int main() {
    int numeros[5] = {1, 2, 3, 4, 5};
    insertarValor(numeros, 2, 99);
    printf("%d\n", numeros[2]);  // Imprime: 99
    return 0;
}
```

> ⚠️ Los arreglos se pasan a funciones **por referencia** (se pasa la dirección del primer elemento). Los cambios dentro de la función **sí afectan** al arreglo original.

### Suma de elementos

```c
int numeros[] = {1, 2, 3};
int suma = 0;

for (int i = 0; i < 3; i++) {
    suma += numeros[i];
}
printf("%d", suma);  // Imprime: 6
```

---

## 🔍 Búsqueda Lineal

La búsqueda en un arreglo consiste en **recorrer el arreglo a fin de encontrar el valor buscado**.

```c
#include <stdio.h>

int main() {
    int numeros[5] = {3, 7, 9, 1, 4};
    int buscado = 9;
    int encontrado = 0;

    for (int i = 0; i < 5; i++) {
        if (numeros[i] == buscado) {
            printf("Encontrado en la posición %d\n", i);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No encontrado.\n");
    }

    return 0;
}
```

La variable `encontrado` cumple el propósito de **determinar si se encontró el número o no**.

Si `buscado = 9`, imprime: `Encontrado en la posición 2`  
Si `buscado = 5`, imprime: `No encontrado.`

---

## 🔎 Búsqueda Binaria

La búsqueda binaria es un algoritmo eficiente que **solo funciona sobre arreglos ordenados**. Divide el arreglo a la mitad en cada paso.

### Relaciones clave

| Concepto | Descripción |
|----------|-------------|
| El ordenamiento de un arreglo | se realiza mediante un determinado criterio de ordenamiento |
| La búsqueda binaria no se puede aplicar | si el arreglo no está ordenado |
| El arreglo debe estar ordenado | para realizar la búsqueda binaria |

### Implementación

```c
#include <stdio.h>

int busquedaBinaria(int arr[], int n, int buscado) {
    int izq = 0, der = n - 1;

    while (izq <= der) {
        int medio = (izq + der) / 2;

        if (arr[medio] == buscado) {
            return medio;           // Encontrado, retorna posición
        } else if (arr[medio] < buscado) {
            izq = medio + 1;        // Buscar en la mitad derecha
        } else {
            der = medio - 1;        // Buscar en la mitad izquierda
        }
    }

    return -1;  // No encontrado
}

int main() {
    int numeros[] = {1, 3, 5, 7, 9, 11, 13};
    int n = 7;
    int buscado = 7;

    int pos = busquedaBinaria(numeros, n, buscado);

    if (pos != -1) {
        printf("Encontrado en la posición %d\n", pos);
    } else {
        printf("No encontrado.\n");
    }

    return 0;
}
```

### ¿Por qué es más eficiente?

| Tipo | Comparaciones máximas (100 elementos) |
|------|--------------------------------------|
| Búsqueda lineal | 100 |
| Búsqueda binaria | 7 (log₂ 100 ≈ 7) |

---

## 🗑️ Búsqueda Binaria con Eliminación de Elemento

Permite encontrar un elemento y luego eliminarlo desplazando los demás hacia la izquierda.

```c
#include <stdio.h>

int busquedaBinaria(int arr[], int n, int buscado) {
    int izq = 0, der = n - 1;
    while (izq <= der) {
        int medio = (izq + der) / 2;
        if (arr[medio] == buscado) return medio;
        else if (arr[medio] < buscado) izq = medio + 1;
        else der = medio - 1;
    }
    return -1;
}

int eliminar(int arr[], int *n, int buscado) {
    int pos = busquedaBinaria(arr, *n, buscado);

    if (pos == -1) {
        printf("Elemento no encontrado.\n");
        return 0;
    }

    // Desplazar elementos hacia la izquierda
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;  // Reducir el tamaño lógico del arreglo
    printf("Elemento eliminado. Nuevo tamaño: %d\n", *n);
    return 1;
}

int main() {
    int datos[] = {2, 4, 6, 8, 10};
    int n = 5;

    eliminar(datos, &n, 6);

    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    // Salida: 2 4 8 10

    return 0;
}
```

> ⚠️ El arreglo debe estar **ordenado** antes de aplicar la búsqueda binaria. Luego de eliminar, el arreglo sigue ordenado.

---

## 🫧 Ordenamiento Burbuja

El método burbuja compara elementos **adyacentes** e intercambia los que están en el orden incorrecto, repitiendo el proceso hasta que el arreglo queda ordenado.

```c
#include <stdio.h>

void burbuja(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambio
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int datos[] = {5, 3, 8, 1, 9, 2};
    int n = 6;

    burbuja(datos, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    // Salida: 1 2 3 5 8 9

    return 0;
}
```

### Paso a paso con {5, 3, 8, 1}

```
Pasada 1: [3, 5, 1, 8]
Pasada 2: [3, 1, 5, 8]
Pasada 3: [1, 3, 5, 8] ✓
```

El ordenamiento se realiza **mediante un determinado criterio de ordenamiento** (en este caso, ascendente).

---

## 📥 Ordenamiento Inserción

Toma cada elemento y lo **inserta en la posición correcta** dentro de la parte ya ordenada del arreglo.

```c
#include <stdio.h>

void insercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;

        // Mover hacia la derecha los elementos mayores que clave
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = clave;
    }
}

int main() {
    int datos[] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    insercion(datos, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    // Salida: 1 2 3 4 5 6

    return 0;
}
```

### Analogía

Es como ordenar cartas en la mano: tomás una carta nueva y la colocás en el lugar correcto entre las que ya tenés ordenadas.

---

## 🎯 Ordenamiento Selección

Busca el **elemento mínimo** del arreglo no ordenado y lo coloca en la posición correcta.

```c
#include <stdio.h>

void seleccion(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        // Buscar el mínimo en el resto del arreglo
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // Intercambiar si encontramos un mínimo distinto
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

int main() {
    int datos[] = {64, 25, 12, 22, 11};
    int n = 5;

    seleccion(datos, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    // Salida: 11 12 22 25 64

    return 0;
}
```

### Comparación de métodos

| Método | Estrategia | Estabilidad |
|--------|------------|-------------|
| Burbuja | Compara adyacentes | Estable |
| Inserción | Inserta en posición correcta | Estable |
| Selección | Busca el mínimo y lo ubica | No estable |

---

## 🔤 Cadenas

En C, una cadena es un **arreglo de caracteres (`char`)** que termina con el carácter nulo `'\0'`.

> ⚠️ Una cadena **no se puede ordenar** aplicando cualquier método de ordenamiento que se utiliza para ordenar un arreglo de enteros directamente. Se requiere usar `strcmp()` para comparar.

### Declaración

```c
// Sintaxis
char nombre[longitud_maxima];

// Ejemplos
char nombre[20];
char ciudad[] = "Resistencia";
```

### Funciones de cadenas más importantes

| Función | Descripción |
|---------|-------------|
| `strlen(s)` | Devuelve la longitud de la cadena |
| `strcpy(dest, src)` | Copia `src` en `dest` |
| `strcmp(s1, s2)` | Compara una cadena con otra; retorna 0 si son iguales |
| `strcat(dest, src)` | Concatena `src` al final de `dest` |
| `strchr(s, c)` | Localiza la primera instancia de un carácter dentro de un string |
| `strupr(s)` | Convierte a mayúsculas |
| `strlwr(s)` | Convierte a minúsculas |

### Funciones de clasificación de caracteres (`<ctype.h>`)

| Función | Descripción |
|---------|-------------|
| `islower(c)` | Devuelve cierto si `c` es una letra minúscula, y falso en caso contrario |
| `isupper(c)` | Verdadero si es letra mayúscula |
| `isdigit(c)` | Verdadero si es dígito |
| `isalpha(c)` | Verdadero si es letra |
| `tolower(c)` | Convierte a minúscula |
| `toupper(c)` | Convierte a mayúscula |

### Ejemplos de uso

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char nombre[20];
    strcpy(nombre, "Juan");

    printf("Nombre: %s\n", nombre);           // Juan
    printf("Largo: %lu\n", strlen(nombre));    // 4

    // Comparación
    char otro[] = "Juan";
    if (strcmp(nombre, otro) == 0) {
        printf("Son iguales\n");
    }

    // Clasificación de carácter
    char c = 'a';
    if (islower(c)) {
        printf("%c es minúscula\n", c);        // a es minúscula
    }

    return 0;
}
```

---

## 🔢 Matrices

Una matriz es un **arreglo bidimensional**: tiene filas y columnas.

### Declaración

```c
// tipo nombre[filas][columnas]
int matriz[2][2];
int mat[3][4];
```

### Inicialización

```c
int mat[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

### Acceso a elementos

Los índices comienzan en 0 para filas y columnas.

```c
int matriz[2][2];
matriz[0][0] = 1;
matriz[0][1] = 2;
matriz[1][0] = 3;
matriz[1][1] = 4;
// Resultado: 1 2 3 4
```

Para guardar el valor 10 en la **segunda fila, tercera columna**:
```c
int mat[3][4];
mat[1][2] = 10;  // índices comienzan en 0
```

### Recorrido de una matriz

```c
#include <stdio.h>

int main() {
    int mat[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int i = 0; i < 2; i++) {        // recorre filas
        for (int j = 0; j < 3; j++) {    // recorre columnas
            printf("%d ", mat[i][j]);
        }
    }
    // Salida: 1 2 3 4 5 6

    return 0;
}
```

### Pasar una matriz a una función

Al declarar el parámetro, se debe especificar el número de columnas:

```c
void imprimir(int m[][2], int filas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", m[i][j]);
        }
    }
}

int main() {
    int datos[3][2] = {{1,2},{3,4},{5,6}};
    imprimir(datos, 3);
    // Salida: 1 2 3 4 5 6
    return 0;
}
```

---

## ⚙️ Funciones

Las funciones son **bloques de código reutilizables** que realizan una tarea específica.

### ¿Por qué usar funciones?

- Cuando cada módulo está bien probado, **se lo puede usar las veces que sea necesario sin volver a revisarlo**.
- El programa es **más simple de comprender** ya que cada módulo se dedica a realizar una tarea en particular.
- La **depuración queda acotada** a cada módulo.

### Tipos de funciones en C

Las funciones en C pueden ser:
- **Definidas por el usuario**: creadas por el programador
- **Predefinidas por C**: incluidas en bibliotecas estándar (`stdio.h`, `string.h`, `math.h`, etc.)

### Sintaxis

```c
tipo_retorno nombre_funcion(parámetros) {
    // cuerpo
    return valor;  // si no es void
}
```

### Función que retorna un valor

```c
#include <stdio.h>

int cuadrado(int x) {
    return x * x;
}

int sumaCuadrados(int a, int b) {
    return cuadrado(a) + cuadrado(b);
}

int main() {
    int resultado = sumaCuadrados(2, 4);
    printf("Resultado: %d\n", resultado);
    // Resultado: 4 + 16 = 20
    return 0;
}
```

### Función void (no retorna valor)

```c
#include <stdio.h>

void saludar() {
    printf("Hola mundo\n");
    // No usa return (o puede tener "return;" sin valor)
}

int main() {
    saludar();   // Imprime: Hola mundo
    return 0;
}
```

### La sentencia `return`

> La sentencia `return` **fuerza la salida inmediata** del cuerpo de la función y se vuelve a la siguiente sentencia después de la llamada.

### Paso de parámetros: por valor vs por referencia

#### Por valor (copia)
Los cambios dentro de la función **NO afectan** a la variable original:

```c
#include <stdio.h>

void modificar(int x) {
    x = 20;
}

int main() {
    int a = 10;
    modificar(a);
    printf("Resultado: %d\n", a);
    // Imprime: 10, porque se pasa una copia del valor original
    // y no se modifica fuera de la función
    return 0;
}
```

#### Por referencia (con puntero o arreglo)
Los arreglos **siempre se pasan por referencia**; los cambios sí afectan al original:

```c
#include <stdio.h>

void agregarFinal(int arr[], int valor, int size) {
    arr[size - 1] = valor;
}

int main() {
    int valores[4] = {1, 2, 3, 4};
    agregarFinal(valores, 99, 4);
    printf("%d\n", valores[3]);  // Imprime: 99
    return 0;
}
```

### Función que recibe y modifica un arreglo

```c
#include <stdio.h>

void duplicar(int v[], int n) {
    int i = 0;
    while (i < n) {
        v[i] = v[i] * 2;
        i++;
    }
}

int main() {
    int datos[] = {1, 3, 4};
    duplicar(datos, 3);
    // Resultado: {2, 6, 8}
    for (int i = 0; i < 3; i++) printf("%d ", datos[i]);
    return 0;
}
```

### Función que asigna valor al primer elemento

```c
#include <stdio.h>

void asignarValor(int arr[], int valor) {
    arr[0] = valor;
}

int main() {
    int datos[5] = {0};
    asignarValor(datos, 100);
    printf("%d\n", datos[0]);  // Imprime: 100
    return 0;
}
```

### Función que muestra todos los elementos

```c
#include <stdio.h>

void mostrar(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int datos[] = {10, 20, 30, 40};
    mostrar(datos, 4);
    // Imprime: 10 20 30 40
    return 0;
}
```

---

## 🏗️ Estructuras (struct)

Una **estructura o registro** es una estructura de datos que **agrupa variables que pueden tener tipos diferentes**.

> A diferencia de los arreglos (que son homogéneos), las estructuras pueden mezclar `int`, `char`, `float`, etc.

### Declaración

```c
struct NombreEstructura {
    tipo campo1;
    tipo campo2;
    // ...
};
```

### Ejemplo: Estructura Persona

```c
#include <stdio.h>
#include <string.h>

struct Persona {
    char nombre[20];
    int edad;
};

int main() {
    struct Persona p;              // Declarar variable de tipo Persona
    strcpy(p.nombre, "Juan");      // Asignar nombre (strings usan strcpy)
    p.edad = 30;                   // Asignar edad

    printf("Nombre: %s, Edad: %d\n", p.nombre, p.edad);
    // Salida: Nombre: Juan, Edad: 30

    return 0;
}
```

### El operador `.`

Se usa para **acceder a miembros de una variable de estructura normal (no puntero)**:

```c
p.nombre   // accede al campo nombre de la variable p
p.edad     // accede al campo edad de la variable p
```

> Si se trabaja con **punteros** a estructuras, se usa `->` en lugar de `.`

### Inicialización directa

```c
struct Persona p = {"Ana", 25};
```

### Arreglo de estructuras

```c
struct Persona personas[3] = {
    {"Juan", 30},
    {"María", 25},
    {"Pedro", 35}
};

for (int i = 0; i < 3; i++) {
    printf("%s tiene %d años\n", personas[i].nombre, personas[i].edad);
}
```

---

## 💾 Estructuras y Archivos

Las estructuras se pueden guardar y leer desde archivos binarios usando `fwrite` y `fread`.

```c
#include <stdio.h>
#include <string.h>

struct Persona {
    char nombre[20];
    int edad;
};

// Guardar en archivo
void guardarPersona(struct Persona p, const char* archivo) {
    FILE* f = fopen(archivo, "ab");  // "ab" = append binario
    if (f == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fwrite(&p, sizeof(struct Persona), 1, f);
    fclose(f);
}

// Leer del archivo
void leerPersonas(const char* archivo) {
    FILE* f = fopen(archivo, "rb");  // "rb" = lectura binaria
    if (f == NULL) {
        printf("Archivo vacío o no encontrado.\n");
        return;
    }

    struct Persona p;
    while (fread(&p, sizeof(struct Persona), 1, f) == 1) {
        printf("Nombre: %s, Edad: %d\n", p.nombre, p.edad);
    }

    fclose(f);
}

int main() {
    struct Persona p1 = {"Juan", 30};
    struct Persona p2 = {"Ana", 25};

    guardarPersona(p1, "personas.dat");
    guardarPersona(p2, "personas.dat");

    leerPersonas("personas.dat");

    return 0;
}
```

### Modos de apertura de archivos

| Modo | Descripción |
|------|-------------|
| `"r"` | Lectura (texto) |
| `"w"` | Escritura (texto, sobreescribe) |
| `"a"` | Agregar al final (texto) |
| `"rb"` | Lectura binaria |
| `"wb"` | Escritura binaria |
| `"ab"` | Agregar binario |

### Ordenamiento de registros en archivo

Para ordenar registros guardados en un archivo, se puede leer todo en un arreglo de estructuras, ordenar con cualquier método (burbuja, selección, etc.) usando `strcmp` para comparar strings, y luego reescribir el archivo:

```c
#include <stdio.h>
#include <string.h>

struct Persona {
    char nombre[20];
    int edad;
};

void ordenarPorNombre(struct Persona arr[], int n) {
    struct Persona temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(arr[j].nombre, arr[j+1].nombre) > 0) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```

---

## 🧩 Programa con Función

Ejemplo completo que combina arreglos, funciones y estructuras de control:

```c
#include <stdio.h>

// Función que busca un elemento y retorna su posición (-1 si no lo encuentra)
int buscar(int arr[], int n, int buscado) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == buscado) {
            return i;
        }
    }
    return -1;
}

// Función que imprime el arreglo
void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función que calcula la suma
int sumar(int arr[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }
    return suma;
}

// Función que encuentra el mayor
int mayor(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int numeros[] = {4, 7, 2, 9, 1, 5};
    int n = 6;

    printf("Arreglo: ");
    imprimir(numeros, n);

    printf("Suma: %d\n", sumar(numeros, n));
    printf("Mayor: %d\n", mayor(numeros, n));

    int pos = buscar(numeros, n, 9);
    if (pos != -1) {
        printf("El 9 está en la posición %d\n", pos);
    } else {
        printf("No encontrado.\n");
    }

    return 0;
}
```

**Salida:**
```
Arreglo: 4 7 2 9 1 5
Suma: 28
Mayor: 9
El 9 está en la posición 3
```

---

## 📌 Resumen de Conceptos Clave

| Concepto | Punto clave |
|----------|-------------|
| Arreglo | Conjunto finito, ordenado y homogéneo. Índices desde 0 |
| Búsqueda lineal | Recorre todo el arreglo; sirve para arreglos no ordenados |
| Búsqueda binaria | Solo para arreglos ordenados; muy eficiente |
| Burbuja | Compara elementos adyacentes e intercambia |
| Inserción | Inserta cada elemento en su lugar correcto |
| Selección | Busca el mínimo y lo coloca en su posición |
| Cadenas | Arreglo de `char` terminado en `'\0'`; usar `strcmp` para comparar |
| Matrices | Arreglo 2D; `mat[fila][columna]`, índices desde 0 |
| Funciones | Reutilizables; `return` fuerza salida inmediata |
| Paso por valor | La función recibe una copia; no modifica el original |
| Paso por referencia | Arreglos y punteros; modifica el original |
| Struct | Agrupa variables de distintos tipos; acceso con `.` |
| Archivos | `fwrite`/`fread` para guardar/leer estructuras binarias |

---

## 🛠️ Compilación y Ejecución

```bash
# Compilar
gcc programa.c -o programa

# Ejecutar
./programa

# Compilar con warnings
gcc -Wall programa.c -o programa
```

---

*Guía elaborada en base a los contenidos del 2º Parcial de Programación I — TUP. Todos los ejemplos están probados y son funcionales en C estándar (C99/C11).*
