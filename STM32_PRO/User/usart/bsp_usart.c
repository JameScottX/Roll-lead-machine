#include "./usart/bsp_usart.h"
#include "roll_func.h"
#include "./led/bsp_led.h"
#include "filter_func.h"

void USART_Config(void)    //避免使用 PA8 PA11
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	
	
	DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK, ENABLE);

	DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = DEBUG_USART_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStructure);


	GPIO_InitStructure.GPIO_Pin = DEBUG_USART_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
  NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART_IRQ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

	USART_InitStructure.USART_BaudRate = DEBUG_USART_BAUDRATE;

	USART_InitStructure.USART_WordLength = USART_WordLength_8b;

	USART_InitStructure.USART_StopBits = USART_StopBits_1;

	USART_InitStructure.USART_Parity = USART_Parity_No ;

	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(DEBUG_USARTx, &USART_InitStructure);
	
  USART_ITConfig(DEBUG_USARTx, USART_IT_RXNE, ENABLE);
	
	USART_Cmd(DEBUG_USARTx, ENABLE);
	USART_ClearFlag(DEBUG_USARTx,USART_FLAG_TC);
	
}

void Usart_SendByte_( USART_TypeDef * pUSARTx, uint8_t ch)
{
	USART_SendData(pUSARTx,ch);		
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
}

void Usart_SendArray_(uint32_t Channel,uint8_t *words,u16 length){
	
    u16 c;
	  for(c=length;c--;){	
			Usart_SendByte_((USART_TypeDef *)Channel,*(words));
			words++;
		}
}

void DEBUG_USART_IRQHandler(void){
	
    uint8_t buffer_;
	   
   if(USART_GetITStatus(DEBUG_USARTx,USART_IT_RXNE)!= RESET){
		 
     buffer_ = USART_ReceiveData(DEBUG_USARTx);
		
     if(buffer_ == TURNTABLE_FLAG){         //手动转盘开始转动
			 
		   turntable_info = START;

		 }else if(buffer_ == SLIT_FLAG){        // 检测到狭缝
			 
		   slit_info = START;
		 
		 }else if(buffer_ == DELIVER_DETECTINFO){ //过滤卷轴检测到圆形

			 filter_func(1);
			 
     }else if(buffer_ == SYSTEM_STOP_FLAG){
			 
		   system_info = STOP;
			 
		 }else if(buffer_ == SYSTEM_START_FLAG){
			 
		   system_info = START;
			 
		 }else if(buffer_ == START_VIBRATION_SYSTEM){
			 
		 		 broom_func(48);
			 
		 }else if(buffer_ == STOP_VIBRATION_SYSTEM){
			 
		 		 broom_func(0);
			 
		 }else if(buffer_ == START_FILTER_SYSTEM){
			 
		 filter_system_info =START;
			 
		 }else if(buffer_ == STOP_FILTER_SYSTEM){
			 
		 filter_system_info =STOP;
		 }
			 		 
	   USART_ClearITPendingBit(DEBUG_USARTx, USART_IT_RXNE);	 
	}				
}



int fputc(int ch, FILE *f)
{
		/* 发送一个字节数据到串口 */
		USART_SendData(DEBUG_USARTx, (uint8_t) ch);
		
		/* 等待发送完毕 */
		while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

///重定向c库函数scanf到串口，重写向后可使用scanf、getchar等函数
int fgetc(FILE *f)
{
		/* 等待串口输入数据 */
		while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(DEBUG_USARTx);
}

