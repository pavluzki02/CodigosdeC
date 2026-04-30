//3.2 Realizar un programa de acuerdo al siguiente enunciado:
#include <stdio.h>

int main() {
    int num, num2, opcion;
    float resul;

    // Entrada
    printf("Ingrese el primer numero: ");
    scanf("%d", &num);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    // Menú
    printf("\nSeleccione una operacion:\n");
    printf("1 - Suma\n");
    printf("2 - Resta\n");
    printf("3 - Multiplicacion\n");
    printf("4 - Division\n");
    scanf("%d", &opcion);

    // Proceso con switch
    switch(opcion) {
        case 1:
            resul = num + num2;
            printf("El Resultado es: %.2f\n", resul);
            break;

        case 2:
            resul = num - num2;
            printf("El Resultado es: %.2f\n", resul);
            break;

        case 3:
            resul = num * num2;
            printf("El Resultado es: %.2f\n", resul);
            break;

        case 4:
            if (num2 != 0) {
                resul = (float) num / num2;
                printf("El Resultado es: %.2f\n", resul);
            } else {
                printf("Error: no se puede dividir por cero\n");
            }
            break;

        default:
            printf("Opcion invalida\n");
    }

    return 0;
}