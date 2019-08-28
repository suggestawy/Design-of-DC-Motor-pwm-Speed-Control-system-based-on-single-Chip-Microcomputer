#include"speed.h"

void main()
{
	flag_1=0;
	m=100;							 
	zhuansu=0;					   
	flag=0;
	zheng=1;				 
	fan=0;

	init();     //初始化
	while(1)
	{
	  keyscan();          //键盘扫描程序
	}

}


void int1()interrupt 2  //外部中断1脉冲技术记录电机的转速 电机转一圈zhuansu加一
{
  zhuansu++;
}

void int2()interrupt 1				 
{
 
  TH0=0xd8;
  TL0=0xf0;							
  flag++;
  	
  if(flag>=200)				    
  {
		display();					
		zhuansu=0;					
		flag=0;
	}
}
void int3()interrupt 3					 
{
	
	TH1=0xff;
	TL1=0x9c;							     
  
	flag_1++;							
	if(flag_1>199)		
		flag_1=1;
	  
  if(kai==1)		  
  {
		if(zheng==1)				
		{
			if(flag_1<m)   
			{
				motor_zheng();					
			}
			else
			{
				motor_stop();
			}
		}
		 
	  if(fan==1)			  
		{
			if(flag_1<m)				
			{
				motor_fan();
			}
			else						
			{
				motor_stop();
			}
		}
		 
	}
	 
	if(kai==0)			  
	{
	   motor_stop();
	}
}
