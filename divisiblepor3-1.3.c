#include <stdio.h>

int main() {
    int num;
    printf("Digite un numero: \n");
    scanf("%d", &num);
    if (num % 3 == 0) {
        printf("El numero es divisible por 3");
    } else {
        printf("El numero no es divisible por 3");
    }
    return 0;
}