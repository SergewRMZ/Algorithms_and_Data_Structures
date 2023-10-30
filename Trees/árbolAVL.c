/**
 * Programación de un árbol AVL (Equilibrado)
*/

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int valor;
	int factorEquilibrio;
	struct nodo *izquierdo;
	struct nodo *derecho;
}	Nodo;

typedef Nodo Arbol;

Nodo *crearNodo(int valor);
void destruirNodo (Nodo *nodo);
void rotacionII (Nodo **problema, Nodo *izq);
void rotacionDD (Nodo **problema, Nodo *der);
void rotacionID (Nodo **n, Nodo *n1);
void rotacionDI (Nodo **n, Nodo *n1);
void insertar (Nodo **raiz, int valor, int *altura);

// Recorridos:

void visitarRaiz(Nodo *raiz);
void inorden (Nodo *raiz);

int main() {
	Arbol *arbol = NULL;
	int altura = 0;
	insertar(&arbol, 5, &altura);
	insertar(&arbol, 20, &altura);
	insertar(&arbol, 2, &altura);
	insertar(&arbol, 13, &altura);
	insertar(&arbol, 7, &altura);
	insertar(&arbol, 12, &altura);
	insertar(&arbol, 4, &altura);
	insertar(&arbol, 25, &altura);	
	insertar(&arbol, 32, &altura);
	insertar(&arbol, 35, &altura);
	insertar(&arbol, 17, &altura);		
			
	printf("Recorrido Inorden: \n");
	inorden(arbol);
	
	
	system("pause");
	return 0;
}

Nodo *crearNodo (int valor) {
	Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
	nuevoNodo->valor = valor;
	nuevoNodo->izquierdo = nuevoNodo->derecho = NULL;
	nuevoNodo->factorEquilibrio = 0;
	return nuevoNodo;
}

void destruirNodo (Nodo *nodo) {
	nodo->derecho = nodo->izquierdo = NULL;
	nodo->factorEquilibrio = 0;
	free(nodo);
}

/* Para la rotaci�n simple despu�s de hacer una inserci�n, tomaremos el nodo donde est� el problema
con el factor de equilibrio y tomaremos su nodo izquierdo o derecho seg�n sea el caso */

void rotacionII (Nodo **problema, Nodo *izq) {
	(*problema)->izquierdo = izq->derecho;
	izq->derecho = (*problema);
	
	if (izq->factorEquilibrio == -1) {
		(*problema)->factorEquilibrio = 0;
		izq->factorEquilibrio = 0;
	}	else {
		(*problema)->factorEquilibrio = -1;
		izq->factorEquilibrio = 1;
	}
	
	*problema = izq;
}

void rotacionDD (Nodo **problema, Nodo *der) {
	(*problema)->derecho = der->izquierdo;
	der->izquierdo = *problema;
	
	if(der->factorEquilibrio == 1) {
		(*problema)->factorEquilibrio = 0;
		der->factorEquilibrio = 0;
	}	else {
		(*problema)->factorEquilibrio = 1;
		der->factorEquilibrio = -1;
	}
	
	*problema = der;
}

void rotacionID (Nodo **n, Nodo *n1) {
	Nodo *n2 = n1->derecho;
	(*n)->izquierdo = n2->derecho;
	n2->derecho = *n;
	n1->derecho = n2->izquierdo;
	n2->izquierdo = n1;
	
	if (n2->factorEquilibrio == 1)
		n1->factorEquilibrio = -1;
	else
		n1->factorEquilibrio = 0;
		
		
	if (n2->factorEquilibrio == -1)
		(*n)->factorEquilibrio = 1;
	else
		(*n)->factorEquilibrio = 0;
	
	n2->factorEquilibrio = 0;
	*n = n2;
}

void rotacionDI(Nodo **n, Nodo *n1) {
	Nodo *n2 = n1->izquierdo;
	(*n)->derecho = n2->izquierdo;
	n2->izquierdo = *n;
	n1->izquierdo = n2->derecho;
	n2->derecho = n1;
	
	if (n2->factorEquilibrio == 1)
		(*n)->factorEquilibrio = -1;
	else
		(*n)->factorEquilibrio = 0;
		
	if (n2->factorEquilibrio == -1)
		n1->factorEquilibrio = 1;
	else 
		n1->factorEquilibrio = 0;
		
	n2->factorEquilibrio = 0;
	*n = n2;
}

void insertar (Nodo **raiz, int valor, int *altura) {
	
	Nodo *n1;
	if (*raiz == NULL) {
		*raiz = crearNodo(valor);
		*altura = 1;
	}
	
	else if (valor < (*raiz)->valor) {
		insertar (&((*raiz)->izquierdo), valor, altura);
		/* Regreso por los nodos del camino */
		if (*altura) {
			switch ((*raiz)->factorEquilibrio) {
				
				case 1: {
					(*raiz)->factorEquilibrio = 0;
					*altura = 0;
					break;
				}
				
				case 0: {
					(*raiz)->factorEquilibrio = -1;
					break;
				}
				
				/* En caso de que viole el equilibrio */
				case -1: {
					printf("El valor %d rompe el equilibrio\n", valor);
					n1 = (*raiz)->izquierdo;
					
					if (n1->factorEquilibrio == -1)
						rotacionII (raiz, n1);
					else
						rotacionID (raiz, n1);
						
					*altura = 0;
					break;
				}
				
			}
		}
	}
	
	else if (valor > (*raiz)->valor) {
		insertar (&((*raiz)->derecho), valor, altura);
		/* Regreso de los nodos del �rbol */
		if (*altura) {
			switch ((*raiz)->factorEquilibrio) {
				
				case 1:
					n1 = (*raiz)->derecho;
					if (n1->factorEquilibrio == 1)
						rotacionDD (raiz, n1);
					else 
						rotacionDI (raiz, n1);
					*altura = 0;
					break;
				
				case 0: 
					(*raiz)->factorEquilibrio = 1;
					break;
				
				/* En caso de que viole el equilibrio */
				case -1:
					*altura = 0;
					break;
			
			}
		}
	}
	
	else {
		printf("ERROR: No pueden haber claves repetidas\n");
		*altura = 0;
	}
}

/* Recorridos del �rbol */


void visitarRaiz (Nodo *nodo) {
	printf("El valor es %d ", nodo->valor);
	printf("Factor de Equilibrio %d\n", nodo->factorEquilibrio);
}

void inorden (Nodo *raiz) {
	if(raiz) {
		inorden (raiz->izquierdo);
		visitarRaiz (raiz);
		inorden (raiz->derecho);
	}
}
