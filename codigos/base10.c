//5.3 Dado el siguiente trozo de programa:
#include<stdio.h>
#include<math.h>

int main () {
	int N,b,x,i=0,s=0;
	printf("Digite el numero que quiera convertir que este en base 10 \n");
	scanf("%d",&N);
	printf("\nIngrese la base que desea aplicar\n");
	scanf("%d",&b);
		   
	while (N > 0) {
		x = N % b;
		N = N / b;
		s = s + x * pow(10,i);
		i++;
	}
	
	printf("\nEl numero convertido en la base aplicada es: %d ", s);
}

