#include"speed.h"

void keyscan()  		//键盘扫描函数
{
	
  if(key_add==0)    		//加一
   {
	  delay(20);      
		if(key_add==0)
		{
			if(m<=199)
			m++;
			displaym();		
		}
	}
  
	if(key_dec==0)	 		//减一
	{
		delay(20);
		if(key_dec==0)
		{
			if(m>=1)
			m--;
			displaym();					
		}
	}
  
	if(key_zheng==0)		//正转
	{
		delay(20);
		if(key_zheng==0)
		{
			zheng=1;		
			fan=0;	  
		}
	}
  
	if(key_fan==0)			//反转
	{
		delay(20);
		if(key_fan==0)
		{
		zheng=0;		
		fan=1;	  		
	
		}
	}
  
	if(key_stop==0)
	{
		delay(20);
		if(key_stop==0)
		{
		while(key_stop==0);
		kai=1-kai;
		}
	}
}
