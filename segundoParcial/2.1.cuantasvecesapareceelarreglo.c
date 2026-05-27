#include <stdio.h>

int main() {
    int A[10] = {5, 3, 8, 1, 9, 2, 7, 4, 6, 10};
    int B[10];
    int C[10];
    int i, num, contador = 0;

    printf("Cargue el arreglo B (10 valores):\n");
    for (i = 0; i < 10; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    for (i = 0; i < 10; i++) {
        C[i] = A[i] + B[i];
    }

    printf("\nArreglo C: ");
    for (i = 0; i < 10; i++) printf("%d ", C[i]);

    printf("\n\nIngrese el valor a buscar en C: ");
    scanf("%d", &num);

    for (i = 0; i < 10; i++) {
        if (C[i] == num) contador++;
    }

    printf("El valor %d aparece %d vez/veces en el arreglo C.\n", num, contador);

    return 0;
}
