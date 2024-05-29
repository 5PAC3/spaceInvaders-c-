#include "ProjectileP.h"

ProjectileP::ProjectileP()
{
	colore = White;
	velocita = 10;
	esiste = true;
}

void ProjectileP::Draw()
{
	DrawPixel(x, y, colore);
	DrawPixel(x - 1, y - 1, colore);
	DrawPixel(x, y - 2, colore);
	DrawPixel(x + 1, y - 3, colore);
	DrawPixel(x, y - 4, colore);
}

void ProjectileP::Start(int x, int y)
{
	//for (int i=0 ; i < 155; i++)
	//{
	if (esiste)
	{
	this->x = x;
	this->y = y;
		Draw();
	}
	//Wait(20);
	//}
}

void ProjectileP::Move()
{
	if (esiste)
	{
		if (y > 25)
		{
			y--;
		}
		if (y == 25)
		{
			esiste = false;
		}
	}
}
