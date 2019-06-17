/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2017  Jose Miguel Barboza
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
 * \file   controlVolume.h
 *         Implements control volumen in the time domain
 * \author Jose Miguel Barboza
 * \date   2017.31.05
 *
 * $Id: controlVolume.cpp $
 */

#include "filter.h"
#include "filter2.h"
#include "filter3.h"

#include "filteradapter.h"
#ifndef CONTROLVOLUME_H
#define CONTROLVOLUME_H

/**
 * Control Volume class
 *
 * This filter has control in the volume gain of the signal.
 *
 * The filter follows the difference equation
 * \f[
 * y(n)=\cvGain x(n)
 * \f]
 */

class controlVolume {

	/*
	filter1Type * f;
	filter2Type * f2;
	filter3Type * f3;
	*/

	FilterAdapter adapter;

	int internalnbr;
public:
    /**
     * Constructor
     */
    controlVolume();

    /**
     * Destructor
     */
    ~controlVolume();

   /**
    * Filter the in buffer and leave the result in out
    */
   void filter(int blockSize,
               int volumeGain,
               float* in,
               float* out);
};


#endif // CONTROLVOLUME_H