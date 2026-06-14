/*
Codigo por Miriam G Ramirez Sanchez
Escuela Superior de Computo
Curso: Analisis y diseno de algoritmos
Algoritmo de ordenamiento heapSort
fecha: 14/03/2023
*/

//librerias

#include <stdio.h>
#include <stdlib.h>

//Prototipo de funciones

void intercambio(int* a, int* b);
int obtenerHijoIzquierdo(int i);
int obtenerHijoDerecho(int i);
void monticulo(int arr[], int N, int i);
void HeapSort(int A[], int n);
void imprimeDatos(int arr[], int N);

/* 
Funcion principal de dos argumentos, un entero y un apuntador de tipo char a el arreglo cadena.
Estos parametros me ayudaran a recibir datos desde la consola de un archivo de texto 
, si la funcion no tiene ambos parametros, valida y automaticamente sale del programa.
El arreglo que estamos usando es un arreglo dinamico por lo que tambien pedimos que nos valide
si la asigancion de memoria fue correcta, si esto sucede procede a recibir los datos que ordenara
y a agregarlos al arreglo para despues enviar por parametro a la funcion HeapSort, incluyendo el numero
de elementos que ordenara y la funcion guardaDatos los colocara ya ordenados en el arreglo
*/

int main(int n, char *cadena[]){
	if(n!=2){
		exit(1);
	}
		int opc =atoi(cadena[1]);
    int a;
    int *arr;
    arr = malloc(opc * sizeof(int));
		if (arr == NULL) {
			printf("Sin memoria");
			exit(1);
		}
		else{
		for(int i=0;i<opc;i++){
					scanf("%d", &arr[i]);//recibe los datos a ordenar
			}
			HeapSort(arr,opc);
			imprimeDatos(arr,opc);//Regresa el arreglo ordenado 
		}

		system("pause");
		return 0;
}

/*
La funcion de intercambio es una funcion auxiliar para poder cumplir con el paso del 
algoritmo de heapSort ya que realiza un intercambio del elemento mas a la izquiera y lo pone en el 
primer elemento del arreglo para despues poder re equilibrar el arbol y que cumpla
que siempre este completo, igual es auxiliar para que siempre se cumpla que el elemento mayor
es la raiz del arbol
*/
void intercambio(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*
La funcion obtenerHijoIzquierdo y obtenerHijoDerecho nos brindan la posicion exacta 
en el arreglo de los respectivos hijos, esto se puede calcular atraves de una expresion algebraica
ya que en el algoritmo heapSort se implementa un arbol binario completo, esto quiere decir
que siempre tendra dos hijos y en caso de no hacerlo, estaran lo mas a la izquierda posible, y 
el número de nodos totales cumple una fórmula específica (2^(h+1) - 1) en función de la altura del arbol
*/
int obtenerHijoIzquierdo(int i) {
    return 2 * i + 1;
}

int obtenerHijoDerecho(int i) {
	return 2 * i + 2;
}
/*
La funcion monticulo forma pequenos monticulos como su nombre lo dice para facilitar el 
trabajo de la funcion HeapSort, en este algoritmo de ordenamiento lo mas importante es esta funcion
ya que de ella depende si es mas o menos eficiente el ordenamiento.
la estructura de monticulo es un pequeno arbol binario completo y debe de tener siempre
una raiz y sus respectivos dos nodos hijos, esta funcion en ayuda de intercambio hacen que en cada 'pasada'
que realice el algoritmo el arbol se vuelva a balancear y este completo.
*/
void monticulo(int arr[], int N, int i){

	int may = i;//raiz //padre
	//Hijos
	int izq = obtenerHijoIzquierdo(i);
	int der = obtenerHijoDerecho(i);
//Hace las comparaciones para que el arbol siempre sea completo
	if (izq < N && arr[izq] > arr[may]){
		may = izq;
	}

	if (der < N && arr[der] > arr[may]){
		may = der;
	}
		

//Reacomoda la raiz ya que el heapSort remueve el mayor elemento y lo 
//sustituye por el ultimo elemento del arreglo
	if (may != i) {

		intercambio(&arr[i], &arr[may]);
		monticulo(arr, N, may);
	}
}
/*
La funcion HeapSort es en donde se lleva a cabo todo el algoritmo, uniendo las funciones 
anteriormente descritas, recibe por parametro un arreglo de datos y un entero que contiene
el tamano del arreglo ya que es una implementacion dinamica, en el primer ciclo
manda a llamar a la funcion monticulo para ordenar los datos y en el segundo ciclo 
elimina el elemento mayor y lo sustituye por el que esta mas a la izquierda con ayuda
de la funcion de intercambio y rebalancea el arbol
*/
void HeapSort(int A[], int n){
	int i;
	for (i = n / 2 - 1; i >= 0; i--){
		monticulo(A, n, i);
	}
	for (i = n - 1; i >= 0; i--) {
		intercambio(&A[0], &A[i]);
		monticulo(A, i, 0);
	}
}
/* Esta funcion imprime los valores del conjunto ya ordenados 
*/

void imprimeDatos(int arr[], int N){
	int i;
	for (i = 0;i < N; i++){
        printf("%d \n", arr[i]);
	}
}

//Fin del programa



