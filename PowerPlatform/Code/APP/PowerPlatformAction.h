#ifndef __POWERPLATFORMACTION_H
#define __POWERPLATFORMACTION_H


#include "OUTPUT.h"//执行的动作锁定赢得输出口
#include "sys.h"//位带操作支持、单片机头文件引入
#include "PWM.h"//比例输出支持
#include "DAC.h"//模拟量输出

//函数命名规则： PP_动作（PP => PowerPlatform）

void PP_StayStill(void);
void PP_SpotTurnLeft(void);
void PP_SpotTurnRight(void);
void PP_GoForward(void);
void PP_Go_TurnLeft(void);
void PP_Go_TurnRight(void);
////



#endif // !__POWERPLATFORMACTION_H
