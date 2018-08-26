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
	
	turnTable_stepper_Init();   //转盘   细分3200
  rolling_stepper_Init();     //卷轴   细分6400
	
	push_reel_Init();           //卷轴推进

  delHelp_Init();              //铅条推进递进
  deliver_stepper_Init();      //铅条推进       细分3200
	delOver_switch_Init();       //推进处光电开关

	broom_init();
	filter_Init();            //过滤卷轴   转向步进细分1600
	
	system_info = STOP;       //系统初始为暂停 
  leadstrip_status = STOP;  //初始化为STOP
  turntable_info = STOP;    //转盘初始手动为停止	
	filter_system_info =STOP; //过滤系统初始暂停
	
	
	while(1)
	{
		
		slit_info = STOP;         //狭缝检测为没有检测到
		leadstrip_status = STOP;
		
	 if(system_info == START){
		 	 		 
		turnTable_stepper(turntable_tinycycle,50); //切换到下一个

		PUSH_REEL_PORT->BRR = PUSH_REEL_PIN;
		mdelay(100);   //机械所需的延时
		
		Usart_SendByte_(USART1,CAMERAREADY_FLAG); //发送开始启用摄像头 
		 
		while(slit_info == STOP) {ROLLING_STEPPER_FUNC(50);} //连续转动时摄像头扫描

		rolling_stepper(rolling4aim,50); //扫描后对准
		
		DEL_HELPER_PORT->BRR = DEL_HELPER_PIN;   //铅皮口推进
		
    //while(1);
		
		ls_leadstrip = LEADIN;		 
		while(1) {		
		DELIVER_STEPPER_FUNC(40);
		if(leadstrip_status == START){break;}
		}//3000为上限值，依据此可以判定铅皮是否用完

		ls_leadstrip = LEADOUT;
		
		deliver_stepper(deliver_rest,40); //推进剩余

		rolling_stepper(rolling_stepper_cycle,20);   //先卷一周

		DEL_HELPER_PORT->BSRR = DEL_HELPER_PIN;  //铅皮口推退离

		while(leadstrip_status ==START) {ROLLING_STEPPER_FUNC(20);}  //开始卷铅皮操作
		rolling_stepper(rolling_rest,20);   //卷剩余
		
		PUSH_REEL_PORT->BSRR = PUSH_REEL_PIN;
		mdelay(100);   //机械所需的延时 	
		
	 }else{
	 
	 if(turntable_info ==START){
		 
		  turntable_info= STOP;
		  turnTable_stepper(turntable_tinycycle,50);
	   }
	
		 
	   }

	}
}


