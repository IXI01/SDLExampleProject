#ifndef _CAPP_H_
#define _CAPP_H_
 
#include <SDL/SDL.h>
#include "CSurface.h"
#include "CEvent.h"
#include "CAnimation.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "CPlayer.h"
=======

>>>>>>> df7decc27a12027f79186c01323091316486853c

#include "Define.h"
 
#include "CArea.h"
#include "CCamera.h"

class CApp : public CEvent {

private:
bool Running;
  
SDL_Surface* Surf_Display;
SDL_Surface* Surf_Grid;
 
SDL_Surface* Surf_X;
SDL_Surface* Surf_O;

SDL_Surface* Surf_Yoshi;

CAnimation Anim_Yoshi;

<<<<<<< HEAD
CPlayer Player;
CPlayer Player2;

=======
>>>>>>> df7decc27a12027f79186c01323091316486853c
// Tic Tac Toe variables
int Grid[9];

enum {
GRID_TYPE_NONE = 0,
  GRID_TYPE_X,
  GRID_TYPE_O
  };

int CurrentPlayer;
public:
 
=======


#include "Define.h"
 
#include "CArea.h"
#include "CCamera.h"

class CApp : public CEvent {

private:
bool Running;
  
SDL_Surface* Surf_Display;
SDL_Surface* Surf_Grid;
 
SDL_Surface* Surf_X;
SDL_Surface* Surf_O;

SDL_Surface* Surf_Yoshi;

CAnimation Anim_Yoshi;

// Tic Tac Toe variables
int Grid[9];

enum {
GRID_TYPE_NONE = 0,
  GRID_TYPE_X,
  GRID_TYPE_O
  };

int CurrentPlayer;
public:
 
>>>>>>> df7decc27a12027f79186c01323091316486853c
CApp();
 
int OnExecute();

bool OnInit();
void OnEvent(SDL_Event* Event);
void OnLoop();
void OnRender();
void OnCleanup();

// Events
void OnExit();
void OnLButtonDown(int mX, int mY);
void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
<<<<<<< HEAD
<<<<<<< HEAD
void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
=======
>>>>>>> df7decc27a12027f79186c01323091316486853c
=======
>>>>>>> df7decc27a12027f79186c01323091316486853c

// Tic Tac Toe methods
void Reset();
void SetCell(int ID, int Type);
  
	
};
 
#endif
