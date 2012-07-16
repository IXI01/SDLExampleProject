#include "Ball.h"

Ball::Ball() {
}

Ball::Ball(int x, int y, float speedX, float speedY) {
  this->x = x;
  this->y = y;
  this->speedX = speedX;
  this->speedY = speedY;
}

Ball::~Ball() {
  
}

void Ball::OnLoop() {
  Move();
}

void Ball::OnRender(SDL_Surface* surfDisplay) {
  SDL_Rect rect;
  rect.x = int(x);
  rect.y = int(y);
  rect.w = BSIZE;
  rect.h = BSIZE;
  
  SDL_FillRect(surfDisplay, &rect, BCOLOR);
}

void Ball::Move() {
  x += (speedX * FPS::FPSControl.GetSpeedFactor());
  y += (speedY * FPS::FPSControl.GetSpeedFactor());

  if (x <= 0 || x >= WWIDTH-BSIZE) {
    if (x <= 0) {
      x = 0;
    }
    else {
      x = WWIDTH-BSIZE;
    }
    
    speedX = -(speedX);
  }
  
  if (y <= 0 || y >= WHEIGHT-BSIZE) {
    if (y <= 0) {
      y = 0;
    }
    else {
      y = WHEIGHT-BSIZE;
    }

    speedY = -(speedY);
  }
  

}
