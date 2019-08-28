#include"speed.h"

void write_com(uchar com) // 向1602写一字节（控制指令）
{
  rs=0;
  rw=0;
  P0=com;
  delay(5);
  en=1;
  delay(10);
  en=0;
}
void write_data(uchar date)// 向1602写一字节（数据）
{
  rs=1;
  rw=0;
  P0=date;
  delay(5);
  en=1;
  delay(5);
  en=0;
}
void init()               // 初始化函数
{ 
  en=0;
  rw=0;
  write_com(0x01);        // lcd初始化，清屏命令
  write_com(0x38);		  // 16*2显示
  write_com(0x0c);		  // 关闭光标
  
  TMOD=0x11;              // 定时器T0方式1 .          
  TH0=0xd8;
  TL0=0xf0;               // 定时器装入初值 
  ET0=1;                  // 定时器0开中断
  TR0=1; 				  // 定时器T0启动 
   
  EX1=1;				  // 外部中断1
  IT1=1; 
  
  TH1=0xff;				   // 定时100us
  TL1=0x9C;		
  ET1=1;                   // 定时器1开中断
  TR1=1;
  
  EA=1;                    
  
  write_com(0x80);
  write_data('V');
  write_data(':');
  write_com(0x87);		
  write_data('r');
  write_data('p');
  write_data('m');
  write_com(0xc0); 
  write_data('z');
  write_data('h');
  write_data('a');
  write_data('n');
  write_data('k');
  write_data('o');
  write_data('n');
  write_data('g');
  write_data('b');
  write_data('i');	  
  write_data(':');
  displaym();
}


void display()
{
	int disdata[5];		        				// 显示占空比的数值，存到此数组
	write_com(0x82);
	zhuansu=zhuansu*30;	  						//将两秒内的计数乘以30得到转每分
	disdata[0] = zhuansu/10000+0x30;
	disdata[1] = zhuansu%10000/1000+0x30;
	disdata[2] = zhuansu%1000/100+0x30;
	disdata[3] = zhuansu%100/10+0x30;
	disdata[4] = zhuansu%10+0x30;
   
	/*
	如果千位为0，让LCD不显示，0x30和0x20可以查询ACSII码表
	0x30变换成十进制的值为48，对于在ASCCII的值为 0
	0x20变换成十进制的值为32，对于在ASCCII的值为 空格（space）
	*/
	if(disdata[0]==0x30)		
	{
		disdata[0]=0x20;						//注意这里用的是赋值符号=，不是等于==
		if( disdata[1]==0x30)					//如果百位为0，让LCD不显示，0x30和0x20可以查询ACSII码表
		{
			disdata[1]=0x20;
			if( disdata[2]==0x30)				//如果百位为0，让LCD不显示，0x30和0x20可以查询ACSII码表
			{
				disdata[2]=0x20;
				if(disdata[3]==0x30)
					disdata[3]=0x20;
			}
		}
   }
	 
   //依次显示五位数据字符
	write_data(disdata[0]);
	delay(4);
	write_data(disdata[1]);
	delay(4);
	write_data(disdata[2]);
	delay(4);
	write_data(disdata[3]);
	delay(4);
	write_data(disdata[4]);
	delay(4);
	write_com(0xd0);			  					
}

void displaym()
{
	write_com(0xcb);
	if(m/200%10!=0)
	write_data(m/200%10+0x30);			  	 	//如果占空比百位不为0则显示百位否则显示空格
	else 
	write_data(' ');
  
	if(m/200%10==0&&m/20%10==0)
	write_data(' ');
	else
	write_data(m/20%10+0x30);				 	//如果占空比小于10 十位正常显示  否则显示空格
	write_data(m/2%10+0x30);				 	//显示个位
}

