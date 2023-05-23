#pragma once
#include "Tablero.h"


class Coordinador
{
	enum Estados{INICIO, INSTRUCCIONES, JUEGO, PAUSA};
	Estados estado;
	int elegir;
	bool jaque;
	Tablero tablerinyo; 

public:

	Coordinador();
	void dibuja();
	void cambio_estado();
	void eleccion(unsigned char elec);

};

