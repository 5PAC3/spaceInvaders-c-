#pragma once
#include "immediate2d.h"

class ProjectileP
{
private:
	Color colore;
public:
	ProjectileP();
	void Draw(int x, int y, Color color);
	void Start(int x, int y);
};

