#include "CCamera.h"
 
CCamera CCamera::CameraControl;
 
CCamera::CCamera() {
    X = Y = 0;
 
    TargetX = TargetY = NULL;
 
    TargetMode = TARGET_MODE_NORMAL;
}
 
void CCamera::OnMove(int MoveX, int MoveY) {
    X += MoveX;
    if (X > 0)
      X = 0;
    if (X < -(TILE_SIZE * MAP_WIDTH * (AREA_SIZE-1)))
      X = -(TILE_SIZE * MAP_WIDTH * (AREA_SIZE-1));
    Y += MoveY;
    if (Y > 0)
      Y = 0;
    if (Y < -(TILE_SIZE * MAP_HEIGHT * (AREA_SIZE-1)))
      Y = -(TILE_SIZE * MAP_HEIGHT * (AREA_SIZE-1));

}
 
int CCamera::GetX() {
  int retX;
  
    if(TargetX != NULL) {
        if(TargetMode == TARGET_MODE_CENTER) {
	  retX = *TargetX - (640 / 2) + 64/2; // 64/2 considers the width of the target
        }
	else {
	  retX = *TargetX;
	}
    }
    else {
      retX = X;
    }

    if (retX < 0)
      return 0;
    if (retX > (TILE_SIZE * MAP_WIDTH * (AREA_SIZE-1)))
    return (TILE_SIZE * MAP_WIDTH * (AREA_SIZE-1));

    return retX;
}
 
int CCamera::GetY() {
  int retY;
    if(TargetY != NULL) {
        if(TargetMode == TARGET_MODE_CENTER) {

	  retY = *TargetY - (536 / 2) + 64/2; // 64/2 considers the height of the target
        }
	else {
	  retY = *TargetY;
	}
    }
    else {
      retY = Y;
    }

    if (retY < 0)
      return 0;
    if (retY > (TILE_SIZE * MAP_HEIGHT * (AREA_SIZE-1)))
    return (TILE_SIZE * MAP_HEIGHT * (AREA_SIZE-1));

    return retY;
}
 
void CCamera::SetPos(int X, int Y) {
    this->X = X;
    this->Y = Y;
}
 

void CCamera::SetTarget(float* X, float* Y) {
    TargetX = X;
    TargetY = Y;
}
