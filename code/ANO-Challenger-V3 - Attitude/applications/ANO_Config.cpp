/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * ����		 �������
 * �ļ���  ��ANO_Config.cpp
 * ����    �������ļ�
 * ����    ��www.anotc.com
 * �Ա�    ��anotc.taobao.com
 * ����QȺ ��190169595
**********************************************************************************/

#include "ANO_Config.h"

ANO_Config ano;


ANO_Config::ANO_Config(void)
{
	f.ANGLE_MODE = 1;
}

//ָʾ��
void ANO_Config::Pilot_Light(void)
{
	static u8 cnt = 0,cnt2 = 0;
	
	
	if(f.ARMED)
	{
		cnt++;
		switch(cnt)
		{
			case 1:
				led.ON1();
				break;
			case 20:
				led.OFF1();
				break;
			case 40:
				cnt = 0;
				break;			
		}
	}
	else
	{
		led.ON1(); 
		led.ON2(); 
	}
	
}


/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/
