#ifndef _BALL_H
#define _BALL_H

#include <SDL/SDL.h>
#include <vector>
#include "FPS.h"
#include "Define.h"
#include "Bar.h"

class Ball {

private:
  float x, y;
  float speedX, speedY;
  float timeout;
  bool active;
  std::vector<const Bar*> bars;

public:
  Ball();
  Ball(float x, float y);
  ~Ball();

  void AddBar(const Bar* bar);
  void OnLoop();
  void OnRender(SDL_Surface* surfDisplay);

private:
  void GenerateRandomSpeed();
  void Move();
};

#endif
















