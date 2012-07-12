#include "CApp.h"

void CApp::OnRender() {
  //Render Blank Surface to Cover Map
  SDL_Rect Rect;
  Rect.x = 0;
  Rect.y = 0;
  Rect.w = WWIDTH;
  Rect.h = WHEIGHT;
  
  SDL_FillRect(Surf_Display, &Rect, 0);
  
  CArea::AreaControl.OnRender(Surf_Display, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
  
  // Render Tic Tac Toe
  CSurface::OnDraw(Surf_Display, Surf_Grid, 0, 0);

  for(int i = 0;i < 9;i++) {
    int X = (i % 3) * 200;
    int Y = (i / 3) * 200;
 
    if(Grid[i] == GRID_TYPE_X) {
      CSurface::OnDraw(Surf_Display, Surf_X, X, Y);
    }else
      if(Grid[i] == GRID_TYPE_O) {
        CSurface::OnDraw(Surf_Display, Surf_O, X, Y);
      }
  }

  // Render Yoshi
  CSurface::OnDraw(Surf_Display, Surf_Yoshi, 600, 0, 0, Anim_Yoshi.GetCurrentFrame() * 64, 64, 64);


  for(int i = 0;(unsigned)i < CEntity::EntityList.size();i++) {
    if(!CEntity::EntityList[i]) continue;
    CEntity::EntityList[i]->OnRender(Surf_Display);
  }
 
  SDL_Flip(Surf_Display);
}

