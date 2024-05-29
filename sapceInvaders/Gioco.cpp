#include "Gioco.h"

Gioco::Gioco()
{
	colore = Lime;
}

void Gioco::Draw()
{
	DrawLine(0, 20, 260, 20, 1, colore);
	DrawLine(0, 20, 0, 190, 1, colore);

	DrawLine(0, 190, 260, 190, 1, colore);
	DrawLine(259, 190, 259, 20, 1, colore);

	//170   20-190


}


