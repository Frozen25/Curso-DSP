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

/*
 * Constructor
 */

controlVolume::controlVolume(){
	/*
	f = filter1_create();
	f2 = filter2_create();
	f3 = filter3_create();
	*/
	internalnbr = 0;
	t = high_resolution_clock::now();
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
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>( t2 - t ).count();

	//cout << "Elapsed: "<< duration<< endl;

	t = t2;

	/*
	float * incp = new float[blockSize];
	float ei = 0;
	for (int n = 0; n < blockSize;n++){
		ei +=in[n]*in[n];
	}
	//if (ei < 0.00001) ei = 0.05 ;
	for (int n = 0; n < blockSize;n++){
		incp[n] = in[n];
	}



	float * outcp = new float[blockSize];
	float * outcp2 = new float[blockSize];
	float * outcp3 = new float[blockSize];
	*/
	adapter.setInput(in,blockSize);
	adapter.getKey();

    for (int n=0; n<blockSize;++n){		
		out[n]=float(volumeGain)*in[n]*0.02;
		//outcp[n] = 0;
		//outcp2[n] = 0;
		//outcp3[n] = 0;
    }
	/*
	filter1_filterBlock( f, incp, outcp, blockSize);
	filter2_filterBlock( f2, incp, outcp2, blockSize);
	filter3_filterBlock( f3, incp, outcp3, blockSize);
	float e = 0;
	float e2 = 0;
	float e3 = 0;

	for (int n = 0; n < blockSize;n++){
		e +=outcp[n]*outcp[n];
		e2 +=outcp2[n]*outcp2[n];
		e3 +=outcp3[n]*outcp3[n];
	}

	e /= float(blockSize);
	e2 /=float(blockSize);
	e3 /=float(blockSize);

	if (e > 0.001f && e2 > 0.001f)
	  cout << "Tecla 1 "<< internalnbr++ << " e1: "  << e << " e2: " << e2<< endl;
	if (e > 0.001f && e3 > 0.001f)
	  cout << "Tecla 3 "<< internalnbr++ << " e1: "  << e << " e3: " << e3<< endl;
	delete[] outcp;
	delete[] outcp2;
	delete[] incp;
	delete[] outcp3;
	*/
}
