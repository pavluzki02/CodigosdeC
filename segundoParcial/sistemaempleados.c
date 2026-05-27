#include <stdio.h>

struct Empleado { //stuct es una ficha que almacena un dato y despues el arreglo se encarga de asignar cuantos empleados hay
    int legajo;
    char nombre[30];
    char sector;
    float sueldo;
};
struct Empleado aux;

int main (){
    struct Empleado empleado[] = {
        {101, "Juan", 'C', 5000.0},   //Ficha 0
        {123, "Marcelo", 'B', 7000.0},//Ficha 1
        {134, "Claudio", 'A', 9600.0},//Ficha 2
        {145, "Dedin", 'A', 54500.0}, //Ficha 3
        {156, "Manin", 'B', 7600.0},  //Ficha 4
        {245, "Juanin", 'A', 54000.0},//Ficha 5
        {107, "Orselin", 'C', 3400.0},//Ficha 6
    };
/*[101][Juan][C][5000] [123][Marcelo][B][7000] [134][Claudio][A][9600]
|___empleados[0]_____| |____empleados[1]_____| |___empleados[2]______|*/


//Ordenamiento
int cantidad = sizeof(empleado) / sizeof(empleado[0]);
/*sizeof(empleados)        // tamaño TOTAL del array completo ejemplo (7 empleados x 70 bytes) = 490 bytes
sizeof(empleados[0])     // tamaño de UN solo empleado               /(1 empleado solo 70 bits) = 70 bytes                 490/70=7         */      
for (int i = 0; i < cantidad - 1;i++){
    for(int j = 0; j < cantidad - i - 1; j++){
        if (empleado[j].legajo > empleado[j + 1].legajo)
        {
            aux = empleado[j];
            empleado[j] = empleado[j+1];
            empleado[j+1]= aux;            
/* 
aux = empleados[j]        // guardás el vaso A en el vaso vacío
empleados[j] = empleados[j+1]  // ponés el vaso B donde estaba A
empleados[j+1] = aux      // ponés el vaso A (guardado) donde estaba B 
*/
        }
        
    }
}
//busquedabinaria
int legajobuscado;
printf("Asigna el legajo que estas buscando \n");
scanf("%d",&legajobuscado);

int inicio = 0;
int fin = cantidad - 1;
int encontrado = 0;
//inicia y el fin va decreciendo mientras busca al numero que se le asigno
while(inicio<=fin){
    int medio = inicio + (fin - inicio) / 2;
    //¿El legajo del empleado actual es MAYOR que el del siguiente?
    //Si acierta el medio con el resultado entonces se termina el while porque da 1
    if(empleado[medio].legajo== legajobuscado){
        encontrado=1;
        printf("Empleado encontrado\n");
        printf("Legajo: %d\n",empleado[medio].legajo);
        printf("Nombre: %s\n",empleado[medio].nombre);
        printf("Sector: %c\n",empleado[medio].sector);
        printf("Sueldo: %.2f\n",empleado[medio].sueldo);       
        break;
    }
    //busca en la parte derecha
    else if (empleado[medio].legajo<legajobuscado){
        inicio = medio + 1;
    }
        else{
            //ahora busca en la parte izquierda
            fin = medio - 1;
        }
}
if(!encontrado){
    printf("Empleado con legajo %d no encontrado. \n",legajobuscado);
}
//busquedabinaria

}