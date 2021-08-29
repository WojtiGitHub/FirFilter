#ifndef FIRFLITER_H
#define FIRFLITER_H

#include <stdint.h>

typedef struct{

    /* points to buffer with values of filter input data */
    float *inputBuffer;

    /* pointer used to put data into buffer */
    float *head;

    /* points to buffer with impulse response of the filter */
    float *impulseResponse;

    /* stores the size of the buffer and the impulseResponse buffer */
    uint8_t bufferSize;

    /* stores filter output value */
    float out;

} FirFilter;

/* init FirFilter struct with data buffer, impulse Response buffer and their size */
void FirFilter_init(FirFilter *fir, float *inputBuffer, float *impulseResponse, uint8_t bufferSize);

/* calcuate filter output based on new sample */
void FirFilter_update(FirFilter *fir, float sampleValue);

#endif
