/* Cola con lista circular */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estructura - Cola
typedef struct nodo{
	int dato;
	int contador;
	struct nodo *next;
} Nodo;

// Function Declarations 

void encolar(Nodo **p, int valor);
int desencolar(Nodo **p);
void mostrarCola(Nodo *p);
int colaVacia(Nodo *p);

// Main Function

int main(){
	setlocale(LC_CTYPE, "SPANISH");
	int opcion, dato, dato_eliminado;
	Nodo *cola = NULL;
	encolar(&cola, 1);
	encolar(&cola, 2);
	encolar(&cola, 3);

	while(1){
		system("cls");
		puts("Estructuras de Datos - Cola con lista circular\n");
		puts("1. Encolar");
		puts("2. Desencolar");
		puts("3. Visualizar el primer elemento de la cola");
		puts("4. Cola Vac�a");
		puts("5. Mostrar todos los elementos de la cola");
		puts("6. Cantidad de elementos de la cola");
		puts("7. Salir del Programa");
		printf("Ingrese la opci�n a la que deea ingresar: ");
		scanf("%d", &opcion); fflush(stdin);
		
		switch(opcion){
			case 1: {
				system("cls");
				printf("Ingrese el n�mero que desea ingresar: ");
				scanf("%d", &dato);
				encolar(&cola, dato);
				break;
			}
			
			case 2:{
				system("cls");
				dato_eliminado = desencolar(&cola);
				printf("El elemento: %d ha sido eliminado de la cola\n", dato_eliminado);
				break;
			}
			
			case 3: {
				system("cls");
				if(colaVacia(cola)){
					printf("A�n no hay elementos en la cola\n");
				}	else{
					printf("El primer elemento de la cola es: %d\n", cola->next->dato);
				}	break;
			}
			
			case 4:{
				system("cls");
				if(colaVacia(cola)){
					printf("La cola est� vac�a, a�n no hay elementos\n");
				}	else{
					mostrarCola(cola);
				}	break;
			}
			
			case 5:{
				system("cls");
				mostrarCola(cola);
				break;
			}
			
			case 6:{
				system("cls");
				if(!colaVacia(cola)){
					printf("Actualmente hay %d elementos en la cola\n", cola->contador);
				}	else{
					printf("La cola est� vac�a, a�n no hay elementos\n");
				}	break;
			}
			
			case 7:{
				exit(1);
				break;
			}
		}
		
		system("pause");
	}
	
	
	mostrarCola(cola);
	system("pause");
	return 0;
}

// Funciones
void encolar(Nodo **p, int valor){
	Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
	if(nuevo == NULL){
		fprintf(stderr, "Error al intentar asignas memoria din�mica\n");
	}
	
	/* Una cola con lista enlazada, consiste en que el �ltimo nodo apunta al primer elemento de la cola.
	Entonces debemos mantener a P apuntando al �ltimo nodo de la lista para que por medio de p->next 
	podamos acceder al primer elemento de la cola. */
	
	nuevo->dato = valor;
	if(colaVacia(*p)){
		nuevo->next = nuevo; // Hacemos que el primer nodo apunte a s� mismo
	} else{
		nuevo->next = (*p)->next; // Hacemos que el apuntador del nuevo elemento apunte al principio de la cola
		(*p)->next = nuevo;	
	}
	
	*p = nuevo;
	if(*p == (*p)->next){
		(*p)->contador = 1;
	}	else{
		(*p)->contador += 1;
	}
	puts("Elemento agregado correctamente");
}

int desencolar(Nodo **p){
	int valor = (*p)->next->dato; // Accedemos al valor del primer elemento
	if((*p) == (*p)->next){
		free(*p);
		*p = NULL;
	}	else{
		Nodo *aux = (*p)->next; // Creamos un nodo auxiliar que apunte al principio de la cola
		(*p)->next = aux->next; // Hacemos que el primer elemento, sea ahora el segundo elemento de la cola
		free(aux);
		
	}
	puts("Elemento eliminado de la cola correctamente");
	return valor;
}

void mostrarCola(Nodo *p){
	Nodo *aux = p->next;
	while(aux != p){
		printf("Elemento: %d\n", aux->dato);
		aux = aux->next;
	}
	
	printf("Elemento: %d\n", aux->dato);
}

int colaVacia(Nodo *p){
	if(p == NULL){
		return 1;
	}	else{
		return 0;
	}
}
