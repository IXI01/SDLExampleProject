#include "CApp.h"

void CApp::OnLoop() {
  Anim_Yoshi.OnAnimate();
<<<<<<< HEAD

  for(int i = 0;(unsigned)i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnLoop();
    }

    CFPS::FPSControl.OnLoop();

    char Buffer[255];
    sprintf(Buffer, "%d", CFPS::FPSControl.GetFPS());
    SDL_WM_SetCaption(Buffer, Buffer);
=======
>>>>>>> df7decc27a12027f79186c01323091316486853c
}
