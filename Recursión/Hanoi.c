/* Torres de Hanoi */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Función recursiva del algoritmo de las torres de Hanoi:
void Hanoi(int numeroDiscos, int origen, int auxiliar, int destino, int *cantidad);
int main() {
	int numero;
	setlocale(LC_CTYPE, "SPANISH");
	puts("\tTorres de Hanoi\n");
	/* Los números más altos representan los discos más grandes, entre [1, n], donde n es el número de discos */
	printf("Ingrese el número de discos de la torre: ");
	scanf("%d", &numero); fflush(stdin);
	printf("\n");
	int cantidad = 0;
	Hanoi(numero, 1, 2, 3, &cantidad);
	printf("\n\tLa cantidad de movimientos es: %d\n", cantidad);
	system("pause");
	return 0;
}

void Hanoi(int numeroDiscos, int origen, int auxiliar, int destino, int *cantidad) {
	if(numeroDiscos == 1)
		printf("Mover el disco de %d a %d\n", origen, destino, cantidad);
	else {
		Hanoi(numeroDiscos - 1, origen, destino, auxiliar, cantidad);
		printf("Mover disco de %d a %d\n", origen, destino, cantidad);
		Hanoi(numeroDiscos -1, auxiliar, origen, destino, cantidad);
	}
	
	*cantidad += 1;
	
}


