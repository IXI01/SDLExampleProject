#ifndef _PONG_H_
#define _PONG_H_

#include <SDL/SDL.h>

#include "Event.h"
#include "Define.h"
#include "Ball.h"
#include "Bar.h"

class Pong : public Event {

  SDL_Surface* Surf_Display;

private:
  bool Running;
  Ball ball;
  Bar player;

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
  void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
  void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
};

#endif
