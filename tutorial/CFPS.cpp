#include "CFPS.h"
 
CFPS CFPS::FPSControl;
 
CFPS::CFPS() {
  OldTime     = 0;
  LastTime    = 0;
 
  SpeedFactor    = 0;
 
  Frames      = 0;
  NumFrames   = 0;
}
 
void CFPS::OnLoop() {
<<<<<<< HEAD
<<<<<<< HEAD
  if((unsigned)OldTime + 1000 < SDL_GetTicks()) {
=======
  if(OldTime + 1000 < SDL_GetTicks()) {
>>>>>>> df7decc27a12027f79186c01323091316486853c
=======
  if(OldTime + 1000 < SDL_GetTicks()) {
>>>>>>> df7decc27a12027f79186c01323091316486853c
    OldTime = SDL_GetTicks();
 
    NumFrames = Frames;
 
    Frames = 0;
  }
 
  SpeedFactor = ((SDL_GetTicks() - LastTime) / 1000.0f) * 32.0f;
 
  LastTime = SDL_GetTicks();
 
  Frames++;
}
 
int CFPS::GetFPS() {
  return NumFrames;
}
 
float CFPS::GetSpeedFactor() {
  return SpeedFactor;
}
