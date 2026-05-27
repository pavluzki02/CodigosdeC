#include <stdio.h>

int main() {
    int A[10] = {5, 3, 8, 1, 9, 2, 7, 4, 6, 10};
    int B[10];
    int C[10];
    int D[20];
    int tamD = 0;
    int i, j, aux, existe, num;

    printf("Ingrese 10 valores para el arreglo B:\n");
    for (i = 0; i < 10; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    for (i = 0; i < 10; i++) {
        C[i] = A[i] + B[i];
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (A[j] < A[j + 1]) {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (B[j] < B[j + 1]) {
                aux = B[j];
                B[j] = B[j + 1];
                B[j + 1] = aux;
            }
        }
    }

    for (i = 0; i < 10; i++) {
        existe = 0;
        for (j = 0; j < tamD; j++) {
            if (D[j] == A[i]) {
                existe = 1;
                break;
            }
        }
        if (!existe) {
            D[tamD] = A[i];
            tamD++;
        }
    }

    for (i = 0; i < 10; i++) {
        existe = 0;
        for (j = 0; j < tamD; j++) {
            if (D[j] == B[i]) {
                existe = 1;
                break;
            }
        }
        if (!existe) {
            D[tamD] = B[i];
            tamD++;
        }
    }

    printf("\nArreglo A ordenado: ");
    for (i = 0; i < 10; i++) printf("%d ", A[i]);

    printf("\nArreglo B ordenado: ");
    for (i = 0; i < 10; i++) printf("%d ", B[i]);

    printf("\nArreglo C (A+B):    ");
    for (i = 0; i < 10; i++) printf("%d ", C[i]);

    printf("\nArreglo D (sin rep): ");
    for (i = 0; i < tamD; i++) printf("%d ", D[i]);

    printf("\n\nIngrese un numero para buscar en D: ");
    scanf("%d", &num);

    int izq = 0, der = tamD - 1, mid, encontrado = 0;
    while (izq <= der) {
        mid = (izq + der) / 2;
        if (D[mid] == num) {
            encontrado = 1;
            break;
        } else if (D[mid] > num) {
            izq = mid + 1;
        } else {
            der = mid - 1;
        }
    }

    printf("Resultado: %d\n", encontrado);

    return 0;
}