#pragma once
#include "Tablero.h"
#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "Pieza.h"
#include "Alfil.h"
#include "Caballo.h"

ListaPiezas p;


void Mundo::rotarOjo()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  


	t.dibuja();
 
	
	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	glDisable(GL_LIGHTING);

	glEnable(GL_LIGHTING);
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{

	
	x_ojo = 4.0;
	y_ojo = 4.0;
	z_ojo = 14.0;
	t.inicializa();
}

void Mundo::tecla(unsigned char key)
{

	t.mueve(key);
}

void Mundo::coord_a_celda(int x, int y)
{
	celda.x=(((x - 190) / 55) + 1); // Posicion en x del raton, la separacion a la izquierda desde que empieza la ventana hasta que empieza el tablero (190) y 55 el ancho de casilla
	celda.y=9-(((y- 100) / 55) + 1); // Pos en y del raton, la separacion a abajo desde que empieza la ventana hasta que empieza el tablero (100) y 55 el ancho de casilla


	if ((celda.x < 1 || celda.y > 8 || celda.x > 8 || celda.y < 1))
		celda = { -1, -1 }; // si se selecciona fuera del tablero
	
	//Comprobacion auxiliar
	std::cout << "(" << celda.x << "," << celda.y << ")" << std::endl; //test realizado para comprobar por consola que la celda seleccionada es la correcta

}


