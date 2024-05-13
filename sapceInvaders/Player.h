#pragma once
#include "immediate2d.h"
#include "ProjectileP.h"

class Player
{
private:
	Color colore;
	int x ,y; //inizio dal centro 189, 130
	ProjectileP projectile;
public:
	Player();
	void Draw();
	void MoveR();
	void MoveL();
	void Shoot();
	int GetX();
	int GetY();
};

