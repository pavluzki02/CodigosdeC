//6.3Escribir el enunciado del problema para el siguiente trozo de programa:
int main(){
char texto[100];
int i=0,n,dif;
dif = 'a'-'A'; //Aca se hace la diferencia entre numero ASCII A=65 - a=97 es igual a 32 que 32 hace que si hay mayus se cambia a minus y minus a mayusculas
printf("Introduzca una cadena: "); 
scanf("%s", texto); 
while (texto[i] != '\0')
{
if ((texto[i] >='a')&&(texto[i] <='z'))
texto[i] -= dif;
 else if ((texto[i]>='A')&&(texto[i]<='Z'))
texto[i] += dif; 
i++; 
}
texto[i] = '\0'; 
for (n=0; n<=i; n++) {
printf("%c", texto[n]);
}
printf("\n\n");
}
//Se busca hacer que los textos  ingresados en mayusculas pasen a minusculas y viceversa