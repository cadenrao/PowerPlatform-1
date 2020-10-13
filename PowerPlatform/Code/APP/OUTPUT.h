#ifndef __OUTPUT_H
#define __OUTPUT_H
#include "sys.h"

//控制左行走马达正反转、控制右行走马达正反转
#define LEFT_MOTER_CONTROLER_1Y PBout(11)
#define LEFT_MOTER_CONTROLER_2Y PBout(12)
#define RIGHT_MOTER_CONTROLER_3Y PBout(13)
#define RIGHT_MOTER_CONTROLER_4Y PBout(14)

//控制后置马达正反转
#define BACK_MOTER_FORWARD_5Y PDout(9)
#define BACK_MOTER_BACKWARD_6Y PDout(10)

//控制后置动力输出举升缸伸缩
#define BACK_CYLINDER_UP_7Y PDout(11)
#define BACK_CYLINDER_UP_8Y PDout(12)

//控制绞盘马达正反转
#define CAPSTAN_MOTOR_CONTROL_9Y PDout(13)
#define CAPSTAN_MOTOR_CONTROL_10Y PDout(14)
//#define HIGH_SPEED_MODE PCout(6)

//高低速模式切换
#define HIGH_SPEED_MODE_11Y PCout(6)
#define HIGH_SPEED_MODE_12Y PCout(7)
#define HIGH_SPEED_MODE_13Y PCout(8)

//控制比例阀输出流量
#define PROPORTIONAL_FLOW_CONTROLER_I1 PAout(0)//
#define PROPORTIONAL_FLOW_CONTROLER_I2 PAout(1)//

//控制油门
#define ACCELERATOR_CONTROLER_U1 PAout(2)
#define ACCELERATOR_CONTROLER_U2 PAout(3)

//14Y阀门
#define CHIEF_14Y PDout(15)

void Output_KEY_Init(void);

#endif // __OUTPUT_H

