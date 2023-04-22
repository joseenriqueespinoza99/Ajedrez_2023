#include "dibuja.h"
dibuja peon[8];
dibuja alfil[2];
dibuja torre[2];
dibuja caballo[2];
dibuja rey;
dibuja reina;

void dibuja::dibujar(const char foto[],float x1,float x2,float y1, float y2)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(foto).id);
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glTexCoord2d(0, 0);    glVertex2f(x1, y1);
    glTexCoord2d(1, 0);    glVertex2f(x2, y1);
    glTexCoord2d(1, 1);    glVertex2f(x2, y2);
    glTexCoord2d(0, 1);    glVertex2f(x1, y2);
    glEnd();
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}
void dibuja::pintarblancas()
{
    float j = 0.0;
    float l = 0.0;
    float k = 0.0;
    float m = 0.0;
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
            peon[i].dibujar("imagenes/peonblanco.png", 0 + j, 1 + j, 2, 1);
        else
            peon[i].dibujar("imagenes/peonnegro.png", 0 + j, 1 + j, 2, 1);
        j++;
    }
    for (int i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
            torre[i].dibujar("imagenes/torrenegra.png", 0 + l, 1 + l, 1, 0);
        else
            torre[i].dibujar("imagenes/torreblanca.png", 0 + l, 1 + l, 1, 0);
        l =7;
    }
    for (int i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
            caballo[i].dibujar("imagenes/caballoblanco.png", 2 + k, 1 + k, 1, 0);
        else
            caballo[i].dibujar("imagenes/caballonegro.png", 2 + k, 1 + k, 1, 0);
        k = 5;
    }
    for (int i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
            alfil[i].dibujar("imagenes/alfilnegro.png", 2+m, 3+m, 1, 0);
        else
            alfil[i].dibujar("imagenes/alfilblanco.png", 2 + m, 3 + m, 1, 0);
        m = 3;
    }
    reina.dibujar("imagenes/damablanca.png", 3, 4, 1, 0);
    rey.dibujar("imagenes/reynegro.png", 4, 5, 1, 0);
}
void dibuja::pintarnegras()
{
    float j = 0.0;
    float l = 0.0;
    float k = 0.0;
    float m = 0.0;
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
            peon[i].dibujar("imagenes/peonnnegro.png", 0 + j, 1 + j, 7, 6);
        else
            peon[i].dibujar("imagenes/peonnblanco.png", 0 + j, 1 + j, 7, 6);
        j++;
    }
    for (int i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
            torre[i].dibujar("imagenes/torrenblanca.png", 0 + l, 1 + l, 8, 7);
        else
            torre[i].dibujar("imagenes/torrennegra.png", 0 + l, 1 + l, 8, 7);
        l = 7;
    }
    for (int i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
            caballo[i].dibujar("imagenes/caballonnegro.png", 2 + k, 1 + k, 8,7);
        else
            caballo[i].dibujar("imagenes/caballonblanco.png", 2 + k, 1 + k, 8, 7);
        k = 5;
    }
    for (int i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
            alfil[i].dibujar("imagenes/alfilnblanco.png", 2 + m, 3 + m, 8, 7);
        else
            alfil[i].dibujar("imagenes/alfilnnegro.png", 2 + m, 3 + m, 8, 7);
        m = 3;
    }
    reina.dibujar("imagenes/damannegra.png", 3, 4, 8, 7);
    rey.dibujar("imagenes/reynblanco.png", 4, 5, 8, 7);
}
