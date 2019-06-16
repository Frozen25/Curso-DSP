#ifndef FILTER_H
#define FILTER_H


class filter
{
public:
	filter();
};




/******************************* SOURCE LICENSE *********************************
Copyright (c) 2019 MicroModeler.

A non-exclusive, nontransferable, perpetual, royalty-free license is granted to the Licensee to
use the following Information for academic, non-profit, or government-sponsored research purposes.
Use of the following Information under this License is restricted to NON-COMMERCIAL PURPOSES ONLY.
Commercial use of the following Information requires a separately executed written license agreement.

This Information is distributed WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

******************************* END OF LICENSE *********************************/

// A commercial license for MicroModeler DSP can be obtained at http://www.micromodeler.com/launch.jsp

// Begin header file, filter1.h


static const int filter1_numStages = 3;
static const int filter1_coefficientLength = 15;
extern float filter1_coefficients[15];

typedef struct
{
	float state[12];
	float output;
} filter1Type;

typedef struct
{
	float *pInput;
	float *pOutput;
	float *pState;
	float *pCoefficients;
	short count;
} filter1_executionState;


filter1Type *filter1_create( void );
void filter1_destroy( filter1Type *pObject );
 void filter1_init( filter1Type * pThis );
 void filter1_reset( filter1Type * pThis );
#define filter1_writeInput( pThis, input )  \
	filter1_filterBlock( pThis, &(input), &(pThis)->output, 1 );

#define filter1_readOutput( pThis )  \
	(pThis)->output

 int filter1_filterBlock( filter1Type * pThis, float * pInput, float * pOutput, unsigned int count );
#define filter1_outputToFloat( output )  \
	(output)

#define filter1_inputFromFloat( input )  \
	(input)

 void filter1_filterBiquad( filter1_executionState * pExecState );



#endif // FILTER_H

