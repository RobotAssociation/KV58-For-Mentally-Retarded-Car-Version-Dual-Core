#include "include.h"

int gear;
int coding;

/*
 * ���뿪��
 * ftmn ��Ӧ�ı�����ͨ��     FTM1/FTM2
 * threshold    ��ֵ   ���ڱ�����ת��������
 *
 * PTC6 Ϊ���뿪������
 */
int CodingSwitch(FTM_Type * ftmn, u8 threshold){
  gear = 0;
  if(!GPIO_Get(PTC6)){
    coding = FTM_AB_Get(ftmn);
    if(coding > 0){
      while(coding > threshold){
         gear++;
         coding -= threshold;
      }
    }else{

      while(coding < -1*threshold){
        gear--;
        coding += threshold;
      }
    }
    PIDMotorLeft.sumError = 0;
    PIDMotorRight.sumError = 0;
  }

  time_delay_ms(20);
  return gear;
}


