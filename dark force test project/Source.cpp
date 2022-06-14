#include "Setup.h"
#include "Player.h"
#include "Map.h"
//#include "Defs.h"

bool isGameRunning = false;
int ticksLastFrame = 0;
Player player;
//Map map;


void Setting()
{
	
}

const int map[MAP_WIDTH][MAP_HEIGHT] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};


void renderMap()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			int TileX = j * TILE_SIZE;
			int TileY = i * TILE_SIZE;
			int tileColor = map[i][j] != 0 ? 255 : 0;

			SDL_SetRenderDrawColor(renderer, 0, tileColor, tileColor, 255);
			SDL_Rect mapTileRect = {
				TileX,
				TileY,
				TILE_SIZE,
				TILE_SIZE
			};
			SDL_RenderFillRect(renderer, &mapTileRect);

		}
	}

}

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
		break;


	}
}

void Update()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TIME_LENGTH));

	float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

	ticksLastFrame = SDL_GetTicks();

	
}

void Render()
{
	SDL_SetRenderDrawColor(renderer, 0, 100, 255, 255);
	SDL_RenderClear(renderer);

	//map.renderMap();
	//renderMap();

	SDL_RenderPresent(renderer);
}

int main(int argc, char* args[])
{
	isGameRunning = initWindow();
	
	Setting();

	while (isGameRunning)
	{
		processInput();
		Update();
		Render();

		
	}

	destroyWindow();

	return 0;
}
