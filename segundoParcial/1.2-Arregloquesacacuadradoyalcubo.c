#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int vector_numeros[10];
    int i;

    srand(time(NULL));

    for (i = 0; i < 10; i++) {
        vector_numeros[i] = (rand() % 10) + 1;
    }

    printf("%-10s %-15s %-15s\n", "Numero", "Cuadrado", "Cubo");
    printf("----------------------------------------\n");
    for (i = 0; i < 10; i++) {
        printf("%-10d %-15.0f %-15.0f\n",
               vector_numeros[i],
               pow(vector_numeros[i], 2),
               pow(vector_numeros[i], 3));
    }

    return 0;
}