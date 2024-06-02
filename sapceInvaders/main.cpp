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

Gioco gioco;
Player p;

uint64_t getMillis() {
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void showWin() {
	int popUpWidth = 90;
	int popUpHeight = 30;
	int popUpY = 90;
	DrawRectangle((IMM2D_WIDTH / 2) - (popUpWidth / 2), popUpY, popUpWidth, popUpHeight, Black, Lime);
	DrawString((popUpWidth)-3, popUpY + 3, "You Won", "Arial", 15, White);
}

void showLose() {
	int popUpWidth = 90;
	int popUpHeight = 30;
	int popUpY = 90;
	DrawRectangle((IMM2D_WIDTH / 2) - (popUpWidth / 2), popUpY, popUpWidth, popUpHeight, Black, Lime);
	DrawString((popUpWidth)-4, popUpY + 3, "You Lose", "Arial", 15, White);
}

void DeleteEveryAlien() {

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
	bool lost = false;
	int punti = 0;

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

		//points
		DrawString(170, 0, "Punti :", "Arial", 8, White);
		DrawString(205, 0, to_string(punti).c_str(), "Arial", 10, White);

		if (!lost)
		{
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
		}

		//hitboxes
		//Row 1
		if (SRow1.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += SRow1.getPoints();
		}
		if (MRow1.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += MRow1.getPoints();
		}
		if (LRow1.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += LRow1.getPoints();
		}

		//Row 2
		if (SRow2.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += SRow2.getPoints();
		}
		if (MRow2.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += MRow2.getPoints();
		}
		if (LRow2.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += LRow2.getPoints();
		}

		//Row 3
		if (SRow3.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += SRow3.getPoints();
		}
		if (MRow3.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += MRow3.getPoints();
		}
		if (LRow3.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += LRow3.getPoints();
		}

		//Row 4
		if (SRow4.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += SRow4.getPoints();
		}
		if (MRow4.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += MRow4.getPoints();
		}
		if (LRow4.colpito(p.getProjectileX(), p.getProjectileY()))
		{
			p.projectileReset();
			projectile = false;
			p.pEreaser();
			punti += LRow4.getPoints();
		}

		if (((!SRow1.getEsiste() && !MRow1.getEsiste() && !LRow1.getEsiste()) && (!SRow2.getEsiste() && !MRow2.getEsiste() && !LRow2.getEsiste()) && (!SRow3.getEsiste() && !MRow3.getEsiste() && !LRow3.getEsiste()) && (!SRow4.getEsiste() && !MRow4.getEsiste() && !LRow4.getEsiste()) ))
		{
			showWin();
		}

		//Row1 lose
		if (SRow1.GetY() >= 188)
		{
			showLose();
			lost = true;
		}
		if (MRow1.GetY() >= 188)
		{
			showLose();
			lost = true;
		}
		if (LRow1.GetY() >= 188)
		{
			showLose();
			lost = true;
		}
		//Row2 lose
		if (SRow2.GetY() >= 188)
		{
			showLose();
			lost = true;
		}
		if (MRow2.GetY() >= 188)
		{
			showLose();
			lost = true;
		}
		if (LRow2.GetY() >= 188)
		{
			showLose();
			lost = true;
		}
		//Row3 lose
		if (SRow3.GetY() >= 188)
		{
			showLose();
			lost = true;
		}
		if (MRow3.GetY() >= 188)
		{
			showLose();
			lost = true;
		}
		if (LRow3.GetY() >= 188)
		{
			showLose();
			lost = true;
		}
		//Row4 lose
		if (SRow4.GetY() >= 188)
		{
			showLose();
			lost = true;
		}
		if (MRow4.GetY() >= 188)
		{
			showLose();
			lost = true;
		}
		if (LRow4.GetY() >= 188)
		{
			showLose();
			lost = true;
		}

		Wait(20);
		Clear();
		clock++;
	}
}