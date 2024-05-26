#pragma once
#include "immediate2d.h"
#include <chrono>
#include <mutex>

class Alieno
{
private:
	Color colore;
	char type; // small=S mid=M large=L
	int x, y;
	int pt;
	std::mutex mtx;
public:
	Alieno();
	Alieno(int x, int y, char type);

	void Draw(int x, int y, Color colore);
	void Move();
	int GetX();
	int GetY();
};