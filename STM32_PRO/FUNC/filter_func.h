#include "stm32f10x.h"

#define DELIVER_IO         GPIOB
#define DELIVER_PIN        GPIO_Pin_9

#define CACHING_IO         GPIOB
#define CACHING_PIN        GPIO_Pin_10

#define ROTATION_IO        GPIOB
#define ROTATION_PIN       GPIO_Pin_11

#define ROTATION_DIR_IO    GPIOB
#define ROTATION_DIR_PIN   GPIO_Pin_12

#define BROOM_IO           GPIOC
#define BROOM_PIN          GPIO_Pin_6

#define DELIVER_DETECTINFO       'F'

#define START_VIBRATION_SYSTEM   'A'
#define STOP_VIBRATION_SYSTEM    'B'
 
#define START_FILTER_SYSTEM      'D'
#define STOP_FILTER_SYSTEM       'E'

#define CAMERAREADY_FLAG2        'G'

#define ROTATION_SPEED  10

extern char filter_system_info ;


void filter_Init(void);
void deliver_func(void);
void caching_func(void);
void rotation_func(char dir,u16 nstep);

void filter_func(char dir);

void broom_init(void);
void broom_func(u16 speed);

void time_Init(void);



