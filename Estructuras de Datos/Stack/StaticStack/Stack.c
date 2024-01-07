#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>
typedef struct pila{
	int tope;
	int datos[5];
} Pila;

/* Prototipos de Funciones*/
void agregarDato(Pila *s1, int *dato);
void mostrarDatos(Pila *); 
void pilaLlena(Pila *);
void eliminarDato (Pila *s1);

/* Funci�n Principal */
int main(){
	setlocale(LC_CTYPE, "SPANISH");
	int opcion, dato;
	Pila *s1 = (Pila *) malloc(sizeof(Pila));
	s1->tope = -1;
	char resp;

	while (1) {
		system("cls");
		puts("\tStatic Stack\n");
		puts("1. Agregar datos ");
		puts("2. Eliminar dato");
		puts("3. Mostrar Stack");
		puts("4. Salir");
		printf("Ingresa la opcion que deseas ejecutar: ");
		scanf("%d", &opcion); fflush(stdin);

		switch(opcion){
			case 1:
				printf("\tIngreso de Datos\n");
				do {
					printf("Ingrese el numero: ");
					scanf("%d", &dato); fflush(stdin);
					agregarDato(s1, &dato);
					
					if(s1->tope == 5) 
						break;
					
					puts("¿Desea ingresar otro numero? S/N");
					scanf("%c", &resp); fflush(stdin);
				}	while (s1->tope == 5 || toupper(resp) == 'S');

				system("cls");
				break;

			case 2:
				eliminarDato(s1);
				printf("Dato eliminado correctamente\n");
				system("pause");
				break;
			

			case 3: 
				system("cls");
				mostrarDatos(s1);
				system("pause");
				break;

			case 4:
				system("cls");
				printf("Saliendo del Programa...");
				exit(EXIT_SUCCESS);
		}
	}
	
	system("pause");
	return 0;
}

/* Funciones */
void agregarDato(Pila *s1, int *dato){
	if(s1->tope == -1){
		s1->datos[++(s1->tope)] = *dato;
	} else{
		s1->datos[++(s1->tope)] = *dato;
	} 
	pilaLlena(s1);
}

void eliminarDato (Pila *s1) {
	if (s1->tope == -1) {
		fprintf(stderr, "La pila está vacía");
	}	

	else {
		s1->datos[s1->tope] = 0;
		s1->tope -= 1;
	}
}

void mostrarDatos(Pila *s1){
	printf("La cantidad de elementos es: %d\n", s1->tope + 1);
	int i = s1->tope;
	for(i; i >= 0; i--) {
		printf("%d\n", s1->datos[i]);
	}
}

void pilaLlena(Pila *s1){
	if(s1->tope == 5){
		fprintf(stderr, "La pila est� llena\n");
	}
}
