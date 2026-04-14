//2.1 Los alumnos de un curso se han dividido en dos grupos A y B de acuerdo al sexo y el nombre. El grupo A está formado por las mujeres con un nombre anterior a la M y los hombres con un nombre posterior a la N y el grupo B por el resto. Escribir un programa que pregunte al usuario su nombre y sexo, y muestre por pantalla el grupo que le corresponde.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char nombre[50], sexo; 
	printf("Escriba su nombre : ");
		scanf("%s",nombre);
		printf("Ingrese su genero (M/F): ");
		scanf(" %c", &sexo);
		
		char  inicial= toupper(nombre[0]);

		if (sexo == 'F' || sexo == 'f')
	{
			if (inicial < 'M'){
			printf("Perteneces al grupo A");
		}else {
				printf("Perteneces al grupo B");
		}
	}
		else if (sexo == 'M' || sexo == 'm'){
			if (inicial < 'N'){
				printf("Perteneces al grupo A");
			}else 
				printf("Perteneces al grupo B");
		}
		else { printf("Perteneces a nada");
		}
		return 0;
		}
	