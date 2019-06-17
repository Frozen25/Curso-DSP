#ifndef FILTERADAPTER_H
#define FILTERADAPTER_H

#include "dtmffilter.h"


class FilterAdapter{
	DtmfToneType *f;



	static float filter_697[15];


	static float filter_770[15];


	static float filter_852[15];

	static float filter_941[15];


	static float filter_1209[15];


	static float filter_1336[15];


	static float filter_1477[15];

	static float filter_1633[15];


	float * out697;
	float * out770;
	float * out852;
	float * out941;
	float * out1209;
	float * out1336;
	float * out1477;
	float * out1633;
	float * in;

	float min_energy;

	int size;

public:
	FilterAdapter();
	char getKey();
	void setInput(float * input, int size);
	~FilterAdapter();
};

#endif // FILTERADAPTER_H
