#include "input.h"

void getInput()
{
	SDL_Event event;
	
	/* Loop through waiting messages and process them */
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			/*
			** Closing the Window or pressing Escape will exit the program
			** The arrow keys will scroll the map around
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
					
					case SDLK_LEFT:
						input.left = 1;
					break;
					
					case SDLK_RIGHT:
						input.right = 1;
					break;
					
					case SDLK_UP:
						input.up = 1;
					break;
					
					case SDLK_DOWN:
						input.down = 1;
					break;
					
					case SDLK_SPACE:
						input.add = 1;
					break;
					
					case SDLK_PERIOD:
					case SDLK_EQUALS:
						input.next = 1;
					break;
					
					case SDLK_COMMA:
					case SDLK_MINUS:
						input.previous = 1;
					break;
					
					case SDLK_s:
						input.save = 1;
					break;
					
					case SDLK_l:
						input.load = 1;
					break;
					
					default:
					break;
				}
			break;
			
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_LEFT:
						input.left = 0;
					break;
					
					case SDLK_RIGHT:
						input.right = 0;
					break;
					
					case SDLK_UP:
						input.up = 0;
					break;
					
					case SDLK_DOWN:
						input.down = 0;
					break;
					
					case SDLK_SPACE:
						input.add = 0;
					break;
					
					case SDLK_PERIOD:
					case SDLK_EQUALS:
						input.next = 0;
					break;
					
					case SDLK_COMMA:
					case SDLK_MINUS:
						input.previous = 0;
					break;
					
					default:
					break;
				}
			break;
			
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button)
				{
					case SDL_BUTTON_LEFT:
						input.add = 1;
					break;
					
					case SDL_BUTTON_RIGHT:
						input.remove = 1;
					break;
					
					default:
					break;
				}
			break;
			
			case SDL_MOUSEBUTTONUP:
				switch(event.button.button)
				{
					case SDL_BUTTON_LEFT:
						input.add = 0;
					break;
					
					case SDL_BUTTON_RIGHT:
						input.remove = 0;
					break;
					
					default:
					break;
				}
			break;
		}
	}
	
	/* Get the mouse coordinates */
	
	SDL_GetMouseState(&input.mouseX, &input.mouseY);
	
	input.mouseX /= TILE_SIZE;
	input.mouseY /= TILE_SIZE;
	
	input.mouseX *= TILE_SIZE;
	input.mouseY *= TILE_SIZE;
}

