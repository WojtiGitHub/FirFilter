#include "FirFilter.h"

/* adds new smaple value to data buffer */
static void addSampleValue(FirFilter *fir, float sampleValue){

    /* adds smaple value to data buffer */
    (*fir->head) = sampleValue;

    /* changes head to next buffer element */
    if(fir->head != &(fir->inputBuffer[fir->bufferSize-1])){

        fir->head++;

    }
    else{

        fir->head = &(fir->inputBuffer[0]);

    }

}

void FirFilter_init(FirFilter *fir, float *inputBuffer, float *impulseResponse, uint8_t bufferSize){

    fir->inputBuffer = inputBuffer;
    fir->impulseResponse = impulseResponse;
    fir->bufferSize = bufferSize;

    fir->head = &(fir->inputBuffer[0]);
    fir->out = 0.0f;

    for(uint8_t i = 0; i < (fir->bufferSize); i++){

        fir->inputBuffer[i] = 0.0f;

    }

}

void FirFilter_update(FirFilter *fir, float sampleValue){

    /* temporary variable to calculate filter output */
    float value = 0.0f;
    /* temporary pointer used to calculate filter output */
    float *ptr = fir->head;

    addSampleValue(fir, sampleValue);

    /* calculating data buffer convolution with filter impulse response */
    for(uint8_t i = 0; i < fir->bufferSize; i++){

        if(ptr != &(fir->inputBuffer[0])){

            ptr--;

        }
        else{

            ptr = &(fir->inputBuffer[fir->bufferSize-1]);

        }

        value += fir->impulseResponse[i] * (*ptr);

    }

    fir->out = value;

}
