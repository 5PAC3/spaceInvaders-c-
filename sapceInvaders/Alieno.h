#pragma once
#include "immediate2d.h"
#include "Ctimer.h"

#define VELOCITA 2

class Alieno
{
private:
	Color colore;
	char type; // small=S mid=M large=L
	int x, y;
	int pt;
	bool spostamento; //true = avanti
	Ctimer deltaT;
	bool esiste;
	 
public:
	Alieno();
	Alieno(int x, int y, char type);
	
	void Draw(int x, int y, Color colore);
	void Move( int row);
	int getSpostamento();
	void colonna( int row, int max, int min);
	int GetX();
	int GetY();
	bool colpito(int xP, int yP);
	bool getEsiste();
	void Delete();
	int getPoints();
};