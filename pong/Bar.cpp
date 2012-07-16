#include "Bar.h"

Bar::Bar() {

}

Bar::Bar(float x, float y, float speed) {
  this->x = x;
  this->y = y;
  this->speed = speed;

  this->moveLeft = false;
  this->moveRight = false;
}

Bar::~Bar() {

}

void Bar::OnLoop() {
  Move();
}

void Bar::OnRender(SDL_Surface* surfDisplay) {
  SDL_Rect rect;
  rect.x = int(x);
  rect.y = int(y);
  rect.w = BARWIDTH;
  rect.h = BARHEIGHT;
  
  SDL_FillRect(surfDisplay, &rect, BCOLOR);
}

void Bar::SetMoveLeft(bool moveLeft) {
  this->moveLeft = moveLeft;
}

void Bar::SetMoveRight(bool moveRight) {
  this->moveRight = moveRight;
}

float Bar::GetX() const {
  return x;
}

float Bar::GetY() const {
  return y;
}

void Bar::Move() {
  if (moveLeft == true && moveRight == false) {
    x -= (speed * FPS::FPSControl.GetSpeedFactor());
  }
  else if (moveLeft == false && moveRight == true) {
    x += (speed * FPS::FPSControl.GetSpeedFactor());
  }

  if (x < 0) {
    x = 0;
  }
  if (x > WWIDTH-BARWIDTH) {
    x = WWIDTH-BARWIDTH;
  }
}
