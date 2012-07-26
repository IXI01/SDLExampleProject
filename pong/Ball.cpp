#include "Ball.h"
#include <cstdlib>
#include <ctime>

#include <iostream>

Ball::Ball() {

}

Ball::Ball(float x, float y) {
  this->x = x;
  this->y = y;
  this->active = false;
  this->dropped = false;
  this->timeout = 32 * TIMEDEATH;
  this->timeinc = 32 * SPEEDINC;
  GenerateRandomSpeed();
}

Ball::~Ball() {
  
}

void Ball::GenerateRandomSpeed() {
  srand((unsigned)time(0));

  speedX = rand()%20 - 9;

  if (speedX < 0 && speedX > -5) {
    speedX = -5;
  }
  if (speedX >= 0 && speedX < 5) {
    speedX = 5;
  }
  
  speedY = rand()%20 - 9;
  if (speedY < 0 && speedY > -5) {
    speedY = -5;
  }
  if (speedY >= 0 && speedY < 5) {
    speedY = 5;
  }
}

void Ball::OnLoop() {
  if (active) {
    Move();

    if (timeinc <= 0) {
      if (speedX < 0) {
	speedX -= SPEEDINC;
      }
      else {
	speedX += SPEEDINC;
      }
      if (speedY < 0) {
	speedY -= SPEEDINC;
      }
      else {
	speedY += SPEEDINC;
      }
      
      timeinc = 32 * INCTIME;
    }

    timeinc -= 1*FPS::FPSControl.GetSpeedFactor();
  }
  else {
    timeout -= 1*FPS::FPSControl.GetSpeedFactor();
    if (timeout <= 0) {
      active = true;
      x = WWIDTH/2 - BSIZE/2;
      y = WHEIGHT/2 - BSIZE/2;
      timeout = 32 * TIMEDEATH;
      timeinc = 32 * INCTIME;

      GenerateRandomSpeed();
    }
  }
}

void Ball::OnRender(SDL_Surface* surfDisplay) {
  if (active) {
    SDL_Rect rect;
    rect.x = int(x);
    rect.y = int(y);
    rect.w = BSIZE;
    rect.h = BSIZE;
    
    SDL_FillRect(surfDisplay, &rect, BCOLOR);
  }
}

void Ball::AddBar(const Bar* bar) {
  this->bars.push_back(bar);
}

void Ball::SetDropped(bool dropped) {
  this->dropped = dropped;
}

float Ball::GetX() const {
  return x;
}

float Ball::GetY() const {
  return y;
}

float Ball::GetSpeedX() const {
  return speedX;
}

float Ball::GetSpeedY() const {
  return speedY;
}

bool Ball::IsActive() const {
  return active;
}

bool Ball::IsDropped() const {
  return dropped;
}

void Ball::Move() {
  float newX, newY;
  float moveX, moveY;

  moveX = speedX * FPS::FPSControl.GetSpeedFactor();
  moveY = speedY * FPS::FPSControl.GetSpeedFactor();

  if (moveY == 0 || moveX == 0)
    return;
  
  
  if(moveX >= 0) {
    newX =  FPS::FPSControl.GetSpeedFactor();
  }
  else {
    newX = -FPS::FPSControl.GetSpeedFactor();
  }

  if(moveY >= 0) {
    newY =  FPS::FPSControl.GetSpeedFactor();
  }
  else {
    newY = -FPS::FPSControl.GetSpeedFactor();
  }

   
  while (true) {
    // Check for Bar Collision
    for(int i = 0;(unsigned)i < bars.size();i++) {
      if (BarCollision(bars[i], newX, newY)) {
	return;
      }
    }

    // Check for Wall Collision
    if (x+newX <= 0 || x+newX >= WWIDTH-BSIZE) {
      speedX = -(speedX);
      break;
    }
  
    if (y+newY <= 0 || y+newY >= WHEIGHT-BSIZE) {
      active = false;
      dropped = true;
      speedY = -(speedY);
      break;
    }

    x += newX;
    y += newY;
    moveX -= newX;
    moveY -= newY;
      
    if(newX > 0 && moveX <= 0) newX = 0;
    if(newX < 0 && moveX >= 0) newX = 0;
 
    if(newY > 0 && moveY <= 0) newY = 0;
    if(newY < 0 && moveY >= 0) newY = 0;
 
    if(moveX == 0) newX = 0;
    if(moveY == 0) newY = 0;
 
    if(moveX == 0 && moveY == 0) break;
    if(newX  == 0 && newY  == 0) break;
 
  }
}

bool Ball::BarCollision(const Bar* bar, float newX, float newY) {
  float ballTopEdge, ballBotEdge, ballLeftEdge, ballRightEdge;
  float barTopEdge, barBotEdge, barLeftEdge, barRightEdge;

  ballTopEdge = y;
  ballBotEdge = y+BSIZE;
  ballLeftEdge = x;
  ballRightEdge = x+BSIZE;

  barTopEdge = bar->GetY();
  barBotEdge = bar->GetY() + BARHEIGHT;
  barLeftEdge = bar->GetX();
  barRightEdge = bar->GetX() + BARWIDTH;
  
  if (barTopEdge < ballBotEdge+newY && ballTopEdge+newY < barBotEdge) {
    if (barLeftEdge < ballRightEdge+newX && ballLeftEdge+newX < barRightEdge) {

      if (barTopEdge < ballBotEdge && ballTopEdge < barBotEdge) {
	if (
	    (barRightEdge < ballLeftEdge && speedX < 0)
	    ||
	    (barLeftEdge > ballRightEdge && speedX > 0)
	    ) {
	  speedX = -(speedX);
	}
	if (barLeftEdge < ballLeftEdge) {
	  x = barRightEdge+1;
	  if (ballRightEdge >= WWIDTH) {
	    x = WWIDTH-BSIZE;

	    y = barTopEdge-BSIZE-1;
	    speedY = -(speedY);
	  }
	}
	else {
	  x = barLeftEdge-BSIZE-1;
	  if (x <= 0) {
	    x = 0;

	    y = barTopEdge-BSIZE-1;
	    speedY = -(speedY);
	  }
	}
      }
      else {
	speedY = -(speedY);
      }
	  
      return true;
    }
  }

  return false;
}

