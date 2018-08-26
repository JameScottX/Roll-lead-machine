#include "stm32f10x.h"

#define TURNTABLE_STEPPER_PORT      GPIOB
#define TURNTABLE_STEPPER_PIN       GPIO_Pin_6
#define TURNTABLE_STEPPER_FUNC(ntime)      TURNTABLE_STEPPER_PORT->BSRR = TURNTABLE_STEPPER_PIN;delay_us(ntime);\
                                          TURNTABLE_STEPPER_PORT->BRR = TURNTABLE_STEPPER_PIN;delay_us(ntime);                                                                 

#define ROLLING_STEPPER_PORT      GPIOB
#define ROLLING_STEPPER_PIN       GPIO_Pin_7
#define ROLLING_STEPPER_FUNC(ntime)      ROLLING_STEPPER_PORT->BSRR = ROLLING_STEPPER_PIN;delay_us(ntime);\
                                           ROLLING_STEPPER_PORT->BRR = ROLLING_STEPPER_PIN;delay_us(ntime);


#define PUSH_REEL_PORT                        GPIOB
#define PUSH_REEL_PIN                         GPIO_Pin_8
#define REEL_PULL()                           PUSH_REEL_PORT->BSRR = PUSH_REEL_PIN
#define REEL_PUSH()                           PUSH_REEL_PORT->BRR = PUSH_REEL_PIN

#define LS_CLOCK                 (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)


//#define LS_ROLLING_PORT           GPIOA
//#define LS_ROLLING_PIN            GPIO_Pin_4
//#define LS_ROLLING_EXTIPORT      GPIO_PortSourceGPIOA
//#define LS_ROLLING_EXTIPIN       GPIO_PinSource4
//#define LS_ROLLING_EXTILINE      EXTI_Line4
//#define LS_ROLLING_EXTIIRQ       EXTI4_IRQn

//#define LS_ROLLING_HANDLER        EXTI4_IRQHandler

//#define LS_TURNTABLE_PORT           GPIOA
//#define LS_TURNTABLE_PIN            GPIO_Pin_5
//#define LS_TURNTABLE_EXTIPORT      GPIO_PortSourceGPIOA
//#define LS_TURNTABLE_EXTIPIN         GPIO_PinSource5
//#define LS_TURNTABLE_EXTILINE         EXTI_Line5
//#define LS_TURNTABLE_EXTIIRQ       EXTI9_5_IRQn
//    
//#define LS_TURNTABLE_HANDLER       EXTI9_5_IRQHandler


#define READY    0x01
#define NOTREADY    0x02

#define STOP        0x00
#define START        0x01
#define NONE        0x03

#define TURNTABLE_SPEED   50
#define ROLLING_DETECT_SPEED  55
#define ROLLING_SPEED    10

#define  TURNTABLE_FLAG                 'T'

#define  CAMERAREADY_FLAG               'C'
#define  SLIT_FLAG                      'S'

#define SYSTEM_STOP_FLAG                'Y'
#define SYSTEM_START_FLAG               'Z'


extern uint8_t turntable_info,rolling_info,system_info,slit_info;

extern char ls_turntable ;
extern char TTS_Stop ;


void turnTable_stepper_Init();
void rolling_stepper_Init();
void push_reel_Init();

void turnTable_stepper(unsigned short step,unsigned short speed);
void rolling_stepper(unsigned short step,unsigned short speed);

void turnTable_go();
void rolling_go();

void delay_us(unsigned short step);




