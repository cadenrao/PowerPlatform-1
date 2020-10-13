#include "PWM.h"
#include "sys.h"
#include "delay.h"

	
///****************************************************************************                 
/// @brief   :本驱动配置PWM4的CH2/CH3 在主程序中首先调用PWM_Init()函数、
///			  接下来使用	TIM_SetComparex(TIMx,uin16_t num_CNT);可以设置占空比
///****************************************************************************


	
///****************************************************************************
/// @data    :                                                                 
/// @input   :
///				arr -- 自动重装值
///				psc -- 时钟预分频数                                                                
/// @output  :	null                                                             
/// @brief   :
///				初始化PWM TIM4,TIM4为72MHz 
///				PWM的频率  PWM频率=72000000/(arr+1)*(psc+1) 
///				TIMx 的频率为 72000000/(psc+1)				
///****************************************************************************
void PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_Parameter;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseParameter;
	TIM_OCInitTypeDef TIM_OCInitStructure;

	//使能相关的GPIO和定时器（TIM）以及复用功能（AFIO）
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//使能定时器4,将使用CH2->PB7 CH3->PB8
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能PB,AFIO
	TIM_DeInit(TIM4);
	

	//初始化PB7
	GPIO_Parameter.GPIO_Mode = GPIO_Mode_AF_PP;//推挽输出
	GPIO_Parameter.GPIO_Pin = GPIO_Pin_7;//TIM4_CH2的输出
	GPIO_Parameter.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Parameter);

	//初始化PB8
	GPIO_Parameter.GPIO_Mode = GPIO_Mode_AF_PP;//推挽输出
	GPIO_Parameter.GPIO_Pin = GPIO_Pin_9;//TIM4_CH4的输出
	GPIO_Parameter.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Parameter);

	//初始化TIM4,设置PWM的频率
	TIM_TimeBaseParameter.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
	TIM_TimeBaseParameter.TIM_Prescaler = psc; //设置用来作为TIMx时钟频率除数的预分频值 
	TIM_TimeBaseParameter.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseParameter.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseParameter); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

	//初始化TIM4 Channel2 PWM模式
	TIM_OCInitStructure.TIM_Pulse = 300;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //根据指定的参数初始化外设TIM4 OC2

	//初始化TIM4 Channel2 PWM模式
	TIM_OCInitStructure.TIM_Pulse = 300;
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);  //根据指定的参数初始化外设TIM4 OC4

	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM4在CCR2上的预装载寄存器
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIM4在CCR3上的预装载寄存器

	TIM_Cmd(TIM4, ENABLE);  //使能TIM4
	
	TIM_SetCompare2(TIM4,0);
	TIM_SetCompare4(TIM4, 0);

}


//PWM_Init(719, 4);//设置PWM为20KHZ
//u16 led0pwmval = 0;

//////while (1)
//////{

//////	switch (KEY_Scan(1))
//////	{
//////	case KEY0_PRES:
//////		led0pwmval += 5;
//////		break;
//////	default:
//////		break;
//////	}

//////	TIM_SetCompare2(TIM4, led0pwmval);
//////	TIM_SetCompare4(TIM4, led0pwmval);
//////}
