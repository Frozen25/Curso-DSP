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

	if (!adapter.isIdle())
    for (int n=0; n<blockSize;++n){		
		out[n]=float(volumeGain)*in[n]*0.02;
    }	

	if (!adapter.onCall()){
		adapter.setInput(in,blockSize);
		adapter.getKey();
	}
	if (adapter.isRinging()){
		auto duration = duration_cast<seconds>( high_resolution_clock::now() - adapter.getRingStartTime() ).count();
		cout << duration << endl;
		if (duration > 10){
			adapter.setIdle();
		}
	}
	//t = high_resolution_clock::now();
}

void controlVolume::updateSentivity(int value)
{
	adapter.updateSensitivity(value);
}

bool controlVolume::isRinging()
{
	return adapter.isRinging();
}

void controlVolume::openCall()
{
	adapter.openCall();
}

bool controlVolume::onCall()
{
	return adapter.onCall();
}

void controlVolume::exitCall()
{
	adapter.exitCall();
}

void controlVolume::typingKeys()
{
	adapter.typingKeys();
}

bool controlVolume::isIdle()
{
	return adapter.isIdle();
}

bool controlVolume::onTypingKeys()
{
	return adapter.onTypingKeys();
}
