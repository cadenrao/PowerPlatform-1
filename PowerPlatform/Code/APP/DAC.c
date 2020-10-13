#include "DAC.h"


///****************************************************************************
/// @brief   : 定义了DAC初始化函数和电压设置函数
/// 使用时先调用DACx_Init() -> Set_Dacx_mVol()                                  
///****************************************************************************



///****************************************************************************
/// @data    : 
/// @input   : null                                                                
/// @output  : null                                                                
/// @brief   : 初始化 dac1相关                                                                
///****************************************************************************
void DAC1_Init(void) {
	DAC_InitTypeDef DAC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	/*使能GPIOA时钟（DACx的输出通道在PA4、PA5）
	* 使能DAC通道*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

	/*将GPIO通道设置为模拟输入（AIN）,因为内部DAC与GPIO连接在一起的
	avoid parasitic consumption */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//设置GPIO为模拟输入模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;//PA4为DAC1输出通道，stm32f10x手册可查
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*DAC通道一配置*/
	DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;//不产生波形
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Disable;//开启将无法输出0 vol
	DAC_Init(DAC_Channel_1, &DAC_InitStructure);

	/*enable dac channel1,once the channel is enabled,the PA4 pin will be automatically
	connected to the dac converter */
	DAC_Cmd(DAC_Channel_1, ENABLE);

	/*set dac channel data and initlize the output 0 vol*/
	DAC_SetChannel1Data(DAC_Align_12b_R, 0);

}

///****************************************************************************
/// @data    :                                                                 
/// @input   : null                                                                
/// @output  : null                                                                
/// @brief   : 初始化 dac1相关                                                                
///****************************************************************************
void DAC2_Init(void)
{
	DAC_InitTypeDef DAC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	/*使能GPIOA时钟（DACx的输出通道在PA4、PA5）
	* 使能DAC通道*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

	/*将GPIO通道设置为模拟输入（AIN）,因为内部DAC与GPIO连接在一起的
	avoid parasitic consumption */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//设置GPIO为模拟输入模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//PA5为DAC1输出通道，stm32f10x手册可查
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*DAC通道一配置*/
	DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;//不产生波形
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Disable;//开启将无法输出0 vol
	DAC_Init(DAC_Channel_2, &DAC_InitStructure);

	/*enable dac channel1,once the channel is enabled,the PA5 pin will be automatically
	connected to the dac converter */
	DAC_Cmd(DAC_Channel_2, ENABLE);

	/*set dac channel data and initlize the output 0 vol*/
	DAC_SetChannel1Data(DAC_Align_12b_R, 0);

}

///****************************************************************************
/// @data    :                                                                 
/// @input   :num_mvol 整型电压值                                                                 
/// @output  :null                                                                 
/// @brief   :使dac1输出电压,参考电压为3.3V 如：输入2000 输出 2v                                                                
///****************************************************************************
void Set_DAC1_mVol(float Voltage)
{
	uint16_t data;
	data = (uint16_t)((Voltage / 3.3) * 4096);
	DAC_SetChannel1Data(DAC_Align_12b_R, data);
	DAC_SoftwareTriggerCmd(DAC_Channel_1, ENABLE);
}


///****************************************************************************
/// @data    :                                                                 
/// @input   :num_mvol 整型电压值                                                                 
/// @output  :null                                                                 
/// @brief   :使dac2输出电压                                                                 
///****************************************************************************
void Set_DAC2_mVol(float Voltage)
{
	uint16_t data;
	data = (uint16_t)((Voltage / 3.3) * 4096);
	DAC_SetChannel2Data(DAC_Align_12b_R, data);
	DAC_SoftwareTriggerCmd(DAC_Channel_2, ENABLE);
}


//while (1)
//{
//	keyState = KEY_Scan(0);	//得到键值,并且支持连按
//	if (keyState)
//	{
//		switch (keyState)
//		{
//			case KEY1_PRES:	//控制LED0翻转	 
//				mvol += 0.05;
//				if(mvol>=3.0) mvol = 3.0;
//				printf("%f\n",mvol);
//				delay_ms(50);
//				break;
//			case KEY2_PRES:
//				mvol -= 0.05;
//				if(mvol <= 0) mvol = 0;
//				printf("%f\n",mvol);
//				delay_ms(50);
//			break;
//		}
//	}
//	else delay_ms(10); 
//	
//	Set_DAC1_mVol(mvol);
//	Set_DAC2_mVol(mvol/2);
//}