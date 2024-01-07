// 19/10/2022
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Estructura Cola */
typedef struct nodo{
	struct nodo *next;
	int dato;
} Nodo;

typedef struct cola{
	Nodo *front;
	Nodo *rear;
} Cola;

/* Prototipos de Funciones*/
Nodo *crearNodo(int dato);
void eliminarNodo(Nodo *nodo);
Cola *crearCola();
int colaVacia(Cola *cola);
void encolar(Cola *cola, int dato);
int consultarFront(Cola *cola);
void desencolar(Cola *cola);
void mostrarCola(Cola *cola);


/* Función Principal */
int main(){
	setlocale(LC_CTYPE, "SPANISH");
	Cola *cola = crearCola();
	int dato, opcion;
	char respuesta;
	//Inicio del programa: 
	do{
		system("cls");
		puts("\tCola Dinámica Lineal - Estructuras de Datos\n");
		puts("1. Encolar");
		puts("2. Desencolar");
		puts("3. Consultar el primer elemento de la cola");
		puts("4. Verificar si la cola está vacía");
		puts("5. Mostrar los elementos de la cola");
		puts("6. Salir del Programa");
		puts("\nIngrese la opción que desea ejecutar: ");
		scanf("%d", &opcion); fflush(stdin);
		
		switch (opcion){
			case 1:{
				do{
					system("cls");
					printf("Ingrese el dato que desea almacenar: ");
					scanf("%d", &dato); fflush(stdin);
					encolar(cola, dato);	
					puts("¿Desea ingresar otro elemento a la cola?");
					scanf("%c", &respuesta); fflush(stdin);
				}	while(respuesta == 'S' || respuesta == 's');
				
				break;
			}
			
			case 2:{
				system("cls");
				desencolar(cola);
				break;
			}
			
			case 3:{
				system("cls");
				dato = consultarFront(cola);
				if(dato != 0){
					printf("El primer dato de la cola es: %d\n", dato);
				}
				break;
			}
			
			case 4:{
				system("cls");
				if(colaVacia(cola)){
					printf("La cola está vacía\n");
				}	else{
					printf("La cola contiene elementos\n");
				}
				break;
			}
			
			case 5:{
				system("cls");
				mostrarCola(cola);
				break;
			}
			
			case 6:{
				system("cls");
				printf("Saliendo del programa...\n");
				exit(1);
				break;
			}
		}	system("pause");
	}	while(opcion != 0);
	
	
	system("pause");
	return 0;
}

/* Funciones */
Nodo *crearNodo(int dato){
	Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
	nodo->dato = dato;
	nodo->next = NULL;
	return nodo;
}

void eliminarNodo(Nodo *nodo){
	nodo->dato = 0;
	nodo->next = NULL;
	free(nodo);
}

Cola *crearCola(){
	Cola *cola = (Cola*)malloc(sizeof(Cola));
	cola->front = NULL;
	cola->rear = NULL;
	return cola;
}

int colaVacia(Cola *cola){
	if(cola->front == NULL && cola->rear == NULL){
		return 1;
	}	else{
		return 0;
	}
}

void encolar(Cola *cola, int dato){
	Nodo *nuevo = crearNodo(dato);
	// Si la cola está vacía, tanto front como rear apuntan al primer nodo de la cola
	if(colaVacia(cola)){	
		cola->front = nuevo;
		cola->rear = nuevo;
	}	else{
		cola->rear->next = nuevo; // Hacemos que el siguiente del último nodo apunte al nuevo nodo.
		cola->rear = nuevo; // Actualizamos nuestro nodo rear, para que apunte al nuevo nodo, que es el último de la cola
	}
}

int consultarFront(Cola *cola){
	if(!colaVacia(cola)){
		return cola->front->dato;
	}	else{
		printf("La cola está vacía\n");
		return 0;
	}
}

void desencolar(Cola *cola){
	if(cola->front){
		Nodo *auxiliar = cola->front;
		cola->front = cola->front->next;
		eliminarNodo(auxiliar);
		puts("PRIMER ELEMENTO DE LA COLA ELIMINADO CORRECTAMENTE");
		// Si al eliminar el nodo la cola queda vacía, entonces vamos a hacer que el último también apunte a NULL
		if(cola->front == NULL){
			printf("La cola ya está vacía\n");
			cola->rear = NULL;
		}
	}	else{
		puts("NO HAY ELEMENTOS EN LA COLA PARA ELIMINAR");
	}
}

void mostrarCola(Cola *cola){
	int i = 0;
	Nodo *nodo = cola->front;
	if(!colaVacia(cola)){
		while(nodo != cola->rear->next){
			printf("Dato %d:\t%d\n", i+1, nodo->dato);
			nodo = nodo->next; i++;
		}	
	}	else{
		printf("No hay elementos en la cola para mostrar\n");
	}
}
