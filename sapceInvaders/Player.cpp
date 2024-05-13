#include "Player.h"

Player::Player()
{
	colore = Lime;
	x = 130;
	y = 188;
}

void Player::Draw()
{
	DrawPixel(x, y - 5, colore);
	DrawPixel(x - 1, y - 5, colore);
	DrawPixel(x + 1, y - 5, colore);
	DrawPixel(x, y - 6, colore);

	DrawRectangle(x - 4, y - 4, 8, 3, colore, colore);

	DrawPixel(x - 4, y - 4, Black);
	DrawPixel(x + 4, y - 4, Black);
}

void Player::MoveR()
{
	if (x < 252)
	{
		x += 2;
	}
}

void Player::MoveL()
{
	if (x > 7)
	{
		x -= 2;
	}
}

void Player::Shoot()
{
	projectile.Start(x, y - 7);
}

int Player::GetX()
{
	return x;
}

int Player::GetY()
{
	return y;
}
