#include "Setup.h"
#include <SDL.h>
//#include "Defs.h"

bool isGameRunning = false;

double posX, posY;
double dirX, dirY;
double planeX, planeY;
double time, oldTime;
int ticksLastFrame = 0;
float deltaTime;

int worldMap[MAP_WIDTH][MAP_HEIGHT] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void processInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isGameRunning = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE)
			isGameRunning = false;
		if (event.key.keysym.sym == SDLK_UP)
		{
			if (worldMap[int(posX + dirX * deltaTime)][int(posY)] == false) posX += dirX * deltaTime;
			if (worldMap[int(posX)][int(posY + dirY * deltaTime)] == false) posY += dirY * deltaTime;
		}
		if (event.key.keysym.sym == SDLK_DOWN)
		{
			if (worldMap[int(posX + dirX * deltaTime)][int(posY)] == false) posX -= dirX * deltaTime;
			if (worldMap[int(posX)][int(posY + dirY * deltaTime)] == false) posY -= dirY * deltaTime;
		}

			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				double oldDirX = dirX;
				dirX = dirX * cos(-deltaTime) - dirY * sin(-deltaTime);
				dirY = oldDirX * sin(-deltaTime) + dirY * cos(-deltaTime);

				}
					if (event.key.keysym.sym == SDLK_LEFT)

						if (event.key.keysym.sym == SDLK_w)

							break;
	case SDL_KEYUP:
		if (event.key.keysym.sym == SDLK_UP)
			//player.walkDirection = 0;
			if (event.key.keysym.sym == SDLK_DOWN)
				//player.walkDirection = 0;
				if (event.key.keysym.sym == SDLK_RIGHT)
					//player.turnDirection = 0;
					if (event.key.keysym.sym == SDLK_LEFT)
						//player.turnDirection = 0;
						if (event.key.keysym.sym == SDLK_w)

							break;
	}
}

void Update()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TIME_LENGTH));


	deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

	ticksLastFrame = SDL_GetTicks();

	//raycasting

	for (int x = 0; x < WINDOW_WIDTH; x++)
	{
		double cameraX = 2 * x / double(WINDOW_WIDTH) - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		//box of map player is in
		int mapX = int(posX);
		int mapY = int(posY);

		// lenght of ray current position to next side positon
		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
		double prepWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?


		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}

		if (rayDirY < 0)
		{
			stepY = 0;
			sideDistY = (posY - mapY) * deltaDistY;

		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		//proform dda
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//see if ray hit wall.
			if (worldMap[mapX][mapY] > 0) hit = 1;
		}

		if (side == 0) prepWallDist = (sideDistX - deltaDistX);
		else           prepWallDist = (sideDistY - deltaDistY);


		//Calculate height of line to draw on screen
		int lineHeight = (int)(hit / prepWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + hit / 2;
		if (drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + hit / 2;
		if (drawEnd >= hit)drawEnd = hit - 1;
	}
}

void Render()
{

}

int main(int argc, char* args[])
{
	isGameRunning = initWindow();
	posX = 22; posY = 12;
	dirX = -1; dirY = 0;
	planeX = 0; planeY = 65;

	time = 0;
	oldTime = 0;

	//timing for input and FPS counter
	
	while (isGameRunning)
	{
		processInput();
		Update();
		Render();
			
		
		
	}



	return 0;
}