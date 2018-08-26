#include "filter_func.h"
#include "./systick/bsp_SysTick.h"
#include "roll_func.h"
#include "./usart/bsp_usart.h"


#define Mechanical_delay 1000

#define Mechanical_delay2 2000

#define Rotation_Angle  400

char filter_system_info ;


uint16_t deliver_count =0;
uint16_t caching_count =0;

char deliver_flag =0;
char caching_flag =0;

char rotation_count =0;
char filter_func_flag =0;

char detect_flag =1;
uint16_t detect_count =0;  //此为摄像头检测的延时

uint16_t rotation_nstep = 0;


void filter_Init(void){
	
	
   GPIO_InitTypeDef GPIO_InitStructure;
	
 	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	
	 GPIO_InitStructure.GPIO_Pin = DELIVER_PIN | CACHING_PIN | ROTATION_PIN | ROTATION_DIR_PIN ;
	
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
   GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
	 DELIVER_IO->BSRR = DELIVER_PIN;
	 CACHING_IO->BRR = CACHING_PIN;
	
 	 time_Init();//启动定时器
	
}

void deliver_func(void){

	DELIVER_IO->BRR = DELIVER_PIN;
	deliver_flag = 0x01;
	
}

void caching_func(void){

		CACHING_IO->BSRR = CACHING_PIN;
	  caching_flag = 0x01;

}


void rotation_delay(u16 ntime){
	
		u8 i;
	  u16 j;
	
	  for(j= ntime;j--;){
			  for(i = 72;i--;);
		} 
}

void rotation_func(char dir,u16 nstep){
	

	   if(dir== 0x01){
			 
		 ROTATION_IO->BSRR  = ROTATION_DIR_PIN;
			
		 }else{
		 
		 ROTATION_IO->BRR  = ROTATION_DIR_PIN;
			 
		 }

		 rotation_nstep = nstep;

}

void broom_init(void){

    GPIO_InitTypeDef GPIO_InitStructure;
		TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
		TIM_OCInitTypeDef  TIM_OCInitStructure;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
	
	
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  	GPIO_InitStructure.GPIO_Pin = BROOM_PIN;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(GPIOC,&GPIO_InitStructure);
	
		TIM_TimeBaseStructure.TIM_Period = 800-1; 
		TIM_TimeBaseStructure.TIM_Prescaler =36-1; 
		TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure);

		TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
		TIM_OCInitStructure.TIM_Pulse = 0;
	
	  TIM_OC1Init(TIM8, &TIM_OCInitStructure); 
		TIM_CtrlPWMOutputs(TIM8,ENABLE);	
		TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable);
				
		

		TIM_ARRPreloadConfig(TIM8, ENABLE); 

		TIM_Cmd(TIM8, ENABLE);	

}


void broom_func(uint16_t speed){

if(speed ==0){

    TIM_SetCompare1(TIM8,800);
	
}else{
	
    TIM_SetCompare1(TIM8,400);
	
	  TIM_SetClockDivision(TIM8,speed);
     }
	
}

void filter_func(char dir){
		
	rotation_func(dir,Rotation_Angle);
  filter_func_flag = 1;
	
	detect_flag = 0; //检测到则不计数
	detect_count=0;
	
}

void time_Init(void){       //1毫秒一次

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
	
	TIM_TimeBaseStructure.TIM_Prescaler= 7200-1;
  TIM_TimeBaseStructure.TIM_Period=10-1;
	TIM_TimeBaseStructure.TIM_ClockDivision =0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseStructure);
	
	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
	TIM_ClearITPendingBit(TIM5, TIM_IT_Update);
	
	TIM_Cmd(TIM5, ENABLE);
	
  NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
}

void TIM5_IRQHandler(void){
	
  if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET  ){
		
	TIM_ClearITPendingBit( TIM5 , TIM_IT_Update );		
		
	if(filter_system_info ==START){
		
		if(deliver_flag == 0x01){
			
			deliver_count++;
			
			if(deliver_count> Mechanical_delay){
				
				DELIVER_IO->BSRR = DELIVER_PIN;
						
				if(deliver_count > Mechanical_delay2 ){
					
					deliver_flag = 0;
					deliver_count =0;
						
					rotation_func(1,Rotation_Angle);

				}				
			}
		}
		
		if(caching_flag == 0x01){
			
			caching_count++;
			
			if(caching_count>500){
				
			CACHING_IO->BRR = CACHING_PIN;
			caching_count =0;
			caching_flag = 0;
				
			}
		}
		
		if(rotation_nstep >0){
			
			rotation_nstep--;
			
			ROTATION_IO->BSRR = ROTATION_PIN;
			rotation_delay(20);		
			ROTATION_IO->BRR = ROTATION_PIN;
			
			if(rotation_nstep == 0)
			rotation_count++;
			
		}
		
		if(filter_func_flag ==1 && rotation_nstep==0){		
				filter_func_flag =0;
				deliver_func();
					
			}
		
		if(rotation_count ==2){    //旋转两次后开始传送卷轴
			
				caching_func();
				rotation_count=0;
				detect_flag=1;
				Usart_SendByte_(USART1,CAMERAREADY_FLAG2);		
			}
		
			
		if(detect_flag){           
			detect_count++;
			if(detect_count > 4000){		
				
				filter_func(0);
				rotation_count = 0;
				
			}		
     }
   }
  }
}