#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 
/************************************************
 ALIENTEK精英STM32开发板实验9
 PWM输出实验  
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
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

