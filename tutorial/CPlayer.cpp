#include "CPlayer.h"
 
CPlayer::CPlayer() {
  Col_X = 8;
  Col_Width = 16;
  Col_Y = 0;
  Col_Height = 2;

  MaxSpeedY = 10;
}
 
bool CPlayer::OnLoad(char* File, int Width, int Height, int MaxFrames) {
  if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
    return false;
  }
 
  return true;
}
 
void CPlayer::OnLoop() {
  CEntity::OnLoop();
}
 
void CPlayer::OnRender(SDL_Surface* Surf_Display) {
  CEntity::OnRender(Surf_Display);
}
 
void CPlayer::OnCleanup() {
  CEntity::OnCleanup();
}
 
void CPlayer::OnAnimate() {
  if(SpeedX != 0) {
    Anim_Control.MaxFrames = 8;
  }else{
    Anim_Control.MaxFrames = 0;
  }
 
  CEntity::OnAnimate();
}
 
bool CPlayer::OnCollision(CEntity* Entity) {
  // Hack so that Collision Event only Triggers when Yoshi is in the air
  bool Return = true;
 
  int StartX     = (X + Col_X) / TILE_SIZE;
  int StartY     = (Y+1 + Col_Y) / TILE_SIZE;
 
  int EndX    = ((X + Col_X) + Width - Col_Width - 1)         / TILE_SIZE;
  int EndY    = ((Y+1 + Col_Y) + Height - Col_Height - 1)    / TILE_SIZE;
 
  for(int iY = StartY;iY <= EndY;iY++) {
    for(int iX = StartX;iX <= EndX;iX++) {
      CTile* Tile = CArea::AreaControl.GetTile(iX * TILE_SIZE, iY * TILE_SIZE);
 
      if(PosValidTile(Tile) == false) {
	Return = false;
      }
    }
  }

  if (Return)
    // End of Hack
    Jump();
  
 
  return true;
}
