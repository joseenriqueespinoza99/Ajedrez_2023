#pragma once
#include "string.h"
#include <iostream>

enum class TipoPieza { ALFIL, TORRE, CABALLO, REINA, REY, PEON };
	class Pieza{
        private:
       TipoPieza piez;
    protected:
     
        bool color;
        int posx;
        int posy;
	public:
    
        virtual ~Pieza() {}
        void dibujar(const char foto[], int x1, int y2);
        void pintar(const char foto1[], const char foto2[], const char foto3[], const char foto4[], int x1, int y2);
        virtual void mueve(unsigned char key) = 0;
        virtual void dibuja() = 0;
        void setColor(bool c);
       // virtual bool esMovimientoValido(int x_origen, int y_origen, int x_destino, int y_destino) = 0;
        bool getColor(){  return color;}
        int getX()  { return posx; }
        int getY()  { return posy; }
        void setX(int x) { this->posx = x; }
        void setY(int y) { this->posy = y; }
       void setPosicion(int x_destino, int y_destino) {
           posx = x_destino;
           posy = y_destino;
        }
       Pieza* muv[27];
       Tablero* t;
	};

