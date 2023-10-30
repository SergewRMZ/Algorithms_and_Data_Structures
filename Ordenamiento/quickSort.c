/**
// SERGE EDUARDO MARTÍNEZ RAMÍREZ
// ESCUELA SUPERIOR DE CÓMPUTO
// MATERIA: Análisis y diseño de algoritmos
// FECHA: 13/03/2023
// ALGORITMO QUICKSORT: 
//  	Es un algoritmo "divide y vencerás" que utilza la estrategia de partir la lista para poder ordenarla,
	    tomando un elemento denominado "pivote" que nos sirve para partir la lista en dos nuevas sublistas. En la sublista
		izquierda tenemos los valores que son menores al valor del pivote, y del lado derecho tenemos los valores que son
		mayores al valor del pivote. En cada llamada a la función se va partiendo de esta manera hasta que las sublistas
		tienen el tamaño de 1 o 0. */
// 
#include <stdio.h>
#include <stdlib.h>

// PROTOTIPOS DE FUNCIONES 
void quickSort(int *a, int primero, int ultimo);
void pedir(int *a, int n);
void mostrarArray(int *a, int ns);

// FUNCIÓN PRINCIPAL
int main(int x, char *cadena[]){
	// Si el programma no recibe dos argumentos a la hora de correrlo, va a haber un error.
	if (x!=2)
		exit(1);
	int *arreglo;
	int i;
	// La cadena recibida, se convierte a un entero para poder asignar el tamaño del arreglo
	int n = atoi(cadena[1]);
	arreglo = malloc(n * sizeof(int));
	// Otra causa de error, es que no se pueda asignar la cantidad de memoria solicitada
	if(arreglo == NULL) {
		printf("No se pudo asignar memoria correctamente\n");
		exit(1);
	}

	for(i =  0; i < n; i++)
		scanf("%d", &arreglo[i]);
	quickSort(arreglo, 0, n-1);
	for(i = 0; i < n; i++)
		printf("%d\n", arreglo[i]);
	free(arreglo);
	system("pause");
	return 0;
}

/**
 * Descripción: Es una función recursiva encargada de ordenar los elementos de un arreglo
 * de tamaño N, recibe el arreglo, la primer y última posición del arreglo.
 * Regresael arreglo ordenado ascendentemente
*/

void quickSort(int *a, int primero, int ultimo){
	// Tomando la primera y última posición de la lista
	int i = primero, j = ultimo;
	// Tomando el valor central de la lista, este será el pivote.
	int centro = (primero + ultimo) / 2;
	int pivote = a[centro];	
	do {
		while(a[i] < pivote) i++; // Mientras el elemento a[i] sea menor que el valor del pivote
		while(a[j] > pivote) j--; // Mientras el elemento a[j] sea mayor que el valor del pivote
		
		// Si i < j, entonces se realiza un intercambio de valores entre la posición i y la posición j
		if(i <= j){
			/* Una vez tenemos los dos valores, los intercambiamos para tener en la sublista
			izquierda los valores menores que pivote y en la sublista derecha los valores mayores que pivote*/
			int auxiliar; // Creando variable auxiliar para realizar un intercambio de valores
			// Realizando el intercambio de valores
			auxiliar = a[i];
			a[i] = a[j];
			a[j] = auxiliar;
			i++; j--;
		}
	}	while(i <= j); // Esto se repite mientras i sea menor o igual que j
	
	if(primero < j)
	//Se repite el proceso para la sublista izquierda
		quickSort(a, primero, j);
	if(ultimo > i)
	// Se repite el proceso para la sublista derecha
		quickSort(a, i, ultimo);
}
