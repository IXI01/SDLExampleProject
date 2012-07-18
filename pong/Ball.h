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
  float timeinc;
  bool dropped;

public:
  Ball();
  Ball(float x, float y);
  ~Ball();

  void AddBar(const Bar* bar);
  void SetDropped(bool dropped);
  void OnLoop();
  void OnRender(SDL_Surface* surfDisplay);
  float GetX() const;
  float GetY() const;
  float GetSpeedX() const;
  float GetSpeedY() const;
  bool IsActive() const;
  bool IsDropped() const;

private:
  bool BarCollision(const Bar* bar, float newX, float newY);
  void GenerateRandomSpeed();
  void Move();
};

#endif
















