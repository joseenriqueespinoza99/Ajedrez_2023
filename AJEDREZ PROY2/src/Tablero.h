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
#include "Coordenadas.h"

class Tablero {
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Coordenadas celda; //celda seleccionada por el raton
	Coordenadas origen;//sirve para determinar la posición origen
	Coordenadas destino;//sirve para determinar la posicion de destino

	ListaPiezas listapiezas;
	Pieza* p[32];
	Pieza* piezaSelecc = nullptr;
	bool turno = true;
	int total = 0;
	enum TipoPieza1 { ALFIL, TORRE, CABALLO, REINA, REY, PEON };
	TipoPieza1 tipo;
	int alpaso = 0; //para el comer al paso

public:
	void setPaso(bool alp) { alpaso = alp; }
	int getPaso() { return alpaso; }

	void dibuja();
	void inicializa();
	void mueve();
	void tecla(unsigned char key);
	void seleccionar_pieza(int x, int y);
	void mover(int x, int y, int comer);
	bool casillaOcupada(int x, int y);
	bool su_turno();
	void coord_a_celda(int x, int y); // Conversion -- coordenadas de la pantalla a celdas de nuestro tablero
	//~Tablero();
	bool comprobar_color(bool color);
	bool comprobar_camino(int origen_x, int origen_y, int destino_x, int destino_y);
	bool comprobar_jaqueRey(bool color);
	Pieza* coronacion(int x, int y);
	void comer_al_paso(int origen_x, int origen_y, int destino_x, int destino_y, bool color);
	bool casillaEnJaque(bool colorRey, int x, int y);
	bool comprobar_enroque_corto(bool color);
	bool comprobar_enroque_largo(bool color);

};

