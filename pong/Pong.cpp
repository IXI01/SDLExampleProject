#include "Pong.h"
#include <cstdio>


Pong::Pong() {
  Running = true;
  
  Surf_Display = NULL;
  gameovertime = 0;
  
  player = Bar(WWIDTH/2-BARWIDTH/2, WHEIGHT-2*BARHEIGHT, BARSPEED);
  playerlives = LIVES;
  comp = Bar(WWIDTH/2-BARWIDTH/2, BARHEIGHT, BARSPEED);
  complives = LIVES;
  ball = Ball(WWIDTH/2 - BSIZE/2, WHEIGHT/2 - BSIZE/2);
  ball.AddBar(&player);
  ball.AddBar(&comp);

  ai = AI(&comp, &ball);
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
  if (gameovertime <=0){
    ball.OnLoop();
    player.OnLoop();
    comp.OnLoop();
    ai.ControlBar();
  }
  GameStatus();
  
  FPS::FPSControl.OnLoop();

  char Buffer[255];
  sprintf(Buffer, "Pong");
  SDL_WM_SetCaption(Buffer, Buffer);
}

void Pong::OnRender() {
  if (gameovertime <=0){
  
    //Render black surface to reset everything
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = WWIDTH;
    rect.h = WHEIGHT;
  
    SDL_FillRect(Surf_Display, &rect, 0);

    ball.OnRender(Surf_Display);
    player.OnRender(Surf_Display);
    comp.OnRender(Surf_Display);

    rect.w = LIVEWIDTH;
    rect.h = LIVEHEIGHT;

    rect.x = LIVEGAP;
    rect.y = LIVEGAP;
    for (int i=0; i<complives; i++) {
      SDL_FillRect(Surf_Display, &rect, BCOLOR);

      rect.x += LIVEWIDTH+LIVEGAP;
    }

    rect.x = WWIDTH-LIVEWIDTH-LIVEGAP;
    rect.y = WHEIGHT-LIVEHEIGHT-LIVEGAP;
    for (int i=0; i<playerlives; i++) {
      SDL_FillRect(Surf_Display, &rect, BCOLOR);

      rect.x -= LIVEWIDTH+LIVEGAP;
    }
  }
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

void Pong::GameStatus() {
  if (gameovertime > 0) {
    gameovertime -= 1*FPS::FPSControl.GetSpeedFactor();
  }

  if (ball.IsDropped()) {
    if (ball.GetY() > WHEIGHT/2) {
      playerlives--;
    }
    else {
      complives--;
    }
    ball.SetDropped(false);
  }

  if (playerlives < 0 || complives < 0) {
    gameovertime = GAMEOVERTIME*32;

    playerlives = LIVES;
    complives = LIVES;

    comp.SetX(WWIDTH/2 - BARWIDTH/2);
    player.SetX(WWIDTH/2 - BARWIDTH/2);
  }
}


int main(int argc, char* argv[]) {
  Pong theApp;
 
  return theApp.OnExecute();
}
