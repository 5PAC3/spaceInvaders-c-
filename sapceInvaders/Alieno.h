#pragma once
#include "immediate2d.h"
<<<<<<< HEAD
#include <chrono>
=======
>>>>>>> 4bb2c16 (commit per capire com funziona sourcetree (nessuna modifica utile))

class Alieno
{
private:
	Color colore;
	char type; // small=S mid=M large=L
	int x, y;
	int pt;
<<<<<<< HEAD
=======
	int velocita;
>>>>>>> 4bb2c16 (commit per capire com funziona sourcetree (nessuna modifica utile))
public:
	Alieno();
	Alieno(int x, int y, char type);

	void Draw(int x, int y, Color colore);
	void Move();
	int GetX();
	int GetY();
};