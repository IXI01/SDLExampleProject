#include "CApp.h"

void CApp::OnLoop() {
  Anim_Yoshi.OnAnimate();


  for(int i = 0;(unsigned)i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnLoop();
    }

  //Collision Events
  for(int i = 0;(unsigned)i < CEntityCol::EntityColList.size();i++) {
    CEntity* EntityA = CEntityCol::EntityColList[i].EntityA;
    CEntity* EntityB = CEntityCol::EntityColList[i].EntityB;
 
    if(EntityA == NULL || EntityB == NULL) continue;
 
    if(EntityA->OnCollision(EntityB)) {
      EntityB->OnCollision(EntityA);
    }
  }
 
CEntityCol::EntityColList.clear();



    CFPS::FPSControl.OnLoop();

    char Buffer[255];
    sprintf(Buffer, "%d", CFPS::FPSControl.GetFPS());
    SDL_WM_SetCaption(Buffer, Buffer);

}
