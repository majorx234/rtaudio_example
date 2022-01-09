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

#include "tri_wave.h"

TriWave::TriWave(int freq, float duration)
{
  freq_ = freq;
  const unsigned int sample_rate = 48000;
  num_samples_ = static_cast<int>(sample_rate * duration);

  unsigned int max = sample_rate/freq_; //->480
  float fmax = static_cast<float>(max);
 
  values_ = (float*)malloc(num_samples_*sizeof(float));
  //for(int i =0; i<num_samples_;i++) {
  //  values_[i] = 2*(((i % (max)) / fmax) - 0.5);
  //}
  
  for(int i =0; i<num_samples_;i++) {
    float s = 0.0f;
    unsigned int n = i % (max);
    if(n < (fmax / 2)) {
      s= ((2 * n) / fmax) - 0.5;
    } else {
      s= -1.0 * ((2 * n) / fmax) + 1.5;      
    }
    values_[i] = 2*s;
    i++;
  }
}

TriWave::~TriWave() {
  if (values_) {
    free(values_);
  }
}

void TriWave::print() {
  printf("%d\n", num_samples_);
  for(int i = 0; i<num_samples_; i++) {
    printf("%f\n", values_[i]); 
  }
}
