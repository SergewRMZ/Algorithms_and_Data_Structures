#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
typedef struct alumno{
	char nombre[50];
	int edad;
	struct alumno *next;
} Alumno;

typedef struct pila{
	Alumno *tope;
} Pila;

/* Prototipos de Funciones */
void mostrarPila(Pila *s1);
Alumno *crearAlumno(char *nombre, int *edad);
void destruirAlumno(Alumno *alumno);
int pilaVacia(Pila *s1);
void push(Pila *s1, char *nombre, int edad);
void pop(Pila *s1);
void contarRegistros(Pila *s1);

/* Función Principal */
int main(){
	setlocale(LC_CTYPE, "SPANISH");
	Pila *s1 = (Pila*)malloc(sizeof(Pila));
	s1->tope = NULL;
	int opcion, edad;
	char nombre[50];
	char resp;
	while(1){
		system("cls");
		puts("\tImplementación de pilas como un sistema de gestión de Alumnos\n");
	
		puts("1. Ingresar nuevo alumno");
		puts("2. Eliminar alumno");
		puts("3. Visualizar el primer registro");
		puts("4. Cantidad de registros");
		puts("5. Mostrar Registros");
		puts("6. Guardar los registros en un archivo de texto");
		puts("\nIngrese la opción que desea ejecutar: ");
		scanf("%d", &opcion); fflush(stdin);
	
		switch(opcion){
			case 1:{
				while(1){
					system("cls");
					puts("Ingrese el nombre del alumno: ");
					gets(nombre); fflush(stdin);
					puts("Ingrese la edad del alumno: ");
					scanf("%d", &edad); fflush(stdin);
					push(s1, nombre, edad);
					puts("¿Ingresar nuevo alumno? S / N");
					scanf("%c", &resp); fflush(stdin);
					if(resp == 'n' || resp == 'N') break;
				}
				break;
			}
			
			case 2:{
				system("cls");
				pop(s1);
				break;
			}
			
			case 3:{
				system("cls");
				if(pilaVacia(s1)){
					puts("No hay registros en la pila");
				} else{
					printf("Nombre: %s\n", s1->tope->nombre);
					printf("Edad: %d\n", s1->tope->edad);
					puts("¿Desea eliminar este registro? S/N");
					scanf("%c", &resp); fflush(stdin);
					if(resp == 's' || resp == 'S') pop(s1);
				}	
				
				break;	
			}
			
			case 4:{
				system("cls");
				contarRegistros(s1);
				break;
			}
			
			case 5:{
				system("cls");
				mostrarPila(s1);
				break;
			}
			
			case 6:{
				system("cls");
				break;
			}
		}
		
		system("pause");
	}
	
	system("pause");
	return 0;
}

/* Funciones */

void mostrarPila(Pila *s1){
	system("cls");
	int i = 1;
	Alumno *aux = s1->tope;
	for(i; aux != NULL; i++){
		printf("Alumno %i\n", i);
		printf("Nombre: %s\n", aux->nombre);
		printf("Edad: %d\n", aux->edad);
		printf("\n");
		aux = aux->next;
	}
}

Alumno *crearAlumno(char *nombre, int *edad){
	Alumno *alumno = (Alumno*)malloc(sizeof(Alumno));
	strncpy(alumno->nombre, nombre, 50);
	alumno->edad = *edad;
	alumno->next = NULL;
	return alumno;
}

void destruirAlumno(Alumno *alumno){
	alumno->next = NULL;
	free(alumno);
}

int pilaVacia(Pila *s1){
	if(s1->tope == NULL){
		return 1;
	}	else{
		return 0;
	}
}

void push(Pila *s1, char *nombre, int edad){
	Alumno *aux = crearAlumno(nombre, &edad);
	if(pilaVacia(s1)){
		s1->tope = aux;
	} else {
		printf("Ya no está vacía\n");
		aux->next = s1->tope;
		s1->tope = aux;
	
	}	
}

void pop(Pila *s1){
	if(pilaVacia(s1)){
		puts("Aún no se han ingresado registros en la Pila");
	}	else{
		Alumno *eliminado = s1->tope;
		Alumno *aux = s1->tope->next;
		s1->tope = aux;
		destruirAlumno(eliminado);
		puts("Alumno eliminado correctamente");
	}
	
}

void contarRegistros(Pila *s1){
	Alumno *aux = s1->tope;
	int i = 0;
	if(pilaVacia(s1)){
		puts("Aún no se han ingresado registros en la Pila");
	}	else{
		for(i; aux != NULL; i++){
			aux = aux->next;
		}
	}	printf("Actualemente hay %d registros en la Pila\n", i);
}
