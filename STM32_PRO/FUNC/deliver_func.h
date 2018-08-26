#include "stm32f10x.h"

#define DELIVER_STEPPER_PORT      GPIOA
#define DELIVER_STEPPER_PIN       GPIO_Pin_3
#define DELIVER_STEPPER_FUNC(ntime)      DELIVER_STEPPER_PORT->BSRR = DELIVER_STEPPER_PIN;delay_us(ntime);\
                                          DELIVER_STEPPER_PORT->BRR = DELIVER_STEPPER_PIN;delay_us(ntime); 


#define LS_DELOver_CLOCK                 (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)

#define LS_DELOver_PORT           GPIOA
#define LS_DELOver_PIN            GPIO_Pin_2

#define LS_DELOver_EXTIPORT      GPIO_PortSourceGPIOA
#define LS_DELOver_EXTIPIN       GPIO_PinSource2
#define LS_DELOver_EXTILINE      EXTI_Line2
#define LS_DELOver_EXTIIRQ       EXTI2_IRQn

#define LS_DELOver_HANDLER        EXTI2_IRQHandler


#define DEL_HELPER_PORT          GPIOC
#define DEL_HELPER_PIN           GPIO_Pin_10

#define INIT_COUNT     0

#define LEADIN    0x04
#define LEADOUT   0x05

#define DELIVER_SPEED_4IN      20
#define DELIVER_SPEED_ROLLING   40

extern char leadstrip_status;
extern char ls_leadstrip;
extern unsigned short del_helpper_count;

void deliver_stepper_Init();
void delOver_switch_Init();
void delHelp_Init();
void del_helpper_func();
void del_helpper_reset();
void deliver_stepper(unsigned short step,unsigned short speed);
