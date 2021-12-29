// Implementation of Low pass filter on STM32 (ARM-Cortex M4)
#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "arm_math.h"                   // ARM::CMSIS:DSP
#include "lowpass_fltr.h"
#include "sine_generator.h"

#define 	SAMPLING_FREQ		1000
#define		SIGNAL_FREQ			10
#define		NOISE_FREQ			50

extern void SystemClock_Config(void);

uint32_t freq;

sine_generator_q15_t Signal_set;
sine_generator_q15_t Noise_set;

q15_t filtered,noise,disturbed,sine;
 
int main()
{
	
	 HAL_Init();
	 SystemClock_Config();
	 freq = HAL_RCC_GetHCLKFreq();
	
	 sine_generator_init_q15(&Signal_set, SIGNAL_FREQ, SAMPLING_FREQ);
	 sine_generator_init_q15(&Noise_set, NOISE_FREQ, SAMPLING_FREQ);
	 low_pass_filter_init(); 


	 while(1)
	 {
		 sine = sine_calc_sample_q15(&Signal_set)/2;
		 noise = sine_calc_sample_q15(&Noise_set)/6;
		 disturbed = noise + sine;
		 filtered  = low_pass_filter(&disturbed);
     HAL_Delay(1);
		 
		 
	 }
}


void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
