#include <stdio.h>
#include <string.h>

int main(){
    char frase[200];
    char letra;
    int contador = 0;

    printf("Ingrese una frase: ");
    scanf(" %[^\n]", frase);

    printf("Ingrese una letra: ");
    scanf(" %c", &letra);

    for (int i = 0; i < strlen(frase); i++){
        if (frase[i] == letra)
            contador++;
    }

    printf("La letra '%c' aparece %d veces en la frase.\n", letra, contador);

    return 0;
}