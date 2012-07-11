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
    if(TargetX != NULL) {
        if(TargetMode == TARGET_MODE_CENTER) {
<<<<<<< HEAD
	  return *TargetX - (WWIDTH / 2);
=======
            return *TargetX - (WWIDTH / 2);
>>>>>>> df7decc27a12027f79186c01323091316486853c
        }
 
        return *TargetX;
    }
 
    return X;
}
 
int CCamera::GetY() {
    if(TargetY != NULL) {
        if(TargetMode == TARGET_MODE_CENTER) {
<<<<<<< HEAD
	  return *TargetY - (WHEIGHT / 2);
=======
            return *TargetY - (WHEIGHT / 2);
>>>>>>> df7decc27a12027f79186c01323091316486853c
        }
 
        return *TargetY;
    }
 
    return Y;
}
 
void CCamera::SetPos(int X, int Y) {
    this->X = X;
    this->Y = Y;
}
 
<<<<<<< HEAD
void CCamera::SetTarget(float* X, float* Y) {
=======
void CCamera::SetTarget(int* X, int* Y) {
>>>>>>> df7decc27a12027f79186c01323091316486853c
    TargetX = X;
    TargetY = Y;
}
