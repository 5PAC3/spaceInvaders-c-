#pragma once
#include "immediate2d.h"
#include <thread>
#include <chrono>
#include <mutex>

class ProjectileP
{
private:
	Color colore;
<<<<<<< HEAD
	std::mutex mtx;
=======
	int velocita;
>>>>>>> 4bb2c16 (commit per capire com funziona sourcetree (nessuna modifica utile))
public:
	ProjectileP();
	void Draw(int x, int y, Color color);
	void Start(int x, int y);
};

