/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2017  Pablo Alvarado
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file   controlVolume.cpp
 *         Implements control volumen in the time domain
 * \author Jose Miguel Barboza
 * \date   2017.31.05
 *
 * $Id: controlVolume.cpp $
 */

#include "controlvolume.h"
#include <cmath>
#include <iostream>

using namespace std;


/*
 * Constructor
 */

controlVolume::controlVolume(){
	f = filter1_create();
	f2 = filter2_create();
	internalnbr = 0;
}


/*
 * Destructor
 */

controlVolume::~controlVolume(){

}


/*
 * Init the filter operation
 */

void controlVolume::filter(int blockSize, int volumeGain, float *in, float *out){

	float * incp = new float[blockSize];
	float ei = 0;
	for (int n = 0; n < blockSize;n++){
		ei +=in[n]*in[n];
	}
	//if (ei < 0.00001) ei = 0.05 ;
	for (int n = 0; n < blockSize;n++){
		incp[n] = in[n];
		//cout << in[n] << endl;
	}


	float * outcp = new float[blockSize];
	float * outcp2 = new float[blockSize];
    for (int n=0; n<blockSize;++n){		
		out[n]=float(volumeGain)*in[n]*0.02;
		outcp[n] = 0;
		outcp2[n] = 0;
    }
	filter1_filterBlock( f, incp, outcp, blockSize);
	filter2_filterBlock( f2, in, outcp2, blockSize);
	float e = 0;
	float e2 = 0;
	for (int n = 0; n < 12;n++){
		e +=outcp[blockSize + n -12]*outcp[blockSize + n -12];
		e2 +=outcp2[blockSize + n -12]*outcp2[blockSize + n -12];
	}

	if (e > 0.001f && e2 > 0.001f)
	  cout << "Tecla 1"<< internalnbr++ << endl;
	delete[] outcp;
	delete[] outcp2;
	delete[] incp;
}
