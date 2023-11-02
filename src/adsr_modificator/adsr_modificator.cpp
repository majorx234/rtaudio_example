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
#include <vector>

#include "rtaudio.hpp"

float* generate_adsr_modificator(size_t size, float ta, float td, float ts, float tr) {
  float* result = (float*)malloc(size * sizeof(float));
  float fmax_attack = size * ta;
  int max_attack = static_cast<int>(fmax_attack);
  float fmax_decay = size * td;
  int max_decay = static_cast<int>(fmax_decay);
  float fmax_sustain = size * ts;
  int max_sustain = static_cast<int>(fmax_sustain);
  float fmax_release = size * tr;
  int max_release = static_cast<int>(fmax_release);
  
  int n = 0;
  while(n < max_attack) {
    float s = ((n % (max_attack)) / fmax_attack);
    result[n] = s;
    n++;
  }
  int j = 0;
  while(n < max_attack + max_decay) {
    float s = (1.0 - (0.7*( (j % (max_decay)) / fmax_decay)));
    result[n] = s;
    j++;
    n++;
  }
  while(n < max_attack+max_decay+max_sustain) {
    float s = 0.3;
    result[n] = s;
    n++;
  }
  int k = 0;
  while(n < size) {
    float s = (0.3 - 0.3*( (k % (max_release)) / fmax_release));
    result[n] = s;
    k++;
    n++;
  }
  return result;
}

std::vector<float> adsr_multiplication(std::vector<float> &in_audio, float* adsr_modification, size_t size) {
  std::vector<float> result{};
  int n = 0;
  while(n < size){
    result.push_back(in_audio[n] * adsr_modification[n]);
    n++;
  }
  return result;
}

int main(int argc, char *argv[]) {
  std::vector<float> in_audio = read_data();
  size_t size = in_audio.size();
  float ta = 0.05f;
  float td = 0.25f;
  float ts = 0.6f;
  float tr = 0.1f;
  float* adsr_modification = generate_adsr_modificator(size, ta, td, ts, tr);
  std::vector<float> adsr_multiplication_result = adsr_multiplication(in_audio, adsr_modification, size);
  write_data(adsr_multiplication_result);
  delete adsr_modification;
  return 0;
}
