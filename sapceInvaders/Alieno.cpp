#include "Alieno.h"

Alieno::Alieno()
{
	colore = White;
	type = ' ';
	x = 0;
	y = 0;
	pt = 0;
	spostamento = true;
	esiste = true;
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
	if (type == 'L')
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
	if (type == 'X')
	{
		DrawPixel(x + 1, y, colore);
		DrawPixel(x, y + 1, colore);

		DrawPixel(x + 6, y, colore);
		DrawPixel(x + 7, y + 1, colore);

		DrawPixel(x + 1, y - 4, colore);
		DrawPixel(x, y - 5, colore);

		DrawPixel(x + 6, y - 4, colore);
		DrawPixel(x + 7, y - 5, colore);
		Wait(200);
		type = ' ';
	}
}

void Alieno::Move(int row)
{	
	int max1 = 240;
	int min1 = 10;

	Draw(x, y, colore);
	//colonna 1
	colonna(row, max1, min1);
}

int Alieno::getSpostamento()
{
	if (spostamento)
	{
		return VELOCITA;
	}
	if (!spostamento)
	{
		return VELOCITA * -1;
	}
}

void Alieno::colonna(int row, int max, int min)
{
	if (row == 1)
	{
		if (x < max || x > min)
		{
			if (deltaT.GetDuration() > 0.1)
			{
				x += getSpostamento();
				deltaT.Start();
			}
			if (x == max)
			{
				y += 10;
				spostamento = false;
				x += getSpostamento();
			}
			if (x == min)
			{
				y += 10;
				spostamento = true;
				x += getSpostamento();
			}
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

bool Alieno::colpito(int xP, int yP)
{
	if (esiste && (yP <= y + 2 && (xP <= x+8 && xP >= x-2)))
	{
		esiste = false;
		type = 'X';

		return true;
	}
	else
	{
		return false;
	}
}

bool Alieno::getEsiste()
{
	return esiste;
}

void Alieno::Delete()
{
	esiste = false;
}

int Alieno::getPoints()
{
	return pt;
}
