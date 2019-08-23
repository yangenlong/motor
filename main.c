	#include "stm32f10x.h"        
	#include "stm32f10x_gpio.h"
	#include "stm32f10x_rcc.h"
	#include "motor.h"
	#include "delay.h"
	#include "key.h"


	int main(void)
	{
	u8 key=1;	
	Motor_12_Config(); //����ĳ�ʹ��
	delay_init();  //��ʱ������ʼ��
	delay_ms(10000);	
	KEY_Init();//������ʼ��     

	while(1)
	{
			key=KEY_Scan(0);	//�õ���ֵ
			if(key)
		{						   
			switch(key)
			{				 
				case WKUP_PRES:	   //�����ת
												Motor_1_PRun(); //��ת
											 Motor_2_STOP();	
												delay_ms(1); 
					break; 
				
				case KEY1_PRES:	   //�����ת 
											 Motor_1_NRun();  //��ת
											 Motor_2_STOP();	
											 delay_ms(1); 
					break;
				case KEY0_PRES:    //���ֹͣ
													Motor_1_STOP();  //ֹͣ
													Motor_2_STOP();	
													delay_ms(1); 
				break;
			}
		}else delay_ms(10); 
	}
	}



