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
	Pieza* pN[16];
	Pieza* pB[16];
	Pieza* piezaSelecc = nullptr;
	Coordenadas coor;
	Pieza* piezas[MAX_PIEZAS];
	bool turno = true; //empiezan blancas


public:
	void dibuja();
	void inicializa();
	void mueve();
	void tecla(unsigned char key);
	void seleccionar_pieza(int x, int y);
	bool su_turno();
	void mover(int x, int y, bool comer);
	bool casillaOcupada(int x, int y);
	//bool comprobar_trayectoria(int or_x, int or_y, int dest_x, int dest_y, bool trayectoria);
	//bool comprobar_posicion(int or_x, int or_y, int dest_x, int dest_y);
	//bool ComprobarNegra(Coordenadas const coordenada);
	//bool ComprobarNegra(Coordenadas const coordenada);
	void coord_a_celda(int x, int y); // Conversion -- coordenadas de la pantalla a celdas de nuestro tablero
	//~Tablero();

	};
