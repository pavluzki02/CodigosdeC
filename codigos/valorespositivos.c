//2.3 Hacer un programa que lea tres números enteros positivos distintos e imprima el mayor valor de los tres.
#include <stdio.h>

int main () {
    int a,b,c;
    printf("Digite 1° numero: \n");
    scanf("%d", &a);
        printf("Digite 2° numero: \n");
    scanf("%d", &b);
        printf("Digite 3° numero: \n");
    scanf("%d", &c);

    if (a > b && a > c) {
        printf("El numero mayor es %d", a);

    }
    else if (b > a && b > c) {
        printf("El numero mayor es %d", b);

    }
        else if (c > a && c > b) {
        printf("El numero mayor es %d", c);
    }
    else {
        printf("Los numeros son iguales");
    }
}