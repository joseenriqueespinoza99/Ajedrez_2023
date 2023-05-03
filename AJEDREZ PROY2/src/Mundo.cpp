#pragma once
#include "Tablero.h"
#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "Pieza.h"
#include "Alfil.h"
#include "Caballo.h"


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
	celda.x=(((x - 163) / 59.5) + 1); // Posicion en x del raton, la separacion a la izquierda desde que empieza la ventana hasta que empieza el tablero (163) y 59.5 el ancho de celda aproximado
	celda.y=(9-((y- 61) / 59.5)); // Pos en y del raton, la separacion por arriba desde que empieza la ventana hasta que empieza el tablero (61) y 59.5 el ancho de celda aproximado


	if ((x < 163 || x > 637 || y < 61 || y > 535)) {
		celda = { 0, 0 }; // si se selecciona fuera del tablero
	}
	t.seleccionar_pieza(celda.x - 1, celda.y - 1);
	t.setX_destino(x);
	t.setY_destino(y);
		t.mover(celda.x - 1, celda.y - 1);
	

	//Comprobacion auxiliar (borrar)
//	std::cout << "(" << x << "," << y << ")" << std::endl;
//	std::cout << "(" << celda.x << "," << celda.y << ")" << std::endl; //test para comprobar visualmente que la celda seleccionada es la correcta

}


