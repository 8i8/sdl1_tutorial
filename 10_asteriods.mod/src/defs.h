#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define MAX_ENTITIES 50
#define MAX_STARS 200
#define MAX_RELOAD_TIME 20

#define PLAYER_SPEED 3
#define BULLET_SPEED 10
#define ROCK_SPEED 4

enum
{
	PLAYER_SPRITE,
	BULLET_SPRITE,
	MAX_SPRITES
};

enum
{
	TYPE_PLAYER,
	TYPE_METEOR,
	TYPE_BULLET
};

enum
{
	ROCK_ANIMATION,
 	MAX_ANIMATIONS
};

enum
{
	EXPLOSION_SOUND,
	BULLET_SOUND,
 	MAX_SOUNDS
};
