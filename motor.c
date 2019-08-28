#include"speed.h"

void motor_stop()  //电机停止函数
{
	out=1;
	out1=1;
}

void motor_zheng() //电机正转
{
	out=0;						
	out1=1;
}

void motor_fan()   //电机反转
{
	out=1;						
	out1=0;
}
