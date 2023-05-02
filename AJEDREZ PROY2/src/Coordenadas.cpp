#include "Coordenadas.h"

Coordenadas::Coordenadas(int xAct, int yAct) {
	//constructor de las coordenadas
	x = xAct;
	y = yAct;
}

Coordenadas::~Coordenadas() {
	//destruir coordenadas anteriores y las sustituyo por actuales

}

int Coordenadas::setY() {
	//obtengo coordenada actual y de la pieza
	return y; 
}

int Coordenadas::setX() { 
	//obtengo coordenada actual x de la pieza
	return x;
}

int Coordenadas:: getX(int xi) {
	//muevo a x siguiente
	this->x = xi; 
	return x; 
}

int Coordenadas::getY(int yi) {
	//muevo a y siguiente
	this->y = yi;
	return y;
}
 
int Coordenadas::getXY(int xx, int yy) {
	//junto x e y siguiente y obtengo la posicion nueva de la pieza
	xx = x;
	yy = y;
	return x;
	return y;
}

int Coordenadas::cambioPos(int x1[1], int x2[1]) {

	 this->posAct[1] = x1[1];
	 this->posSig[1] = x2[1]; 
	 return posSig[1];
	 return posAct[1];
}

