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

	Ctimer timer;
	timer.Start();

	int clock = 0;
	int firstRowClock = clock;
	int projectileClock = clock;

	Gioco gioco;
	Player p;
	Alieno S(30, 30, 'S');
	Alieno M(30, 43, 'M');
	Alieno L(30, 55, 'L');

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
	
		//S.Draw(30, 30, White);
		M.Draw(30, 43, White);
		L.Draw(30, 55, White);


		/*if (S.GetX() < 240)
		{
			if (clock - firstRowClock == 10)
			{
				S.Move();
				firstRowClock = clock;
			}
		}*/

		//fps counter
		uint64_t ora = getMillis();
		uint64_t delta = ora - last;
		last = ora;
		DrawString(0, 0, to_string(delta).c_str(), "Arial", 15, White);

	
		S.Move(&timer);


	
		Wait(20);

		
		Clear();
		clock++;
	}
	
}

// destra \u001b[C     77
// sinistra \u001b[D     75