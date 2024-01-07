// 03/11/2022 Serge Eduardo Martínez Ramírez
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct nodo{
    int dato;
    struct nodo *next;
} Nodo;

typedef struct lista{
    Nodo *frente;
    int longitud;
} Lista;

/* Prototipos de funciones */
Lista *crearLista();
Nodo *crearNodo(int dato);
void destruirNodo(Nodo *nodo);
void insertarInicio(Lista *lista, int dato);
void insertarFinal(Lista *lista, int dato);
void insertarPosicion(Lista *lista, int dato, int pos);
// Funciones para visualizar elementos de la lista:
int verInicio(Lista *lista);
int verFinal(Lista *lista);
int verPosicion(Lista *lista, int pos);

// Cantidad de datos de la lista: 
int cantidadDatos(Lista *lista);

// Funciones para eliminar elementos de la lista:
void eliminarInicio(Lista *lista);
void eliminarFinal(Lista *lista);
void eliminarPosicion(Lista *lista, int pos);

//Función para buscar un dato en la lista:
void buscarDato(Lista *lista, int dato);
// Función para mostrar los datos de la lista:
void mostrarLista(Lista *lista);

/* Función Principal */
int main(){
	setlocale(LC_CTYPE, "SPANISH");
    Lista *lista = crearLista();  
    
    // Variables:
    int opcion, dato, posicion;
    char resp;
    do{
    	system("cls");
	    puts("\tLista enlazada dinámica\n");
	    puts("1. Insertar dato al inicio");
	    puts("2. Insertar dato al final");
	    puts("3. Insertar dato en la posicion N");
	    puts("4. Visualizar el primer dato de la lista");
	    puts("5. Visualizar el último dato de la lista");
	    puts("6. Visualizar el N dato de la lista");
	    puts("7. Eliminar el primer dato de la lista");
	    puts("8. Eliminar el último dato de la lista");
	    puts("9. Eliminar el N elemento de la lista");
	    puts("10. Buscar un dato en la lista");
	    puts("11. Mostrar datos de la lista");
	    puts("12. Cantidad de datos de la lista");
	    printf("\nIngrese la opción que desea ejecutar: ");
	    scanf("%d", &opcion); fflush(stdin);
	    
	    switch(opcion){
	    	case 1:{
	    		do{
	    			system("cls");
	    			puts("Ingrese el dato que desea ingresar: ");
	    			scanf("%d", &dato); fflush(stdin);
	    			insertarInicio(lista, dato);
	    			puts("¿Desea ingresar otro dato? S/N");
	    			scanf("%c", &resp); fflush(stdin);
				}	while(resp == 'S' || resp == 's');
				
				break;
			}
			
			case 2:{
				do{
	    			system("cls");
	    			puts("Ingrese el dato que desea ingresar: ");
	    			scanf("%d", &dato); fflush(stdin);
	    			insertarFinal(lista, dato);
	    			puts("¿Desea ingresar otro dato? S/N");
	    			scanf("%c", &resp); fflush(stdin);
				}	while(resp == 'S' || resp == 's');
				
				break;
			}
			
			case 3:{
				do{
	    			system("cls");
	    			puts("Ingrese el dato que desea ingresar: ");
	    			scanf("%d", &dato); fflush(stdin);
	    			puts("Ingrese la posición en la que desea ingresar el elemento: ");
	    			scanf("%d", &posicion); fflush(stdin);
	    			insertarPosicion(lista, dato, posicion);
	    			puts("¿Desea ingresar otro dato? S/N");
	    			scanf("%c", &resp); fflush(stdin);
				}	while(resp == 'S' || resp == 's');
				break;
			}
			
			case 4:{
				int elemento;
				elemento = verInicio(lista);
				if(elemento){
					printf("\nEL PRIMER ELEMENTO DE LA LISTA ES: %d\n", elemento);
				}	break;
			}
			
			case 5:{
				int elemento;
				elemento = verFinal(lista);
				if(elemento){
					printf("\nEL ÚLTIMO ELEMENTO DE LA LISTA ES: %d\n", elemento);
				}
				break;
			}
			
			case 6:{
				int elemento;
				printf("\nIngrese la posición del elemento que quiere ver: ");
				scanf("%d", &posicion); fflush(stdin);
				elemento = verPosicion(lista, posicion);
				if(elemento){
					printf("Dato: %d\n", elemento);
				}
				break;
			}
			
			case 7:{
				eliminarInicio(lista);
				break;
			}
			
			case 8:{
				eliminarFinal(lista);
				break;
			}
			
			case 9:{
				printf("\nIngrese la posición del dato que desea eliminar: ");
				scanf("%d", &posicion); fflush(stdin);
				eliminarPosicion(lista, posicion);
				break;
			}
			
			case 10:{
				printf("\nIngrese el dato que desea buscar: ");
				scanf("%d", &dato); fflush(stdin);
				buscarDato(lista, dato);
				break;
			}
			
			case 11:{
				system("cls");
				mostrarLista(lista);
				break;
			}	
			
			case 12:{
				printf("\nACTUALMENTE HAY %d DATOS EN LA LISTA\n", cantidadDatos(lista));
				break;
			}
			
			
		}	system("pause");
	}	while(opcion != 0); // Se termina si la opcion ingresada es cero
    
    
    system("pause");
    return 0;
}

/* Funciones */
Lista *crearLista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->frente = NULL;
    lista->longitud = 0;
    return lista;
}

Nodo *crearNodo(int dato){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->next = NULL;
    return nodo;
}

void destruirNodo(Nodo *nodo){
    free(nodo);
}

void insertarInicio(Lista *lista, int dato){
    Nodo *nuevoNodo = crearNodo(dato);
    nuevoNodo->next = lista->frente;
    lista->frente = nuevoNodo;
    lista->longitud++;
}

void insertarFinal(Lista *lista, int dato){
    Nodo *nuevoNodo = crearNodo(dato);
    if(lista->frente == NULL){
    	lista->frente = nuevoNodo;
	}	else{
		Nodo *aux = lista->frente;
	    while(aux->next){
	        aux = aux->next;
	    }
	    aux->next = nuevoNodo;
	}
	
	lista->longitud++;
}

void insertarPosicion(Lista *lista, int dato, int pos){
    Nodo *nuevoNodo = crearNodo(dato);
    if(lista->frente == NULL){
        lista->frente = nuevoNodo;
    }   else{
        Nodo *aux = lista->frente;
        int i = 1;
        
		/* Tomamos el anterior elemento al de la posicioón asignada, posteriormente hacemos que el
		siguiente del nuevo nodo apunte al siguiente del nodo aux y después el siguiente
		del no aux apuntará al nuevo nodo. De esta manera el dato queda insertado en la posición
		asignada por el usuario. Si la posición sobrepasa el límite de elementos de la lista, simplemente
		se agrega el elemento al final de la lista. */
		
        while((i < pos-1) && (aux->next)){
        	aux = aux->next; 
        	i++;
		}  
        nuevoNodo->next = aux->next;
        aux->next = nuevoNodo;
    }
    
    lista->longitud++;
}

int verInicio(Lista *lista){
	if(lista->frente == NULL){
		puts("No hay elementos en la lista");
		return 0;
	}	else{
		return lista->frente->dato;
	}
}

int verFinal(Lista *lista){
	if(lista->frente == NULL){
		puts("No hay elementos en la lista");
		return 0;
	}	else{
		Nodo *aux = lista->frente;
		int i = 0;
		for(i; aux->next ; i++){
			aux = aux->next;
		}	
		
		return aux->dato;
	}
}

int verPosicion(Lista *lista, int pos){
	if(lista->frente == NULL){
		puts("No hay elementos en la lista");
		return 0;
	}	else{
		Nodo *aux = lista->frente;
		int i = 1;
		for(i; (i < pos) && (aux->next); i++){
			aux = aux->next;
		}	
		
		if(i != pos){
			printf("No se encuentra el elemento %d de la lista, porque la lista contiene %d elementos\n", pos, lista->longitud);
			return 0;
		}	else{
			return aux->dato;
		}
	}
}

int cantidadDatos(Lista *lista){
	return lista->longitud;
}

void eliminarInicio(Lista *lista){
	if(lista->frente == NULL){
		puts("No hay elementos en la lista para eliminar");
	}	else{
		Nodo *nodoEliminado = lista->frente;
		lista->frente = lista->frente->next;
		destruirNodo(nodoEliminado);
		lista->longitud--;
		puts("Dato eliminado correctamente");
	}
}

void eliminarFinal(Lista *lista){
	if(lista->frente == NULL){
		puts("No hay elementos en la lista para eliminar");
	}	else{
		// Verificando qué hacer si la lista solo contiene un elemento
		if(lista->frente->next == NULL){
			Nodo *nodoEliminado = lista->frente;
			lista->frente = NULL;
			destruirNodo(nodoEliminado);
			lista->longitud--;
		}	else{
			Nodo *aux = lista->frente;
			/* Recorrer la lista hasta hallar el penúltimo elemento de la lista */
			while(aux->next->next != NULL){
				aux = aux->next; // Penúltimo elemento de la lista
			}
			
			Nodo *nodoEliminado = aux->next;
			aux->next = NULL;
			destruirNodo(nodoEliminado);
			lista->longitud--;	
		}
		
		puts("Dato eliminado correctamente");	
	}
}
void eliminarPosicion(Lista *lista, int pos){
	if(lista->frente == NULL){
		puts("No hay elementos en la lista para eliminar");
	}	else{
		if(pos == 1){
			eliminarInicio(lista);
		} else if(pos <= lista->longitud){
			Nodo *aux = lista->frente;
			int i = 1;
			for(i; i < pos-1; i++){
				aux = aux->next;
			}	printf("Elemento anterior: %d\n", aux->dato); 
			Nodo *nodoEliminado = aux->next;
			aux->next = nodoEliminado->next;
			destruirNodo(nodoEliminado);
			lista->longitud--;	
		}
		
		puts("Dato eliminado correctamente");
	}
}

void buscarDato(Lista *lista, int dato){
	if(lista->frente == NULL){
		puts("La lista está vacía");
	}	else{
		puts("Buscando el dato...");
		Nodo *aux = lista->frente;
		int posicion = 0, i = 1;
		for(i; i <= lista->longitud; i++){
			if(aux->dato == dato){
				posicion = i;
				i = lista->longitud; // Para detener el bucle
			}
			aux = aux->next;
		}
		
		printf("El dato que busca está en la posición %d de la lista\n\n", posicion);	
	}
	
}

void mostrarLista(Lista *lista){
	Nodo *aux = lista->frente;
	int i = 0;
	for(i; aux != NULL; i++){
		printf("Dato %d:\t\t%d\n", i+1, aux->dato);
		aux = aux->next;
	}
}

