#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void mergeSort(int *a, int inicio, int final);
void mezcla(int *a, int inicio, int centro, int final);
int main(int argc, char *argv[]){
	if(argc!=2) 
		exit (1);
	int n=atoi(argv[1]);
    int *arreglo;
    int i;
    arreglo = malloc(n*sizeof(int));//creaci�n del arreglo din�mico
	for(i=0;i<n;i++){
    	scanf("%d",&arreglo[i]);//lee los datos del archivo numeros10millones.txt
	}
    mergeSort(arreglo, 0, n-1);//llamado a la funci�n merge, utiliza el arreglo y su tama�o
    for(i=0; i < n; i++)
        printf("%d\n", arreglo[i]);//impresi�n de los n�meros ordenados
    free(arreglo);//liberar el espacio del arreglo
    return 0;
}

void mergeSort(int *a, int inicio, int final){
    if(inicio < final){
        int central = (inicio + final) / 2;
        mergeSort(a, inicio, central); // Ordena la primera mitad de la lista
        mergeSort(a, central+1, final); // Ordena la segunda mitad de la lista
        mezcla(a, inicio, central, final); // Fusiona las dos sublistas ordenadas
    }
}

void mezcla(int *a, int inicio, int centro, int final){//funcion de mezclar arreglos
    int i, j, k;
    int elementosIzq = centro - inicio + 1;
    int elementosDer = final - centro;

    int *izquierdo = (int*) malloc(elementosIzq*sizeof(int));
    int *derecho = (int*) malloc(elementosDer*sizeof(int));

    for(i = 0; i < elementosIzq; i++)
        izquierdo[i] = a[inicio+i];

    for(j = 0; j < elementosDer; j++)
        derecho[j] = a[centro + 1 + j];

    i = j = 0;
    k = inicio;

    while(i < elementosIzq && j < elementosDer){
        if(izquierdo[i] <= derecho [j]){
            a[k] = izquierdo[i];
            i++;
        }   else{
            a[k] = derecho[j];
            j++;
        }   
        k++;
    }

    /* En caso de que alguno de los arreglos se quede sin elementos
	 para comparar, debe de vaciar los arreglos */
    while(j < elementosDer){
        a[k] = derecho[j];
        j++; k++;
    }

    while(i < elementosIzq){
        a[k] = izquierdo[i];
        i++; k++;
    }

    free(izquierdo);
    free(derecho);
}
