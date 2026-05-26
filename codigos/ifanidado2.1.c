//2.2 Indicar su un carácter ingresado por teclado es una vocal.

#include <stdio.h>

int main() {
    char vocal;
    printf("Digite un caracter: \n");
    scanf("%c", &vocal);
    if (vocal == 'a' || vocal == 'e' || vocal == 'i' || vocal == 'o' || vocal == 'u' ||
        vocal == 'A' || vocal == 'E' || vocal == 'I' || vocal == 'O' || vocal == 'U') {
        printf("El caracter es una vocal");
    } else {
        printf("El caracter no es una vocal");
    }
}