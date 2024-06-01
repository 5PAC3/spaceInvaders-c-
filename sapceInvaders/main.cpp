#define IMM2D_WIDTH 260 //x
#define IMM2D_HEIGHT 224 //y
#define IMM2D_SCALE 4

#define IMM2D_IMPLEMENTATION   
#include "immediate2d.h"

//include delle classi 
#include "Gioco.h"
#include "Player.h"
#include "Alieno.h"

#include <thread>
#include <chrono>
using namespace std;

uint64_t getMillis() {
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

bool compara(int x1, int y1, int x2, int y2, int xP, int yP) {
	if (x1 <= xP && x2 >= xP && y1 <= yP && y2 >= yP)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void run() {
	Ctimer timerRow1;
	Ctimer timerRow2;
	Ctimer timerRow3;
	Ctimer timerRow4;

	//staert di tutti i timer
	timerRow1.Start();
	timerRow2.Start();
	timerRow3.Start();
	timerRow4.Start();

	//rows
	int row1 = 1;
	int row2 = 2;
	int row3 = 3;
	int row4 = 4;

	int clock = 0;
	int firstRowClock = clock;
	int projectileClock = clock;

	Gioco gioco;
	Player p;

	//row 1
	Alieno SRow1(30, 30, 'S');
	Alieno MRow1(30, 50, 'M');
	Alieno LRow1(30, 70, 'L');
	//row 2
	Alieno SRow2(70, 30, 'S');
	Alieno MRow2(70, 50, 'M');
	Alieno LRow2(70, 70, 'L');
	//row 3
	Alieno SRow3(110, 30, 'S');
	Alieno MRow3(110, 50, 'M');
	Alieno LRow3(110, 70, 'L');
	//row 3
	Alieno SRow4(150, 30, 'S');
	Alieno MRow4(150, 50, 'M');
	Alieno LRow4(150, 70, 'L');

	uint64_t last = 0;

	bool projectile = false;
	while (true)
	{
		auto now = std::chrono::system_clock::now();
		gioco.Draw();
		p.Draw();


		const char key = LastKey();

		if (key == 'd' || key == 'D')
		{
			p.MoveR();
		}
		if (key == 'a' || key == 'A')
		{
			p.MoveL();
		}
		//spara proiettile 
		if (key == ' ')
		{
			if (!projectile)
			{
				if (clock - projectileClock > 40)
				{
					projectile = true;
					p.Shoot();
					projectileClock = clock;

				}
			}
		}
		if (projectile)
		{
			p.moveProjectile();
			if (!p.getPStatus())
			{
				projectile = false;
				p.projectileReset();
			}
		}
	
		//ms counter
		uint64_t ora = getMillis();
		uint64_t delta = ora - last;
		last = ora;
		DrawString(0, 0, to_string(delta).c_str(), "Arial", 15, White);
		DrawString(30, 0, "ms ogni ciclo", "Arial", 8, White);
		
		//mostra comandi
		DrawString(0, 190, " A per muoverti a sinistra    D per muoverti a destra", "Arial", 8, White);
		DrawString(0, 205, " Barra Spaziatrice per sparare", "Arial", 8, White);

		//movimento alieni
		SRow1.Move(row1);
		MRow1.Move(row1);
		LRow1.Move(row1);

		SRow2.Move(row1);
		MRow2.Move(row1);
		LRow2.Move(row1);

		SRow3.Move(row1);
		MRow3.Move(row1);
		LRow3.Move(row1);

		SRow4.Move(row1);
		MRow4.Move(row1);
		LRow4.Move(row1);

		//test hitbox
		/*if (compara(SRow1.GetHX1(), SRow1.GetHY1(), SRow1.GetHX2(), SRow1.GetHY2(), p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
		}*/

		//x1 <= xP && x2 >= xP && y1 <= yP && y2 >= yP
		// 
		//compara(10, 60, 100, 50, p.getProjectileX(), p.getProjectileY())

		/*if (SRow1.GetHX1() <= p.getProjectileX() && SRow1.GetHY1(), SRow1.GetHX2(), SRow1.GetHY2(), p.getProjectileX(), p.getProjectileY())
		{
			
			p.projectileReset();
			projectile = false;
			p.pEreaser();
		}*/

		DrawString(0, 105, to_string(p.getProjectileX()).c_str(), "Arial", 7, White);
		DrawString(0, 90, to_string(p.getProjectileY()).c_str(), "Arial", 7, White);

		DrawString(20, 105, to_string(SRow1.GetX()).c_str(), "Arial", 7, LightGreen);
		DrawString(20, 90, to_string(SRow1.GetY()).c_str(), "Arial", 7, LightGreen);

		if (p.getProjectileY() <= SRow1.GetY() && (p.getProjectileX() <= SRow1.GetX()+8 && p.getProjectileX() >= SRow1.GetX()-8))
		{
			DrawString(100, 100, "0", "Arial", 15, LightGreen);

		}
		if (SRow1.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			DrawString(100, 120, "xxx", "Arial", 15, LightBlue);
		}
		Wait(20);
		Clear();
		clock++;
	}
}