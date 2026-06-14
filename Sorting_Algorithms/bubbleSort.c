#include <stdio.h>			//libreria estandar de entrada y salida
#include <stdlib.h>			//libreria estandar  (para la memoria dinamica)
void BurbujaS(int *A, int n);			//Prototipo de la funcion en que se encuentra nuestro algoritmo

int main(int argc, char *argv[]) {
	int i, *A;								//Declaramos la variable para iterar y un apuntador que se utilizara para almacenar un arreglo de enteros
	if(argc!=2) 							
		exit (1);							//Finalizar por error por entrada no valida
	int n=atoi(argv[1]);					//Convertir segundo argumento en entero

    A = malloc(n*sizeof(int));				//Haciendo un arreglo dinamico de N elementos y asignando el puntero a la variable A
    
    for(i=0;i<n;i++){						
    	scanf("%d",&A[i]);					//Lee los valores de entrada y los asigna al arreglo dinamico A
	}
	BurbujaS(A, n);							//Llevar a cabo el ordenamiento llamando a la funcion
    for (i = 0; i < n; i++) {				//realizar cada impresion de la posicion 0 hasta la posicion n	del arreglo
        printf("%d\n ", A[i]);     			//imprime los valores ordenados previamente
    }
	return 0;
}

void BurbujaS(int A[], int n) {					//Funcion con A como arreglo y n como posicion en el arreglo
    int i, j, aux;
    for (i = 0; i <= n - 2; i++) {				//Analiza desde la posicion 0 a la n-1 del arreglo
        for (j = 0; j <= n - 2; j++) {			//Analiza los elementos adyacentes de 0 a n-1
            if (A[j] > A[j + 1]) {				//Si el elem analizado es mayor al sig
                aux = A[j];						//Guardamos el valor en el aux
                A[j] = A[j + 1];				//Se realiza el cambio de posicion, dando el valor del sig a A[j]
                A[j + 1] = aux;					//Asignamos el valor anterior guardado de A[j] a A[j+1]
            }
        }
    }
}

