#include <stdio.h>

int main() {
    int n, num;
    int c15 = 0, c50 = 0, c_rango = 0;
    int i = 0;

    printf("Ingrese la cantidad de numeros: ");
    scanf("%d", &n);

    if (n > 0) {
        do {
            printf("Ingrese un numero: ");
            scanf("%d", &num);

            if (num < 15) {
                c15++;
            }

            if (num > 50) {
                c50++;
            }

            if (num > 25 && num < 45) {
                c_rango++;
            }

            i++;
        } while (i < n);
    }

    printf("Menores a 15: %d\n", c15);
    printf("Mayores a 50: %d\n", c50);
    printf("Entre 25 y 45: %d\n", c_rango);

    return 0;
}