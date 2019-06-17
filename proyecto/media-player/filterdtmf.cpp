#include "filterdtmf.h"




float filter_h697_taps[15] = {
	0.004877986164101032, 0, -0.004877986164101032, 1.9840462833127273, -0.9938598273011481,// b0, b1, b2, a1, a2
	0.0625, -0.125, 0.0625, 1.9877922150138905, -0.9970215905363072,// b0, b1, b2, a1, a2
	0.0001220703125, 0.000244140625, 0.0001220703125, 1.9863621718213003, -0.996828866193088// b0, b1, b2, a1, a2

};




float filter_v1209_taps[15] = {
	0.0049053103978721905, 0, -0.0049053103978721905, 1.965240653569662, -0.9938598273011479,// b0, b1, b2, a1, a2
	0.03125, -0.0625, 0.03125, 1.9693524461237588, -0.9969812643967478,// b0, b1, b2, a1, a2
	0.000244140625, 0.00048828125, 0.000244140625, 1.967133224729759, -0.9968691861684079// b0, b1, b2, a1, a2

};


FilterDTMF::FilterDTMF(VerticalDTMFValue freqV, HorizontalDTMFValue freqH)
{

	//this->sizeH = bufferSize;
	//this->sizeV = bufferSize;
    switch (freqV) {
    case V697:
		//this->V = filter_h697_taps;
        this->lastV = 0;
        break;
    case V770:

        break;
    case V852:

        break;
    case V941:

        break;
    default:
        break;
    }

    switch (freqH) {
    case H1209:
		//this->H = filter_v1209_taps;
        this->lastH = 0;

        break;
    case H1336:

        break;
    case H1477:

        break;
    case H1633:

        break;

    default:
        break;
    }


    for(unsigned int i = 0; i < sizeH; ++i)
        historyH[i] = 0;
    lastH = 0;
    for(unsigned int i = 0; i < sizeV; ++i)
        historyV[i] = 0;
    lastV = 0;

}

void FilterDTMF::put(double input)
{
    this->historyV[this->lastV++] = input;
    this->lastV = this->lastV % this->sizeV;
    this->historyH[this->lastH++] = input;
    this->lastH = this->lastH % this->sizeH;
}

double FilterDTMF::getH(){
    double acc = 0;
    unsigned int index = lastH, i;
    for(i = 0; i < sizeH; ++i) {
        index = index != 0 ? index-1 : sizeH-1;
        acc += historyH[index] * H[i];
    };
    return acc;
}


double FilterDTMF::getV()
{
    double acc = 0;
    unsigned int index = lastV, i;
    for(i = 0; i < sizeV; ++i) {
        index = index != 0 ? index-1 : sizeV-1;
        acc += historyV[index] * V[i];
    };
    return acc;
}




/*
int filter2_filterBlock( filter2Type * pThis, float * pInput, float * pOutput, unsigned int count )
{
	filter2_executionState executionState;          // The executionState structure holds call data, minimizing stack reads and writes
	if( ! count ) return 0;                         // If there are no input samples, return immediately
	executionState.pInput = pInput;                 // Pointers to the input and output buffers that each call to filterBiquad() will use
	executionState.pOutput = pOutput;               // - pInput and pOutput can be equal, allowing reuse of the same memory.
	executionState.count = count;                   // The number of samples to be processed
	executionState.pState = pThis->state;                   // Pointer to the biquad's internal state and coefficients.
	executionState.pCoefficients = filter2_coefficients;    // Each call to filterBiquad() will advance pState and pCoefficients to the next biquad

	// The 1st call to filter2_filterBiquad() reads from the caller supplied input buffer and writes to the output buffer.
	// The remaining calls to filterBiquad() recycle the same output buffer, so that multiple intermediate buffers are not required.

	filter2_filterBiquad( &executionState );		// Run biquad #0
	executionState.pInput = executionState.pOutput;         // The remaining biquads will now re-use the same output buffer.

	filter2_filterBiquad( &executionState );		// Run biquad #1

	filter2_filterBiquad( &executionState );		// Run biquad #2

	// At this point, the caller-supplied output buffer will contain the filtered samples and the input buffer will contain the unmodified input samples.
	return count;		// Return the number of samples processed, the same as the number of input samples

}

 void filter2_filterBiquad( filter2_executionState * pExecState )
{
	// Read state variables
	float w0, x0;
	float w1 = pExecState->pState[0];
	float w2 = pExecState->pState[1];

	// Read coefficients into work registers
	float b0 = *(pExecState->pCoefficients++);
	float b1 = *(pExecState->pCoefficients++);
	float b2 = *(pExecState->pCoefficients++);
	float a1 = *(pExecState->pCoefficients++);
	float a2 = *(pExecState->pCoefficients++);

	// Read source and target pointers
	float *pInput  = pExecState->pInput;
	float *pOutput = pExecState->pOutput;
	short count = pExecState->count;
	float accumulator;

	// Loop for all samples in the input buffer
	while( count-- )
	{
		// Read input sample
		x0 = *(pInput++);

		// Run feedback part of filter
		accumulator  = w2 * a2;
		accumulator += w1 * a1;
		accumulator += x0 ;

		w0 = accumulator ;

		// Run feedforward part of filter
		accumulator  = w0 * b0;
		accumulator += w1 * b1;
		accumulator += w2 * b2;

		w2 = w1;		// Shuffle history buffer
		w1 = w0;

		// Write output
		*(pOutput++) = accumulator ;
	}

	// Write state variables
	*(pExecState->pState++) = w1;
	*(pExecState->pState++) = w2;

}

*/



