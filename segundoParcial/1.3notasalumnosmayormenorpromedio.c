#include <stdio.h>

int main() {
    float notas[5];
    float acum = 0, mayor, menor;
    int i;

    printf("Ingrese las 5 notas del alumno (entre 0 y 10):\n");
    for (i = 0; i < 5; i++) {
        do {
            printf("Nota %d: ", i + 1);
            scanf("%f", &notas[i]);
        } while (notas[i] < 0 || notas[i] > 10);
        acum += notas[i];
    }

    mayor = notas[0];
    menor = notas[0];
    for (i = 1; i < 5; i++) {
        if (notas[i] > mayor) mayor = notas[i];
        if (notas[i] < menor) menor = notas[i];
    }

    printf("\nNotas ingresadas: ");
    for (i = 0; i < 5; i++) printf("%.1f ", notas[i]);
    printf("\nPromedio:    %.2f\n", acum / 5);
    printf("Nota mayor:  %.1f\n", mayor);
    printf("Nota menor:  %.1f\n", menor);

    return 0;
}
