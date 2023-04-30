#pragma once
#include "freeglut.h"
#include "Tablero.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Pieza.h"
#include "Posicion.h"

class Mundo {
private:
public:
//Atributos
	Tablero t;
	float x_ojo;
	float y_ojo;
	float z_ojo;

	Posicion celda; //celda seleccionada por el raton

//Metodos
	
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	void coord_a_celda(int x, int y); // Conversion -- coordenadas de la pantalla a celdas de nuestro tablero

};


