#include "ProjectileP.h"

ProjectileP::ProjectileP()
{
	colore = White;
}

void ProjectileP::Draw(int x, int y, Color color)
{
	DrawPixel(x, y, color);
	DrawPixel(x - 1, y - 1, color);
	DrawPixel(x , y - 2, color);
	DrawPixel(x +1 , y - 3, color);
	DrawPixel(x, y - 4, color);
}

void ProjectileP::Start(int x, int y)
{
	int a = y;

	for (int i=0 ; i < 155; i++)
	{
		Draw(x, y--, colore);
		Wait(20);
		Draw(x, a--, Black);
		Wait(2);
	}
	
}
