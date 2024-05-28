#pragma once
#include "immediate2d.h"
#include "Ctimer.h"

class Alieno
{
private:
	Color colore;
	char type; // small=S mid=M large=L
	int x, y;
	int pt;
	int velocita;
public:
	Alieno();
	Alieno(int x, int y, char type);

	void Draw(int x, int y, Color colore);
	void Move(Ctimer* deltaT);
	int GetX();
	int GetY();
};