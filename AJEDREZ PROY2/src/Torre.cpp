#include "Torre.h"

//Torre::Torre()
//{

//}
void Torre::mueve(unsigned char key)
{
	int i = getx();
	int j = gety();
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
	setx(i);
	sety(j);
	glutPostRedisplay;
}

void Torre::dibuja() {
	torre.setColor(true);
			if (torre.getColor() == true) {
				torre.pintar("imagenes/torrenegra.png", "imagenes/torreblanca.png", "imagenes/torrenblanca.png", "imagenes/torrennegra.png", getx(), gety()+1);
				casilla_torre = true;
			}
			else {
				torre.pintar("imagenes/torreblanca.png", "imagenes/torrenegra.png", "imagenes/torrennegra.png", "imagenes/torrenblanca.png", getx(), gety()+1);
				casilla_torre = true;
			}
}