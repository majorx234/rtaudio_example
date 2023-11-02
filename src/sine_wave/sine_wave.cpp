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
#include <math.h>
#define _USE_MATH_DEFINES

#include "rtaudio.hpp"
#include "sine_wave.hpp"

SineWave::SineWave(int freq, float duration)
{
  const unsigned int sample_rate = 48000;

  freq_ = freq;
  int num_samples_ = static_cast<int>(duration * sample_rate);
  for(int i = 0;i<num_samples_;i++)
  {
    values_.push_back(sin((2.0 * M_PI * freq_ * i) / sample_rate));
  }
}

SineWave::~SineWave() {
}

void SineWave::print() {
  write_data(values_);
}
