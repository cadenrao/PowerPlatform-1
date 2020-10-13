#include "OUTPUT.h"

void Output_KEY_Init(void)
{

		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(
			 RCC_APB2Periph_GPIOA|
			 RCC_APB2Periph_GPIOB|
			 RCC_APB2Periph_GPIOC|
			 RCC_APB2Periph_GPIOD, ENABLE);//使能PE端口时钟

	//配置PD9、PD10、PD11、PD12、PD13、PD14、PD15
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9| GPIO_Pin_10 | //用于控制后置马达正反转
									  GPIO_Pin_11 | GPIO_Pin_12 | //控制后置动力输出举升缸伸缩
									  GPIO_Pin_13 | GPIO_Pin_14 | //控制绞盘马达正反转
									  GPIO_Pin_15 ;// 未定义
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出方式
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度为50MHz
		GPIO_Init(GPIOD, &GPIO_InitStructure);//初始化PD端口

	//配置PA0、PA1、PA2、PA3
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | //控制比例阀输出流量
									  GPIO_Pin_2 | GPIO_Pin_3;  //控制油门大小

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出方式
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度为50MHz
		GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化PD端口

	//配置PB11、PB12、PB13、PB14
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | //控制左行走马达正反转
			                          GPIO_Pin_13 | GPIO_Pin_14;  //控制右行走马达正反转

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出方式
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度为50MHz
		GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化PD端口

	//配置PC6、PC7、PC8
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;  //低速、高速模式切换
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出方式
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度为50MHz
		GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化PD端口

}
