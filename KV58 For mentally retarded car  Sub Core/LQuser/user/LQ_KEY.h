/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
��ƽ    ̨������KV58F24���ܳ�VDĸ��
����    д��CHIUSIR
��E-mail  ��chiusir@163.com
�������汾��V1.0
�������¡�2017��12��15��
�������Ϣ�ο����е�ַ��
����    վ��http://www.lqist.cn
���Ա����̡�http://shop36265907.taobao.com
------------------------------------------------
��dev.env.��IAR7.80.4
��Target  ��MKV58F1M0VLQ24
��Crystal �� 50.000Mhz
��busclock��120.000MHz
��pllclock��240.000MHz
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
#ifndef __LQ_KEY_H__
#define __LQ_KEY_H__

#include "include.h"

/*******************************************************************************
* Definitions
******************************************************************************/
//����ģ���
typedef enum
{
    down=0,
    left=1,
    middle=2, 
    right=3, 
    up=4, 
} KEYn_e;
typedef enum
{
    LOW=0,  //DOWN
    HIGH=1, //UP  
    FAIL=0xff,
}KEYs_e;

extern void TestLED(void);
extern void KEY_Init(void);
//extern u8 KEY_Read(KEYn_e keyno);
extern u8 KEYRead();
extern void  Test_GPIO_KEY(void);
extern void  Test_GPIO_EXINT(void);
#endif 