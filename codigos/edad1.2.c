//1.2	Calcular la edad de una persona de acuerdo al algoritmo elaborado en el TP1.
#include<stdio.h>

int main() {
    int edad,dia_nac,dia_act,mes_nac,mes_act, anio_nac, anio_act;
    printf("Digite el año de nacimiento: [YYYY]\n");
    scanf("%d",&anio_nac);
    printf("Ponga el mes de nacimiento: [MM]\n");
    scanf("%d",&mes_nac);
    printf("Ponga el dia nacimiento: [DD]\n");
    scanf("%d",&dia_nac);
    printf("Digite el año actual: [YYYY]\n");
    scanf("%d",&anio_act);
    printf("Ponga el mes actual: [MM]\n");
    scanf("%d",&mes_act);
    printf("Ponga el dia actual: [DD]\n");
    scanf("%d",&dia_act);
    if(anio_act>anio_nac){
           if(mes_act>0 && mes_act<= 12 && mes_nac>0 && mes_nac<= 12){
            if(dia_act>0 && dia_act<= 31 && dia_nac>0 && dia_nac<= 31){
                edad=anio_act-anio_nac;
     }
      }
       }
        else{
        printf("La fecha de nacimiento es incorrecta, vuelva a intentar.\n");
        return 0;
     }
     if (mes_act<mes_nac){
        edad=edad-1;
     }
     else if(mes_act==mes_nac){
        if(dia_act<dia_nac){
            edad=edad-1;
        }
        if (mes_act>mes_nac){
            edad=edad;
        }
     }
 
        printf("La edad de la persona es: %d años\n", edad);
     

}