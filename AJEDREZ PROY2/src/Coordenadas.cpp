#include "Coordenadas.h"



Coordenadas::~Coordenadas() {
	//destruir coordenadas anteriores y las sustituyo por actuales

}

int Coordenadas::setY(int yi) {
	//obtengo coordenada actual y de la pieza
	this->y = yi;
	return y;
}

int Coordenadas::setX(int xi) {
	//obtengo coordenada actual x de la pieza
	this->x = xi;
	return x;
}

int Coordenadas::getX() {
	//muevo a x siguiente
	
	return x;
}

int Coordenadas::getY() {
	//muevo a y siguiente
	
	return y;
}

int Coordenadas::getXY(int xx, int yy) {
	//junto x e y siguiente y obtengo la posicion nueva de la pieza
	xx = x;
	yy = y;
	return x;
	return y;
}

/*
int Coordenadas::cambioPos(int x1[2], int x2[2]) {

	this->posAct[2] = x1[2];
	this->posSig[2] = x2[2];
	return posSig[2];
	return posAct[2];
}
*/

