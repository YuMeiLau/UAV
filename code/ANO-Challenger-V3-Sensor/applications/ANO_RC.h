#ifndef __ANO_RC_H
#define __ANO_RC_H

#include "ANO_Config.h"

#define RC_MID  			1500                     
#define RC_MINCHECK		1150                      
#define RC_MAXCHECK  	1850 
#define RC_MINTHROTTLE 1150
#define RC_MAXTHROTTLE 1900
#define RC_RATE  			50
#define RC_EXPO  			50
#define THR_MID  			50
#define THR_EXPO 			0		

#define PITCH_LOOKUP_LENGTH 7
#define THROTTLE_LOOKUP_LENGTH 12

enum {
    ROLL = 0,
    PITCH,
    YAW,
    THROTTLE,
    AUX1,
    AUX2,
    AUX3,
    AUX4,
    AUX5,
    AUX6
};

class ANO_RC
{
	
public:
	
	ANO_RC();

	uint16_t rawData[10];
	int16_t Command[4];

	//������ʼ��
	void Init(void);
	//ң��ͨ�����ݴ���
	void Cal_Command(void);
	//ҡ��λ�ü��
	void check_sticks(void);
	//����ͨ�����
	void CheckAUX(void);

private:
	
	int16_t lookupPitchRollRC[PITCH_LOOKUP_LENGTH];     
	int16_t lookupThrottleRC[THROTTLE_LOOKUP_LENGTH]; 

};

extern ANO_RC rc;

#endif


