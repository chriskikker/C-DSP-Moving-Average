#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "projectheader.h"


int main(){

	MovingAverageFilter myFilter;
	Filter_Init(&myFilter);

	f32 frequency = 1.0f;
	f32 sample_rate = 50.0f;

	printf("Time,Noisy,Filtered\n");

	for(int i = 0; i < 100; i++){
		
		f32 t = (f32)i / sample_rate;
		

		f32 clean_signal = sinf(2.0f * 3.14159f * frequency * t);
		f32 noise = ((f32)rand()/(f32)RAND_MAX) - 0.5f;
		f32 noisy_sample = noise + clean_signal;
		f32 filtered_sample = Filter_Update(&myFilter, noisy_sample);

		printf("%.3f,%.3f,%.3f\n",t, noisy_sample, filtered_sample);
	}

	return 0;
}
