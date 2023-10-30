#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#define N 12
typedef struct arbol{
	char arreglo[N];
	int cont;
} Arbol;

void insertarDato(Arbol *arbol, char dato);
void eliminarDato(Arbol *arbol);
Arbol *crearArbol();
void mostrarArbol(Arbol *arbol);
void mostrarHijo(Arbol *arbol, char dato);
void mostrarHermano(Arbol *arbol, char dato);
void mostrarPadre(Arbol *arbol, char dato);
int mostrarMenu();

int main(){
	setlocale(LC_CTYPE, "SPANISH");
	Arbol *arbol = crearArbol();
	int dato;
// Insertando los datos del árbol
	insertarDato(arbol, 'A');
	insertarDato(arbol, 'B');
	insertarDato(arbol, 'C');
	insertarDato(arbol, 'D');
	insertarDato(arbol, 'E');
	insertarDato(arbol, 'F');
	insertarDato(arbol, 'G');
	insertarDato(arbol, 'H');
	insertarDato(arbol, 'I');
	insertarDato(arbol, 'J');
	insertarDato(arbol, 'K');
	while(1) {
		system("cls");
		puts("\tÁrbol Binario\n");
		int opcion = mostrarMenu();
		switch(opcion) {
			case 1: {
				system("cls");
				int nuevoDato;
				printf("Ingrese el nuevo dato que desea ingresar al árbol: ");
				scanf("%c", &nuevoDato); fflush(stdin);
				insertarDato(arbol, nuevoDato);
				break;
			}
			
			case 2: {
				system("cls");
				eliminarDato(arbol);
				break;
			}
			
			case 3: {
				system("cls");
				int dato;
				printf("Ingrese el dato: ");
				scanf("%c", &dato); fflush(stdin);
				dato = toupper(dato);
				mostrarHijo(arbol, dato);
				break;
			}
			
			case 4: {
				system("cls");
				int dato;
				printf("Ingrese el dato: ");
				scanf("%c", &dato); fflush(stdin);
				dato = toupper(dato);
				mostrarHermano(arbol, dato);
				break;
			}
			
			case 5: {
				system("cls");
				int dato;
				printf("Ingrese el dato: ");
				scanf("%c", &dato); fflush(stdin);
				dato = toupper(dato);
				mostrarPadre(arbol, dato);
				break;
			}
			
			case 6: {
				system("cls");
				mostrarArbol(arbol);
				break;
			}
			
			case 7: {
				printf("\nLa cantidad de nodos del árbol es: %d\n", arbol->cont - 1);
				break;
			}	
		}
		
		system("pause");
	}
	
	system("pause");
	return 0;
}

int mostrarMenu() {
	int opcion = 0;
	puts("1. Agregar nuevo dato");
	puts("2. Eliminar último elemento del árbol");
	puts("3. Mostrar hijo de un nodo");
	puts("4. Mostrar el hermano de un nodo");
	puts("5. Mostrar el padre de un nodo");
	puts("6. Mostrar el árbol como un arreglo");
	puts("7. Cantidad de elementos del árbol");
	puts("8. Salir del Programa\n");
	printf("Ingrese la opción que desesa ejecutar: ");
	scanf("%d", &opcion); fflush(stdin);
	return opcion;
}

void mostrarArbol(Arbol *arbol) {
	int i = 0;
	for(i = 1; i < arbol->cont; i++)
		 printf("%4c", arbol->arreglo[i]);
	printf("\n");
}

Arbol *crearArbol() {
	Arbol *a = (Arbol*) malloc(sizeof(Arbol));
	a->cont = 1;
	return a;
}

void insertarDato(Arbol *arbol, char dato) {
	if(arbol->cont == N)
		printf("El árbol está completo\n");
	else {
		arbol->arreglo[arbol->cont] = dato;
		arbol->cont++;
	}
}

void eliminarDato(Arbol *arbol) {
	if(arbol->cont == 1)
		printf("El árbol está vacío\n");
	else {
		arbol->cont--;
		printf("Dato eliminado correctamente\n");
	}
}

void mostrarHijo(Arbol *arbol, char dato) {
	char hijo;
	printf("Dato ingresado: %c\n", dato);
	printf("Ingrese 'I' para consultar hijo izquierdo y 'D' para hijo derecho: ");
	scanf("%c", &hijo); fflush(stdin);
	hijo = toupper(hijo);
		int posicion, interruptor = 0;
		int i = 1;
		for(i; i < arbol->cont; i++) {
			if(arbol->arreglo[i] == dato) {
				interruptor = 1;
				if(hijo == 'I')
					posicion = i * 2;
				else if(hijo == 'D')
					posicion = (i * 2) + 1;
				// Si la posición es mayor que el número de nodos del árbol, no hay hijos.
				if(posicion > arbol->cont)
					printf("El dato %c, no tiene hijos\n", dato);
				else
					printf("El hijo izquierdo de %c es: %c\n", dato, arbol->arreglo[posicion]);
				break;
			}
		}
		
		if(interruptor == 0)
			printf("El dato que ingresó no se encuentra en el árbol\n");
}

void mostrarHermano(Arbol *arbol, char dato) {
	printf("Dato ingresado: %c\n", dato);
	if(arbol->arreglo[1] == dato)
		printf("La raíz del árbol no tiene hermano\n");
	
	else {
		int i = 1;
		int posicion, interruptor = 0;
		for(i = 1; i < arbol->cont; i++) {
			if(arbol->arreglo[i] == dato) {
				if(i % 2 == 0)
					posicion = i + 1;
				else 
					posicion = i - 1;
				interruptor = 1;
				printf("El hermano de %c es: %c\n", dato, arbol->arreglo[posicion]);
				break;
			}
		}
		
		if(interruptor == 0)
			printf("El dato que ingresó no se encuentra en el árbol\n");
	}
}

void mostrarPadre(Arbol *arbol, char dato) {
	printf("Dato ingresado: %c\n", dato);
	int i = 1, posicion, interruptor = 0;
	for(i = 1; i < arbol->cont; i++) {
		if(arbol->arreglo[1] == dato)
			printf("La raíz del árbol no tiene padre\n");
		else if(arbol->arreglo[i] == dato) {
			posicion = i / 2;
			interruptor = 1;
			printf("El padre de %c es: %c\n", dato, arbol->arreglo[posicion]);
			break;
		}
	}
	
	if(interruptor == 0)
		printf("El dato que ingresó no se encuentra en el árbol\n");
}
