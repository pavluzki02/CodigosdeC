//4.4 Escribir un programa que permita determinar si un número entero que se ingresa por   teclado es perfecto. Un número es perfecto si es igual a la suma de sus divisores propios

#include <stdio.h>

int main() {
    int num;
    int suma = 0;

    printf("Digite un numero : ");
    scanf("%d", &num);

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }

    if (suma == num) {
        printf("El numero es perfecto\n");
    } else {
        printf("El numero NO es perfecto\n");
    }

    return 0;
}