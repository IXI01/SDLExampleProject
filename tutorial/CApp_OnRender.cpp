#include "CApp.h"

void CApp::OnRender() {

<<<<<<< HEAD
<<<<<<< HEAD
  //Render Blank Surface to Cover Map
  SDL_Surface *surface = NULL;

  //create the new surface
  surface = SDL_CreateRGBSurface (Surf_Display->flags, WWIDTH, WHEIGHT,
  				  Surf_Display->format->BitsPerPixel,
  				  Surf_Display->format->Rmask,
  				  Surf_Display->format->Gmask,
  				  Surf_Display->format->Bmask,
  				  Surf_Display->format->Amask);

  //fill the new surface with black
  if (surface != NULL)
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x0,0x0,0x0));
  CSurface::OnDraw(Surf_Display, surface, 0, 0);

  
  CArea::AreaControl.OnRender(Surf_Display, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
=======
  CArea::AreaControl.OnRender(Surf_Display, CCamera::CameraControl.GetX(), CCamera::CameraControl.GetY());
 
>>>>>>> df7decc27a12027f79186c01323091316486853c
=======
  CArea::AreaControl.OnRender(Surf_Display, CCamera::CameraControl.GetX(), CCamera::CameraControl.GetY());
 
>>>>>>> df7decc27a12027f79186c01323091316486853c
  
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

<<<<<<< HEAD
<<<<<<< HEAD

  for(int i = 0;(unsigned)i < CEntity::EntityList.size();i++) {
    if(!CEntity::EntityList[i]) continue;

    CEntity::EntityList[i]->OnRender(Surf_Display);
  }
=======
=======
>>>>>>> df7decc27a12027f79186c01323091316486853c
  // Render Blank Surface to Cover Map
  SDL_Surface *surface = NULL;

  // create the new surface
  surface = SDL_CreateRGBSurface (Surf_Display->flags, 576, 64,
				  Surf_Display->format->BitsPerPixel,
				  Surf_Display->format->Rmask,
				  Surf_Display->format->Gmask,
				  Surf_Display->format->Bmask,
				  Surf_Display->format->Amask);

  // fill the new surface with black
  if (surface != NULL)
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x0,0x0,0x0));
  CSurface::OnDraw(Surf_Display, surface, 664, 0);

<<<<<<< HEAD
>>>>>>> df7decc27a12027f79186c01323091316486853c
=======
>>>>>>> df7decc27a12027f79186c01323091316486853c
 
  SDL_Flip(Surf_Display);
}

