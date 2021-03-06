#include "CApp.h"

bool CApp::OnInit() {
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }
  
  if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
    return false;
  }

   
  if((Surf_Grid = CSurface::OnLoad((char *)"./gfx/grid.bmp")) == NULL) {
    return false;
  }
 
  if((Surf_X = CSurface::OnLoad((char *)"./gfx/x.bmp")) == NULL) {
    return false;
  }

  if((Surf_O = CSurface::OnLoad((char *)"./gfx/o.bmp")) == NULL) {
    return false;
  }

  if((Surf_Yoshi = CSurface::OnLoad((char *)"./gfx/yoshi.bmp")) == NULL) {
    return false;
  }
  Anim_Yoshi.MaxFrames = 8;
  
  CSurface::Transparent(Surf_X, 255, 0, 255);
  CSurface::Transparent(Surf_O, 255, 0, 255);
   
  Reset();

  
  if(CArea::AreaControl.OnLoad((char *)"./maps/1.area") == false) {
    return false;
  }
  
  SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);


  if(Player.OnLoad((char *)"./gfx/yoshi2.bmp", 64, 64, 8) == false) {
    return false;
  }
 
  if(Player2.OnLoad((char *)"./gfx/yoshi2.bmp", 64, 64, 8) == false) {
    return false;
    }

  Player.X = 25;
  Player2.X = 150;
 
  CEntity::EntityList.push_back(&Player);
  CEntity::EntityList.push_back(&Player2);

  CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
  CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);
  
  return true;
}
  

