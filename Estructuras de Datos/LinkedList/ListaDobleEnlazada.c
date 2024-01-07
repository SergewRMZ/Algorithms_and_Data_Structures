#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct nodo{
	int dato;
	struct nodo *next;
	struct nodo *previous;
} Nodo;

typedef struct lista{
	Nodo *frente;
	Nodo *final; 
	int longitud;
} Lista;

/* PROTOTIPOS DE FUNCIONES */
Lista *crearLista();
Nodo *crearNodo(int dato);
void destruirNodo(Nodo *nodo);
int listaVacia(Lista *lista);
// Funciones para la inserción de elementos en la lista:
void insertarInicio(Lista *lista, int dato);
void insertarFinal(Lista *lista, int dato);
void insertarIzquierda(Lista *lista, int dato, int posicion);
void insertarDerecha(Lista *lista, int dato,int posicion);
// Funciones para la eliminación de elementos de la lista:
void eliminarInicio(Lista *lista);
void eliminarFinal(Lista *lista);
void eliminarPosicion(Lista *lista, int posicion);
void mostrarLista(Lista *lista);

/* Función Principal */
int main(){
	setlocale(LC_CTYPE, "SPANISH");
	Lista *lista = crearLista();
		
	insertarInicio(lista, 1);
	insertarInicio(lista, 56);
	insertarInicio(lista, 12);
	insertarInicio(lista, 4);

	mostrarLista(lista);
	puts("\n");
	eliminarInicio(lista);
	
	mostrarLista(lista);
	eliminarPosicion(lista, 9);
	eliminarPosicion(lista, 9);
	eliminarPosicion(lista, 9);
	puts("\n");
	
	mostrarLista(lista);
	if(!(listaVacia(lista))){
		printf("Último elemento de la lista: %d\n", lista->final->dato);
		printf("Primer elemento de la lista: %d\n", lista->frente->dato);
	}
	printf("Cantidad de elementos de la lista: %d\n", lista->longitud);
	system("PAUSE");
	return 0;
} /* Fin de Main */

Lista *crearLista(){
	Lista *lista = (Lista*)malloc(sizeof(Lista));
	lista->frente = NULL;
	lista->final = NULL;
	lista->longitud = 0;
	return lista;
}

Nodo *crearNodo(int dato){
	Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
	nodo->dato = dato;
	nodo->next = NULL;
	nodo->previous = NULL;
	return nodo;
}

void destruirNodo(Nodo *nodo){
	free(nodo);
}

int listaVacia(Lista *lista){
	if((lista->frente == NULL) && (lista->final == NULL))
		return 1;
	else
		return 0;
}

void insertarInicio(Lista *lista, int dato){
	Nodo *nuevoNodo = crearNodo(dato);
	if(listaVacia(lista)){
		lista->frente = lista->final = nuevoNodo;
	}	else{
		nuevoNodo->next = lista->frente;
		lista->frente->previous = nuevoNodo;
		lista->frente = nuevoNodo;
	}
	
	lista->longitud++;
}

void insertarFinal(Lista *lista, int dato){
	Nodo *nuevoNodo = crearNodo(dato);
	if(listaVacia(lista)){
		lista->frente = lista->final = nuevoNodo;
	}	else{
		nuevoNodo->previous = lista->final;
		lista->final->next = nuevoNodo;
		lista->final = nuevoNodo;
	}
	
	lista->longitud++;
}

void insertarIzquierda(Lista *lista, int dato, int posicion){
	Nodo *nuevoNodo = crearNodo(dato);
	if(listaVacia(lista)){
		lista->frente = lista->final = nuevoNodo;
	}	else{
		
		int i = 1;
		Nodo *aux = lista->frente;
		while((aux != NULL) && (i < posicion-1)){
			aux = aux->next;
			i++;
		}	
		if(posicion == 1){
			insertarInicio(lista, dato);
		}	else{
			nuevoNodo->next = aux->next;
			nuevoNodo->previous = aux;
			if(aux->next != NULL)
				aux->next->previous = nuevoNodo;
			else
				lista->final = nuevoNodo;
			aux->next = nuevoNodo;
		}	
	}
	
	
	lista->longitud++;
}

void insertarDerecha(Lista *lista, int dato, int posicion){
	Nodo *nuevoNodo = crearNodo(dato);
	if(listaVacia(lista)){
		lista->frente = lista->final = nuevoNodo;
	}	else{
		int i = 1;
		Nodo *aux = lista->frente;
		while((aux != NULL) && (i < posicion)){
			aux = aux->next;
			i++;
		}	
			
		if(posicion == 1)
			insertarInicio(lista, dato);
						
		else if(posicion > lista->longitud)
			insertarFinal(lista, dato);
				
		else{
			nuevoNodo->next = aux;
			nuevoNodo->previous = aux->previous;
			if(aux->previous != NULL)
				aux->previous->next = nuevoNodo;
			else
				lista->frente = nuevoNodo;
			aux->previous = nuevoNodo;
		}
	}
	
	lista->longitud++;
}

/* Eliminar elementos de la lista */
void eliminarInicio(Lista *lista){
	if(!(listaVacia(lista))){
		if((lista->frente->next == NULL) && (lista->frente->previous == NULL)){
			destruirNodo(lista->frente);
			lista->frente = NULL;
			lista->final = NULL;
		}	else{
			Nodo *eliminado = lista->frente;
			lista->frente = lista->frente->next;
			lista->frente->previous = NULL;
			destruirNodo(eliminado);
			
		}
		
		lista->longitud--;
	}	else{
		printf("La lista está vacía\n");
	}
}

void eliminarFinal(Lista *lista){
	if(!(listaVacia(lista))){
		if((lista->frente->next == NULL) && (lista->frente->previous == NULL)){
			destruirNodo(lista->frente);
			lista->frente = NULL;
			lista->final = NULL;
		}	else{
			Nodo *eliminado = lista->final;
			lista->final->previous->next = NULL; // Hacemos que el siguiente del anterior nodo apunte a NULL
			lista->final = lista->final->previous;
			destruirNodo(eliminado);
			
		}
		
		lista->longitud--;
		
	}	else{
		printf("La lista está vacía");
	}
}

void eliminarPosicion(Lista *lista, int posicion){
	if(!(listaVacia(lista))){
		int i = 1;
		Nodo *aux = lista->frente;
		while((aux != NULL) && i < posicion){
			aux = aux->next;
			i++;
		}	
			
		if(posicion > lista->longitud)
			eliminarFinal(lista);	
		else if(posicion == 1)
			eliminarInicio(lista);
		else{
			if(aux->next == NULL)
				eliminarFinal(lista);
			else{
				aux->previous->next = aux->next;
				aux->next->previous = aux->previous;
				free(aux);
			}
			
			lista->longitud--;
		}
		
	}	else{
		printf("La lista está vacía");
	}
}

void mostrarLista(Lista *lista){
	if(!(listaVacia(lista))){
		Nodo *aux = lista->frente;
		int i = 1;
		while(aux != NULL){
			printf("Dato %d: %d\n", i, aux->dato);
			if(aux->previous != NULL){
				printf("Dato anterior: %d\n", aux->previous->dato);
			}
			
			if(aux->next != NULL){
				printf("Dato siguiente: %d\n", aux->next->dato);
			}
			aux = aux->next;
			i++;
		}
	}	else{
		printf("La lista no contiene elementos para mostrar\n");
	}
}
