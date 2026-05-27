#include <stdio.h>

int main() {
    int A[10] = {5, 3, 8, 1, 9, 2, 7, 4, 6, 10};
    int B[10];
    int E[20];
    int tamE = 0;
    int i, j, aux, existe, num, clave;

    printf("Ingrese 10 valores para el arreglo B:\n");
    for (i = 0; i < 10; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    for (i = 0; i < 10; i++) {
        existe = 0;
        for (j = 0; j < tamE; j++) {
            if (E[j] == A[i]) {
                existe = 1;
                break;
            }
        }
        if (!existe) {
            E[tamE] = A[i];
            tamE++;
        }
    }

    for (i = 0; i < 10; i++) {
        existe = 0;
        for (j = 0; j < tamE; j++) {
            if (E[j] == B[i]) {
                existe = 1;
                break;
            }
        }
        if (!existe) {
            E[tamE] = B[i];
            tamE++;
        }
    }

    for (i = 1; i < tamE; i++) {
        clave = E[i];
        j = i - 1;
        while (j >= 0 && E[j] > clave) {
            E[j + 1] = E[j];
            j--;
        }
        E[j + 1] = clave;
    }

    printf("\nArreglo A: ");
    for (i = 0; i < 10; i++) printf("%d ", A[i]);

    printf("\nArreglo B: ");
    for (i = 0; i < 10; i++) printf("%d ", B[i]);

    printf("\nArreglo E (ordenado, sin repetidos): ");
    for (i = 0; i < tamE; i++) printf("%d ", E[i]);

    printf("\n\nIngrese un numero para buscar en E: ");
    scanf("%d", &num);

    int izq = 0, der = tamE - 1, mid, encontrado = 0;

    if (num >= E[0] && num <= E[tamE - 1]) {
        while (izq <= der) {
            mid = (izq + der) / 2;
            if (E[mid] == num) {
                encontrado = 1;
                break;
            } else if (E[mid] < num) {
                izq = mid + 1;
            } else {
                der = mid - 1;
            }
        }
        printf("%s en el arreglo E.\n", encontrado ? "Encontrado" : "No encontrado");
    } else {
        printf("El numero esta fuera del rango del arreglo E.\n");
    }

    return 0;
}
