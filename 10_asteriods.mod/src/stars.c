#include "stars.h"

int getStarColor(int);

void resetStars()
{
	int i;

	for (i=0;i<MAX_STARS;i++)
	{
		star[i].x = rand() % SCREEN_WIDTH;
		star[i].y = rand() % SCREEN_HEIGHT;
		star[i].speed = 1 + (rand() % 12);
	}
}

void doStars()
{
	int i;

	for (i=0;i<MAX_STARS;i++)
	{
		star[i].x -= star[i].speed;

		if (star[i].x <= 0)
		{
			star[i].x = SCREEN_WIDTH + rand() % 20;
			star[i].y = rand() % SCREEN_HEIGHT;
			star[i].speed = 1 + (rand() % 12);
		}
	}
}

void drawStars()
{
	int i;
	SDL_Rect rect;

	for (i=0;i<MAX_STARS;i++)
	{
		rect.x = star[i].x;
		rect.y = star[i].y;
		rect.w = 1;
		rect.h = 1;

		SDL_FillRect(game.screen, &rect, getStarColor(star[i].speed));
	}
}

int getStarColor(int speed)
{
	SDL_Color color;
	
	switch (speed)
	{
		case 1:
		case 2:
		case 3:
			color.r = 155;
			color.g = 155;
			color.b = 155;
			break;
				
		case 4:
		case 5:
		case 6:
			color.r = 190;
			color.g = 190;
			color.b = 190;
			break;
				
		case 7:
		case 8:
		case 9:
			color.r = 225;
			color.g = 225;
			color.b = 225;
			break;
			
		default:
			color.r = 255;
			color.g = 255;
			color.b = 255;
			break;
	}
	
	return SDL_MapRGB(game.screen->format, color.r, color.g, color.b);
}
