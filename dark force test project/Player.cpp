#include "Player.h"

Player::Player()
{
	posX = WINDOW_WIDTH / 2;
	posY = WINDOW_HEIGHT / 2;
	width = 5;
	height = 5;
	turnDirection = 0;
	walkDirection = 0;
	rotationAngle = PI / 2;
	WalkSpeed = 100;
	turnSpeed = 45 * (PI / 180);
}

void Player::renderPlayer()
{
}
