#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fibonacci(int n);

int main(){
	setlocale(LC_CTYPE, "SPANISH");
	int n = 0;
	puts("\tSerie de Fibonacci de manera recursiva\n");
	printf("Ingrese el n-ésimo término que desea saber de la serie Fibonacci: ");
	scanf("%d", &n); fflush(stdin);
	int termino = fibonacci(n);
	printf("El n-ésimo término de la sucesión es: %d\n", termino);
	
	system("pause");
	return 0;
}

int fibonacci(int n){
	int f;
	if(n <= 2){
		f = 1;
	}	else{
		f = fibonacci(n-1) + fibonacci(n-2);
	}	return f;
}
