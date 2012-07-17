#include "Pong.h"
#include <cstdio>


Pong::Pong() {
  Running = true;
  
  Surf_Display = NULL;
  player = Bar(WWIDTH/2-BARWIDTH/2, WHEIGHT-2*BARHEIGHT, BARSPEED);
  ball = Ball(WWIDTH/2 - BSIZE/2, WHEIGHT/2 - BSIZE/2);
  ball.AddBar(&player);
}

Pong::~Pong() {

}

bool Pong::OnInit() {
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }

  Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if(Surf_Display == NULL) {
    return false;
  }

  return true;
}

void Pong::OnEvent(SDL_Event* Event) {
  Event::OnEvent(Event);
}

void Pong::OnLoop() {
  ball.OnLoop();
  player.OnLoop();

  FPS::FPSControl.OnLoop();

  char Buffer[255];
  sprintf(Buffer, "%d", FPS::FPSControl.GetFPS());
  SDL_WM_SetCaption(Buffer, Buffer);
}

void Pong::OnRender() {
  //Render black surface to reset everything
  SDL_Rect Rect;
  Rect.x = 0;
  Rect.y = 0;
  Rect.w = WWIDTH;
  Rect.h = WHEIGHT;
  
  SDL_FillRect(Surf_Display, &Rect, 0);

  ball.OnRender(Surf_Display);
  player.OnRender(Surf_Display);

  SDL_Flip(Surf_Display);
}

void Pong::OnCleanup() {
  SDL_FreeSurface(Surf_Display);

  SDL_Quit();
}


int Pong::OnExecute() {
  if(OnInit() == false) {
    return -1;
  }

  SDL_Event Event;

  while(Running) {
    while(SDL_PollEvent(&Event)) {
      OnEvent(&Event);
    }
    OnLoop();
    OnRender();
  }

  OnCleanup();
  
  return 0;
}

int main(int argc, char* argv[]) {
  Pong theApp;
 
  return theApp.OnExecute();
}
