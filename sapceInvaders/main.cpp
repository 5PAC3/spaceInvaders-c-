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

void run() {
	Ctimer timerRow1;
	Ctimer timerRow2;
	Ctimer timerRow3;

	//staert di tutti i timer
	timerRow1.Start();
	timerRow2.Start();
	timerRow3.Start();

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
	Alieno SRow1(30, 10, 'S');
	Alieno MRow1(30, 23, 'M');
	Alieno LRow1(30, 35, 'L');
	//row 2
	//Alieno SRow2(35, 10, 'S');
	//Alieno MRow2(35, 23, 'M');
	//Alieno LRow2(35, 35, 'L');

	uint64_t last = 0;
	while (true)
	{
		auto now = std::chrono::system_clock::now();
		gioco.Draw();
		p.Draw();


		const char key = LastKey();

		if (key == 'd')
		{
			p.MoveR();
		}
		if (key == 'a')
		{
			p.MoveL();
		}
		if (key == ' ')
		{
			if (clock - projectileClock > 40)
			{
				thread T(&Player::Shoot, &p);
				T.detach();
				projectileClock = clock;

			}
		}
	
		//fps counter
		uint64_t ora = getMillis();
		uint64_t delta = ora - last;
		last = ora;
		DrawString(0, 0, to_string(delta).c_str(), "Arial", 15, White);
		DrawString(30, 0, "ms ongi ciclo", "Arial", 8, White);
		
		//mostra comandi
		DrawString(0, 190, " A per muoverti a sinistra    D per muoverti a destra", "Arial", 8, White);
		DrawString(0, 205, " Spazio per sparare", "Arial", 8, White);

		//movimento alieni
		SRow1.Move( row1);
		MRow1.Move( row1);
		LRow1.Move( row1);

		//SRow2.Move(&timerRow2, row1);
		//MRow2.Move(&timerRow2, row1);
		//LRow2.Move(&timerRow2, row1);

	
		Wait(20);
		Clear();
		clock++;
	}
	
}