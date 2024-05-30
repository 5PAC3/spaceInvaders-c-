#include "ProjectileP.h"

ProjectileP::ProjectileP()
{
	x = 0;
	y = 0;
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
	if (esiste)
	{
		this->x = x;
		this->y = y;
		Draw();
	}
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

void ProjectileP::reset()
{
	x = 0;
	y = 0;
	colore = White;
	velocita = 10;
	esiste = true;
}

int ProjectileP::getX()
{
	return x;
}

int ProjectileP::getY()
{
	return y;
}