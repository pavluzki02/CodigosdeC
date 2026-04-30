//4.1 Escribir un programa que pregunte al usuario su edad y muestre por pantalla todos los años que ha cumplido (desde 1 hasta su edad).
#include <stdio.h>

int main() {
    int edad, i;

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    for (i = 1; i <= edad; i++) {
        printf("%d\n", i);
    }

    return 0;
}