#ifndef _AI_H
#define _AI_H

#include "Ball.h"
#include "Bar.h"
#include "Define.h"

class AI {
  Bar* bar;
  Ball* ball;

public:
  AI();
  AI(Bar* bar, Ball* ball);
  ~AI();

  void ControlBar();
};

#endif
