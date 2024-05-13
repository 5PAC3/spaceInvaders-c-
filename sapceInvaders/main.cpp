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
using namespace std;

void run() {
	int clock = 0;

	Gioco gioco;
	Player p;
	Alieno S(30, 30, 'S');
	Alieno M(30, 43, 'M');
	Alieno L(30, 55, 'L');

	while (true)
	{
		gioco.Draw();
		p.Draw();


		const char key = LastKey();

		if (key == 'd')
		{
			p.MoveR();
		}else if (key == 'a')
		{
			p.MoveL();
		}
		if (key == ' ')
		{
			thread T(&Player::Shoot, &p);
			T.detach();
		}
	
		//S.Draw(30, 30, White);
		M.Draw(30, 43, White);
		L.Draw(30, 55, White);

		if (S.GetX() < 240)
		{
			thread S1(&Alieno::Move, &S);
			S1.detach();
		}

		Wait(20);
		Clear();
		clock++;
	}
	
}

// destra \u001b[C     77
// sinistra \u001b[D     75