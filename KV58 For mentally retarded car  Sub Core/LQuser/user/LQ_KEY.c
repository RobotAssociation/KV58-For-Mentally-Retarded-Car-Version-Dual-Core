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
��busclock��137.500MHz
��pllclock��275.000MHz
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/

#include "include.h"

void KEY_Init(void)
{
  GPIO_Init(GPIOB,19,GPI,1);

}

//u8 KEY_Read(KEYn_e keyno)
//{
//  switch(keyno)
//  {
//  case down:
//    return GPIO_Get(PTC7);
//    break;
//
//  case left:
//    return GPIO_Get(PTC8);
//    break;
//
//  case middle:
//    return GPIO_Get(PTC9);
//    break;
//
//  case right:
//    return GPIO_Get(PTC12);
//    break;
//
//  case up:
//    return GPIO_Get(PTC13);
//    break;
//
//  default:
//    return 0XFF;
//  }
//}

u8 KEYRead(){
  return GPIO_Get(PTB19);
}

/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
����  �ߡ�CHIUSIR
������˵�������԰�����OLED��ʾ
�������汾��V1.0
�������¡�2017��11��24�� 
����������
������ֵ����
������ֵ����
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
void Test_GPIO_KEY(void)
{ 
  while (1)
  {  
    //���԰���      
    if(KEY_Read(up)==0)
      LCD_P6x8Str(13,3,(uint8_t*)"KEY0 Pressed!   ");
    else LCD_P6x8Str(13,3,(uint8_t*)"KEY0 NO Pressed!");
    if(KEY_Read(down)==0)
      LCD_P6x8Str(13,5,(uint8_t*)"KEY1 Pressed!   ");
    else LCD_P6x8Str(13,5,(uint8_t*)"KEY1 NO Pressed!");
    if(KEY_Read(middle)==0)
      LCD_P6x8Str(13,7,(uint8_t*)"KEY2 Pressed!   ");
    else LCD_P6x8Str(13,7,(uint8_t*)"KEY2 NO Pressed!");
    
    //LED��˸
    LED_Ctrl(LED1, RVS);     
    
    //��ʱ
    time_delay_ms(50);
  }
}

void PORTB_IRQHandler(void)
{
  int n;
  n=20;
  if((PORTB_ISFR & (1<<n)))
  {
      PORTB_ISFR |= (1<<n);
      /* �û����������ж��ڳ��� */
      LED_Ctrl(LED0, RVS); 
  }
  n=21;
  if((PORTB_ISFR & (1<<n)))
  {
      PORTB_ISFR |= (1<<n);
      /* �û����������ж��ڳ��� */
      LED_Ctrl(LED1, RVS); 
  }
  n=22;
  if((PORTB_ISFR & (1<<n)))
  {
      PORTB_ISFR |= (1<<n);
      /* �û����������ж��ڳ��� */
      LED_Ctrl(LED2, RVS); 
  }
}

void Test_GPIO_EXINT(void)
{  
  EXTI_Init(GPIOB,22,rising_down);   //K2
  EXTI_Init(GPIOB,21,falling_up);    //K1�ж�  
  EXTI_Init(GPIOB,20,falling_up);    //K0�ж� 
  for(;;)
  {  
    //systick�ж���ʱ
    time_delay_ms(5);
  }
}