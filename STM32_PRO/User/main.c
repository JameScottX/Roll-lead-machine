#include "stm32f10x.h"
#include "./led/bsp_led.h"   
#include "./usart/bsp_usart.h"
#include "./key/bsp_key.h"  
#include "./systick/bsp_SysTick.h"
#include "filter_func.h"
#include "roll_func.h"
#include "deliver_func.h"

#define turntable_tinycycle 640
#define rolling_stepper_cycle 6400

#define rolling4aim 880
#define deliver_rest  6000
#define rolling_rest  3200

unsigned int Task_Delay[NumOfTask]; 

int main(void) 	
{		
	
	USART_Config();
	LED_GPIO_Config();
	SysTick_Init();
	
	turnTable_stepper_Init();   //ת��   ϸ��3200
  rolling_stepper_Init();     //����   ϸ��6400
	
	push_reel_Init();           //�����ƽ�

  delHelp_Init();              //Ǧ���ƽ��ݽ�
  deliver_stepper_Init();      //Ǧ���ƽ�       ϸ��3200
	delOver_switch_Init();       //�ƽ�����翪��

	broom_init();
	filter_Init();            //���˾���   ת�򲽽�ϸ��1600
	
	system_info = STOP;       //ϵͳ��ʼΪ��ͣ 
  leadstrip_status = STOP;  //��ʼ��ΪSTOP
  turntable_info = STOP;    //ת�̳�ʼ�ֶ�Ϊֹͣ	
	filter_system_info =STOP; //����ϵͳ��ʼ��ͣ
	
	
	while(1)
	{
		
		slit_info = STOP;         //������Ϊû�м�⵽
		leadstrip_status = STOP;
		
	 if(system_info == START){
		 	 		 
		turnTable_stepper(turntable_tinycycle,50); //�л�����һ��

		PUSH_REEL_PORT->BRR = PUSH_REEL_PIN;
		mdelay(100);   //��е�������ʱ
		
		Usart_SendByte_(USART1,CAMERAREADY_FLAG); //���Ϳ�ʼ��������ͷ 
		 
		while(slit_info == STOP) {ROLLING_STEPPER_FUNC(50);} //����ת��ʱ����ͷɨ��

		rolling_stepper(rolling4aim,50); //ɨ����׼
		
		DEL_HELPER_PORT->BRR = DEL_HELPER_PIN;   //ǦƤ���ƽ�
		
    //while(1);
		
		ls_leadstrip = LEADIN;		 
		while(1) {		
		DELIVER_STEPPER_FUNC(40);
		if(leadstrip_status == START){break;}
		}//3000Ϊ����ֵ�����ݴ˿����ж�ǦƤ�Ƿ�����

		ls_leadstrip = LEADOUT;
		
		deliver_stepper(deliver_rest,40); //�ƽ�ʣ��

		rolling_stepper(rolling_stepper_cycle,20);   //�Ⱦ�һ��

		DEL_HELPER_PORT->BSRR = DEL_HELPER_PIN;  //ǦƤ��������

		while(leadstrip_status ==START) {ROLLING_STEPPER_FUNC(20);}  //��ʼ��ǦƤ����
		rolling_stepper(rolling_rest,20);   //��ʣ��
		
		PUSH_REEL_PORT->BSRR = PUSH_REEL_PIN;
		mdelay(100);   //��е�������ʱ 	
		
	 }else{
	 
	 if(turntable_info ==START){
		 
		  turntable_info= STOP;
		  turnTable_stepper(turntable_tinycycle,50);
	   }
	
		 
	   }

	}
}


