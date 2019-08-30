# Design-of-DC-Motor-pwm-Speed-Control-system-based-on-single-Chip-Microcomputer

题目：基于单片机的直流电机PWM调试系统设计。

从电子元器件的选型，原理图设计，PCB板的绘制，到最后的代码整个流程都有介绍，按照这个流程走你可以设计出一个简单的PWM调速系统。

电子元件：STC89C51RC,三极管(S9012,S9013) ,二极管,小功率直流电机，LCD1602，按键开关，霍尔传感器，具体参数忘记了大概就是这些，等下次我上传原理图的时候就明确了

主要由五个模块组成 1muc控制模块，2电源模块，3电机驱动模块，4LCD1602液晶显示模块，按键电路设计模块

调速系统具备的功能：

51单片机的最小系统复位功能

五个按键分别控制 加速，减速，正转，反转，停止。

液晶屏显示转速和占空比。

在电源稳定和足够的前提下可以实现1%~5%的速度精度。

原理图：![image](https://github.com/suggestawy/Pictures/blob/master/%E5%8E%9F%E7%90%86%E5%9B%BE.png)

PCB图: ![image](https://github.com/suggestawy/Pictures/blob/master/PCB.png)


代码说明：mian.c中包含外部中断和主函数。display.c中包含着显示占空比和转速的显示函数。motor.c中存在着电机动作控制函数。keyscan.c包含按键扫描函数。
speed.h 则是包含着所有的头文件以及参数的定义



注册账号很久了，一直都是用来查资料，没有想过写自己的东西，这次就打算把以前做过的设计整理一下放到这里。今天先起个头，其他的有空再写

https://blog.csdn.net/weixin_44880138 留个csdn联系方式 大部分时间混博客的
