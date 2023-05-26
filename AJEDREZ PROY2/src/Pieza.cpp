#include "Pieza.h"

void Pieza::dibujar(const char foto[], int x1, int y1){ //Dibujar las piezas ( foto es el nombre de la foto y x1, y1 las coordenadas en las que se dibuja)
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(foto).id);
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glTexCoord2d(0, 0);    glVertex2f(x1, y1);
    glTexCoord2d(1, 0);    glVertex2f(x1+1, y1);
    glTexCoord2d(1, 1);    glVertex2f(x1+1, y1-1);
    glTexCoord2d(0, 1);    glVertex2f(x1, y1-1);
    glEnd();
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}

void Pieza::pintar(const char foto1[], const char foto2[], const char foto3[], const char foto4[], int x1,int y1) {//funcion que cambia el fondo de las piezas dependiendo de las coordenadas
    for (int j = 0; j <8; j++) {//bucle que va de 0 a 9 y suma 1
        for (int i = 0; i < 9; i++) {//bucle mas rapido que va de 0 a 9 y suma 1
            if (x1 == j && y1 == i) { //si i y j son iguales a x e y
                if (j % 2 == 0) {//Bucle para las coordenadas y, 
                    if (i % 2 == 0) {//Bucle para las coordenadas x
                        if (color==true)
                            dibujar(foto2, j,i);
                        else
                            dibujar(foto4, j,i);
                    }
                    else
                    {
                        if (color == true)
                            dibujar(foto1, j, i);
                        else
                            dibujar(foto3, j, i);
                    }
                }
                else
                {
                    if (i % 2 == 1) {//Bucle para las coordenadas x
                        if (color == true)
                            dibujar(foto2, j, i);
                        else
                            dibujar(foto4, j, i);
                    }
                    else
                    {
                        if (color == true)
                            dibujar(foto1, j, i);
                        else
                            dibujar(foto3, j, i);
                    }
                }
            }
        }
    }  
}


