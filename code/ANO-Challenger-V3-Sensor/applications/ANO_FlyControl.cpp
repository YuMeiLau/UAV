/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * 作者		 ：匿名科创
 * 文件名  ：ANO_FlyControl.cpp
 * 描述    ：飞行控制
 * 官网    ：www.anotc.com
 * 淘宝    ：anotc.taobao.com
 * 技术Q群 ：190169595
**********************************************************************************/
#include "ANO_FlyControl.h"

ANO_FlyControl fc;


ANO_FlyControl::ANO_FlyControl()
{
	//重置PID参数
	PID_Reset();
}

//重置PID参数
void ANO_FlyControl::PID_Reset(void)
{

}

//飞行器姿态外环控制
void ANO_FlyControl::Attitude_Outter_Loop(void)
{
	
}

//飞行器姿态内环控制
void ANO_FlyControl::Attitude_Inner_Loop(void)
{
	motor.writeMotor(rc.Command[THROTTLE],0,0,0);
}	


/************************ (C) COPYRIGHT 2014 ANO TECH *****END OF FILE**********************/
