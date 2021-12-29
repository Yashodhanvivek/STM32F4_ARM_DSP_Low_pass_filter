// Low pass filter coeeficients

#include "lowpass_fltr.h"

#define FILTER_TAPS		        32
#define	FILTER_BLOCK_LEN 		1	

q15_t low_pass_filter_coeff[FILTER_TAPS] = 
{
0xFB5C,
0x021C,
0x0219, 
0x024E,  

0x02AC,   
0x0325,    
0x03B0,     
0x0445,      

0x04DC,        
0x056E,         
0x05F7,          
0x0675,           

0x06DB,            
0x072D,             
0x0766,              
0x0782,               

0x0782,                
0x0766,                 
0x072D,                  
0x06DB,                   

0x0675,                    
0x05F7,                     
0x056E,                      
0x04DC,                       

0x0445,
0x03B0,
0x0325,
0x02AC,

0x024E,
0x0219,
0x021C,
0xFB5C,
};

q15_t  low_pass_filter_state[FILTER_TAPS +FILTER_BLOCK_LEN];

arm_fir_instance_q15  low_pass_filter_set;

void low_pass_filter_init(void)
{
	  arm_fir_init_q15(&low_pass_filter_set, FILTER_TAPS, low_pass_filter_coeff, 	     
low_pass_filter_state, FILTER_BLOCK_LEN);

}

q15_t low_pass_filter(q15_t *input)
{
	 q15_t out;
	 arm_fir_q15(&low_pass_filter_set, input, &out, FILTER_BLOCK_LEN);
	
	return out;
	

	
}

