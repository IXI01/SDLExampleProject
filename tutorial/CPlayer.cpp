#include "CPlayer.h"
 
CPlayer::CPlayer() {
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
 
void CPlayer::OnCollision(CEntity* Entity) {
}
