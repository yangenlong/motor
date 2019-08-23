	#include "stm32f10x.h"        
	#include "stm32f10x_gpio.h"
	#include "stm32f10x_rcc.h"
	#include "motor.h"
	#include "delay.h"
	#include "key.h"


	int main(void)
	{
	u8 key=1;	
	Motor_12_Config(); //电机的初使化
	delay_init();  //延时函数初始化
	delay_ms(10000);	
	KEY_Init();//按键初始化     

	while(1)
	{
			key=KEY_Scan(0);	//得到键值
			if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	   //电机正转
												Motor_1_PRun(); //正转
											 Motor_2_STOP();	
												delay_ms(1); 
					break; 
				
				case KEY1_PRES:	   //电机反转 
											 Motor_1_NRun();  //反转
											 Motor_2_STOP();	
											 delay_ms(1); 
					break;
				case KEY0_PRES:    //电机停止
													Motor_1_STOP();  //停止
													Motor_2_STOP();	
													delay_ms(1); 
				break;
			}
		}else delay_ms(10); 
	}
	}



