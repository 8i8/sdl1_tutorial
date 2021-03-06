#include "defs.h"

typedef struct Game
{
	int score, status;
	SDL_Surface *screen;
	TTF_Font *font;
	SDL_Joystick *joystick;
} Game;

typedef struct Sprite
{
	SDL_Surface *image;
} Sprite;

typedef struct Sound
{
	Mix_Chunk *effect;
} Sound;

typedef struct Entity
{
	int active, type;
	int x, y, thinkTime;
	SDL_Surface *sprite;
	void (*action)(void);
	void (*draw)(void);
} Entity;

typedef struct Control
{
	int up, down, left, right, fire;
} Control;

typedef struct Redefine
{
	int redefineIndex;
	char redefineString[255];
} Redefine;
