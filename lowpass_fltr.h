#ifndef __LOWPASS_FLTR_H__
#define __LOWPASS_FLTR_H__
#include "arm_math.h"                   // ARM::CMSIS:DSP

q15_t low_pass_filter(q15_t *input);
void low_pass_filter_init(void);

#endif

