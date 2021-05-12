#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 
/************************************************
 ALIENTEK��ӢSTM32������ʵ��9
 PWM���ʵ��  
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

 int main(void)
 {		
 	u16 pwmval=200;    
	delay_init();
	TIM1_PWM_Init(499,71);
	PWM_ROTATE_Init();
	while(1)  
	{
		delay_ms(2000);
		if(pwmval<500)
		{
			TIM_SetCompare1(TIM1,pwmval);
			TIM_SetCompare2(TIM1,pwmval);
			pwmval+=10;
		}
		else{
			delay_ms(1000);
			pwmval =0;
			TIM_SetCompare1(TIM1,pwmval );
			TIM_SetCompare2(TIM1,pwmval );
		}
	}
 }

