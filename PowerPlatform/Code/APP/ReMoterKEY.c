#include "ReMoterKEY.h"


void REMOTER_KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	//使能PORTE,PORTF时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOF, ENABLE);
	//初始化GPIOE的按键输入
	//--PEin(0) --刹车
	//--PEin(1) --加档
	//--PEin(2)--减档
	//--PEin(3)--左转

	//--PEin(4)--右转
	//--PEin(11)--油门加档
	//--PEin(12)--油门减档
	GPIO_InitStructure.GPIO_Pin =   GPIO_Pin_0 | GPIO_Pin_1 |
									GPIO_Pin_2 | GPIO_Pin_3 |
									GPIO_Pin_4 | GPIO_Pin_11 |
									GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入（复位后为高电平）
	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE被使用的IO

	//初始化GPIOF的按键输入
	//--PFin(0)--高低速模式切换
	//--PFin(1)--油缸提升
	//--PFin(2)--油缸提升
	//--PFin(3)--绞盘收
	//--PFin(4)--绞盘收
	//--PFin(5)--后置马达正转
	//--PFin(6)--后置马达反转
	//--PFin(7)--驻车
	//--PFin(8)--遥控掉电
	GPIO_InitStructure.GPIO_Pin =   GPIO_Pin_0 | GPIO_Pin_1 |
									GPIO_Pin_2 | GPIO_Pin_3 |
									GPIO_Pin_4 | GPIO_Pin_5 |
									GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入（复位后为高电平）
	GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化GPIOE被使用的IO

}



