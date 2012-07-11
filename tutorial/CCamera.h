#ifndef _CCAMERA_H_
    #define _CCAMERA_H_
 
<<<<<<< HEAD
#include <SDL/SDL.h>
=======
#include <SDL.h>
>>>>>>> df7decc27a12027f79186c01323091316486853c
 
#include "Define.h"
 
enum {
    TARGET_MODE_NORMAL = 0,
    TARGET_MODE_CENTER
};
 
class CCamera {
    public:
        static CCamera CameraControl;
 
    private:
        int X;
        int Y;
 
<<<<<<< HEAD
        float* TargetX;
        float* TargetY;
=======
        int* TargetX;
        int* TargetY;
>>>>>>> df7decc27a12027f79186c01323091316486853c
 
    public:
        int TargetMode;
 
    public:
        CCamera();
 
    public:
        void OnMove(int MoveX, int MoveY);
 
    public:
        int GetX();
        int GetY();
 
    public:
        void SetPos(int X, int Y);
 
<<<<<<< HEAD
        void SetTarget(float* X, float* Y);
=======
        void SetTarget(int* X, int* Y);
>>>>>>> df7decc27a12027f79186c01323091316486853c
};
 
#endif
