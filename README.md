# 📚 TUPProgI — Guía de Conceptos: Arreglos, Cadenas, Matrices, Funciones y Estructuras en C

> Guía completa de los temas del 2º Parcial de Programación I (TUP). Incluye teoría, ejemplos de código y explicaciones detalladas de cada concepto.

---

## 📋 Índice

- [Arreglos](#-arreglos)
- [Búsqueda Lineal](#-búsqueda-lineal)
- [Búsqueda Binaria](#-búsqueda-binaria)
- [Búsqueda Binaria con Eliminación de Elemento](#-búsqueda-binaria-con-eliminación-de-elemento)
- [Swap (Intercambio)](#-swap-intercambio)
- [Ordenamiento Burbuja (Bubble Sort)](#-ordenamiento-burbuja-bubble-sort)
- [Ordenamiento Inserción (Insertion Sort)](#-ordenamiento-inserción-insertion-sort)
- [Ordenamiento Selección (Selection Sort)](#-ordenamiento-selección-selection-sort)
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

## 🔄 Swap (Intercambio)

El **swap** es la operación de **intercambiar los valores de dos variables**. Es la operación fundamental que usan los algoritmos de ordenamiento (Burbuja y Selección) para mover elementos a su posición correcta.

Para intercambiar dos variables se necesita una **variable auxiliar temporal** (`temp`). Sin ella, uno de los valores se perdería.

```c
int a = 5, b = 10;

// ✅ CORRECTO: usando variable auxiliar
int temp = a;  // temp = 5
a = b;         // a = 10
b = temp;      // b = 5

printf("a=%d, b=%d\n", a, b);  // a=10, b=5
```

```c
// ❌ INCORRECTO: sin auxiliar (se pierde el valor de a)
a = b;  // a = 10 (el 5 original se pierde)
b = a;  // b = 10 (ya no hay forma de recuperar el 5)
```

Como función reutilizable (requiere punteros):

```c
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int a = 3, b = 7;
swap(&a, &b);
printf("a=%d, b=%d\n", a, b);  // a=7, b=3
```

---

## 🫧 Ordenamiento Burbuja (Bubble Sort)

El **Bubble Sort** (o método burbuja) es un algoritmo de ordenamiento que compara elementos **adyacentes** e intercambia los que están en el orden incorrecto, repitiendo el proceso hasta que el arreglo queda completamente ordenado.

**¿Por qué se llama "burbuja"?** Porque los elementos más grandes "burbujean" hacia el final del arreglo en cada pasada, igual que las burbujas suben al tope de un líquido.

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

## 📥 Ordenamiento Inserción (Insertion Sort)

El **Insertion Sort** es un algoritmo de ordenamiento que divide el arreglo conceptualmente en dos partes: una parte **ya ordenada** (izquierda) y una parte **sin ordenar** (derecha). En cada paso, toma el primer elemento de la parte sin ordenar y lo **inserta en la posición correcta** dentro de la parte ordenada, desplazando los demás hacia la derecha si es necesario.

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

## 🎯 Ordenamiento Selección (Selection Sort)

El **Selection Sort** es un algoritmo de ordenamiento que en cada pasada **busca el elemento mínimo** del segmento no ordenado del arreglo y lo coloca en su posición definitiva mediante un swap. Repite este proceso hasta que todo el arreglo queda ordenado.

**Idea clave:** en cada iteración "selecciona" el menor elemento restante y lo pone donde corresponde.

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

| Método | Definición | Estrategia | Usa Swap |
|--------|------------|------------|----------|
| **Bubble Sort** | Compara pares de elementos adyacentes y los intercambia si están en orden incorrecto, "burbujeando" los mayores al final | Compara adyacentes | ✅ Sí |
| **Insertion Sort** | Toma cada elemento de la parte no ordenada y lo inserta en su posición correcta dentro de la parte ya ordenada | Desplaza e inserta | ❌ Desplaza |
| **Selection Sort** | En cada pasada busca el elemento mínimo del segmento no ordenado y lo intercambia con el primero de ese segmento | Busca mínimo y ubica | ✅ Sí |

---

## 🔤 Cadenas

En C, una cadena es un **arreglo de caracteres (`char`)** que termina con el carácter nulo `'\0'`.

> ⚠️ Una cadena **no se puede ordenar** aplicando cualquier método de ordenamiento que se utiliza para ordenar un arreglo de enteros directamente. Se requiere usar `strcmp()` para comparar.

### El carácter nulo `'\0'`

`'\0'` es el **carácter nulo** (valor ASCII 0) que marca el **fin de una cadena** en C. Toda cadena de texto termina con este carácter de forma automática cuando se usa una cadena literal.

```c
char saludo[] = "Hola";
// En memoria se almacena: 'H' 'o' 'l' 'a' '\0'
// El arreglo ocupa 5 posiciones, no 4
```

> ⚠️ Si olvidás el `'\0'`, las funciones de cadena como `printf("%s")` o `strlen()` seguirán leyendo memoria hasta encontrar un 0, causando comportamiento impredecible.

```c
// Forma manual de poner el terminador
char nombre[6];
nombre[0] = 'J';
nombre[1] = 'u';
nombre[2] = 'a';
nombre[3] = 'n';
nombre[4] = '\0';  // ← imprescindible
```

### El especificador `%s`

`%s` es el **especificador de formato para cadenas** en `printf` y `scanf`. Le indica a la función que debe leer o imprimir una cadena de caracteres (hasta encontrar `'\0'`).

```c
char nombre[] = "Juan";

printf("%s\n", nombre);        // Imprime: Juan
printf("Hola, %s!\n", nombre); // Imprime: Hola, Juan!

// Leer una cadena (sin espacios)
char ciudad[20];
scanf("%s", ciudad);   // Lee hasta el primer espacio o Enter
```

> ⚠️ `scanf("%s")` **no lee espacios**. Para leer una línea completa con espacios, se usa `fgets()`.

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
| `strlen(s)` | Devuelve la **longitud** de la cadena (sin contar el `'\0'`) |
| `strcpy(dest, src)` | **Copia** el contenido de `src` en `dest` |
| `strcmp(s1, s2)` | **Compara** dos cadenas; retorna 0 si son iguales, negativo si `s1 < s2`, positivo si `s1 > s2` |
| `strcat(dest, src)` | **Concatena** (une) `src` al final de `dest` |
| `strchr(s, c)` | Localiza la **primera instancia** de un carácter dentro de un string |
| `fgets(dest, n, stdin)` | Lee una línea completa **incluyendo espacios** |
| `strupr(s)` | Convierte a mayúsculas |
| `strlwr(s)` | Convierte a minúsculas |

---

### Definiciones detalladas

#### `strlen(s)`

Devuelve la cantidad de caracteres de la cadena **sin contar el `'\0'`**.

```c
#include <string.h>

char texto[] = "Hola";
int largo = strlen(texto);
printf("%d\n", largo);  // Imprime: 4
```

#### `strcpy(dest, src)`

**Copia** la cadena `src` (fuente) dentro de `dest` (destino), incluyendo el `'\0'` final. En C no se puede asignar una cadena con `=` directamente, por eso se usa `strcpy`.

```c
#include <string.h>

char destino[20];
strcpy(destino, "Juan");
printf("%s\n", destino);  // Imprime: Juan

// ❌ INCORRECTO en C:
// destino = "Juan";  → error de compilación
```

#### `strcmp(s1, s2)`

**Compara** dos cadenas carácter por carácter (según su valor ASCII).

| Resultado | Significado |
|-----------|-------------|
| `0` | Las cadenas son **iguales** |
| `< 0` | `s1` es **menor** que `s2` (alfabéticamente anterior) |
| `> 0` | `s1` es **mayor** que `s2` (alfabéticamente posterior) |

```c
#include <string.h>

char a[] = "Juan";
char b[] = "Juan";
char c[] = "Ana";

if (strcmp(a, b) == 0) printf("Iguales\n");       // ✓ Iguales
if (strcmp(c, a) < 0)  printf("Ana va antes\n");  // ✓ Ana < Juan
```

#### `strcat(dest, src)`

**Concatena** (une) la cadena `src` al final de `dest`. El destino debe tener suficiente espacio para albergar ambas cadenas.

```c
#include <string.h>

char saludo[30] = "Hola, ";
strcat(saludo, "Mundo!");
printf("%s\n", saludo);  // Imprime: Hola, Mundo!
```

#### `fgets(dest, n, stdin)`

Lee una línea completa desde el teclado, **incluyendo espacios**, hasta `n-1` caracteres. Es la alternativa segura a `scanf("%s")` cuando la entrada puede contener espacios.

```c
#include <stdio.h>

char nombre[50];
printf("Ingresá tu nombre completo: ");
fgets(nombre, 50, stdin);
printf("Nombre: %s", nombre);
// Entrada: "Juan Perez"
// Salida:  "Nombre: Juan Perez"
```

> 💡 `fgets` incluye el `'\n'` (Enter) al final de la cadena. Si molesta, se puede eliminar así:
> ```c
> nombre[strcspn(nombre, "\n")] = '\0';
> ```

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
| Swap | Intercambio de dos valores usando una variable auxiliar `temp` |
| Bubble Sort | Compara e intercambia elementos adyacentes hasta ordenar |
| Insertion Sort | Inserta cada elemento en su posición dentro de la parte ordenada |
| Selection Sort | Busca el mínimo en cada pasada y lo coloca en su posición definitiva |
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
