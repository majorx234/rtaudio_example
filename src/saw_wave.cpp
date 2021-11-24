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

#include "saw_wave.h"

SawWave::SawWave()
{
  unsigned int duration = 1.0;
  unsigned int freq = 440;
  const unsigned int sample_rate = 48000;
  num_samples = static_cast<int>(sample_rate * duration);

  unsigned int max = sample_rate/freq; //->480
  float fmax = static_cast<float>(max);
 
  values = (float*)malloc(num_samples*sizeof(float));
  printf("%d\n",num_samples);
  for(int i =0; i<num_samples;i++) {
    values[i] = ((i % (max)) / fmax) - 1;
  }
}

SawWave::~SawWave() {
  if (values) {
    delete values;
  }
}

void SawWave::print() {
  for(int i = 0; i<num_samples; i++) {
    printf("%f\n", values[i]); 
  }
}
