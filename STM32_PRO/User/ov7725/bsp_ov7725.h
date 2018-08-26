#ifndef __OV7725_H
#define __OV7725_H 
	   
#include "stm32f10x.h"

#define IMAGE_WIDTH  180
#define IMAGE_HEIGHT  180
#define GRAY_THRESHOLD     60
#define WIDTH_REC 20
#define HEIGHT_REC 110

#define RGB(r,g,b)			(((r>>3)<<11)|((g>>2)<<5)|b>>3)
#define GETR_FROM_RGB16(RGB565)   ((unsigned char)((  ((unsigned short int )RGB565)  >>11)<< 3))            //����8 λ R    
#define GETG_FROM_RGB16(RGB565)   ((unsigned char)((  ((unsigned short int )(RGB565  & 0x7ff)) >>5)<< 2))   //����8 λ G    
#define GETB_FROM_RGB16(RGB565)   ((unsigned char)((  ((unsigned short int )(RGB565  & 0x1f))<<3)))         //����8 λ B    

extern u8 x_start ;
extern u8 y_start ;

extern u8 LineX_s;
extern u8 LineY_s;
extern u8 LineX_e;
extern u8 LineY_e;

#define COUNT_SMALTHRESHOLD 60
#define COUNT_DIF     5

void my_temp_Init(void);

typedef struct
{	

	
	uint8_t QVGA_VGA; //0��QVGA��1VGA
	
	/*VGA:sx + width <= 320 �� 240 ,sy+height <= 320 �� 240*/
	/*QVGA:sx + width <= 320 ,sy+height <= 240*/
	uint16_t cam_sx; //����ͷ����X��ʼλ��
	uint16_t cam_sy; //����ͷ����Y��ʼλ��
	
	uint16_t cam_width;//ͼ��ֱ��ʣ���
	uint16_t cam_height;//ͼ��ֱ��ʣ���
	
	uint16_t lcd_sx;//ͼ����ʾ��Һ������X��ʼλ��
	uint16_t lcd_sy;//ͼ����ʾ��Һ������Y��ʼλ��
	uint8_t lcd_scan;//Һ������ɨ��ģʽ��0-7��
	
	uint8_t light_mode;//����ģʽ��������Χ[0~5]
	int8_t saturation;//���Ͷ�,������Χ[-4 ~ +4]   
	int8_t brightness;//���նȣ�������Χ[-4~+4]
	int8_t contrast;//�Աȶȣ�������Χ[-4~+4]
	uint8_t effect;	//����Ч����������Χ[0~6]:	


}OV7725_MODE_PARAM;


/* �Ĵ����궨�� */
#define REG_GAIN      0x00
#define REG_BLUE      0x01
#define REG_RED       0x02
#define REG_GREEN     0x03
#define REG_BAVG      0x05
#define REG_GAVG      0x06
#define REG_RAVG      0x07
#define REG_AECH      0x08
#define REG_COM2      0x09
#define REG_PID       0x0A
#define REG_VER       0x0B
#define REG_COM3      0x0C
#define REG_COM4      0x0D
#define REG_COM5      0x0E
#define REG_COM6      0x0F
#define REG_AEC       0x10
#define REG_CLKRC     0x11
#define REG_COM7      0x12
#define REG_COM8      0x13
#define REG_COM9      0x14
#define REG_COM10     0x15
#define REG_REG16     0x16
#define REG_HSTART    0x17
#define REG_HSIZE     0x18
#define REG_VSTRT     0x19
#define REG_VSIZE     0x1A
#define REG_PSHFT     0x1B
#define REG_MIDH      0x1C
#define REG_MIDL      0x1D
#define REG_LAEC      0x1F
#define REG_COM11     0x20
#define REG_BDBase    0x22
#define REG_BDMStep   0x23
#define REG_AEW       0x24
#define REG_AEB       0x25
#define REG_VPT       0x26
#define REG_REG28     0x28
#define REG_HOutSize  0x29
#define REG_EXHCH     0x2A
#define REG_EXHCL     0x2B
#define REG_VOutSize  0x2C
#define REG_ADVFL     0x2D
#define REG_ADVFH     0x2E
#define REG_YAVE      0x2F
#define REG_LumHTh    0x30
#define REG_LumLTh    0x31
#define REG_HREF      0x32
#define REG_DM_LNL    0x33
#define REG_DM_LNH    0x34
#define REG_ADoff_B   0x35
#define REG_ADoff_R   0x36
#define REG_ADoff_Gb  0x37
#define REG_ADoff_Gr  0x38
#define REG_Off_B     0x39
#define REG_Off_R     0x3A
#define REG_Off_Gb    0x3B
#define REG_Off_Gr    0x3C
#define REG_COM12     0x3D
#define REG_COM13     0x3E
#define REG_COM14     0x3F
#define REG_COM16     0x41
#define REG_TGT_B     0x42
#define REG_TGT_R     0x43
#define REG_TGT_Gb    0x44
#define REG_TGT_Gr    0x45
#define REG_LC_CTR    0x46
#define REG_LC_XC     0x47
#define REG_LC_YC     0x48
#define REG_LC_COEF   0x49
#define REG_LC_RADI   0x4A
#define REG_LC_COEFB  0x4B 
#define REG_LC_COEFR  0x4C
#define REG_FixGain   0x4D
#define REG_AREF1     0x4F
#define REG_AREF6     0x54
#define REG_UFix      0x60
#define REG_VFix      0x61
#define REG_AWBb_blk  0x62
#define REG_AWB_Ctrl0 0x63
#define REG_DSP_Ctrl1 0x64
#define REG_DSP_Ctrl2 0x65
#define REG_DSP_Ctrl3 0x66
#define REG_DSP_Ctrl4 0x67
#define REG_AWB_bias  0x68
#define REG_AWBCtrl1  0x69
#define REG_AWBCtrl2  0x6A
#define REG_AWBCtrl3  0x6B
#define REG_AWBCtrl4  0x6C
#define REG_AWBCtrl5  0x6D
#define REG_AWBCtrl6  0x6E
#define REG_AWBCtrl7  0x6F
#define REG_AWBCtrl8  0x70
#define REG_AWBCtrl9  0x71
#define REG_AWBCtrl10 0x72
#define REG_AWBCtrl11 0x73
#define REG_AWBCtrl12 0x74
#define REG_AWBCtrl13 0x75
#define REG_AWBCtrl14 0x76
#define REG_AWBCtrl15 0x77
#define REG_AWBCtrl16 0x78
#define REG_AWBCtrl17 0x79
#define REG_AWBCtrl18 0x7A
#define REG_AWBCtrl19 0x7B
#define REG_AWBCtrl20 0x7C
#define REG_AWBCtrl21 0x7D 
#define REG_GAM1      0x7E
#define REG_GAM2      0x7F
#define REG_GAM3      0x80
#define REG_GAM4      0x81
#define REG_GAM5      0x82
#define REG_GAM6      0x83
#define REG_GAM7      0x84
#define REG_GAM8      0x85
#define REG_GAM9      0x86
#define REG_GAM10     0x87
#define REG_GAM11     0x88
#define REG_GAM12     0x89
#define REG_GAM13     0x8A
#define REG_GAM14     0x8B
#define REG_GAM15     0x8C
#define REG_SLOP      0x8D
#define REG_DNSTh     0x8E
#define REG_EDGE0     0x8F
#define REG_EDGE1     0x90
#define REG_DNSOff    0x91
#define REG_EDGE2     0x92
#define REG_EDGE3     0x93
#define REG_MTX1      0x94
#define REG_MTX2      0x95
#define REG_MTX3      0x96
#define REG_MTX4      0x97
#define REG_MTX5      0x98
#define REG_MTX6      0x99
#define REG_MTX_Ctrl  0x9A
#define REG_BRIGHT    0x9B
#define REG_CNST      0x9C
#define REG_UVADJ0    0x9E
#define REG_UVADJ1    0x9F
#define REG_SCAL0     0xA0
#define REG_SCAL1     0xA1
#define REG_SCAL2     0xA2
#define REG_SDE       0xA6
#define REG_USAT      0xA7
#define REG_VSAT      0xA8
#define REG_HUECOS    0xA9
#define REG_HUESIN    0xAA
#define REG_SIGN      0xAB
#define REG_DSPAuto   0xAC



/************************** OV7725 �������Ŷ���********************************/
// FIFO ���ʹ�ܣ���ģ���е�OE
#define      OV7725_OE_GPIO_CLK                       RCC_APB2Periph_GPIOA
#define      OV7725_OE_GPIO_PORT                      GPIOA
#define      OV7725_OE_GPIO_PIN                       GPIO_Pin_3

// FIFO д��λ
#define      OV7725_WRST_GPIO_CLK                     RCC_APB2Periph_GPIOC
#define      OV7725_WRST_GPIO_PORT                    GPIOC
#define      OV7725_WRST_GPIO_PIN                     GPIO_Pin_4

// FIFO ����λ
#define      OV7725_RRST_GPIO_CLK                     RCC_APB2Periph_GPIOA
#define      OV7725_RRST_GPIO_PORT                    GPIOA
#define      OV7725_RRST_GPIO_PIN                     GPIO_Pin_2

// FIFO ��ʱ��
#define      OV7725_RCLK_GPIO_CLK                     RCC_APB2Periph_GPIOC
#define      OV7725_RCLK_GPIO_PORT                    GPIOC
#define      OV7725_RCLK_GPIO_PIN                     GPIO_Pin_5

// FIFO дʹ��
#define      OV7725_WE_GPIO_CLK                       RCC_APB2Periph_GPIOD
#define      OV7725_WE_GPIO_PORT                      GPIOD
#define      OV7725_WE_GPIO_PIN                       GPIO_Pin_3


// 8λ���ݿ�
#define      OV7725_DATA_GPIO_CLK                     RCC_APB2Periph_GPIOB
#define      OV7725_DATA_GPIO_PORT                    GPIOB
#define      OV7725_DATA_0_GPIO_PIN                   GPIO_Pin_8
#define      OV7725_DATA_1_GPIO_PIN                   GPIO_Pin_9
#define      OV7725_DATA_2_GPIO_PIN                   GPIO_Pin_10
#define      OV7725_DATA_3_GPIO_PIN                   GPIO_Pin_11
#define      OV7725_DATA_4_GPIO_PIN                   GPIO_Pin_12
#define      OV7725_DATA_5_GPIO_PIN                   GPIO_Pin_13
#define      OV7725_DATA_6_GPIO_PIN                   GPIO_Pin_14
#define      OV7725_DATA_7_GPIO_PIN                   GPIO_Pin_15

// OV7725���ж�
#define      OV7725_VSYNC_GPIO_CLK                    RCC_APB2Periph_GPIOE
#define      OV7725_VSYNC_GPIO_PORT                   GPIOC
#define      OV7725_VSYNC_GPIO_PIN                    GPIO_Pin_3

#define      OV7725_VSYNC_EXTI_SOURCE_PORT            GPIO_PortSourceGPIOC
#define      OV7725_VSYNC_EXTI_SOURCE_PIN             GPIO_PinSource3
#define      OV7725_VSYNC_EXTI_LINE                   EXTI_Line3
#define      OV7725_VSYNC_EXTI_IRQ                    EXTI3_IRQn
#define      OV7725_VSYNC_EXTI_INT_FUNCTION           EXTI3_IRQHandler




#define FIFO_OE_H()     OV7725_OE_GPIO_PORT->BSRR =OV7725_OE_GPIO_PIN	  
#define FIFO_OE_L()     OV7725_OE_GPIO_PORT->BRR  =OV7725_OE_GPIO_PIN	  /*����ʹFIFO���ʹ��*/

#define FIFO_WRST_H()   OV7725_WRST_GPIO_PORT->BSRR =OV7725_WRST_GPIO_PIN	  /*��������FIFOд(����from����ͷ)ָ���˶� */
#define FIFO_WRST_L()   OV7725_WRST_GPIO_PORT->BRR  =OV7725_WRST_GPIO_PIN	  /*����ʹFIFOд(����from����ͷ)ָ�븴λ*/

#define FIFO_RRST_H()   OV7725_RRST_GPIO_PORT->BSRR =OV7725_RRST_GPIO_PIN	  /*��������FIFO��(���ݴ�FIFO���)ָ���˶� */
#define FIFO_RRST_L()   OV7725_RRST_GPIO_PORT->BRR  =OV7725_RRST_GPIO_PIN	  /*����ʹFIFO��(���ݴ�FIFO���)ָ�븴λ */

#define FIFO_RCLK_H()   OV7725_RCLK_GPIO_PORT->BSRR =OV7725_RCLK_GPIO_PIN	  
#define FIFO_RCLK_L()   OV7725_RCLK_GPIO_PORT->BRR  =OV7725_RCLK_GPIO_PIN	  /*FIFO�������ʱ��*/

#define FIFO_WE_H()     OV7725_WE_GPIO_PORT->BSRR =OV7725_WE_GPIO_PIN	  /*����ʹFIFOд����*/
#define FIFO_WE_L()     OV7725_WE_GPIO_PORT->BRR  =OV7725_WE_GPIO_PIN


#define READ_FIFO_PIXEL(RGB565)   	do{\
	                                  RGB565=0;\
	                                  FIFO_RCLK_L();\
	                                  RGB565 = (OV7725_DATA_GPIO_PORT->IDR) & 0xff00;\
	                                  FIFO_RCLK_H();\
                                    FIFO_RCLK_L();\
	                                  RGB565 |= (OV7725_DATA_GPIO_PORT->IDR >>8) & 0x00ff;\
	                                  FIFO_RCLK_H();\
                                    }while(0)

#define FIFO_PREPARE                do{\
	                                  FIFO_RRST_L();\
	                                  FIFO_RCLK_L();\
	                                  FIFO_RCLK_H();\
	                                  FIFO_RRST_H();\
	                                  FIFO_RCLK_L();\
	                                  FIFO_RCLK_H();\
                                    }while(0)

#define OV7725_ID       0x21
																		
																		
																		

/*��Ϣ���*/
#define OV7725_DEBUG_ON         0

#define OV7725_INFO(fmt,arg...)           printf("<<-OV7725-INFO->> "fmt"\n",##arg)
#define OV7725_ERROR(fmt,arg...)          printf("<<-OV7725-ERROR->> "fmt"\n",##arg)
#define OV7725_DEBUG(fmt,arg...)          do{\
                                          if(OV7725_DEBUG_ON)\
                                          printf("<<-OV7725-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
                                          }while(0)

																		

void OV7725_GPIO_Config(void);
ErrorStatus OV7725_Init(void);
void ImagDisp(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);
void OV7725_Light_Mode(uint8_t mode);
void OV7725_Color_Saturation(int8_t sat);
void OV7725_Brightness(int8_t bri);
void OV7725_Contrast(int8_t cnst);
void OV7725_Special_Effect(uint8_t eff);
void VSYNC_Init(void);				
void OV7725_Window_Set(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height,uint8_t QVGA_VGA);

void image_edge_get(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);
void image_1dimensional(void);
void iamge_kernel(void);
u8 image_calculate(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height,u8 cut);
void image_show(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);																					
#endif























