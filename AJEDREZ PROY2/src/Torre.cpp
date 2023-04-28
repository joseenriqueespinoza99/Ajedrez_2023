#include "Torre.h"

Torre::Torre()
{

}
Torre::Torre(int x, int y, bool color) {
	this->posx = x;
	this->posy = y;
	this->color = color;

}
void Torre::mueve(unsigned char key) 
{
	int i = getX();
	int j = getY();
	if (key == 'a')
	{
		i--;
	}
	if (key == 'd')
	{
		i++;
	}
	if (key == 'w')
	{
		j++;
	}
	if (key == 's')
	{
		j--;
	}
	setX(i);
	setY(j);
	glutPostRedisplay;
}

void Torre::dibuja() {
	setColor(true);
			if (getColor() == true) {
				pintar("imagenes/torrenegra.png", "imagenes/torreblanca.png", "imagenes/torrenblanca.png", "imagenes/torrennegra.png", getX(), getY()+1);
				casilla_torre = true;
			}
			else {
				pintar("imagenes/torreblanca.png", "imagenes/torrenegra.png", "imagenes/torrennegra.png", "imagenes/torrenblanca.png", getX(), getY()+1);
				casilla_torre = true;
			}
}