#include "player.h"

extern int loadSprite(char *);
extern void drawImage(SDL_Surface *, int, int);
extern void addBullet(int, int);
extern SDL_Surface *getSprite(int);

void initPlayer()
{
	player.sprite = getSprite(PLAYER_SPRITE);
	
	player.x = SCREEN_WIDTH / 2;
	player.y = SCREEN_HEIGHT / 2;
	
	player.h = player.sprite->h;
	player.w = player.sprite->w;
	
	player.active = 1;
	player.type = TYPE_PLAYER;
}

void doPlayer()
{
	if (player.active == 1)
	{	

		player.thinkTime--;
		
		if (player.thinkTime <= 0)
		{
			player.thinkTime = 0;
		}

		if (input.up == 1)
		{
			player.y -= PLAYER_SPEED;
			
			/* Don't allow the player to move off the screen */
			
			if (player.y < 0)
			{
				player.y = 0;
			}
		}
		
		if (input.down == 1)
		{
			player.y += PLAYER_SPEED;
			
			/* Don't allow the player to move off the screen */
			
			if (player.y + player.h >= SCREEN_HEIGHT)
			{
				player.y = SCREEN_HEIGHT - (player.h + 1);
			}
		}
		
		if (input.left == 1)
		{
			player.x -= PLAYER_SPEED;
			
			/* Don't allow the player to move off the screen */
			
			if (player.x < 0)
			{
				player.x = 0;
			}
		}
		
		if (input.right == 1)
		{
			player.x += PLAYER_SPEED;
			
			/* Don't allow the player to move off the screen */
			
			if (player.x + player.w >= SCREEN_WIDTH)
			{
				player.x = SCREEN_WIDTH - (player.w + 1);
			}
		}

		if (input.fire == 1)
		{
			/* You can only fire when the thinkTime is 0 or less */
			
			if (player.thinkTime <= 0)
			{
				addBullet(player.x + player.sprite->w, player.y + (player.sprite->h / 2));
				
				player.thinkTime = MAX_RELOAD_TIME;
			}
		}
	}
}

void drawPlayer()
{
	/* Draw the image in the player structure */
	
	if (player.active == 1)
	{
		drawImage(player.sprite, player.x, player.y);
	}
}

