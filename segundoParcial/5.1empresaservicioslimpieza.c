#include <stdio.h>
#include <string.h>

#define MAX 100
// el tipo de cliente E o P
typedef struct {
    int numCliente;
    char tipoCliente; 
    char nombre[50];
    char celu[20];
} Cliente;

// Carga los datos de cliente primero
int cargar(Cliente clientes[]) {
    int n;

    printf("Cuantos clientes se registran? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n ----Cliente---- %d \n", i+1);
        printf("Nro Cliente: ");
        scanf("%d", &clientes[i].numCliente);
        printf("Tipo (E/P): ");
        scanf(" %c", &clientes[i].tipoCliente);
        printf("Nombre: ");
        scanf(" %[^\n]", clientes[i].nombre);
        printf("celu: ");
        scanf(" %s", clientes[i].celu);
    }
    return n;
}

// Ordenar el num cliente por burbuja
void ordenar(Cliente clientes[], int n) {
    Cliente temp;
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1-i; j++)
            if (clientes[j].numCliente > clientes[j+1].numCliente) {
                temp = clientes[j];
                clientes[j] = clientes[j+1];
                clientes[j+1] = temp;
            }
}

// Mostrar listado
void mostrar(Cliente clientes[], int n) {
    int totalE = 0, totalP = 0;
    printf("\n%-15s %-15s %-20s %-15s\n", "Num.Cliente", "Tipo-Cliente", "Nombre", "Nro. Contacto");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-15d %-15c %-20s %-15s\n",
            clientes[i].numCliente,
            clientes[i].tipoCliente,
            clientes[i].nombre,
            clientes[i].celu);
        if (clientes[i].tipoCliente == 'E') totalE++;
        else totalP++;
    }
    printf("--------------------------------------------------------------\n");
    printf("Total de Clientes: %d\n", n);
    printf("Total de Clientes Tipo E: %d\n", totalE);
    printf("Total de Clientes Tipo P: %d\n", totalP);
}

// creamos Busqueda binaria por numCliente
int busquedaBinaria(Cliente clientes[], int n, int nroBuscar) {
    int ini = 0, fin = n-1;
    while (ini <= fin) {
        int mid = (ini + fin) / 2;
        if (clientes[mid].numCliente == nroBuscar)
            return mid;
        else if (clientes[mid].numCliente < nroBuscar)
            ini = mid + 1;
        else
            fin = mid - 1;
    }
    return -1;
}

// SE encarga de separar los arreglos de tipos P y E
void separar(Cliente clientes[], int n,
             Cliente tipoE[], int *nE,
             Cliente tipoP[], int *nP) {
    *nE = 0;
    *nP = 0;
    for (int i = 0; i < n; i++) {
        if (clientes[i].tipoCliente == 'E')
            tipoE[(*nE)++] = clientes[i];
        else
            tipoP[(*nP)++] = clientes[i];
    }
}

int main() {
    Cliente clientes[MAX], tipoE[MAX], tipoP[MAX];
    int n, nE, nP;

    n = cargar(clientes);
    ordenar(clientes, n);
    mostrar(clientes, n);

    // Busqueda binaria
    int nroBuscar;
    printf("\nIngrese Nro. Cliente a buscar: ");
    scanf("%d", &nroBuscar);
    int pos = busquedaBinaria(clientes, n, nroBuscar);
    if (pos != -1)
        printf("Cliente encontrado: %s (Tipo: %c, celu: %s)\n",
            clientes[pos].nombre, clientes[pos].tipoCliente, clientes[pos].celu);
    else
        printf("Cliente no encontrado.\n");

    // Separar por tipo
    separar(clientes, n, tipoE, &nE, tipoP, &nP);
    printf("\n--- Clientes Tipo E ---\n");
    mostrar(tipoE, nE);
    printf("\n--- Clientes Tipo P ---\n");
    mostrar(tipoP, nP);

    return 0;
}