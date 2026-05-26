#include <stdio.h>

int main() {
	int edad,edadactual, contador = 0;
	float monto,montoactual;
	
	do {
		printf("Ingrese la edad inicial (5 a 18): ");
		scanf("%d", &edad);
	} while (edad < 5 || edad > 18);
	
	printf("Ingrese el monto inicial: ");
	scanf("%f",&monto);
	
	edadactual = edad;
	montoactual = monto;
	
	while (monto <= 1000) {
		monto *= 2;
		edad++;
		contador++;
	}
	
	
	printf("Se le empezo a dar el dinero desde que tenia %d años\n", edadactual);
	printf("El monto por cumpleaños es %.2f $\n", montoactual);
	printf("Años transcurridos: %d\n", contador);
	printf("Edad cuando supera los 1000 $: %d años\n", edad);
	
	return 0;
}