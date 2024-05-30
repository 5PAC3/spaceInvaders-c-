#pragma once
#include "immediate2d.h"
#include <thread>
#include <chrono>
#include <mutex>

class ProjectileP
{
private:
	Color colore;
	int velocita;
	int x, y;
public:
	bool esiste;
	ProjectileP();
	void Draw();
	void Start(int x, int y);
	void Move();
	void reset();
	int getX();
	int getY();
};

