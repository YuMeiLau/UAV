/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * ����		 �������ƴ�
 * �ļ���  ��ANO_FlyControl.cpp
 * ����    �����п���
 * ����    ��www.anotc.com
 * �Ա�    ��anotc.taobao.com
 * ����QȺ ��190169595
**********************************************************************************/
#include "ANO_FlyControl.h"

ANO_FlyControl fc;


ANO_FlyControl::ANO_FlyControl()
{
	//����PID����
	PID_Reset();
}

//����PID����
void ANO_FlyControl::PID_Reset(void)
{

}

//��������̬�⻷����
void ANO_FlyControl::Attitude_Outter_Loop(void)
{
	
}

//��������̬�ڻ�����
void ANO_FlyControl::Attitude_Inner_Loop(void)
{
	motor.writeMotor(rc.Command[THROTTLE],0,0,0);
}	


/************************ (C) COPYRIGHT 2014 ANO TECH *****END OF FILE**********************/
