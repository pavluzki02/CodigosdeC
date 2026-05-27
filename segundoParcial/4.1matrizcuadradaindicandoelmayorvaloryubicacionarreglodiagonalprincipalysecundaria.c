#include <stdio.h>

int main() {
	int A[3][3];
	int i, j, k;
	int repetido;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			do {
				repetido = 0;
				printf("Ingrese un numero para [%d][%d]: ", i, j);
				scanf("%d", &A[i][j]);
				for(int x = 0; x < 3; x++) {
					for(int y = 0; y < 3; y++) {
						if((x != i || y != j) && A[x][y] == A[i][j]) {
							repetido = 1;
						}
					}
				}
				
				if(repetido)
					printf("Numero repetido, ingrese otro.\n");
				
			} while(repetido);
		}
	}
	printf("\nMatriz:\n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("%4d", A[i][j]);
		}
		printf("\n");
	}
	int max = A[0][0], min = A[0][0];
	int max_i = 0, max_j = 0, min_i = 0, min_j = 0;
	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if(A[i][j] > max) {
				max = A[i][j];
				max_i = i;
				max_j = j;
			}
			if(A[i][j] < min) {
				min = A[i][j];
				min_i = i;
				min_j = j;
			}
		}
	}
	printf("\nMaximo: %d en (%d,%d)\n", max, max_i, max_j);
	printf("Minimo: %d en (%d,%d)\n", min, min_i, min_j);
	
	int diagP[3], diagS[3];
	
	for(i = 0; i < 3; i++) {
		diagP[i] = A[i][i];
		diagS[i] = A[i][2 - i];
	}
	
	printf("\nDiagonal principal: ");
	for(i = 0; i < 3; i++) {
		printf("%d ", diagP[i]);
	}
	
	printf("\nDiagonal secundaria: ");
	for(i = 0; i < 3; i++) {
		printf("%d ", diagS[i]);
	}
	
	return 0;
}
