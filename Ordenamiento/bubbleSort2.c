/*
VILLEGAS GOMEZ ALEJANDRA
ESCUELA SUPERIOR DE COMPUTO
MATERIA: Analisis y diseño de algoritmos
Algoritmo BubbleSort Optimizado 2
FECHA: 07/03/2023
*/

#include <stdio.h>			//libreria estandar de entrada y salida
#include <stdlib.h>			//libreria estandar  (para la memoria dinamica)

/*El ordenamiento burbuja, consta de comparar cada elemento con el siguiente, 
intercambiando sus posiciones si no estan ordenados correctamente;
Se observa que al final de cada iteracion el elemento mayor queda correctamente posicionado, 
por lo que no es necesario volver a compararlo, reduciendo asi las iteraciones. 
Ademas, en esta segunda optimizacion no se ejecutara el bucle for hasta el final en cada pasada, 
pues se detiene la pasada tan pronto como no se detecten cambios en el arreglo */

void BurbujaOpti(int *A, int n);			//Prototipo de la funcion en que se encuentra nuestro algoritmo

int main(int argc, char *argv[]) {
	int i, *A;								//Declaramos la variable para iterar y un apuntador que se utilizara para almacenar un arreglo de enteros
	if(argc!=2) 							
		exit (1);							//Finalizar por error por entrada no valida
	int n=atoi(argv[1]);					//Convertir segundo argumento en entero


    A = malloc(n*sizeof(int));				//Haciendo un arreglo dinamico de N elementos y asignando el puntero a la variable A
    
    for(i=0;i<n;i++){						
    	scanf("%d",&A[i]);					//Lee los valores de entrada y los asigna al arreglo dinamico A
	}
	BurbujaOpti(A, n);							//Llevar a cabo el ordenamiento llamando a la funcion
    for (i = 0; i < n; i++) {				//realizar cada impresion de la posicion 0 hasta la posicion n	del arreglo
        printf("%d ", A[i]);     			//imprime los valores ordenados previamente
        printf("\n");
    }
	return 0;
}

void BurbujaOpti(int A[], int n) {				//Funcion con A como arreglo y n como posicion en el arreglo
    int aux,j;
    int i=0;						
    int cambios = 1; 							//Bandera, para controlar si se han realizado cambios en el arreglo durante la pasada.
    while (i<=n-2 && cambios != 0) {			//continuara mientras se sigan realizando cambios en el arreglo
        cambios = 0;							//cambios a 0 pues no se han realizado cambios durante esa pasada
        for (j = 0; j <= (n - 2)-i; j++) {		//Se resta i a la llegada (el numero de elementos que ya han sido ordenados en las pasadas anteriores)
            if (A[j] < A[j + 1]) {				//Si el elem analizado es mayor al sig
                aux = A[j];						//Guardar el valor en el auxiliar
                A[j] = A[j + 1];				//Se realiza el cambio de posicion, dando el valor del sig a A[j]
                A[j + 1] = aux;					//Asignamos el valor anterior guardado de A[j] a A[j+1]
                cambios = 1; 					// bandera a 1 para indicar que se ha realizado al menos un cambio durante la pasada.
            }
        }
        i=i+1; 									//Asegura que no se revisen los elementos ya ordenados en la parte superior del arreglo durante las pasadas posteriores
    }											//Si no se realizaron cambios en el arreglo durante una pasada, el bucle while se detiene y la función termina
}
