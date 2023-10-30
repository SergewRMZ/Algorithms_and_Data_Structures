/*
Codigo por Miriam G Ramirez Sanchez
Escuela Superior de Computo
Curso: Analisis y diseno de algoritmos
Algoritmo de ordenamiento Arbol Binario
fecha: 14/03/2023
*/

//librerias

#include <stdio.h>
#include <stdlib.h>

/*
Tipo de dato abstracto Nodo. Cada nodo contiene un dato
en este caso de tipo entero y un apuntador a siguiente, en este caso 
a izquierda y derecha en donde en izquierda encontraremos valores menores al dato del nodo
y en la derecha valores menores a este
*/

struct Nodo {
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

/*
Creamos un apuntador al nuevo nodo y le pasamos como parametro el valor del dato del nodo anterior y definimos que el TDA
Nodo sea dinamico. Declaramos un apuntador del TDA Nodo y apuntara al dato recibido del parametro, este sera la raiz del arbol
*/

struct Nodo *nuevoNodo(int dato) {
    size_t tamanioNodo = sizeof(struct Nodo);
    struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);
    nodo->dato = dato;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

//Prototipo de funciones

int datoI(struct Nodo *raiz);
void insertar(struct Nodo *nodo, int dato);
void inorden(struct Nodo *nodo);


/* 
Funcion principal de dos argumentos, un entero y un apuntador de tipo char a el arreglo cadena.
Estos parametros me ayudaran a recibir datos desde la consola de un archivo de texto 
, si la funcion no tiene ambos parametros, valida y automaticamente sale del programa.
La funcion recibe un primer dato con el que inicia el arbol, el peor de los casos seria que el primer dato
fuese el mas pequeno del arreglo ya que lo asigna como raiz y no incluimos una funcion que haga que el 
arbol siempre este balanceado. 
*/
int main(int n, char *cadena[]) { 

    int raizDato,i; 
       if(n!=2){
            exit(1);
        } 
    int el=atoi(cadena[1]);
    scanf("%d", &raizDato);
    struct Nodo *raiz = nuevoNodo(raizDato);
        for(i=1;i<el;i++){//Ingresara los demas nodos, tomando como comparacion al Nodo padre
                datoI(raiz);
        }inorden(raiz);

    system("pause");
	return 0;
}

/*
La funcion insertar es una funcion donde la operacion basica es la comparacion, ya que
define en donde insertara el valor del dato, recibe como parametro el apuntador a un nodo y 
el valor entero del dato y empieza a hacer comparaciones. Si el dato es mayor que la raiz
del nodo, se insertara a la derecha, creando dos posibles escenarios, si no hay un nodo existente lo crea
y asigna el dato, de lo contario solamente lo asigna. Ocurre lo contrario cuando es menor, ya que se 
agregara a la izquierda y realizara la misma evaluacion.
*/
void insertar(struct Nodo *nodo, int dato) {

    if (dato > nodo->dato) {
        if (nodo->derecha == NULL) {
            nodo->derecha = nuevoNodo(dato);
            
        } else {
            insertar(nodo->derecha, dato);
        }
    } else {
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo(dato);
        } else {
            insertar(nodo->izquierda, dato);
        }
    }
}

/*
En esta funcion recursiva realizamos el recorrido inorden de un arbol binario. Recibe como parametro un apuntador y un entero auxiliar
este apuntador me permite ir a las diferentes posiciones del arreglo donde estaran mis datos ordenados y
y el entero auxiliar me permite definir el tamano de este arreglo, ya que es dinamico y en base a esto primero validara que el arbol
no este vacio y procedera a realizar iteraciones mientras asigna valores a los elementos del arreglo
*/
void inorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        inorden(nodo->izquierda);
        printf("%d \n", nodo->dato);
        inorden(nodo->derecha);
    } 
}

/*
La funcion datoI es la que nos ayuda a delcarar el incio del arbol, ya que necesitamos una raiz, aunque esta funcion nos limita
a que exista un desbalance el arbol que no es lo mas correcto en cuestiones algoritmicas, ya que se puede optimizar pero para este 
caso no implementamos una funcion que rebalancee. Toma como parametro un apuntador a raiz en donde se quedara el valor guardado y 
retorna 0 ya que no realiza operaciones que devuelvan informacion
*/
int datoI(struct Nodo *raiz){
    int dato1;
    scanf("%d", &dato1);
    insertar(raiz, dato1);

    return 0;
}

//Fin del programa