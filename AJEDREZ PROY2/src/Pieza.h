#pragma once
#include "string.h"
#include <iostream>
#include "Coordenadas.h"

	class Pieza{

    private:
        int jugador_actual;
        int movimientos = 0; //para saber si una pieza se ha movido o sigue en su posicion original
    protected:
        int x, y;
        bool color;
        Coordenadas Coordenadas;

	public:

        virtual ~Pieza() {}
        enum class TipoPieza { ALFIL, TORRE, CABALLO, REINA, REY, PEON};

        void dibujar(const char foto[], int x1, int y2);
        void pintar(const char foto1[], const char foto2[], const char foto3[], const char foto4[], int x1, int y2);
        void setColor(bool c);

        virtual void mueve(unsigned char key) = 0;
        virtual void dibuja() = 0;
        virtual bool esmovimientoValido(int x_Destino, int y_Destino, bool comer) = 0;
        
        //virtual bool esMovimientoValido(int x_origen, int y_origen, int x_destino, int y_destino) = 0;
        bool getColor(){  return color;}
        void setMov() { movimientos++; }
        int getMov() { return movimientos; }
        int getX()  { return Coordenadas.getX(); }
        int getY()  { return Coordenadas.getY(); }
        void setX(int x) { this->Coordenadas.setX(x); }
        void setY(int y) { this->Coordenadas.y = y; }
        void setPosicion(int x_destino, int y_destino) { Coordenadas.x = x_destino; Coordenadas.y = y_destino;}
	    virtual void mover(int x, int y, bool comer)=0;
        virtual TipoPieza getClass() const = 0;
        //las hacemos amigas para que puedan acceder a los atributo privados de la otra clase
   
	    };

