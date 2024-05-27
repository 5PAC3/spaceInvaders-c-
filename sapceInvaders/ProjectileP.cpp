#include "ProjectileP.h"

ProjectileP::ProjectileP()
{
	colore = White;
	velocita = 10;
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
	int a = x;
	int b = y;

	for (int i=0 ; i < 155; i++)
	{

		//std::lock_guard<std::mutex> lock(mtx);

		Draw(x, y--, colore);
<<<<<<< HEAD
		std::this_thread::sleep_for(std::chrono::milliseconds(20)); 
=======
		Wait(20);
		Draw(x, b--, Black);
		Wait(2);
>>>>>>> 4bb2c16 (commit per capire com funziona sourcetree (nessuna modifica utile))
	}
	
}
