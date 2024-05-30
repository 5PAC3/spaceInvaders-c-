#include "Alieno.h"

Alieno::Alieno()
{
	colore = White;
	type = ' ';
	x = 0;
	y = 0;
	pt = 0;
	spostamento = true;
	hx1 = x;
	hy1 = y + 4;
	hx2 = x + 8;
	hy2 = y - 3;
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
			if (deltaT.GetDuration() > 10)
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

int Alieno::GetHX1()
{
	return hx1;
}

int Alieno::GetHY1()
{
	return hy1;
}

int Alieno::GetHX2()
{
	return hx2;
}

int Alieno::GetHY2()
{
	return hy2;
}