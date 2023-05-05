#pragma once
class Coordenadas
{
private:

	int x;
	int y;
	
public:

	virtual ~Coordenadas();
	int setX(int xi);//{ return x; }
	int setY(int yi);// { return y; }
	int getX();// { this->x = xi; return x; }
	int getY();// { this->y = yi; return y; }
	int getXY(int xx, int yy);// { return x; return y; };
	//las hacemos amigas para que puedan acceder a los atributo privados de la otra
	friend class Pieza;
};

