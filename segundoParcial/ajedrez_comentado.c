#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura que representa una pieza de ajedrez
struct Pieza
{
  int posicion[2]; // posicion[0] = fila, posicion[1] = columna
  char tipo[20];   // tipo de pieza: peon, torre, caballo, alfil, reina, rey
  char color;      // 'b' para blanco, 'n' para negro
  int valor;       // valor numerico de la pieza (peon=1, torre=5, etc.)
  int activa;      // 1 si esta en juego, 0 si fue capturada
};

// Prototipos de funciones (declaracion anticipada para que el compilador las conozca)
void ordenarPiezas(struct Pieza piezas[], int cantidad);
struct Pieza buscarPieza(struct Pieza piezas[], int cantidad, int fila, int columna);
void listarPiezasPorValor(struct Pieza piezas[], int cantidad);
void listarPiezasPorPosicion(struct Pieza piezas[], int cantidad);
void listarPiezasActivas(struct Pieza piezas[], int cantidad);
void capturarPieza(struct Pieza piezas[], int cantidad, int fila, int columna);
void restaurarPieza(struct Pieza piezas[], int cantidad, int fila, int columna);
void modificarPieza(struct Pieza piezas[], int cantidad, int fila, int columna);
void mostrarEstadisticas(struct Pieza piezas[], int cantidad);
void agregarPieza(struct Pieza piezas[], int *cantidad, struct Pieza nuevaPieza);
char *seleccionarTipoDePieza(int numeroPieza);
int obtenerValorDePieza(int numeroPieza);
void mostrarMenu();

int main()
{
  // Arreglo de hasta 100 piezas y contador de cuantas hay cargadas
  struct Pieza piezas[100];
  int cantidad = 0;
  int opcion;

  // Bucle principal del programa: se repite hasta que el usuario elija salir (opcion 10)
  do
  {
    mostrarMenu();
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
    {
      // Se crea una nueva pieza y se piden sus datos al usuario
      struct Pieza nueva;
      printf("Fila: ");
      scanf("%d", &nueva.posicion[0]);
      printf("Columna: ");
      scanf("%d", &nueva.posicion[1]);

      int numeroPieza;
      printf("Seleccione el tipo de pieza:\n");
      printf("1. Peon\n2. Torre\n3. Caballo\n4. Alfil\n5. Reina\n6. Rey\n");
      printf("Ingrese una opcion: ");
      scanf("%d", &numeroPieza);

      // Se asigna el tipo y valor segun el numero elegido
      strcpy(nueva.tipo, seleccionarTipoDePieza(numeroPieza));
      printf("Color ('b' blanco, 'n' negro): ");
      scanf(" %c", &nueva.color); // el espacio antes de %c descarta el salto de linea anterior
      nueva.valor = obtenerValorDePieza(numeroPieza);
      nueva.activa = 1; // toda pieza nueva empieza activa
      agregarPieza(piezas, &cantidad, nueva);
      break;
    }
    case 2:
      listarPiezasPorValor(piezas, cantidad);
      break;
    case 3:
    {
      // Se pide la posicion y se busca la pieza en el arreglo
      int fila, columna;
      printf("Fila de la pieza a buscar: ");
      scanf("%d", &fila);
      printf("Columna de la pieza a buscar: ");
      scanf("%d", &columna);

      struct Pieza encontrada = buscarPieza(piezas, cantidad, fila, columna);
      // Si posicion[0] es -1 significa que no se encontro ninguna pieza
      if (encontrada.posicion[0] != -1)
        printf("Posicion: (%d,%d), Tipo: %s, Color: %c, Valor: %d\n",
               encontrada.posicion[0], encontrada.posicion[1], encontrada.tipo, encontrada.color, encontrada.valor);
      else
        printf("Pieza no encontrada.\n");
      break;
    }
    case 4:
      listarPiezasPorPosicion(piezas, cantidad);
      break;
    case 5:
      listarPiezasActivas(piezas, cantidad);
      break;
    case 6:
    {
      int fila, columna;
      printf("Fila de la pieza a capturar: ");
      scanf("%d", &fila);
      printf("Columna de la pieza a capturar: ");
      scanf("%d", &columna);
      capturarPieza(piezas, cantidad, fila, columna);
      break;
    }
    case 7:
    {
      int fila, columna;
      printf("Fila de la pieza a restaurar: ");
      scanf("%d", &fila);
      printf("Columna de la pieza a restaurar: ");
      scanf("%d", &columna);
      restaurarPieza(piezas, cantidad, fila, columna);
      break;
    }
    case 8:
    {
      int fila, columna;
      printf("Fila de la pieza a modificar: ");
      scanf("%d", &fila);
      printf("Columna de la pieza a modificar: ");
      scanf("%d", &columna);
      modificarPieza(piezas, cantidad, fila, columna);
      break;
    }
    case 9:
      mostrarEstadisticas(piezas, cantidad);
      break;
    case 10:
      printf("Saliendo...\n");
      break;
    default:
      printf("Opcion invalida.\n");
    }

  } while (opcion != 10);

  return 0;
}

// Recorre el arreglo buscando una pieza en la fila y columna indicadas.
// Si la encuentra la devuelve. Si no, devuelve una pieza con posicion[0] = -1 como señal de "no encontrada".
struct Pieza buscarPieza(struct Pieza piezas[], int cantidad, int fila, int columna)
{
  for (int i = 0; i < cantidad; i++)
  {
    if (piezas[i].posicion[0] == fila && piezas[i].posicion[1] == columna)
      return piezas[i];
  }
  // Pieza "vacia" que se usa como valor de error
  struct Pieza noEncontrada;
  noEncontrada.posicion[0] = -1;
  noEncontrada.posicion[1] = -1;
  return noEncontrada;
}

// Lista todas las piezas ordenadas de mayor a menor valor.
// Trabaja sobre una copia del arreglo para no alterar el orden original.
void listarPiezasPorValor(struct Pieza piezas[], int cantidad)
{
  // Copia el arreglo original en uno temporal
  struct Pieza copia[100];
  for (int i = 0; i < cantidad; i++)
    copia[i] = piezas[i];

  // Bubble Sort: ordena de mayor a menor segun el campo valor
  struct Pieza aux;
  for (int i = 0; i < cantidad - 1; i++)
    for (int j = 0; j < cantidad - i - 1; j++)
      if (copia[j].valor < copia[j + 1].valor) // si el de la izquierda vale menos, intercambia
      {
        aux = copia[j];
        copia[j] = copia[j + 1];
        copia[j + 1] = aux;
      }

  printf("\nPiezas ordenadas por valor:\n");
  for (int i = 0; i < cantidad; i++)
    printf("Posicion: (%d,%d), Tipo: %s, Color: %c, Valor: %d, %s\n",
           copia[i].posicion[0], copia[i].posicion[1], copia[i].tipo,
           copia[i].color, copia[i].valor,
           copia[i].activa ? "activa" : "capturada"); // operador ternario para mostrar el estado
}

// Lista todas las piezas ordenadas por posicion (primero por fila, luego por columna).
// Tambien trabaja sobre una copia para no modificar el arreglo original.
void listarPiezasPorPosicion(struct Pieza piezas[], int cantidad)
{
  struct Pieza copia[100];
  for (int i = 0; i < cantidad; i++)
    copia[i] = piezas[i];

  // Bubble Sort: ordena por fila; si la fila es igual, desempata por columna
  struct Pieza aux;
  for (int i = 0; i < cantidad - 1; i++)
    for (int j = 0; j < cantidad - i - 1; j++)
      if (copia[j].posicion[0] > copia[j + 1].posicion[0] ||
          (copia[j].posicion[0] == copia[j + 1].posicion[0] &&
           copia[j].posicion[1] > copia[j + 1].posicion[1]))
      {
        aux = copia[j];
        copia[j] = copia[j + 1];
        copia[j + 1] = aux;
      }

  printf("\nPiezas ordenadas por posicion:\n");
  for (int i = 0; i < cantidad; i++)
    printf("Posicion: (%d,%d), Tipo: %s, Color: %c, Valor: %d\n",
           copia[i].posicion[0], copia[i].posicion[1], copia[i].tipo,
           copia[i].color, copia[i].valor);
}

// Recorre el arreglo y muestra solo las piezas con activa == 1
void listarPiezasActivas(struct Pieza piezas[], int cantidad)
{
  printf("\nPiezas activas:\n");
  int encontradas = 0;
  for (int i = 0; i < cantidad; i++)
    if (piezas[i].activa == 1)
    {
      printf("Posicion: (%d,%d), Tipo: %s, Color: %c, Valor: %d\n",
             piezas[i].posicion[0], piezas[i].posicion[1], piezas[i].tipo,
             piezas[i].color, piezas[i].valor);
      encontradas++;
    }
  if (encontradas == 0)
    printf("No hay piezas activas.\n");
}

// Busca la pieza en la posicion indicada y pone activa = 0 (capturada)
void capturarPieza(struct Pieza piezas[], int cantidad, int fila, int columna)
{
  for (int i = 0; i < cantidad; i++)
    if (piezas[i].posicion[0] == fila && piezas[i].posicion[1] == columna)
    {
      piezas[i].activa = 0;
      printf("Pieza en posicion (%d,%d) capturada.\n", fila, columna);
      return;
    }
  printf("Pieza en posicion (%d,%d) no encontrada.\n", fila, columna);
}

// Busca la pieza en la posicion indicada y permite cambiar su fila, columna y color
void modificarPieza(struct Pieza piezas[], int cantidad, int fila, int columna)
{
  for (int i = 0; i < cantidad; i++)
    if (piezas[i].posicion[0] == fila && piezas[i].posicion[1] == columna)
    {
      printf("Nueva fila: ");
      scanf("%d", &piezas[i].posicion[0]);
      printf("Nueva columna: ");
      scanf("%d", &piezas[i].posicion[1]);
      printf("Nuevo color ('b' blanco, 'n' negro): ");
      scanf(" %c", &piezas[i].color);
      printf("Pieza modificada correctamente.\n");
      return;
    }
  printf("Pieza en posicion (%d,%d) no encontrada.\n", fila, columna);
}

// Ordena el arreglo original por posicion usando Bubble Sort (fila primero, columna como desempate)
void ordenarPiezas(struct Pieza piezas[], int cantidad)
{
  struct Pieza aux;
  for (int i = 0; i < cantidad - 1; i++)
    for (int j = 0; j < cantidad - i - 1; j++)
      if (piezas[j].posicion[0] > piezas[j + 1].posicion[0] ||
          (piezas[j].posicion[0] == piezas[j + 1].posicion[0] &&
           piezas[j].posicion[1] > piezas[j + 1].posicion[1]))
      {
        aux = piezas[j];
        piezas[j] = piezas[j + 1];
        piezas[j + 1] = aux;
      }
}

// Busca la pieza por posicion y la marca como activa nuevamente (activa = 1)
void restaurarPieza(struct Pieza piezas[], int cantidad, int fila, int columna)
{
  for (int i = 0; i < cantidad; i++)
    if (piezas[i].posicion[0] == fila && piezas[i].posicion[1] == columna)
    {
      piezas[i].activa = 1;
      printf("Pieza en posicion (%d,%d) restaurada.\n", fila, columna);
      return;
    }
  printf("Pieza en posicion (%d,%d) no encontrada.\n", fila, columna);
}

// Cuenta cuantas piezas tienen activa == 1 y cuantas == 0, y muestra el resumen
void mostrarEstadisticas(struct Pieza piezas[], int cantidad)
{
  int activas = 0, capturadas = 0;
  for (int i = 0; i < cantidad; i++)
    if (piezas[i].activa == 1)
      activas++;
    else
      capturadas++;
  printf("Total de piezas: %d\n", cantidad);
  printf("Activas: %d\n", activas);
  printf("Capturadas: %d\n", capturadas);
}

// Agrega una nueva pieza al arreglo si no se supero el limite de 100.
// Recibe cantidad por puntero para poder modificar la variable original del main.
void agregarPieza(struct Pieza piezas[], int *cantidad, struct Pieza nuevaPieza)
{
  if (*cantidad < 100)
  {
    piezas[*cantidad] = nuevaPieza; // se guarda en la posicion actual del contador
    (*cantidad)++;                  // se incrementa el contador (con parentesis por precedencia)
    printf("Pieza agregada: Posicion (%d,%d), Tipo: %s, Color: %c\n",
           nuevaPieza.posicion[0], nuevaPieza.posicion[1], nuevaPieza.tipo, nuevaPieza.color);
  }
  else
    printf("No se pueden agregar mas piezas. Capacidad maxima alcanzada.\n");
}

// Devuelve el nombre del tipo de pieza segun el numero elegido en el menu
char *seleccionarTipoDePieza(int numeroPieza)
{
  switch (numeroPieza)
  {
  case 1: return "peon";
  case 2: return "torre";
  case 3: return "caballo";
  case 4: return "alfil";
  case 5: return "reina";
  case 6: return "rey";
  default: return "desconocida";
  }
}

// Devuelve el valor numerico de la pieza segun el estandar del ajedrez
int obtenerValorDePieza(int numeroPieza)
{
  switch (numeroPieza)
  {
  case 1: return 1;  // peon
  case 2: return 5;  // torre
  case 3: return 3;  // caballo
  case 4: return 3;  // alfil
  case 5: return 9;  // reina
  case 6: return 100; // rey (valor alto para indicar que es irremplazable)
  default: return 0;
  }
}

// Muestra el menu principal con todas las opciones disponibles
void mostrarMenu()
{
  printf("\nMenu de opciones:\n");
  printf("1. Agregar pieza\n");
  printf("2. Listar piezas por valor\n");
  printf("3. Buscar pieza por posicion\n");
  printf("4. Listar piezas por posicion\n");
  printf("5. Mostrar piezas activas\n");
  printf("6. Capturar pieza\n");
  printf("7. Restaurar pieza\n");
  printf("8. Modificar pieza\n");
  printf("9. Mostrar estadisticas (activas/capturadas)\n");
  printf("10. Salir\n");
}
