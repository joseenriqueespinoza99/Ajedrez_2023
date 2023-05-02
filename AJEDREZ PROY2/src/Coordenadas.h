#pragma once

class Coordenadas
{
protected:
	int x;
	int y;
	int posAct[1];
	int posSig[1];

public:
	Coordenadas(int xAct, int yAct);
	virtual ~Coordenadas();
	int setX();//{ return x; }
	int setY();// { return y; }
	int getX(int xi);// { this->x = xi; return x; }
	int getY(int yi);// { this->y = yi; return y; }
	int getXY(int xx, int yy);// { return x; return y; };
	int cambioPos(int x1[1], int x2[1]);
};

