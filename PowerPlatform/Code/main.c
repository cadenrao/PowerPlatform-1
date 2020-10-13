#include "sys.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "PWM.h"
#include "DAC.h"
#include "usart.h"
#include "beep.h"
#include "ReMoterKEY.h"
#include "OUTPUT.h"
#include "stdio.h"
#include "EXTI.h"




int main()
{
	//遥控器所接的IO口的初始化
	REMOTER_KEY_Init();
	//输出IO口的初始化
	Output_KEY_Init();
	//初始化中断,初始化后如果有外部按键按下时会自动相应
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置NVIC中断分组2：2位抢占优先级，2位响应优先级
	MY_EXTI_Init();//初始化中断
	delay_init();

	//for (size_t i = 0; i < length; i++)
	//{

	//}
	while(1){}

	//啊2121212


//	//设置油缸升降状态
//	if (EN_CYLINDER_UP) {
      
}
//	if(EN_CYLINDER_DOWN){}
//	//设置后置马达输出状态
//	if (EN_BACK_MOTOR_FORWARD) {}
//	if(EN_BACK_MOTOR_BACKWARD){}
//	//设置绞盘状态
//	if (EN_CAPSTAN_IN) {}
//	if(EN_CAPSTAN_OUT){}
//	//设置高低速模式
//	if (EN_HIGH_SPEED_MODE) {}
//	else{}









