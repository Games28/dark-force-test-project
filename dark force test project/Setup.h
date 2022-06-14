#ifndef SETUP_H
#define SETUP_H

#include <SDL.h>
#include "Defs.h"
#include <iostream>


	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static color_t* colorBuffer;
	static SDL_Texture* colorBufferTexture;

	


	bool initWindow();


	void destroyWindow();

	void clearColorBuffer(color_t color);

	void renderColorBuffer();


#endif // !SETUP_H

