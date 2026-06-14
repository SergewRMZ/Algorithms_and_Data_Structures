/*
MÁNICA QUINTERO MARCO ANTONIO
ESCUELA SUPERIOR DE COMPUTO
MATERIA: Analisis y diseño de algoritmos
Algoritmo Insert Sort
FECHA: 14/03/2023
*/

#include <stdio.h> // Incluye la librería estándar de entrada/salida
#include <stdlib.h> // Incluye la librería estándar de funciones generales

void Insercion(int *A, int n); // Declaración de la función Insercion

int main(int argc, char *argv[]) { // Función principal que recibe argumentos desde la línea de comandos

    if(argc!=2) // Verifica que se haya pasado un argumento
        exit (1);

    int n=atoi(argv[1]); // Convierte el argumento pasado como una cadena de caracteres a un entero

    int *A; // Declaración del puntero A
    int i;

    A = malloc(n*sizeof(int)); // Reserva memoria dinámicamente para un arreglo de enteros de tamaño n

    for(i=0;i<n;i++){ // Ciclo que pide al usuario que ingrese los n elementos del arreglo
        scanf("%d",&A[i]); 
    }

    Insercion(A, n); // Llama a la función Insercion para ordenar el arreglo

    for (i = 0; i < n; i++) { // Ciclo que imprime los elementos del arreglo ya ordenados
        printf("%d\n ", A[i]);
    }

    printf("\n");
    free(A); // Libera la memoria reservada para el arreglo
    return 0; // Retorna 0 si todo fue exitoso
}

void Insercion(int *A, int n) { // Función que ordena el arreglo por el método de inserción
    int i, j, temp;
    for (i = 0; i < n; i++) { // Ciclo que recorre el arreglo
        j = i;
        temp = A[i];
        while ((j > 0) && (temp < A[j - 1])) { // Ciclo que intercambia el elemento actual con los elementos anteriores que sean mayores a él
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp; // Coloca el elemento actual en la posición correcta en el arreglo
    }
}
