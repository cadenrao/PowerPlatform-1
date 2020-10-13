#ifndef __REMOTERKEY_H
#define __REMOTERKEY_H
#endif // !__REMOTERKEY_H

#include "sys.h"

/*signal for recv*/
#define LOCK_CAR_BTN				PEin(0) //刹车
#define ADD_CAR_GEAR_BTN			PEin(1) //加档
#define SUBTRACT_CAR_GEAR_BTN		PEin(2)//减档
#define TURN_LEFT_BTN				PEin(3)//左转
#define TURN_RIGHT_BTN				PEin(4)//右转
#define SWITCH_SPEED_MODE_BTN		PFin(0)//高低速模式切换
#define CYLINDER_UP_BTN				PFin(1)//油缸提升
#define CYLINDER_DOWN_BTN			PFin(2)//油缸下降
#define CAPSTAN_IN_BTN				PFin(3)//绞盘收
#define CAPSTAN_OUT_BTN				PFin(4)//绞盘放
#define BACK_MOTOR_FORWARD_BTN		PFin(5)//后置马达正转
#define BACK_MOTOR_BACKWARD_BTN		PFin(6)//后置马达反转
#define ACCELERATOR_UP_BTN			PEin(11)//油门加档
#define ACCELERATOR_DOWN_BTN		PEin(12)//油门减档
#define PARKING_BTN					PFin(7)//驻车
#define LOST_POWER_BTN				PFin(8)//遥控掉电

/*按键动作*/
#define EN_LOCK_CAR  LOCK_CAR_BTN == 0//刹车
#define DIS_LOCK_CAR LOCK_CAR_BTN == 1//未刹车
#define EN_ADD_CAR_GEAR ADD_CAR_GEAR_BTN == 0//加档
#define EN_SUBTRACT_CAR_GEAR SUBTRACT_CAR_GEAR_BTN == 0//减档
#define EN_TURN_LEFT TURN_LEFT_BTN == 0//左转
#define EN_TURN_RIGHT TURN_RIGHT_BTN == 0//右转
#define EN_HIGH_SPEED_MODE SWITCH_SPEED_MODE_BTN == 0//高速模式
#define EN_LOW_SPEED_MODE SWITCH_SPEED_MODE_BTN == 1//低速模式
#define EN_CYLINDER_UP CYLINDER_UP_BTN == 0//油缸提升
#define EN_CYLINDER_DOWN CYLINDER_DOWN_BTN == 0//油缸下降
#define EN_CAPSTAN_IN CAPSTAN_IN_BTN == 0//绞盘收
#define EN_CAPSTAN_OUT CAPSTAN_OUT_BTN == 0//绞盘放
#define EN_BACK_MOTOR_FORWARD BACK_MOTOR_FORWARD_BTN == 0//后置马达正转
#define EN_BACK_MOTOR_BACKWARD	BACK_MOTOR_BACKWARD_BTN	== 0//后置马达反转
#define EN_ACCELERATOR_UP ACCELERATOR_UP_BTN == 0//油门加档
#define EN_ACCELERATOR_DOWN ACCELERATOR_DOWN_BTN == 0//油门减档
#define EN_PARKING PARKING_BTN == 0//驻车
#define DIS_PARKING PARKING_BTN == 1//未驻车
#define EN_LOST_POWER LOST_POWER_BTN == 0//遥控掉电
//定义返回键值的函数

//IO初始化
void REMOTER_KEY_Init(void);

