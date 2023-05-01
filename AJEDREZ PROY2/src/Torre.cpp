#include "Torre.h"
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
			if (color == true) {
				pintar("imagenes/torrenegra.png", "imagenes/torreblanca.png", "imagenes/torrenblanca.png", "imagenes/torrennegra.png", getX(), getY()+1);
				//casilla_torre = true;
			}
			else {
				pintar("imagenes/torreblanca.png", "imagenes/torrenegra.png", "imagenes/torrennegra.png", "imagenes/torrenblanca.png", getX(), getY()+1);
				//casilla_torre = true;
			}
}

void Torre::movimientos() {
	int var1 = 0, var2 = 0, var3 = 0, var4 = 0; 
	bool encontrado = false;
	Pieza* coordenadas_de_consulta;
	
	for (int i = getX() + 1; i <= 8; i++) {
		coordenadas_de_consulta->setX(i);
		coordenadas_de_consulta->setX(getY());

		
		if (getColor() && t->EspacioBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - getX() - 1;
		}
		else if (!getColor() && t->EspacioNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - getX() - 1;
		}

		
		if (!getColor() && t->EspacioBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - getX();
		}
		else if (getColor() && t->EspacioNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var1 = i - getX();
		}
	}
	if (!encontrado) 
		var1 = 8 - getX();

	encontrado = false; 
	for (int i = getX() - 1; i >= 1; i--) {
		coordenadas_de_consulta->setX(i);
		coordenadas_de_consulta->setY(getY());

		
		if (getColor() && t->EspacioBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = getX() - i - 1;
		}
		else if (!getColor() && t->EspacioNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = getX() - i - 1;
		}

		
		if (!getColor() && t->EspacioBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = getX() - i;
		}
		else if (getColor() && t->EspacioNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var2 = i - getX() - i;
		}
	}
	if (!encontrado)
		var2 = getX() - 1;


	encontrado = false;
	for (int i = getY() + 1; i <= 8; i++) {
		coordenadas_de_consulta->setX(getX());
		coordenadas_de_consulta->setY(i);

		
		if (getColor() && t->EspacioBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - getY() - 1;
		}
		else if (!getColor() && t->EspacioNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - getY() - 1;
		}

		
		if (!getColor() && t->EspacioBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - getY();
		}
		else if (getColor() && t->EspacioNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var3 = i - getY();
		}
	}
	if (!encontrado) 
		var3 = 8 - getY();


	encontrado = false; 
	for (int i = getY() - 1; i >= 1; i--) {
		coordenadas_de_consulta->setX(getX());
		coordenadas_de_consulta->setY(i);

		
		if (getColor() && t->EspacioBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = getY() - i - 1;
		}
		else if (!getColor() && t->EspacioNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = getY() - i - 1;
		}

		
		if (!getColor() && t->EspacioBlancas(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = getY() - i;
		}
		else if (getColor() && t->EspacioNegras(coordenadas_de_consulta) && !encontrado) {
			encontrado = true;
			var4 = i - getY() - i;
		}
	}
	if (!encontrado)
		var4 = getY() - 1;


	for (int i = 0; i < var1; i++) 
	{
		muv[i]->setX(getX() + i + 1);
		muv[i]->setX(getY());
	}
	for (int i = 0; i < var2; i++) 
	{
		muv[i + var1]->setX(getX() - i - 1);
		muv[i + var1]->setX(getY());
	}
	for (int i = 0; i < var3; i++) 
	{
		muv[i + var1 + var2]->setX(getX());
		muv[i + var1 + var2]->setX(getY() + i + 1);
	}
	for (int i = 0; i < var4; i++) 
	{
		muv[i + var1 + var2 + var3]->setX(getX());
		muv[i + var1 + var2 + var3]->setX(getY() - i - 1);
	}

	

}
