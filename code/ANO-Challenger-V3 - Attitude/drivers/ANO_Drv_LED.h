#ifndef __ANO_DRV_LED_H__
#define __ANO_DRV_LED_H__

#include "board.h"

class ANO_LED
{

public:
	
	static void Init(void);

	void ON1(void);
	void ON2(void);
	void OFF1(void);
	void OFF2(void);
};

extern ANO_LED led;

#endif

