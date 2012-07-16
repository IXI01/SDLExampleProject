#include "FPS.h"

FPS FPS::FPSControl;
 
FPS::FPS() {
  oldTime = 0;
  lastTime = 0;
 
  speedFactor = 0;
 
  frames = 0;
  numFrames = 0;
}
 
void FPS::OnLoop() {

  if((unsigned)oldTime + 1000 < SDL_GetTicks()) {

    oldTime = SDL_GetTicks();
 
    numFrames = frames;
 
    frames = 0;
  }
 
  speedFactor = ((SDL_GetTicks() - lastTime) / 1000.0f) * 32.0f;
 
  lastTime = SDL_GetTicks();
 
  frames++;
}
 
int FPS::GetFPS() {
  return numFrames;
}
 
float FPS::GetSpeedFactor() {
  return speedFactor;
}
