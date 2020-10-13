
#ifndef _LED__H
#define _LED__H
#include "sys.h"
#include "delay.h"

#define SET_PB5LED_OFF GPIO_SetBits(GPIOB,GPIO_Pin_5) //设置PB5口LED等所连的状态
#define SET_PB5LED_ON GPIO_ResetBits(GPIOB,GPIO_Pin_5)
#define PB5LED_Off GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_5)==1 //读取PB5是否关闭（输出为高时关闭）

#define SET_PE5LED_OFF GPIO_SetBits(GPIOE,GPIO_Pin_5)
#define SET_PE5LED_ON GPIO_ResetBits(GPIOE,GPIO_Pin_5)
#define PE5LED_Off GPIO_ReadOutputDataBit(GPIOE,GPIO_Pin_5) == 1 //读取PB5状态（输出为高时关闭）

//位代操作
#define LED0 PBout(5)// PB5
#define LED1 PEout(5)// PE5	


//#define SET_PB7LED_ON GPIO_SetBits(GPIOB,GPIO_Pin_7)
//#define SET_PB7LED_OFF GPIO_ResetBits(GPIOB,GPIO_Pin_7)
//#define PB7LED_Off GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_7) == 1 //读取PB7状态（输出为高时关闭）

#endif

void UserLED_Init(void);
void FluentLEDs(void);
