/**
// SERGE EDUARDO MARTÍNEZ RAMÍREZ
// ESCUELA SUPERIOR DE CÓMPUTO
// MATERIA: Análisis y diseño de algoritmos
// FECHA: 13/03/2023
// ALGORITMO SHELLSORT: 
// 		El ordenamiento Shell, es un algoritmo de ordenamiento eficiente que mejora el ordenamiento
		por inserción, porque  divide la lista original en varias sublistas pequeñas y ordenarlas por separado
		a medida de que el intervalo va decreciendo. 
		
		En el peor de los casos, la complejidad de este algoritmo es n^2 en el mejor de los casos es O(n log^2 n) */
		
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// PROTOTIPOS DE FUNCIONES 
void shellSort (int *a, int n);
void mostrarArreglo (int *a, int n);
void pedir(int *a, int n);

// Función de ShellSort
void shellSort (int *a, int n) {
    int intervalo, i, j, k;
    //Se divide la lista 
    intervalo = n / 2; 
    // Mientras el intervalo sea mayor a cero
    while (intervalo > 0) {
    	// Se itera desde la mitad de la sublista hasta el final
        for (i = intervalo; i < n; i++) {
            // Se toma el valor que se encuentra al inicio de cada sublista
			j = i - intervalo;
            while (j >= 0) {
                k = j + intervalo;
                // Se commparan los valores, si es menor, se sale del bucle porque no hay que hacer intercambio
                if (a[j] <= a[k])
                    j = -1; // Se sale del búcle si esto se cumple

                // En caso de que no, entonces se realiza el intercambio
                else { 
                    int auxiliar = a[j];
                    a[j] = a[k];
                    a[k] = auxiliar;
                    j -= intervalo;
                }
            }
        }
		// Se reduce a la mitad en cada iteración, hasta que intervalo teng el valor de 1.
        intervalo /= 2;
    }
}

// Se encarga de mostrar el arreglo ordenado
void mostrarArreglo (int *a, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    printf("\n");
}   

// Se encarga de recibir la entrada de datos a ordenar
void pedir(int *a, int n) {
	int i;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

int main(int argc, char *argv[]) {
	// Haciendo un arreglo dinámico de N elementos
	if(argc!=2){
        exit(1);
    	}
	argc=atoi(argv[1]);
	int *arreglo = (int*) malloc(argc * sizeof(int));
	pedir(arreglo, argc);
	shellSort(arreglo, argc);
	mostrarArreglo(arreglo, argc);
	free(arreglo); // Se libera la memoria
    system("pause");
	return 0;
}
