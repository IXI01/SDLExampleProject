#include "Pong.h"

void Pong::OnExit() {
  Running = false;
}

void Pong::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
  switch(sym) {
  case SDLK_LEFT: {
    player.SetMoveLeft(true);
    break;
  }
  case SDLK_RIGHT: {
    player.SetMoveRight(true);
    break;
  }
    
  default: {
    break;
  }
  }
}

void Pong::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
  switch(sym) {
  case SDLK_LEFT: {
    player.SetMoveLeft(false);
    break;
  }
  case SDLK_RIGHT: {
    player.SetMoveRight(false);
    break;
  }
    
   default: {
    break;
  }

  }
}
