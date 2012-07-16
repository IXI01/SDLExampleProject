#ifndef _BALL_H
#define _BALL_H

#include <SDL/SDL.h>
#include "FPS.h"
#include "Define.h"

class Ball {

private:
float x, y;
float speedX, speedY;

public:
Ball();
Ball(int x, int y, float speedX, float speedY);
~Ball();
void OnLoop();
void OnRender(SDL_Surface* surfDisplay);

private:
void Move();
};

#endif
















