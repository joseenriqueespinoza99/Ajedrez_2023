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
	torres->dibuja();
	alfiles->dibuja();
	caballos->dibujaCab();
	t.dibuja();

    //fichas.dibuja();
   
	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	glDisable(GL_LIGHTING);

	glEnable(GL_LIGHTING);
}

void Mundo::mueve()
{
	//fichas.mueve();
}

void Mundo::inicializa()
{


	x_ojo = 4.0;
	y_ojo = 4.0;
	z_ojo = 14.0;
}

void Mundo::tecla(unsigned char key)
{
	alfiles->mueve(key);
	torres->mueve(key);

	//cb.mueveCab(p[2], z);
}
