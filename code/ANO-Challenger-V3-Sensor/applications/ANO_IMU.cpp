/******************** (C) COPYRIGHT 2014 ANO Tech *******************************
 * 作者		 ：匿名科创
 * 文件名  ：ANO_IMU.cpp
 * 描述    ：飞行器姿态计算
 * 官网    ：www.anotc.com
 * 淘宝    ：anotc.taobao.com
 * 技术Q群 ：190169595
**********************************************************************************/
#include "ANO_IMU.h"

ANO_IMU imu; 

ANO_IMU::ANO_IMU()
{
}

//IMU初始化
void ANO_IMU::Init()
{
	//滤波器参数初始化
	filter_Init();
	//传感器初始化
	sensor_Init();	
}

//更新传感器数据
void ANO_IMU::updateSensor()
{
	//读取加速度
	mpu6050.Read_Acc_Data();
	//读取角速度
	mpu6050.Read_Gyro_Data();	
	//获取角速度，单位为度每秒
	gyro = mpu6050.Get_Gyro();
	//获取加速度采样值
	acc = mpu6050.Get_Acc();
}


//计算飞行器姿态
void ANO_IMU::getAttitude()
{
	float deltaT;
	Vector3d accTemp, gyroTemp;
	
	//加速度数据一阶低通滤波
	acc_lpf = LPF_1st(acc_lpf, acc, ano.factor.acc_lpf);


	//计算实际测量的加速度和重力加速度的比值
	accRatio = acc_lpf.length_squared() * 100 / (ACC_1G * ACC_1G);		
	
	deltaT = getDeltaT(GetSysTime_us());
	
}


void ANO_IMU::filter_Init()
{
	//加速度一阶低通滤波器系数计算
	ano.factor.acc_lpf = LPF_1st_Factor_Cal(IMU_LOOP_TIME * 1e-6, ACC_LPF_CUT);

}

void ANO_IMU::sensor_Init()
{
	//初始化MPU6050，1Khz采样率，98Hz低通滤波
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
