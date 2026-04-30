#include <stdio.h>

int main() {
    int num, suma = 0;

    do {
        printf("Ingrese un numero entero: ");
        scanf("%d", &num);

        suma += num;

        if (!(suma % 2 == 0 && suma > 20)) {
            printf("OK\n");
        }

    } while (!(suma % 2 == 0 && suma > 20));

    printf("Total acumulado: %d\n", suma);

    return 0;
}