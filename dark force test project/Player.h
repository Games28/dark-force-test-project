#pragma once
#include "Defs.h"
class Player
{
public:
	Player();
	void renderPlayer();

public:
	float posX, posY;
	float width, height;
	int turnDirection, walkDirection;
	float rotationAngle;
	float WalkSpeed, turnSpeed;
};

