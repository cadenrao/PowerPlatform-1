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
	//ң�������ӵ�IO�ڵĳ�ʼ��
	REMOTER_KEY_Init();
	//���IO�ڵĳ�ʼ��
	Output_KEY_Init();
	//��ʼ���ж�,��ʼ����������ⲿ��������ʱ���Զ���Ӧ
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����NVIC�жϷ���2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	MY_EXTI_Init();//��ʼ���ж�
	delay_init();

	//for (size_t i = 0; i < length; i++)
	//{

	//}
	while(1){}

	//��2121212


//	//�����͸�����״̬
//	if (EN_CYLINDER_UP) {
      
}
//	if(EN_CYLINDER_DOWN){}
//	//���ú���������״̬
//	if (EN_BACK_MOTOR_FORWARD) {}
//	if(EN_BACK_MOTOR_BACKWARD){}
//	//���ý���״̬
//	if (EN_CAPSTAN_IN) {}
//	if(EN_CAPSTAN_OUT){}
//	//���øߵ���ģʽ
//	if (EN_HIGH_SPEED_MODE) {}
//	else{}









