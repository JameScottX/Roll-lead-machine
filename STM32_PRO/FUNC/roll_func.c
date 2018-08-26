#include "roll_func.h"
#include "./led/bsp_led.h"
#include "./systick/bsp_SysTick.h"

uint8_t turntable_info,rolling_info,system_info,slit_info;


char ls_turntable =NOTREADY;
char ls_rolling   =NOTREADY;


void turnTable_stepper_Init(){
	
		GPIO_InitTypeDef GPIO_InitStructure;
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Pin = TURNTABLE_STEPPER_PIN;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

		GPIO_Init(TURNTABLE_STEPPER_PORT,&GPIO_InitStructure);
	
}


void delay_us(unsigned short step){
	
   unsigned int i=0,j =0;
	
	for(i=0;i<step;i++){
	for(j=0;j<72;j++);
	}

}

void turnTable_stepper(unsigned short step,unsigned short speed){
	
  unsigned short temp ;
	temp = step;
	while(temp !=0){
    temp--;		
   TURNTABLE_STEPPER_FUNC(speed);
	}
}

void rolling_stepper(unsigned short step,unsigned short speed){

  unsigned short temp ;
	temp = step;
	while(temp !=0){
    temp--;		
   ROLLING_STEPPER_FUNC(speed);
	}	
}

void rolling_stepper_Init(){
	
		GPIO_InitTypeDef GPIO_InitStructure;
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Pin = ROLLING_STEPPER_PIN;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

		GPIO_Init(ROLLING_STEPPER_PORT,&GPIO_InitStructure);
	
}

void push_reel_Init(){

		GPIO_InitTypeDef GPIO_InitStructure;
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Pin = PUSH_REEL_PIN;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

		GPIO_Init(PUSH_REEL_PORT,&GPIO_InitStructure);
  	PUSH_REEL_PORT->BSRR = PUSH_REEL_PIN;

}





