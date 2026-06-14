#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Prototipos de Funciones */
void binario(int n);
void octal(int n);
void hexadecimal(int n);

int main(){
	setlocale(LC_CTYPE, "SPANISH");
	int numero = 0;
	printf("Ingrese el número que desea convertir: ");
	scanf("%d", &numero); fflush(stdin);	
	printf("\nBinario: ");
	binario(numero); printf("\n");
	printf("Octal: ");
	octal(numero); printf("\n");
	printf("Hexadecimal: ");
	hexadecimal(numero); printf("\n");
	system("pause");
	return 0;
}

void binario(int n) {
	if(n > 1)
		binario(n/2);
	printf("%d", n % 2);
}

void octal(int n) {
	if(n > 1)
		octal(n / 8);
	printf("%d", n % 8); 
}

void hexadecimal(int n) {
	if(n > 1)
		hexadecimal(n / 16);
	int residuo = n % 16;
	if(residuo > 9){
		switch(residuo){
			case 10: {
				printf("%c", 'A');
				break;
			}
			
			case 11: {
				printf("%c", 'B');
				break;
			}
			
			case 12: {
				printf("%c", 'C');
				break;
			}
			
			case 13: {
				printf("%d", 'D');
				break;
			}
			
			case 14: {
				printf("%d", 'E');
				break;
			}
			
			case 15: {
				printf("%d", 'F');
				break;
			}
		}
	}	
	
	else 
		printf("%d", residuo);
	
	
}
