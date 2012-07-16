#ifndef _PONG_H_
#define _PONG_H_

#include <SDL/SDL.h>

#include "Event.h"
#include "Define.h"
#include "Ball.h"

class Pong : public Event {

  SDL_Surface* Surf_Display;

private:
  bool Running;
  Ball ball;

public:
  Pong();
  ~Pong();
 
  int OnExecute();

  bool OnInit();
  void OnEvent(SDL_Event* Event);
  void OnLoop();
  void OnRender();
  void OnCleanup();

  // Events
  void OnExit();
};

#endif
