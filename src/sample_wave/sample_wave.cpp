/* 
 * This file is part of the rtaudio_example distribution (https://github.com/majorx234/rtaudio_example ).
 * Copyright (c) 2021 Majorx234
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sndfile.hh>

#include "rtaudio.hpp"
#include "sample_wave.hpp"

SampleWave::SampleWave(char* filename)
{
  const unsigned int sample_rate = 48000;
  float duration = 1.0;
  freq_ = 0;
  int num_samples_ = static_cast<int>(duration * sample_rate);
  SndfileHandle wave_file;
  wave_file = SndfileHandle(filename);

  //values_ = reinterpret_cast<float*>(malloc(num_samples_*sizeof(float)));
  wave_file.readf(values_.data(), num_samples_);
}

SampleWave::~SampleWave() {
}

void SampleWave::print() {
  write_data(values_);
}
