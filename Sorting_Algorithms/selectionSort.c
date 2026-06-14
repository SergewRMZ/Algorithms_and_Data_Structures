// SERGE EDUARDO MARTÍNEZ RAMÍREZ
// ESCUELA SUPERIOR DE CÓMPUTO
// MATERIA: Análisis y diseño de algoritmos
// FECHA: 13/03/2023

//Librerias

#include <stdio.h>
#include <stdlib.h>

//Prototipo de funciones

void mostrarArreglo (int a[], int tam);
void selectSort(int array[], int tam);

/*
Funcion principal o main, recibe como parametro de entrada el numero de
datos a ordenar y una cadena con ellos, utiliza un arreglo dinamico para guardar los
datos si la memoria fue asignada correctamente. Procede a llamar
a la funcion selectSort donde se ejecutara el algoritmo de ordenamiento y por ultimo nos mostrara los datos ordenados
*/

int main(int n, char *cadena[]) {
	if(n !=2) 
		exit (1);
	int nElemento=atoi(cadena[1]);
    int *arreglo;
	arreglo = malloc(nElemento *sizeof(int));
		if (arreglo == NULL) {
			printf("Sin memoria");
			exit(1);
		} else{
			for(int i=0;i<nElemento;i++){
				scanf("%d", &arreglo[i]);
			}
			selectSort(arreglo, nElemento);
		}
	mostrarArreglo(arreglo, nElemento);

	system("pause");
    return 0;
}

/*
La funcion selectSort consiste en buscar el mínimo elemento de la lista e intercambiarlo
con el primer elemento, busca de nuevo el elemento mínimo en el resto de la lista y 
lo intercambia con el segundo.
*/

void selectSort(int array[], int tam){
	int i, j, aux, minimo;
	for (i = 0; i < tam; i++) {
		minimo = i;
			for(j = i+1; j < tam; j++) {
				if(array[j] < array[minimo]) {
					minimo = j;
				}
			}
	aux = array[i];
	array[i] = array[minimo];
	array[minimo] = aux;
	}
}
/*
La funcion selectSort imprime los elementos del arreglo ya ordenado 
con ayuda de un ciclo for para iterar sobre el 
*/
void mostrarArreglo (int a[], int tam) {
	for(int i = 0; i < tam; i++)
		printf("%d \n", a[i]);
}

//Fin del programa
