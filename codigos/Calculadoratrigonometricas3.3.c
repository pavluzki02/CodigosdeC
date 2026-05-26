//3.3 Crear una calculadora de funciones trigonométricas. Dado un ángulo ingresado por el usuario (en grados) se debe calcular a una de las 3 funciones trigonométricas básicas.
#include <stdio.h>
#include <math.h>


int main() {
    int opcion;
    float ang, radia, resul;
    printf("Ingrese los grados de un angulo: ");
    scanf("%f", &ang);

    radia = ang * 3.1416 / 180;

    printf("\nSeleccione la función trigonometrica:\n");
    printf("1 - Seno\n");
    printf("2 - Coseno\n");
    printf("3 - Tangente\n");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            resul = sin(radia);
            printf("El Seno es : %.4f\n", resul);
            break;

        case 2:
            resul = cos(radia);
            printf("El Coseno es : %.4f\n", resul);
            break;

        case 3:
            resul = tan(radia);
            printf("La Tangente es : %.4f\n", resul);
            break;

        default:
            printf("Opcion invalida\n");
    }

    return 0;
}