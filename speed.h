#ifndef __SPEED_H
#define __SPEED_H

#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int 
void displaym();    //duty占空比显示
void motor_stop();  //电机停止函数
void motor_zheng(); //电机正转
void motor_fan();   //电机反转

sbit en=P2^5;		 // 1602 en6管脚
sbit rs=P2^7;	 	 // 1602端口rs4管脚
sbit rw=P2^6;		 // lcd1602控制端口 rw5管脚
sbit key_add=P1^0;	 // 占空比加1
sbit key_dec=P1^1;	 // 占空比减一
sbit key_zheng=P1^2; // 正转
sbit key_fan=P1^3;	 // 反转
sbit key_stop=P1^4;	 // 开始停止切换
sbit out=P3^4;	     // PWM输出用于正传
sbit out1=P3^7;		 // PWM输出用于反转

uint zhuansu,flag,m,flag_1,zheng,fan,kai;

void delay(uint z)   // 延时1ms函数
{

 uint x,y;
 for(x=0;x<z;x++)
     for(y=0;y<110;y++);
}

#endif
