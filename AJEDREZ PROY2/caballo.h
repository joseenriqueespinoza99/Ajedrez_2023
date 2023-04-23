#pragma once



class caballo
{
public:
	//parametros para saber donde esta el caballo
	unsigned int fila;
	unsigned int columna;
	int posAct[2];
	int posSig[2];
	int k;
	char movV;
	char movH[2];
	void mueveCab();
	bool comprobacion(int x, int y);
	
};

