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
	int hx1;
	int hy1;
	int hx2;
	int hy2;
	 
public:
	Alieno();
	Alieno(int x, int y, char type);
	
	void Draw(int x, int y, Color colore);
	void Move( int row);
	int getSpostamento();
	void colonna( int row, int max, int min);
	int GetX();
	int GetY();

	int GetHX1();
	int GetHY1();

	int GetHX2();
	int GetHY2();

	bool colpito(int xP, int yP);
};