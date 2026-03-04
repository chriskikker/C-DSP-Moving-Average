#include "projectheader.h"

void Filter_Init(MovingAverageFilter *f){
	
	f->index=0;
	f->sum=0.0f;

	for(int i=0; i < FILTER_SIZE; i++){
		f->buffer[i] = 0.0f;
	}

}

float Filter_Update(MovingAverageFilter *f, float next_sample){
	
	f->sum -= f->buffer[f->index]; // vonjuk ki a legregebbi mintat az atlagbol

	f->buffer[f->index] = next_sample; // uj minta felvetele

	f->sum += next_sample; // uj minta az atlagba helyezese
	
	f->index = (f->index + 1) % FILTER_SIZE;

	return f->sum / FILTER_SIZE;
}
