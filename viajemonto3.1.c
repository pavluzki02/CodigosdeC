#include <stdio.h>

int main() {
	int a,b,c,monto;
	
	printf("Seleccione el viaje que desea realizar.\n");
	printf(" 1- Taco Pozo | 2-Villa Ángela | 3- Castelli | 4- San Martín\n");
	printf(" $ 40.000     | $ 35.000       | 40.500      | 25.000\n");	
	scanf("%d",&a);
	switch (a){
	case 1: 
				printf("Usted ha seleccionado Taco Pozo\n");
			c=  40000;
			break;
	case 2: 
				printf("Usted ha seleccionado Villa Ángela\n");
			c=  35000;
			break;
	case 3: 
				printf("Usted ha seleccionado Castelli \n");
			c=  40500;
			break;
	case 4: 
				printf("Usted ha seleccionado San Martín\n");
			c=  25000;
			break;
	default: 
	printf("Opción invalida \n");
	}
	printf("Digite el monto que tiene usted disponible en su cuenta\n");
	scanf("%d",&monto);
		
	if (monto >= c) {
		printf("Disfrute de su viaje");
	} else {
		printf("No le alcanza para ese destino\n");
		
		if (monto >= 40500) {
			printf("Puede viajar a Castelli");
		} else if (monto >= 40000) {
			printf("Puede viajar a Taco Pozo");
		} else if (monto >= 35000) {
			printf("Puede viajar a Villa Angela");
		} else if (monto >= 25000) {
			printf("Puede viajar a San Martin");
		} else {
			printf("No le alcanza para ningun destino");
		}
	}
	
	return 0;
}