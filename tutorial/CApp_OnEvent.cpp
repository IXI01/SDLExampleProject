#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event) {
  CEvent::OnEvent(Event);
}

void CApp::OnExit() {
  Running = false;
}

void CApp::OnLButtonDown(int mX, int mY) {
  if (mX > 600 || mY > 600) {
    return;
  }
  int ID    = mX / 200;
  ID = ID + ((mY / 200) * 3);
 
  if(Grid[ID] != GRID_TYPE_NONE) {
    return;
  }
 
  if(CurrentPlayer == 0) {
    SetCell(ID, GRID_TYPE_X);
    CurrentPlayer = 1;
  }else{
    SetCell(ID, GRID_TYPE_O);
    CurrentPlayer = 0;
  }
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
  switch(sym) {
  case SDLK_r: Reset(); break;
  case SDLK_LEFT: {
    Player.MoveLeft = true;
    break;
  }
 
  case SDLK_RIGHT: {
    Player.MoveRight = true;
    break;
  }
  case SDLK_SPACE: {
    Player.Jump();
    break;
  }
  default:
    break;
  }
}

void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
  switch(sym) {
  case SDLK_LEFT: {
    Player.MoveLeft = false;
    break;
  }
 
  case SDLK_RIGHT: {
    Player.MoveRight = false;
    break;
  }
 
  default: {
  }

  }
}
