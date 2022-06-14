#include "Map.h"





//void Map::renderMap()
//{
//	for (int i = 0; i < MAP_HEIGHT; i++)
//	{
//		for(int j = 0; j < MAP_WIDTH; j++)
//		{
//			int TileX = j * TILE_SIZE;
//			int TileY = i * TILE_SIZE;
//			int tileColor = map[i][j] != 0 ? 255 : 0;
//
//			SDL_SetRenderDrawColor(Setup::renderer, tileColor, tileColor, tileColor, 255);
//			SDL_Rect mapTileRect = {
//				TileX,
//				TileY,
//				TILE_SIZE,
//				TILE_SIZE
//			};
//			SDL_RenderFillRect(Setup::renderer, &mapTileRect);
//
//		}
//	}
//	
//}
