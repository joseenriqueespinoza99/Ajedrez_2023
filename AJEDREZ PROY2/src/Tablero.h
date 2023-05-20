#pragma once
#include "freeglut.h"
#include "ETSIDI.h"

#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Rey.h"
#include "Peon.h"
#include "Dama.h"
#include "Pieza.h"
#include "ListaPiezas.h"
#include "Posicion.h"

class Tablero {
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Posicion celda; //celda seleccionada por el raton
	Posicion origen;//sirve para determinar la posición origen
	Posicion destino;//sirve para determinar la posicion de destino
	
	ListaPiezas listapiezas;
	Pieza* p[32];
	Pieza* piezaSelecc = nullptr;

public:
	void dibuja();
	void inicializa();
	void mueve();
	void tecla(unsigned char key);
	void seleccionar_pieza(int x, int y);
	void mover(int x, int y, bool comer);
	bool casillaOcupada(int x, int y);
	void coord_a_celda(int x, int y); // Conversion -- coordenadas de la pantalla a celdas de nuestro tablero
	//~Tablero();

	};
