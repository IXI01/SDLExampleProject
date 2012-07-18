#ifndef _BAR_H
#define _BAR_H

#include <SDL/SDL.h>
#include "FPS.h"
#include "Define.h"

class Bar {

private:
  float x, y, speed;
  bool moveLeft, moveRight;

public:
  Bar();
  Bar(float x, float y, float speed);
  ~Bar();
  void OnLoop();
  void OnRender(SDL_Surface* surfDisplay);

  void SetMoveLeft(bool moveLeft);
  void SetMoveRight(bool moveRight);

  void SetX(float x);
  void SetY(float y);
  
  float GetX() const;
  float GetY() const;
  
private:
  void Move();
};

#endif
