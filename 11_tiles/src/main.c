/*
 * This tutorial will open a 640 x 480 screen
 * and display a map. Pressing escape
 * or closing the window will exit the program
 */

#include "main.h"

extern short init(char *);
extern void cleanup(void);
extern void getInput(void);
short short loadMap(char *);
extern SDL_Surface *loadImage(char *);
extern void draw(void);
extern void delay(unsigned int);

int main(int argc, char *argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	
	if (init("Parallel Realities Tutorial 11"))
		goto equit;
	
	/* Load the brick image */
	if ((brickImage = loadImage("gfx/brick.png")) == NULL)
		goto equit;
	
	/* Load the background image */
	if ((backgroundImage = loadImage("gfx/background.png")) == NULL)
		goto equit;
	
	if (loadMap("data/maps/map02.dat"))
		goto equit;
	
	while (1)
	{
		getInput();
		draw();

		/* Stop excessive cpu use */
		delay(frameLimit);
		frameLimit = SDL_GetTicks() + 16;
	}
equit:	
	/* Call the cleanup function when the program exits */
	cleanup();
	
	return 0;
}
