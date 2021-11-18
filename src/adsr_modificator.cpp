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

float* einlesen(size_t* size) {  
  int i = 0;
  int num_samples = 0;
  i = scanf("%d" , &num_samples);
  float* result = (float*)malloc(num_samples*sizeof(float));
  int j = 0;
  float sample = 0;
  do {
    i = scanf("%f" , &sample);
    if(i!=EOF)
    {
      result[j] = sample; 
      j++;
    }
    // Einfügen! abbruch wenn speicher voll
  } while (i != EOF);
  *size = num_samples;
  return result;
}

int ausgeben(float* in_audio, size_t size) {
  unsigned int n = 0;
  printf("%d\n", size);
  while(n < size) {
    printf("%f\n", in_audio[n]);
    n++;
  }
  return 0;
}

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

float* adsr_multiplication(float* in_audio, float* adsr_modification, size_t size) {
  float* result = (float*)malloc(size * sizeof(float));
  int n = 0;
  while(n < size){
    result[n] = in_audio[n] * adsr_modification[n];
    n++;
  }
  return result;
}


int main(int argc, char *argv[])
{
  size_t size = 0;
  float* in_audio = einlesen(&size);
  float ta = 0.05f;
  float td = 0.25f;
  float ts = 0.6f;
  float tr = 0.1f;
  float* adsr_modification = generate_adsr_modificator(size, ta, td, ts, tr);
  unsigned int duration = size/48000;
  float* adsr_multiplication_result = adsr_multiplication(in_audio, adsr_modification, size);
  ausgeben(adsr_multiplication_result, size);
  delete in_audio;
  delete adsr_modification;
  delete adsr_multiplication_result;
  return 0;
}
