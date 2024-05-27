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

public:
	ProjectileP();
	void Draw(int x, int y, Color color);
	void Start(int x, int y);
};

