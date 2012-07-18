#include "AI.h"
#include <math.h>

AI::AI() {
  this->bar = NULL;
  this->ball = NULL;
}

AI::AI(Bar* bar, Ball* ball) {
  this->bar = bar;
  this->ball = ball;
}

AI::~AI() {
}

void AI::ControlBar() {
  float midOfBar = bar->GetX()+BARWIDTH/2;
  float midOfBall = ball->GetX()+BSIZE/2;

  if (!ball->IsActive()) {
    midOfBall = WWIDTH/2;
  }

  if (
      (ball->GetY() > bar->GetY() && ball->GetSpeedY() > 0)
      ||
      (ball->GetY() < bar->GetY() && ball->GetSpeedY() < 0)
      ) {
    midOfBall = WWIDTH/2;
  }
  
  bar->SetMoveLeft(false);
  bar->SetMoveRight(false);


  if (fabs(midOfBar - midOfBall) > 5) {
    if (midOfBar < midOfBall) {
      bar->SetMoveRight(true);
    }
    else if (midOfBar > midOfBall) {
      bar->SetMoveLeft(true);
    }
  }
}
