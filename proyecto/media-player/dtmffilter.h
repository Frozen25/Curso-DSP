#ifndef DTMFFILTER_H
#define DTMFFILTER_H


static const int DtmfTone_numStages = 3;
static const int DtmfTone_coefficientLength = 15;

typedef struct
{
	float state[12];
	float output;
	float DtmfTone_coefficients[15];
} DtmfToneType;



typedef struct
{
	float *pInput;
	float *pOutput;
	float *pState;
	float *pCoefficients;
	short count;
} DtmfTone_executionState;





DtmfToneType *DtmfTone_create( void );
void DtmfTone_destroy( DtmfToneType *pObject );
void DtmfTone_init( DtmfToneType * pThis );
void DtmfTone_reset( DtmfToneType * pThis );


#define DtmfTone_writeInput( pThis, input )  \
	DtmfTone_filterBlock( pThis, &(input), &(pThis)->output, 1 );

#define DtmfTone_readOutput( pThis )  \
	(pThis)->output

 int DtmfTone_filterBlock( DtmfToneType * pThis, float * pInput, float * pOutput, unsigned int count, float DtmfTone_coefficients[15]);
#define DtmfTone_outputToFloat( output )  \
	(output)

#define DtmfTone_inputFromFloat( input )  \
	(input)

 void DtmfTone_filterBiquad( DtmfTone_executionState * pExecState );



#endif // DTMFFILTER_H
