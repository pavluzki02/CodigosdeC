#include <stdio.h>
#include <string.h>

int main(){
    char palabra[100];

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    int largo = strlen(palabra);

    printf("La palabra '%s' tiene %d letras\n", palabra, largo);

    printf("Al reves: ");
    for (int i = largo-1; i >= 0; i--)
        printf("%c", palabra[i]);
    printf("\n");

    return 0;
}