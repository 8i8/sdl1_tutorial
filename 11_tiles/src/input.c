#include "input.h"

void getInput()
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			/*
			 * Closing the Window or pressing Escape will exit the
			 * program Pressing Space will play the sound effect
			 */
			case SDL_QUIT:
			exit(0);
			break;
			
			case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					exit(0);
				break;
				
				default:
				break;
			}
			break;
		}
	}
}
