#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define n 10
typedef struct lista{
	int final;
	int frente;
	int arreglo[n];
} Lista;


/* Prototipos de Funciones */
void crearLista(Lista *lista);
int listaVacia(Lista *lista);
int listaLlena(Lista *lista);

/* Funciones para insertar elementos */
void pushFrente(Lista *lista, int dato);
void recorrerDerecha(Lista *lista, int frente, int final);
void pushFinal(Lista *lista, int dato);
void pushPosicion(Lista *lista, int dato, int posicion);

/* Funciones para eliminar elementos */
void popFrente(Lista *lista);
void recorrerIzquierda(Lista *lista, int frente, int final);
void popFinal(Lista *lista);
void popPosicion(Lista *lista, int posicion);

/* Funciones para consultar los datos de la lista*/
int consultarInicio(Lista *lista);
int consultarFinal(Lista *lista);
int consultarPosicion(Lista *lista, int posicion);

/* Función encargada de buscar el elemento ingresado en la lista */
void buscarElemento(Lista *lista, int dato);
/* Función para imprimir los elementos de la lista */
void mostrarLista(Lista *lista);
/* Función Principal */
int main(){
	setlocale(LC_CTYPE, "SPANISH");
	Lista lista;
	crearLista(&lista);
	pushFrente(&lista, 1);
	pushFrente(&lista, 2);
	pushFrente(&lista, 3);
	pushFrente(&lista, 15);
	pushFinal(&lista, 10);
	
	pushPosicion(&lista, 22, 2);
	mostrarLista(&lista);
	printf("El primer elemento de la lista es: %d\n", consultarInicio(&lista));
	printf("El último elemento de la lista es: %d\n", consultarFinal(&lista));
	printf("El cuarto elemento de la lista es: %d\n", consultarPosicion(&lista, 4));
	puts("\n");
	printf("Buscando el elemento 10 en la lista...\n");
	buscarElemento(&lista, 10);
	printf("Buscando el elemento 35 en la lista...\n");
	buscarElemento(&lista, 35);
	system("pause");
	return 0;
}

/* Funciones */
void crearLista(Lista *lista){
	lista->final = -1;
	lista->frente = 0;
}

int listaVacia(Lista *lista){
	if(lista->final == -1){
		return 1;
	}	else{
		return 0;
	}
}

int listaLlena(Lista *lista){
	if(lista->final == n-1){
		return 1;
	}	else{
		return 0;
	}
}

void pushFrente(Lista *lista, int dato){	
	if(!listaLlena(lista)){
		recorrerDerecha(lista, 0 , lista->final);
		lista->arreglo[0] = dato;
		lista->final++;
	}	else{
		puts("No se pueden agregar más elementos a la lista\n");
	}
}

void recorrerDerecha(Lista *lista, int frente, int final){
	while(final != frente-1){
		lista->arreglo[final+1] = lista->arreglo[final];
		final--;
	}
}

void pushFinal(Lista *lista, int dato){
	if(!listaLlena(lista)){
		lista->final++;
		lista->arreglo[lista->final] = dato;
	}	else{
		puts("No se pueden agregar más elementos a la lista\n");
	}
}

void pushPosicion(Lista *lista, int dato, int posicion){
	if(posicion-1 == 0){
		pushFrente(lista, dato);
	}
	
	else if(posicion -1 == lista->final){
		pushFinal(lista, dato);
	}
	
	else{
		if(!listaLlena(lista)){
			recorrerDerecha(lista, posicion-1, lista->final);
			lista->arreglo[posicion-1] = dato;
			lista->final++;
		}	else{
			puts("No se pueden agregar más elementos a la lista\n");
		}
	}
}

void popFrente(Lista *lista){
	if(!listaVacia(lista)){
		recorrerIzquierda(lista, 0, lista->final);
		lista->final--;
	}	else{
		puts("La lista está vacía\n");
	}
}

void recorrerIzquierda(Lista *lista, int frente, int final){
	while(frente != final){
		lista->arreglo[frente] = lista->arreglo[frente+1];
		frente++;
	}
}

void popFinal(Lista *lista){
	if(!listaVacia(lista)){
		lista->final--;
	}	else{
		puts("La lista está vacía");
	}
}

void popPosicion(Lista *lista, int posicion){
	if(posicion-1 == 0){
		popFrente(lista);
	}
	
	else if(posicion-1 == lista->final){
		popFinal(lista);
	}
	
	else{
		if(!listaVacia(lista)){
			recorrerIzquierda(lista, posicion-1, lista->final);
			lista->final--;
		}	else{
			puts("La lista está vacía");
		}	
	}
}

int consultarInicio(Lista *lista){
	int dato = lista->arreglo[0];
	return dato;
}

int consultarFinal(Lista *lista){
	int dato = lista->arreglo[lista->final];
	return dato;
}

int consultarPosicion(Lista *lista, int posicion){
	int dato = lista->arreglo[posicion-1];
	return dato;
}

void mostrarLista(Lista *lista){
	int i = 0; 
	for(i = 0; i <= lista->final; i++){
		printf("%d\t", lista->arreglo[i]);
	}	printf("\n");
}

void buscarElemento(Lista *lista, int dato){
	int i = 0;
	int pos = -1;
	int final = lista->final;
	for(i; i <= final; i++){
		if(lista->arreglo[i] == dato){
			pos = i; 
		}
	}
	if(pos == -1)
		printf("No se encontró el elemento\n");
	else
		printf("Elemento encontrado en la posición: %d\n", pos+1);
	
}



