#include <stdio.h>

/****************************************************/
/* Objetivo: Leer un carácter, un entero,            */
/*           un real y un real en doble             */
/*           precisión desde la Entrada Estándar    */
/*           y mostrarlos por la Salida Estándar    */
/*                                                  */
/* Entrada: Un carácter, un entero, un real         */
/*          y un real doble.                        */
/* Salida: Mostrarlos por pantalla                  */
/****************************************************/

int main() {
    char c;
    int n;
    float r;
    double d;

    printf("Ingrese un caracter: ");
    scanf(" %c", &c);

    printf("Ingrese un entero: ");
    scanf("%d", &n);

    printf("Ingrese un real: ");
    scanf("%f", &r);

    printf("Ingrese un real doble: ");
    scanf("%lf", &d);

    printf("\nCaracter: %c\n", c);
    printf("Entero: %d\n", n);
    printf("Real: %.2f\n", r);
    printf("Doble: %.2lf\n", d);

    return 0;
}