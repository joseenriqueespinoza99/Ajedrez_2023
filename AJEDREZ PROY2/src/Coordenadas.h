#pragma once
class Coordenadas
{
protected:
	int x;
	int y;
	int posAct[2];
	int posSig[2];

public:
	Coordenadas(int xAct, int yAct);
	virtual ~Coordenadas();
	int setX() { return x; }
	int setY() { return y; }
	int getX(int xi) { this->x = xi; return x; }
	int getY(int yi) { this->y = yi; return y; }
	int cambioPos(int x1[2], int x2[2]) { this->posAct[2] = x1[2]; this->posSig[2] = x2[2]; }
};

