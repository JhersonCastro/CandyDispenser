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
	cbreak(); // Deshabilitar el búfer de línea
	noecho(); // No mostrar las entradas del usuario
	keypad(stdscr,TRUE); // Habilitar la entrada de teclado
	curs_set(0); // Ocultar el cursor

	int choice;
	while (1) {
		// Mostrar la pantalla de bienvenida
		clear();
		printw("/-/-/-/Bienvenido a la Máquina Dispensadora de Dulces!/-/-/\n\n");
		printw("Por favor seleccione una opción:\n");
		printw("1.--> Ingresar como Administrador\n");
		printw("2.--> Ingresar como Usuario\n\n");
		printw("Su elección: ");
		refresh(); // Actualizar la pantalla

		// Capturar la elección del usuario
		scanw("%d", &choice);

		// Verificar la opción seleccionada
		if (choice == 1) {
			// Opción para ingresar como administrador
			clear();
			printw("Ingresando como Administrador...\n");
			// Aquí implementamos la funcionalidad para el modo administrador
			getch(); // Esperar a que el usuario presione una tecla
		}
		else if (choice == 2) {
			// Opción para ingresar como usuario
			clear();
			printw("Ingresando como Usuario...\n");
			// Aquí  implementamos la funcionalidad para el modo usuario
			getch(); // Esperar a que el usuario presione una tecla
		}
		else {
			// Opción no válida
			clear();
			printw("Opción no válida. Por favor intente de nuevo.\n");
			getch(); // Esperar a que el usuario presione una tecla
		}
		clear(); // Limpiar la pantalla después de cada selección
	}

	// Restaurar la configuración de la terminal y finalizar ncurses
	endwin();
	return 0;
}



