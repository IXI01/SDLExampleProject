#include "Ball.h"
#include <cstdlib>
#include <ctime>

#include <iostream>

Ball::Ball() {

}

Ball::Ball(float x, float y) {
  this->x = x;
  this->y = y;
  this->active = true;
  this->timeout = 32 * 2;
  GenerateRandomSpeed();
}

Ball::~Ball() {
  
}

void Ball::GenerateRandomSpeed() {
  srand((unsigned)time(0));

  speedX = rand()%20 - 9;
  if (speedX == 0) {
    speedX = 1;
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
  }
  else {
    timeout -= 1*FPS::FPSControl.GetSpeedFactor();
    if (timeout <= 0) {
      active = true;
      x = WWIDTH/2 - BSIZE/2;
      y = WHEIGHT/2 - BSIZE/2;
      this->timeout = 32 * 2;
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

void Ball::Move() {
  float newX, newY;
  float moveX, moveY;

  moveX = speedX * FPS::FPSControl.GetSpeedFactor();
  moveY = speedY * FPS::FPSControl.GetSpeedFactor();
  
  if(moveX != 0) {
    if(moveX >= 0) {
      newX =  FPS::FPSControl.GetSpeedFactor();
    }
    else {
      newX = -FPS::FPSControl.GetSpeedFactor();
    }
  }

  if(moveY != 0) {
    if(moveY >= 0) {
      newY =  FPS::FPSControl.GetSpeedFactor();
    }
    else {
      newY = -FPS::FPSControl.GetSpeedFactor();
    }
  }
  else {
    return;
  }
   
  while (true) {
    // Check for Bar Collision
    for(int i = 0;(unsigned)i < bars.size();i++) {
      if (bars[i]->GetY() < y+newY+BSIZE
	  && y+newY < bars[i]->GetY()+BARHEIGHT) {
	if (bars[i]->GetX() < x+newX+BSIZE
	    && x+newX < bars[i]->GetX()+BARWIDTH) {

	  if (bars[i]->GetY() < y+BSIZE
	      && y < bars[i]->GetY()+BARHEIGHT) {
	    if (
		(bars[i]->GetX()+BARWIDTH < x
		&& speedX < 0)
		||
		(bars[i]->GetX() > x+BSIZE
		&& speedX > 0)
		) {
	      speedX = -(speedX);
	    }
	    if (bars[i]->GetX() < x) {
	      x = bars[i]->GetX()+BARWIDTH+1;
	      if (x+BSIZE >= WWIDTH) {
		x = WWIDTH-BSIZE;

		y = bars[i]->GetY()-BSIZE-1;
		speedY = -(speedY);
	      }
	    }
	    else {
	      x = bars[i]->GetX()-BSIZE-1;
	      if (x <= 0) {
		x = 0;

		y = bars[i]->GetY()-BSIZE-1;
		speedY = -(speedY);
	      }
	    }
	  }
	  else {
	    speedY = -(speedY);
	  }
	  
	  return;
	}
      }
    }

    // Check for Wall Collision
    if (x+newX <= 0 || x+newX >= WWIDTH-BSIZE) {
      speedX = -(speedX);
      break;
    }
  
    if (y+newY <= 0 || y+newY >= WHEIGHT-BSIZE) {
      if (y+newY <= 0) {
	
      }
      else {
	active = false;
      }
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


  // Check for Bar Collision
  /*for(int i = 0;(unsigned)i < bars.size();i++) {
    if (bars[i]->GetY() < y+BSIZE && y < bars[i]->GetY()+BARHEIGHT) {
    if (bars[i]->GetX() < newX+BSIZE && newX < bars[i]->GetX()+BARWIDTH) {
    speedX = -(speedX);
    return;
    }
    }

    if (bars[i]->GetY() < newY+BSIZE && newY < bars[i]->GetY()+BARHEIGHT) {
    if (bars[i]->GetX() < newX+BSIZE && newX < bars[i]->GetX()+BARWIDTH) {
	
    speedY = -(speedY);
    return;
    }
    }
    }
    x = newX;
    y = newY;
  
    // Check for Wall Collision
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
    active = false;
    }

    speedY = -(speedY);
    }
  */

}
