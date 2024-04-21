// Simple C program to display "Hello World"
// Header file for input output functions
#include <stdio.h>
#include <stdlib.h>
#include "CandyMachine.h"
#include <curses.h>
#include <signal.h>

// main function -
// where the execution of program begins
int main()
{
	CandyMachine cm;


	initCandyMachine(&cm);
#pragma region INIT_CANDY
	Candy Gumball, ChocolateBar, Lollipop, JellyBean, CandyCane;

	Gumball.name = "Gumball";
	Gumball.price = 500;

	ChocolateBar.name = "Chocolate Bar";
	ChocolateBar.price = 1000;

	Lollipop.name = "Lollipop";
	Lollipop.price = 700;

	JellyBean.name = "Jelly Bean";
	JellyBean.price = 200;

	CandyCane.name = "Candy Cane";
	CandyCane.price = 300;

	Queue s;
	queueInit(&s);
	for (int i = 0; i < 7; i++)
	{
		enqueue(&s, &Gumball);
	}
	for (int i = 0; i < 7; i++)
	{
		printf("%s\n", ((Candy*)dequeue(&s))->name);
	}

#pragma endregion
	
	printf("Hello World hola");

	// Inicializar la pantalla
	initscr();
	cbreak(); // Deshabilitar el b�fer de l�nea
	noecho(); // No mostrar las entradas del usuario
	keypad(stdscr,TRUE); // Habilitar la entrada de teclado
	curs_set(0); // Ocultar el cursor

	int choice;
	while (1) {
		// Mostrar la pantalla de bienvenida
		clear();
		printw("/-/-/-/Bienvenido a la M�quina Dispensadora de Dulces!/-/-/\n\n");
		printw("Por favor seleccione una opci�n:\n");
		printw("1.--> Ingresar como Administrador\n");
		printw("2.--> Ingresar como Usuario\n\n");
		printw("Su elecci�n: ");
		refresh(); // Actualizar la pantalla

		// Capturar la elecci�n del usuario
		scanw("%d", &choice);

		// Verificar la opci�n seleccionada
		if (choice == 1) {
			// Opci�n para ingresar como administrador
			clear();
			printw("Ingresando como Administrador...\n");
			// Aqu� implementamos la funcionalidad para el modo administrador
			getch(); // Esperar a que el usuario presione una tecla
		}
		else if (choice == 2) {
			// Opci�n para ingresar como usuario
			clear();
			printw("Ingresando como Usuario...\n");
			// Aqu�  implementamos la funcionalidad para el modo usuario
			getch(); // Esperar a que el usuario presione una tecla
		}
		else {
			// Opci�n no v�lida
			clear();
			printw("Opci�n no v�lida. Por favor intente de nuevo.\n");
			getch(); // Esperar a que el usuario presione una tecla
		}
		clear(); // Limpiar la pantalla despu�s de cada selecci�n
	}

	// Restaurar la configuraci�n de la terminal y finalizar ncurses
	endwin();
	return 0;
}



