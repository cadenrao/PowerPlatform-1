#include "EXTI.h"



/****************************************************************************
* @name   :void EXTI_Init(void)
* @input  :null
* @output :null
* @brief  :初始化所用到的中断GPIO口，并绑定中断线
****************************************************************************/
void MY_EXTI_Init()
{
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);//外部中断，需要使能AFIO时钟

	  //PE0中断线以及中断初始化配置
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource0);
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	//PE1中断线以及中断初始化配置
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource1);
	EXTI_InitStructure.EXTI_Line = EXTI_Line1;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	//PE2中断线以及中断初始化配置
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	//PE3中断线以及中断初始化配置
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	//PE4中断线以及中断初始化配置
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	//PE11中断线以及中断初始化配置
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource11);
	EXTI_InitStructure.EXTI_Line = EXTI_Line11;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	//PE12中断线以及中断初始化配置
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource12);
	EXTI_InitStructure.EXTI_Line = EXTI_Line12;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);


	//EXTI0
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //响应优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	//EXTI1
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//抢占优先级2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //响应优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	//EXTI2
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//抢占优先级2 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //响应优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	//EXTI3
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//抢占优先级2 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //响应优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	//EXTI4
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//抢占优先级2 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //响应优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	//EXTI15_10
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //响应优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}


/****************************************************************************
* @name   :void EXTI0_IRQHandler(void)
* @input  :null
* @output :null
* @brief  :外部中断EXTI0服务函数,PE0口按键按下的响应函数
*			（刹车）
****************************************************************************/
void EXTI0_IRQHandler(void)
{
	delay_ms(10);
	EXTI_ClearITPendingBit(EXTI_Line0);
	if(EN_LOCK_CAR)
	{
		
	}

}


/****************************************************************************
* @name   :void EXTI1_IRQHandler(void)
* @input  :null
* @output :null
* @brief  :外部中断EXTI1服务函数,PE1口按键按下的响应函数
*			（左遥感向上拨动的响应函数）
****************************************************************************/
void EXTI1_IRQHandler(void)
{

}

/****************************************************************************
* @name   :void EXTI2_IRQHandler(void)
* @input  :null
* @output :null
* @brief  :外部中断EXTI2服务函数,PE2口按键按下的响应函数
*			（左摇杆向下拨动响应函数）
****************************************************************************/
void EXTI2_IRQHandler(void)
{

}

/****************************************************************************
* @name   :void EXTI3_IRQHandler(void)
* @input  :null
* @output :null
* @brief  :外部中断EXTI3服务函数,PE3口按键按下的响应函数
*			（左摇杆向左拨动响应函数）
****************************************************************************/
void EXTI3_IRQHandler(void)
{

}


/****************************************************************************
* @name   :void EXTI4_IRQHandler(void)
* @input  :null
* @output :null
* @brief  :外部中断EXTI4服务函数,PE4口按键按下的响应函数
*			（右摇杆向右拨动响应函数）
****************************************************************************/
void EXTI4_IRQHandler(void)
{

}


/****************************************************************************
* @name   :void EXTI4_IRQHandler(void)
* @input  :null
* @output :null
* @brief  :外部中断EXTI15_10服务函数,PE11和PF2口按键按下的响应函数
*			（右摇杆向上和向下拨动响应函数）
****************************************************************************/
void EXTI15_10_IRQHandler(void)
{

}


