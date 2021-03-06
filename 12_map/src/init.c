#include "init.h"

void init(char *title)
{
	/* Initialise SDL Video and Audio */
	
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0)
	{
		printf("Could not initialize SDL: %s\n", SDL_GetError());
		
		exit(1);
	}
	
	/* Open a screen */
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);
	
	if (screen == NULL)
	{
		printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());

		exit(1);
	}
	
	/* Set the screen title */
	
	SDL_WM_SetCaption(title, NULL);
	
	/* Hide the mouse cursor */
	
	SDL_ShowCursor(SDL_DISABLE);
}

void cleanup()
{
	/* Free the brick image */
	
	if (brickImage != NULL)
	{
		SDL_FreeSurface(brickImage);
	}
	
	/* Free the brick image */
	
	if (backgroundImage != NULL)
	{
		SDL_FreeSurface(backgroundImage);
	}
	
	/* Shut down SDL */
	
	SDL_Quit();
}
