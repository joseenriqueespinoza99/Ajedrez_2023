#pragma once
class Coordenadas
{
private:
	int x;
	int y;
	int posAct[2];
	int posSig[2];

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

