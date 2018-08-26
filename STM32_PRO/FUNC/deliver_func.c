#include "deliver_func.h"
#include "roll_func.h"
#include "./led/bsp_led.h"  


char ls_leadstrip = LEADIN;
char leadstrip_status = STOP;


unsigned short del_helpper_count = INIT_COUNT;


void deliver_stepper_Init(){

		GPIO_InitTypeDef GPIO_InitStructure;
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Pin = DELIVER_STEPPER_PIN;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

		GPIO_Init(DELIVER_STEPPER_PORT,&GPIO_InitStructure);

}

void delHelp_Init(){

		GPIO_InitTypeDef GPIO_InitStructure;
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Pin = DEL_HELPER_PIN;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

		GPIO_Init(DEL_HELPER_PORT,&GPIO_InitStructure);
	  DEL_HELPER_PORT->BSRR = DEL_HELPER_PIN;
}

void delOver_switch_Init(){

	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(LS_DELOver_CLOCK,ENABLE);
	
  NVIC_InitStructure.NVIC_IRQChannel = LS_DELOver_EXTIIRQ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = LS_DELOver_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(LS_DELOver_PORT,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(LS_DELOver_EXTIPORT, LS_DELOver_EXTIPIN);
	
	EXTI_InitStructure.EXTI_Line = LS_DELOver_EXTILINE;
	
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  EXTI_ClearFlag(LS_DELOver_EXTILINE);


}


void LS_DELOver_HANDLER()
{
	
if(EXTI_GetITStatus(LS_DELOver_EXTILINE) != RESET) 
	{
		
		if(ls_leadstrip == LEADIN && GPIO_ReadInputDataBit(GPIOA,LS_DELOver_PIN) ==RESET){
		
			leadstrip_status  = START;
			LED1(1);
			delay_us(100);
			
		}else if(ls_leadstrip == LEADOUT && GPIO_ReadInputDataBit(GPIOA,LS_DELOver_PIN) ==SET ){
			
		  leadstrip_status  = STOP;
			LED1(0);
			delay_us(100);
		}

		EXTI_ClearITPendingBit(LS_DELOver_EXTILINE);     
	} 
}


void deliver_stepper(unsigned short step,unsigned short speed){
	
  unsigned short temp ;
	temp = step;
	while(temp !=0){
    temp--;		
   DELIVER_STEPPER_FUNC(speed);
	}
}



void del_helpper_func(){

  if(del_helpper_count>6000){
	   return;
	}
	if(del_helpper_count==6000){
	
	  DEL_HELPER_PORT->BSRR = DEL_HELPER_PIN;
	}
	del_helpper_count ++;
	
}


void del_helpper_reset(){

   DEL_HELPER_PORT->BRR = DEL_HELPER_PIN;
	 del_helpper_count = INIT_COUNT;
}




