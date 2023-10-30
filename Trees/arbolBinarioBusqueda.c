/* Construcción de un árbol binario de búsqueda */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Structs */
typedef struct nodo {
	int valor;
	struct nodo *izquierdo;
	struct nodo *derecho;
	struct nodo *padre;	/* Implementamos la referencia al padre para simplificar el trabajo de eliminar nodo */
} Nodo;

typedef Nodo Arbol;

/* Function Prototypes */
Nodo *crearNodo ( int valor, Nodo *padre);
void destruirNodo ( Nodo *nodo );
static void insertarConPadre ( Nodo **arbol, Nodo *padre, int valor );
void insertar ( Nodo **arbol, int valor );
void determinarExistencia ( Nodo *arbol, int valor );
void visitarNodo ( Nodo *arbol );

/* Eliminar Nodo */
Nodo *obtener( Nodo *arbol, int valor );
static void reemplazar ( Nodo *arbol, Nodo *nuevoNodo );
static Nodo *minimo ( Nodo *arbol );
static void eliminarNodo ( Nodo *nodoEliminar );
void eliminar ( Nodo *arbol, int valor );

/* Recorridos del árbol */
void inorden ( Nodo *raiz );
void preorden ( Nodo *raiz );
void postorden ( Nodo *raiz );

/* Functions */
Nodo *crearNodo ( int valor, Nodo *padre ) {
	Nodo *nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
	nuevoNodo->valor = valor;
	nuevoNodo->izquierdo = nuevoNodo->derecho = NULL;
	nuevoNodo->padre = padre;
	return nuevoNodo;
}

void destruirNodo ( Nodo *nodo ) {
	nodo->izquierdo = nodo->derecho = NULL;
	free(nodo);
}

static void insertarConPadre ( Nodo **arbol, Nodo *padre, int valor ) {
	if( *arbol == NULL ) {
		*arbol = crearNodo(valor, padre);
	}	else {
		int valorRaiz = (*arbol)->valor;
		if ( valor < valorRaiz ) {
			insertarConPadre( &(*arbol)->izquierdo, *arbol, valor );
		}	else {
			insertarConPadre( &(*arbol)->derecho, *arbol, valor );
		}
	}
}

void insertar ( Nodo **arbol, int valor ) {
	insertarConPadre ( arbol, NULL, valor );
}

int existe ( Nodo *arbol, int valor ) {
	if( arbol == NULL ) 
		return 0;
	else if ( arbol->valor == valor ) {
		return 1;
	}	
	else if ( valor < arbol->valor ) 
		return existe( arbol->izquierdo, valor );
	else 
		return existe( arbol->derecho, valor );
}

void determinarExistencia ( Nodo *arbol, int valor ) {
	if(existe(arbol, valor))
		printf("El nodo %d existe en el árbol\n", valor);
	else
		printf("El nodo %d NO EXISTE en el árbol\n", valor);
}

Nodo *obtener ( Nodo *arbol, int valor ) {
	if ( arbol == NULL ) {
		return NULL;
	}	else if ( arbol->valor == valor ) {
		return arbol;
	}	else if ( valor < arbol->valor ) {
		return obtener ( arbol->izquierdo, valor );
	}	else {
		return obtener ( arbol->derecho, valor );
	}
}

static void reemplazar ( Nodo *arbol, Nodo *nuevoNodo ) {
	if ( arbol->padre ) {
		// Si el padre existe, procedemos a colocar en padre de arbol el nuevoNodo como nuevo hijo.
		if ( arbol->valor == arbol->padre->izquierdo->valor )
			arbol->padre->izquierdo = nuevoNodo;
		else if ( arbol->valor == arbol->padre->derecho->valor )
			arbol->padre->derecho = nuevoNodo;
	}
	
	if ( nuevoNodo ) {
		// Procedemos a poner como padre de nuevoNodo a arbol->padre.
		nuevoNodo->padre = arbol->padre;
	}
}

static Nodo *minimo ( Nodo *arbol ) {
	if (arbol == NULL) return NULL;
	if (arbol->izquierdo) return minimo(arbol->izquierdo);
	else return arbol;
}

static void eliminarNodo ( Nodo *nodoEliminar ) {
	if (nodoEliminar->izquierdo && nodoEliminar->derecho) {
		// En caso de que el nodo a eliminar tenga dos hijos
		Nodo *min = minimo(nodoEliminar->derecho);
		nodoEliminar->valor = min->valor;
		eliminarNodo (min);
	}
	
	else if (nodoEliminar->izquierdo) {
		// En caso de que tenga el hijo izquierdo
		reemplazar (nodoEliminar, nodoEliminar->izquierdo);
		destruirNodo(nodoEliminar);
	}
	
	else if (nodoEliminar->derecho) {
		// En caso de que tenga el hijo derecho
		reemplazar (nodoEliminar, nodoEliminar->derecho);
		destruirNodo(nodoEliminar);
	}
	
	else {
		// Si no tiene hijos es porque es un nodo hoja
		reemplazar (nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
	}
}

void eliminar ( Nodo *arbol, int valor ) {
	if ( arbol == NULL )
		printf("El árbol está vacío\n");	
	else if ( valor < arbol->valor )
		eliminar ( arbol->izquierdo, valor );
	else if ( valor > arbol->valor )
		eliminar ( arbol->derecho, valor );
	else 
		eliminarNodo ( arbol );
}

void visitarNodo ( Nodo *raiz ) {
	printf(" %d ", raiz->valor);
}

void inorden ( Nodo *raiz ) {
	if (raiz) {
		inorden ( raiz->izquierdo );
		visitarNodo ( raiz );
		inorden ( raiz->derecho );
	}
}

void preorden ( Nodo *raiz ) {
	if (raiz) {
		visitarNodo ( raiz );
		preorden ( raiz->izquierdo );
		preorden ( raiz->derecho );
	}
}

void postorden ( Nodo *raiz ) {
	if(raiz) {
		postorden ( raiz->izquierdo );
		postorden ( raiz->derecho );
		visitarNodo ( raiz );
	}
}

/* Main */

int main(int argc, char **argv) {
	setlocale(LC_CTYPE, "SPANISH");
	Arbol *arbol = NULL;
	insertar(&arbol, 5);
	insertar(&arbol, 10);
	insertar(&arbol, 4);
	insertar(&arbol, 8);
	insertar(&arbol, 15);
	insertar(&arbol, 20);
	insertar(&arbol, 2);
	
	determinarExistencia(arbol, 8);	
	determinarExistencia(arbol, 7);
	
	printf("INORDEN: ");
	inorden(arbol); printf("\n");
	
	printf("PREORDEN: ");
	preorden(arbol); printf("\n");
	
	printf("POSTORDEN: ");
	postorden(arbol); printf("\n");
	
	printf("Eliminando el 4\n");
	eliminar(arbol, 4);
	printf("PREORDEN: ");
	preorden(arbol); printf("\n\n");
	
	printf("Eliminando el 5\n");
	eliminar(arbol, 5);
	printf("PREORDEN: ");
	preorden(arbol); printf("\n\n");
	
	system("PAUSE");
	return 0;
}
