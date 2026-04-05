#include <stdio.h>

int main () {

    int nota[5],suma = 0;
    int aprobado = 0,desapro = 0;
    float promedio;
    printf("Escribe las 5 notas registradas \n");
    for (int i = 0; i < 5; i++) {
        scanf("%i",&nota[i]);
    }
    for (int i = 0; i < 5; i++) {
    suma += nota[i];
    printf("Nota %d: %d \n", i, nota[i]);
    if (nota[i] < 6) {
        desapro++;
    }
    else{
        aprobado ++;
    }
 

    
}
promedio = suma / 5.0;
printf("Promedio: %.2f\n", promedio);
printf("Aprobados son: %i\n", aprobado);
printf("Desaprobados son: %i\n", desapro);

return 0;

}