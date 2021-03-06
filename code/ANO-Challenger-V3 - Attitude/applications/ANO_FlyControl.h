#ifndef __ANO_FLYCONTROL_H
#define __ANO_FLYCONTROL_H

#include "ANO_Config.h"

#define FLYANGLE_MAX 350  //最大飞行倾角35度

enum {
    PIDROLL,
    PIDPITCH,
    PIDYAW,
    PIDANGLE,
    PIDMAG,
    PIDVELZ,
    PIDALT,
		PIDITEMS
};

class ANO_FlyControl
{

public:
	
	ANO_PID pid[PIDITEMS];

	ANO_FlyControl();

	void PID_Reset(void);
	void AltHoldReset(void);

	//姿态外环控制
	void Attitude_Outter_Loop(void);

	//姿态内环控制
	void Attitude_Inner_Loop(void);

private:
	
	uint8_t rollPitchRate;
	uint8_t yawRate;
	int32_t RateError[3];

};

extern ANO_FlyControl fc;

#endif























