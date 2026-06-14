// Segunda optimización al algoritmo de ordenamiento burbuja.
#include <stdio.h>
#include <stdlib.h>

/*El ordenamiento burbuja, consta de comparar cada elemento con el siguiente, 
intercambiando sus posiciones si no estan ordenados correctamente;
Se observa que al final de cada iteracion el elemento mayor queda correctamente posicionado, 
por lo que no es necesario volver a compararlo, reduciendo asi las iteraciones. 
Ademas, en esta segunda optimizacion no se ejecutara el bucle for hasta el final en cada pasada, 
pues se detiene la pasada tan pronto como no se detecten cambios en el arreglo */

void BurbujaOpti(int *A, int n);

int main(int argc, char *argv[]) {
	int i, *A;							
	if(argc!=2) 							
		exit (1);						
	int n=atoi(argv[1]);					


    A = malloc(n*sizeof(int));				
    
    for(i=0;i<n;i++){						
    	scanf("%d",&A[i]);					
	}
	BurbujaOpti(A, n);							
    for (i = 0; i < n; i++) {			
        printf("%d ", A[i]);
        printf("\n");
    }
	return 0;
}

void BurbujaOpti(int A[], int n) {				
    int aux,j;
    int i=0;						
    int cambios = 1; 					
    while (i<=n-2 && cambios != 0) {			
        cambios = 0;							
        for (j = 0; j <= (n - 2)-i; j++) {
            if (A[j] < A[j + 1]) {				
                aux = A[j];
                A[j] = A[j + 1];				
                A[j + 1] = aux;
                cambios = 1;
            }
        }
        i=i+1; 								
    }
}
