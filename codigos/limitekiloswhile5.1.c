//5.1 Suponga que la Provincia del Chaco impone a los pescadores un límite en los Kg. de pesca que pueden recoger en un día, para preservar los recursos del río Paraná. Desarrolle un programa al que primero se le dé ese límite y luego se le vayan dando los pesos de lo que se va pescando y vaya mostrando el total de Kg. pescados hasta ese momento. Cuando supere el máximo se debe informar por pantalla en cuanto está excedido y terminar.
#include <stdio.h>

int main() {
	int limkg,dia,maximo=0;
	
	printf("El limite actual vigente estipulado de la Provincia del Chaco es de 20kg por día. \n"); 

	while (maximo < 20){
	printf("Ingrese los kilos. \n");	
	scanf("%d",&limkg);
    maximo += limkg;
	printf("Acumulado: %d kg\n", maximo);
}
	printf("Superaste el limite diario.\n");

	
	return 0;
}