#ifndef FILTER3_H
#define FILTER3_H


class filter3
{
public:
	filter3();
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

// Begin header file, filter3.h


static const int filter3_numStages = 3;
static const int filter3_coefficientLength = 15;
extern float filter3_coefficients[15];

typedef struct
{
	float state[12];
	float output;
} filter3Type;

typedef struct
{
	float *pInput;
	float *pOutput;
	float *pState;
	float *pCoefficients;
	short count;
} filter3_executionState;


filter3Type *filter3_create( void );
void filter3_destroy( filter3Type *pObject );
 void filter3_init( filter3Type * pThis );
 void filter3_reset( filter3Type * pThis );
#define filter3_writeInput( pThis, input )  \
	filter3_filterBlock( pThis, &(input), &(pThis)->output, 1 );

#define filter3_readOutput( pThis )  \
	(pThis)->output

 int filter3_filterBlock( filter3Type * pThis, float * pInput, float * pOutput, unsigned int count );
#define filter3_outputToFloat( output )  \
	(output)

#define filter3_inputFromFloat( input )  \
	(input)

 void filter3_filterBiquad( filter3_executionState * pExecState );



#endif // FILTER3_H
