#pragma once
#include "Tablero.h"


class Coordinador
{
	enum Estados{INICIO, INSTRUCCIONES, JUEGO, PAUSA, FIN};
	Estados estado;
	int elegir;
	Tablero tablerinyo; 

public:

	Coordinador();
	void dibuja();
	void cambio_estado();
	void mueve();
	void coord_a_celda(int x, int y);
	void eleccion(unsigned char elec);

};

