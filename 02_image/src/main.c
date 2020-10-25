/* This tutorial will open a 640 x 480 screen,
** load an image and display it at specified coordinates
** and wait for the user to either close
** the window or press escape
*/

#include "main.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern SDL_Surface *loadImage(char *);
extern void updateScreen(void);

int main(int argc, char *argv[])
{
	/* Start up SDL */
	init("Parallel Realities Tutorial 2");
	
	/* Call the cleanup function when the program exits */
	atexit(cleanup);
	
	dexterImage = loadImage("gfx/dexter.jpg");
	
	/* If we get back a NULL image, just exit */
	if (dexterImage == NULL)
		exit(0);
	
	while (1)
	{
		getInput();
		updateScreen();
		SDL_Delay(16);
	}
	
	exit(0);
}
