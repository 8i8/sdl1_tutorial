#include "init.h"

short init(char *title)
{
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
		printf("Could not initialize SDL: %s\n", SDL_GetError());
		return -1;
	}
	
	screen = SDL_SetVideoMode(640, 480, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);
	
	if (screen == NULL) {
		printf("Couldn't set screen mode to 640 x 480: %s\n",
				SDL_GetError());
		return -1;
	}
	
	SDL_WM_SetCaption(title, NULL);
	/* Hide the mouse cursor */
	SDL_ShowCursor(SDL_DISABLE);

	return 0;
}

void cleanup()
{
	if (brickImage != NULL)
		SDL_FreeSurface(brickImage);
	if (backgroundImage != NULL)
		SDL_FreeSurface(backgroundImage);
	SDL_Quit();
}
