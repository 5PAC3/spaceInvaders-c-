#include "Alieno.h"

Alieno::Alieno()
{
	colore = White;
	type = ' ';
	x = 0;
	y = 0;
	pt = 0;
	velocita = 1;
}

Alieno::Alieno(int x, int y, char type)
{
	this->x = x;
	this->y = y;
	this->type = type;
	colore = White;

	if (type == 'S') {
		pt = 30;
	}
	if (type == 'M') {
		pt = 20;
	}
	if (type == 'L') {
		pt = 10;
	}
}

void Alieno::Draw(int x, int y, Color colore)
{
	if (type == 'S')
	{
		//corpo
		DrawRectangle(x, y, 8, 1, colore, colore);
		DrawLine(x + 1, y - 1, x + 7, y -1, 1, colore);
		//occhi
		DrawPixel(x + 2, y , Black);
		DrawPixel(x + 6, y , Black);
		//testa
		DrawLine(x + 2, y - 2, x + 6, y - 2, 1, colore);
		DrawLine(x + 3, y - 3, x + 5, y - 3, 1, colore);
		//tentacoli
		DrawLine(x + 1, y + 2, x + 7, y + 4, 1, colore);
		DrawLine(x + 7, y + 2, x + 1, y + 4, 1, colore);
	}
	if (type == 'M')
	{
		//corpo
		DrawRectangle(x, y, 8, 1, colore, colore);
		DrawLine(x + 1, y - 1, x + 7, y - 1, 1, colore);
		//occhi
		DrawPixel(x + 2, y, Black);
		DrawPixel(x + 6, y, Black);
		//antenne
		DrawPixel(x + 2, y - 2, colore);
		DrawPixel(x + 1, y - 3, colore);
		DrawPixel(x + 6, y - 2, colore);
		DrawPixel(x + 7, y - 3, colore);
		//gamba dx
		DrawPixel(x + 7, y + 2, colore);
		DrawPixel(x + 6, y + 3, colore);
		DrawPixel(x + 5, y + 3, colore);
		//gamba sx
		DrawPixel(x + 1, y + 2, colore);
		DrawPixel(x + 2, y + 3, colore);
		DrawPixel(x + 3, y + 3, colore);
		//braccio dx
		DrawPixel(x - 1, y + 2, colore);
		DrawPixel(x - 1, y + 3, colore);
		//braccio sx
		DrawPixel(x + 9, y + 2, colore);
		DrawPixel(x + 9, y + 3, colore);
	}
	if(type == 'L')
	{
		//corpo
		DrawRectangle(x, y, 9, 1, colore, colore);
		DrawLine(x + 1, y - 1, x + 8, y - 1, 1, colore);
		//testa
		DrawPixel(x + 3, y - 2, colore);
		DrawPixel(x + 4, y - 2, colore);
		DrawPixel(x + 5, y - 2, colore);
		DrawPixel(x + 6, y - 2, colore);
		//occhi
		DrawPixel(x + 2, y, Black);
		DrawPixel(x + 3, y, Black);
		DrawPixel(x + 7, y, Black);
		DrawPixel(x + 6, y, Black);
		//gambe 
		DrawPixel(x + 2, y + 2, colore);
		DrawPixel(x + 3, y + 2, colore);
		DrawPixel(x + 1, y + 3, colore);
		DrawPixel(x + 7, y + 2, colore);
		DrawPixel(x + 6, y + 2, colore);
		DrawPixel(x + 8, y + 3, colore);
		//bocca
		DrawPixel(x + 4, y + 3, colore);
		DrawPixel(x + 5, y + 3, colore);
	}
}

void Alieno::Move(Ctimer* deltaT)
{	
	Draw(x, y, colore);
	if (x < 240)
	{
		if (deltaT->GetDuration() > 1000)
		{
			x++;
			deltaT->Start();
		}
	}
}

int Alieno::GetX()
{
	return x;
}

int Alieno::GetY()
{
	return y;
}