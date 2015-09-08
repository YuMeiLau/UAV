/******************** (C) COPYRIGHT 2014 ANO Tech *******************************
 * ����		 �������ƴ�
 * �ļ���  ��ANO_IMU.cpp
 * ����    ����������̬����
 * ����    ��www.anotc.com
 * �Ա�    ��anotc.taobao.com
 * ����QȺ ��190169595
**********************************************************************************/
#include "ANO_IMU.h"

ANO_IMU imu; 

ANO_IMU::ANO_IMU()
{
}

//IMU��ʼ��
void ANO_IMU::Init()
{
	//�˲���������ʼ��
	filter_Init();
	//��������ʼ��
	sensor_Init();	
}

//���´���������
void ANO_IMU::updateSensor()
{
	//��ȡ���ٶ�
	mpu6050.Read_Acc_Data();
	//��ȡ���ٶ�
	mpu6050.Read_Gyro_Data();	
	//��ȡ���ٶȣ���λΪ��ÿ��
	gyro = mpu6050.Get_Gyro();
	//��ȡ���ٶȲ���ֵ
	acc = mpu6050.Get_Acc();
}


//�����������̬
void ANO_IMU::getAttitude()
{
	float deltaT;
	Vector3d accTemp, gyroTemp;
	
	//���ٶ�����һ�׵�ͨ�˲�
	acc_lpf = LPF_1st(acc_lpf, acc, ano.factor.acc_lpf);


	//����ʵ�ʲ����ļ��ٶȺ��������ٶȵı�ֵ
	accRatio = acc_lpf.length_squared() * 100 / (ACC_1G * ACC_1G);		
	
	deltaT = getDeltaT(GetSysTime_us());
	
}


void ANO_IMU::filter_Init()
{
	//���ٶ�һ�׵�ͨ�˲���ϵ������
	ano.factor.acc_lpf = LPF_1st_Factor_Cal(IMU_LOOP_TIME * 1e-6, ACC_LPF_CUT);

}

void ANO_IMU::sensor_Init()
{
	//��ʼ��MPU6050��1Khz�����ʣ�98Hz��ͨ�˲�
	mpu6050.Init(1000,256);
}

float ANO_IMU::getDeltaT(uint32_t currentT)
{
	static uint32_t previousT;
	float	deltaT = (currentT - previousT) * 1e-6;	
	previousT = currentT;
	
	return deltaT;
}

/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/
